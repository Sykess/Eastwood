
import java.net.*;
import java.awt.event.*;
import java.awt.*;
import java.io.*;
import java.util.*;

class  ClientInfo{
	String name;
	Socket cs;
	public ClientInfo(String nm,Socket s)
	{
		name = nm;
		cs = s;
	}

	}



public class multichatserver {

	ServerSocket  ss;
	Socket s;
	Hashtable list;
	PrintStream chatLog;
	Vector namevect;


	public multichatserver()
	{
		list = new Hashtable();
		namevect = new Vector();
		try
		{
		chatLog = new PrintStream(new FileOutputStream("multichat.log"));
	}catch(IOException e)
	{
		System.out.println("Error opening file");
		System.exit(1);
	}
	   try{
		ss = new ServerSocket(2000);
		while(true)
		{
		 System.out.println("SERVER READY TO TAKE REQUESTS");
		 s = ss.accept();
		 new FileThread(s).start();

		}
	}catch(IOException ioe)
	{
		System.out.println("IOException Caught");
	}
	}


class FileThread extends Thread{

	Socket fs;
	BufferedReader br;
	String name;
	public FileThread(Socket s)
	{
		fs = s;
	}
	public void run()
	{
		try
		{
		InputStream  is = fs.getInputStream();
		OutputStream os = fs.getOutputStream();
		br = new BufferedReader (new InputStreamReader(is));
		while((name = br.readLine())!=null)
		{
		  if(list.containsKey(name))
		  {
		   	continue;
		  }
		  else
		  {
			  ClientInfo cinfo = new ClientInfo(name,fs);
			  chatLog.println(name+" Registered from Host:"+fs.getInetAddress().getHostName()+"and IP address:"+fs.getInetAddress().getHostAddress() );
			  list.put(name,cinfo);
			  Enumeration enumm = list.elements();
			  namevect.addElement(name);
			  while(enumm.hasMoreElements())
			  {
			    ClientInfo clinfo =(ClientInfo)enumm.nextElement();
			    System.out.println("client name"+clinfo.name);
			    new DataOutputStream(clinfo.cs.getOutputStream()).writeInt(1);
			    ObjectOutputStream obos = new ObjectOutputStream(clinfo.cs.getOutputStream());
			    obos.writeObject(namevect);
			    obos.flush();
			  }
			  new messageThread(name,fs).start();
			  System.out.println("Thread Started.");
			  break;
		  }
	   }

   }
	   catch(IOException ioe)
	   {
		   System.out.println("IOException Caught");
	   }


}
}

class messageThread extends Thread{
	Socket ms;
	String name;
	public messageThread(String nm,Socket s)
	{
		ms = s;
		name = nm;
	}

	public void run()
	{
		InputStream is;
		OutputStream os;
		BufferedReader br;
		String message;
		try{
			is = ms.getInputStream();
		    os = ms.getOutputStream();
		    br = new BufferedReader(new InputStreamReader(is));

			while((message = br.readLine())!=null)
		    {
			   System.out.println("message sent from "+ name);
		       Enumeration en = list.elements();
			   while(en.hasMoreElements())
			    {
			    	ClientInfo clinf = (ClientInfo)en.nextElement();
			    	if(!clinf.name.equals(name))
			    	{
			    	  new DataOutputStream(clinf.cs.getOutputStream()).writeInt(0);
				   	  //clinf.ps.println(name+": "+message);
				   	  PrintWriter pw = new PrintWriter(new OutputStreamWriter(clinf.cs.getOutputStream()),true);
				   	  pw.println(name+": "+message);
			        }
				 //clinf.ps.println(name+": "+message);
			    }

		   }
		   System.out.println("out of while loop");

	}catch(IOException ioe)
	{
		list.remove(name);
		chatLog.println(name + "Quits.");
		return;
	}


	}

  }




  public static void main(String args[])
  {
	  multichatserver mcs = new multichatserver();
  }
}