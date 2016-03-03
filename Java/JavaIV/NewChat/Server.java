
import java.io.*;
import java.net.*;
import java.text.SimpleDateFormat;
import java.util.*;

public class Server
{
    private static int clientId;
    private ArrayList<ClientThread> al;
    //private ServerGUI serverGui;
    private SimpleDateFormat dateFormat;
    private int port;
    private boolean keepRunning;

    public Server(int port)
    {
        //serverGui = gui;
        this.port = port;
        dateFormat = new SimpleDateFormat("HH:mm:ss");
        al = new ArrayList<ClientThread>();
    }

    public void start() 
    {
        keepRunning = true;
        try
        {
            ServerSocket ss = new ServerSocket(port);
            while(keepRunning)
            {
                display("Waiting for clients");
                Socket socket = ss.accept();
                if (!keepRunning)
                {
                    break;
                }
                ClientThread t = new ClientThread(socket);
                al.add(t);
                t.start();
            }
            try
            {
                ss.close();
                for(int i = 0; i < al.size(); i++)
                {
                    ClientThread ct = al.get(i);
                    try
                    {
                        ct.ois.close();
                        ct.oos.close();
                        ct.sock.close();
                    } catch (Exception e)
                    {
                        e.printStackTrace();
                    }
                }
            } catch (Exception e)
            {
                display("Error closing server and clients");
                e.printStackTrace();
            }
        } catch (Exception e)
        {
            display("Error with server socket");
            e.printStackTrace();
        }
    } // end of start


    public static void main(String[] args)
    {
        int portNum = 3484;
        switch(args.length)
        {
            case 1:
                try
                {
                    portNum = Integer.parseInt(args[0]);
                } catch (Exception e)
                {
                    System.out.println("Invalid port num");
                    return;
                }
            case 0:
                break;
            default:
                System.out.println("Invalid usage");
                return;
        }
        Server server = new Server(portNum);
        server.start();
    }

    private void stop()
    {
        keepRunning = false;
    }

    private void display(String mess)
    {
        String message = dateFormat.format(new Date()) + " " + mess;
        //serverGui.appendEvent(message + "\n");
        System.out.println(message);
    }

    private synchronized void sendMessages(String message, String recip, String sender)
    {
        String formatMsg = dateFormat.format(new Date());
        formatMsg = formatMsg + " " + message + "\n";
        //serverGui.appendChat(formatMsg);
        for (int i = al.size() -1; i >= 0; i--)
        {
            ClientThread ct = al.get(i);
            if (!recip.equalsIgnoreCase("All"))
            {
                if (!ct.userName.equalsIgnoreCase(recip) && !ct.userName.equalsIgnoreCase(sender))
                {
                    continue;
                }
            }
            if (!ct.writeMsg(formatMsg))
            {
                al.remove(i);
                display("Client " + ct.userName + " has disconnected.");
            }
        }
    }
    
    // Used in case of logout button
    synchronized void remove(int id)
    {
        for (int i = 0; i < al.size(); i++)
        {
            ClientThread ct = al.get(i);
            if (ct.id == id)
            {
                al.remove(i);
                return;
            }
        }
    }

    class ClientThread extends Thread
    {
        Socket sock;
        ObjectInputStream ois;
        ObjectOutputStream oos;
        int id;
        String userName;
        MyMessage myMessage;
        String date;

        ClientThread(Socket sock)
        {
            clientId++;
            id = clientId;
            this.sock = sock;
            try
            {
                oos = new ObjectOutputStream(sock.getOutputStream());
                ois = new ObjectInputStream(sock.getInputStream());
                userName = (String) ois.readObject();
                display(userName + "has connected.");
            } catch (Exception e)
            {
                display("Error creating streams");
                return;
            }
            date = new Date().toString() + "\n";
        }

        public void run()
        {
            boolean keepRunning = true;
            while (keepRunning)
            {
                try
                {
                    myMessage = (MyMessage) ois.readObject();
                } catch (Exception e)
                {
                    display (userName + ": error reading streams");
                    break;
                }
                String message = myMessage.getMessage();

                // Recipients of chat message
                String recipient = myMessage.getRecipient();
                String sender = myMessage.getUser();

                switch(myMessage.getType())
                {
                    case MyMessage.MESSAGE:
                        sendMessages(userName + ":  " + message, recipient, sender);
                        break;
                    case MyMessage.LOGOUT:
                        keepRunning = false;
                        break;
                    case MyMessage.USERLIST:
                        writeMsg("List of current users\n");
                        for (int i = 0; i < al.size(); i++)
                        {
                            ClientThread ct = al.get(i);
                            writeMsg((i+1) + ": " + ct.userName);
                        }
                        break;
                }
            }
            remove(id);
            close();
        }

        private void close()
        {
            try
            {
                if (oos != null) oos.close();
                if (ois != null) ois.close();
                if (sock != null) sock.close();
            }catch (Exception e)
            {
                e.printStackTrace();
            }
        }

        private boolean writeMsg(String msg)
        {
            if (!sock.isConnected())
            {
                close();
                return false;
            }
            try
            {
                oos.writeObject(msg);
            } catch(Exception e)
            {
                display("Error sending message to " + userName);
            }
            return true;
        }
    }
}
