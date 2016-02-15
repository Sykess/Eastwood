import java.util.*;
import java.net.*;
import java.io.*;

public class Server
{
	public static void main(String[] args) throws Exception
	{
		Scanner scan = new Scanner(System.in);
		ArrayList<ServerSideClientHandler> list = new ArrayList<ServerSideClientHandler>();
		System.out.println("Server Started...");
		ServerSocket ss = new ServerSocket(4324);
		while(true)
		{
			System.out.println("Waiting for clients to connect...");
			Socket socket = ss.accept();
			ServerSideClientHandler ssch = new ServerSideClientHandler(socket, list);
			System.out.print("Enter the name for this user: ");
			String userName = scan.next();
			System.out.println(userName);
			ssch.setName(userName);
			list.add(ssch);
			Thread t = new Thread(ssch);
			t.start();
			System.out.println("Client connected.  There are " + list.size() + " clients connected.");
		}
	}
}
