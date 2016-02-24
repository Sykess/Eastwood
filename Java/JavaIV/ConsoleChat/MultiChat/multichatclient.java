import java.io.*;
import java.net.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.util.*;


public class multichatclient extends Frame implements ActionListener,KeyListener {

	Label meslabel;
	Vector namevect;
	TextField mesg;
	Button send,login,exit;
	TextArea ta,usrlist;
	Panel top,mid,bot;
	String message,messg,usr,name;
	InputStream is ;
	OutputStream os ;
	BufferedReader br ;
	PrintStream ps ;
	Socket s;
	public multichatclient(String title)
	{
		super(title);
		initComponents();
		setLayout(new BorderLayout());
		top = new Panel();
		top.setLayout(new GridLayout(1,2));
		bot = new Panel();
		bot.setLayout(new GridLayout(1,3,5,5));
		setSize(500,500);
		setBackground(Color.gray);
		setForeground(Color.black);
		meslabel = new Label("Message",Label.RIGHT);
		mesg = new TextField(20);
		ta = new TextArea("Client: hello!\n",50,50,TextArea.SCROLLBARS_BOTH);
		usrlist = new TextArea("user list",50,20,TextArea.SCROLLBARS_BOTH);
		send = new Button("Send");
		login = new Button("Login");
		exit = new Button("Exit");
		send.setEnabled(false);
		top.add(meslabel);
		top.add(mesg);
		bot.add(login);
		bot.add(send);
		bot.add(exit);
		add(top,BorderLayout.NORTH);
		add(bot,BorderLayout.SOUTH);
		add(ta,BorderLayout.CENTER);
		add(usrlist,BorderLayout.EAST);
		send.addActionListener(this);
		mesg.addKeyListener(this);
		login.addActionListener(this);
		exit.addActionListener(this);
		try
		 {
			s = new Socket("127.0.0.1",2000);
			is = s.getInputStream();
			os = s.getOutputStream();
			ps = new PrintStream(os);
		  } catch(IOException ie)
		  {
			  ie.printStackTrace();
		  }
	  }

	public void actionPerformed(ActionEvent ae)
	{
		Button btn = (Button)ae.getSource();
		byte reply = 0;
		if(btn == login)
		{
			loginDialog ld = new loginDialog(this);
			ld.show();
			usr = ld.user;
			//usrlist.append("\n"+usr);
			//System.out.println("USER NAME:"+ usr);
			ps.println(usr);
			ps.flush();
			login.setEnabled(false);
			send.setEnabled(true);
			new MessageReader().start();
		}
		if(btn == send)
		{
		  String txt = mesg.getText();
		  ps.println(txt);
		  ps.flush();
		  ta.append(txt+"\n");
          mesg.setText("");
      	}
		if(btn == exit)
		{
			try
			{
			s.close();
		}catch(IOException ioe)
		{
		}
			System.exit(1);
		}


	}
	public void keyPressed(KeyEvent ke)
	{
	}
	public void keyReleased(KeyEvent ke)
	{
	}
	public void keyTyped(KeyEvent ke)
	{

	}


    public void initComponents()
    {
		addWindowListener(new WindowAdapter(){
			public void  windowClosing(WindowEvent we)
			{
				setVisible(false);
			}
		});


	}


 class MessageReader extends Thread {
	 int check=0;
	 ObjectInputStream objis;
	 DataInputStream dis;
	 String msg;
	 public void run()
	 	 {
			  try
			   {
				   while(true)
				   {
				   dis = new DataInputStream(is);
				   check = dis.readInt();
				   if(check == 1)
				   {
				     objis = new ObjectInputStream(is);
			 	     namevect =(Vector)objis.readObject();
			 	     System.out.println("No of users in list:"+namevect.size());
			 	     Enumeration en = namevect.elements();
			 	     usrlist.setText("User List");
				     while(en.hasMoreElements())
				      {
				        name = (String)en.nextElement();
				        System.out.println("name added to list:"+name);
				        usrlist.append("\n"+name);
			 	      }
			 	      System.out.println("check: "+check);
			       }
			       else
			       {
					   br = new BufferedReader(new InputStreamReader(is));
					   msg = br.readLine();
					   ta.append(msg+"\n");
					   while((msg = br.readLine())!=null)
					   {
						 String mymsg = msg;
						 mymsg = mymsg.substring(4,mymsg.length()-1);
						 System.out.println("message received is:"+mymsg);
						 //mymsg = "hello";
						 JOptionPane.showMessageDialog(null,mymsg,"Message Received",JOptionPane.INFORMATION_MESSAGE);
						 ta.append(mymsg+"\n");
						 System.out.println("check: "+check);
					   }

				   }

			   }

 			    }catch(Exception e)
			 	 {
			 	   System.out.println(e);
			 	 }



      }
 }






  public static void main(String s[])
    {
      multichatclient mcc= new multichatclient("Messenger");
      mcc.setVisible(true);
      mcc.show();
    }

}

class  loginDialog extends Dialog implements ActionListener{
	Label loginname;
	TextField logintext;
	Button okay;
	Panel top,central;
	String user;

	loginDialog(Frame parent)
	{
		super(parent,"User Login",true);
		setSize(400,100);
		setResizable(false);
		setFont(new Font("ComicSans",Font.BOLD|Font.ITALIC,15));
		loginname = new Label("Enter Login:",Label.RIGHT);
		logintext = new TextField(15);
		okay = new Button("OK");
		//okay.setBounds(10,10,20,20);
		top = new Panel();
		central = new Panel();
		central.setLayout(new FlowLayout());
		top.setLayout(new GridLayout(1,2,5,5));
		top.add(loginname);
		top.add(logintext);
		central.add(okay);
		add(central,BorderLayout.CENTER);
		add(top,BorderLayout.NORTH);
		okay.addActionListener(this);
	}

	public void actionPerformed(ActionEvent ae)
	{
		user = logintext.getText();
		dispose();
	}

}




