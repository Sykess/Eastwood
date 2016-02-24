
import java.io.*;
import java.net.*;
import java.text.SimpleDateFormat;
import java.util.*;

public class Server
{
    private static int clientId;
    private ArrayList<ClientThread> al;
    private ServerGUI serverGui;
    private SimpleDateFormat dateFormat;
    private int port;
    private bool keepRunning;

    public Server(int port, ServerGUI gui)
    {
        serverGui = gui;
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
                Socket socket = serverSocket.accept();
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
                serverSocket.close();
                for(int i = 0; i < al.size(); i++)
                {
                    ClientThread ct = al.get(i);
                    try
                    {
                        ct.sInput.close();
                        ct.sOutput.close();
                        ct.socket.close();
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

    private void stop()
    {
        keepRunning = false;
    }

    private void display(String mess)
    {
        String message = dateFormat.format(new Date()) + " " + mess;
        serverGui.appendEvent(message + "\n");
    }

    private synchronized void sendMessages(String message, String recip, String sender)
    {
        String formatMsg = dateFormat.format(new Date());
        formatMsg = formatMsg + " " + message + "\n";
        serverGui.appendChat(formatMsg);
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
            uniqueId++;
            id = uniqueId;
            this.sock = sock;
            try
            {
                oos = new ObjectOutputStream(socket.getOutputStream());
                ois = new ObjectInputStream(socket.getInputStream());
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
        
        


        





}
