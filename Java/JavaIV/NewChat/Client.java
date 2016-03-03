
import java.util.*;
import java.net.*;
import java.io.*;


public class Client
{
    private ObjectInputStream ois;
    private ObjectOutputStream oos;
    private Socket socket;
    
    private ChatGUI cg;
    private String server, userName;
    private int port;

    public String getUsername() { return userName; }

    Client(String server, int port, String userName)
    {
        this(server, port, userName, null);
    }

    Client(String server, int port, String userName, ChatGUI cg)
    {
        this.server = server;
        this.port = port;
        this.userName = userName;
        this.cg = cg;
    }

    public boolean start()
    {
        try
        {
            socket = new Socket(server, port);
        } catch (Exception e)
        {
            display("Error connecting to server");
            return false;
        }
        display("Connection accepted!");

        try
        {
            ois = new ObjectInputStream(socket.getInputStream());
            oos = new ObjectOutputStream(socket.getOutputStream());
        } catch (Exception e)
        {
            display("Error creating streams");
            return false;
        }

        // Create and start a new thread to listen to server
        new ListenToServer().start();
        try
        {
            oos.writeObject(userName);
        } catch (Exception e)
        {
            display("Error logging in");
            disconnect();
            return false;
        }
        return true;
    }


    private void display(String msg)
    {
        if(cg != null)
        {
            cg.append(msg + "\n");
        } else
        {
            System.out.println(msg);
        }
    }

    void sendMessage(MyMessage msg)
    {
        try
        {
            oos.writeObject(msg);
        }catch (Exception e)
        {
            display("Error writing to server");
        }
    }

    private void disconnect()
    {
        try
        {
            if (ois != null) ois.close();
            if (oos != null) oos.close();
            if (socket != null) socket.close();
        } catch (Exception e){}
        if (cg != null)
        {
            cg.connectionFailed();
        }
    }


    class ListenToServer extends Thread
    {
        public void run()
        {
            while(true)
            {
                try
                {
                    String msg = (String) ois.readObject();
                    if(cg != null)
                    {
                        cg.append(msg);
                    }
                } catch (Exception e)
                {
                    display("Server has closed down");
                    if (cg != null)
                    {
                        cg.connectionFailed();
                    }
                    break;
                }
            }
        }
    }




}

