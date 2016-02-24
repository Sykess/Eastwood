import java.awt.*;
import javax.swing.*;

public class ChatGUI 
{                    
    private JFrame frame = new JFrame("Chat!");
    
    private JPanel channelPanel = new JPanel();        
    private JPanel contactsPanel = new JPanel();
    private JPanel textPanel = new JPanel();
    private JPanel messagePanel = new JPanel();        
    private JPanel jp = new JPanel();    
    private JPanel panel = new JPanel();	
    private JPanel chatLayout = new JPanel();
    //blank in the NORTH makes sure the messages don't go all the way to the top
    private JPanel blank = new JPanel(); 
    
    private Color buttonsGrey = new Color(179,179,179);
    private Color messagesGrey = new Color(223,223,223);
    private Color background = new Color(69, 82, 104);    
    
    private JLabel separator = new JLabel(" ");
    private JTextField input;	
        
    private JTextArea messages = new JTextArea();
    
    private JButton join = new JButton("Join");
    private JButton leave = new JButton("Leave");
    private JButton pm = new JButton("Private Message");
    private JButton sendButton = new JButton("Send");    
    
    public static void main(String[] args)
    {
        new ChatGUI();        
    }
    
    public ChatGUI()
    {
        //Setting up the background colors
        join.setBackground(Color.orange);
        leave.setBackground(Color.orange);
        pm.setBackground(Color.orange);
        frame.setBackground(background);
        contactsPanel.setBackground(background);
        textPanel.setBackground(messagesGrey);
        channelPanel.setBackground(background);
        blank.setBackground(background);
        jp.setBackground(background);
        
        frame.setSize(700,500);
        frame.add(jp);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
       
        //layouts                  
        GridLayout contactsLayout = new GridLayout(18,1, 5, 2);        
        channelPanel.setLayout(new GridLayout(10,1, 5, 2));
        contactsPanel.setLayout(new GridLayout(18,1, 5, 2));

        //The next two loops are adding text to the buttons for the sake of example, 
        //they should be replaced by something that actually corresponds to what 
        //is being done in the final product
        for(int i=0;i<17;i++)
        {
            addContact("filler");
        }
        
        contactsPanel.add(separator);        
        contactsPanel.add(pm);
  
        for(int i=0;i<7;i++)
        {
            addChannel("filler");
        }        
 
        channelPanel.add(join);
        channelPanel.add(leave);
        messagePanel.add(messages);
        messagePanel.setBackground(background);
        
        jp.add(channelPanel, BorderLayout.EAST);
        jp.add(contactsPanel, BorderLayout.WEST);
        ChatPanel(); //this sets what's in the south
        jp.add(textPanel, BorderLayout.CENTER);
        jp.add(blank, BorderLayout.NORTH);
                        
        frame.setVisible(true);
    }
    
    //this makes the text input panel.
    public void ChatPanel()
    {
	panel.setLayout(new BorderLayout(5,5));
        chatLayout.setBackground(background);

	// Create our main field that will hold the input text.
	input = new JTextField();
	input.setSize(50,50);
        input.setColumns(40);
	chatLayout.add(input);

	// Create our send button and attach it to the panel.
	sendButton = new JButton("SEND");
	sendButton.setSize(80, 30);
	sendButton.setLocation(125, 270);
        //sendButton.addActionListener(this);
	chatLayout.add(sendButton);      
        panel.add(chatLayout);

        jp.add(panel,BorderLayout.SOUTH);
    }
       
    //adding a button. 
    private void addContact(String s)
    {            
        JButton conB = new JButton(s);
        conB.setBackground(buttonsGrey);
        contactsPanel.add(conB);                          
    }
    
    private void addChannel(String s)
    {
        JButton chanB  = new JButton(s);
        chanB.setBackground(buttonsGrey);
        channelPanel.add(chanB);
    }
}