
import java.net.*;
import java.io.*;
import java.util.*;

public class ServerSideClientHandler implements Runnable
{
	private ObjectInputStream in;
	private ObjectOutputStream out;
	private ArrayList<ServerSideClientHandler> list;
	private String mailbox = "";

	public ServerSideClientHandler(Socket socket, ArrayList<ServerSideClientHandler> l)
	{
		try{
			in = new ObjectInputStream(socket.getInputStream());
        	out = new ObjectOutputStream(socket.getOutputStream());
        	list = l;
  		}catch(Exception e){
			e.printStackTrace();
		}
	}

	public void sendMail(String s)
	{
		mailbox = mailbox + "\n" + s;
	}

	public void run()
	{
		while(true)
		{
			try{
		    	String request = (String)in.readObject();
		    	System.out.println("Client said: " + request);
		    	for(int i = 0; i < list.size(); i++)
		    	{
					list.get(i).sendMail(request);
					out.writeObject(mailbox);
					mailbox = "";

				}
		    	//System.out.println(request);
		    	//out.writeObject("you said:"+ request);
			}catch(Exception e){
				e.printStackTrace();
			}
        }
	}
}