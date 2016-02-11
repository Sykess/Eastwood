
import java.util.*;
import java.net.*;
import java.io.*;

public class Server
{
    public static void main(String[] args) throws Exception
    {
		ArrayList<ServerSideClientHandler> list = new ArrayList<>();
		System.out.println("Server started...");
        ServerSocket ss = new ServerSocket(4324);
		while(true)
		{
        	System.out.println("Waiting for client to connect...");
        	Socket socket = ss.accept();
        	System.out.println("Client connected");
        	ServerSideClientHandler ssch = new ServerSideClientHandler(socket, list);
        	list.add(ssch);
        	Thread t = new Thread(ssch);
        	t.start();
		}



        //ObjectInputStream ois = new ObjectInputStream(socket.getInputStream());
        //ObjectOutputStream oos = new ObjectOutputStream(socket.getOutputStream());

		/*
        while(true)
        {
            String request = (String)ois.readObject();
            System.out.println("Client said: " + request);
            //System.out.println(request);
            oos.writeObject("you said:"+ request);
            //receive request (wait to get request)
            //print
            //generate response
            //send
        }
        */
    }
}
