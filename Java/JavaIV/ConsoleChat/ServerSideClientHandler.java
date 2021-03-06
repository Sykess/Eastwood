import java.util.*;
import java.net.*;
import java.io.*;

public class ServerSideClientHandler implements Runnable, MessageListener
{
	private ObjectInputStream in;
	private ObjectOutputStream out;
	private ArrayList<ServerSideClientHandler> list;
	private MessageReceiver mr;
	private String name;

	public void setName(String name) { this.name = name; }
	public String getName() { return name; }

	public ServerSideClientHandler(Socket socket, ArrayList<ServerSideClientHandler> l)
	{
		try
		{
			in = new ObjectInputStream(socket.getInputStream());
			mr = new MessageReceiver(in, this);
			Thread t = new Thread(mr);
			out = new ObjectOutputStream(socket.getOutputStream());
			t.start();
			list = l;
		}
		catch(Exception e)
		{
			System.out.println("Unable to connect.");
			//e.printStackTrace();
		}
	}

	public void deliverMessage(String s)
	{
		System.out.println("A client said:" + s);
		for(int i = 0; i < list.size(); i++)
		{
			// Here you could check for names, etc. Instead of send to all
			list.get(i).sendMail(s);
		}
	}
	// Or maybe make something like this
	public void deliverMessage(String s, String name)
	{
		System.out.println("A client said:" + s);
		for(int i = 0; i < list.size(); i++)
		{
			if(list.get(i).getName().equals(name))
			{
				list.get(i).sendMail(s);
			}
		}
	}

	public void sendMail(String s)
	{
		try
		{
			out.writeObject(s);
		}
		catch(Exception e)
		{
			System.out.println("Client can not receive mail.");
			//e.printStackTrace();
		}
	}

	public void removeMe()
	{
		list.remove(this);
		System.out.println("Client left.  There are " + list.size() + " clients connected.");
	}

	public void run()
	{
		System.out.println("New client is here!!!");
	}
}