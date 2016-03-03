import javax.swing.*;
import java.awt.*;
import java.awt.event.*;


public class ChatGUI extends JFrame implements ActionListener
{
    private JLabel label1, label2;
    private JTextField tf;
    private JTextField tfServer, tfPort, tfSend;
    private JButton login, logout, userList;
    private JTextArea chatRoom;
    private boolean connected;
    private Client client;
    private int defaultPort;
    private String defaultHost;

    ChatGUI(String host, int port)
    {
        super("Chat GUI");
        defaultPort = port;
        defaultHost = host;

        JPanel bottomPanel = new JPanel(new GridLayout(5,1));
        JPanel serverPanel = new JPanel(new GridLayout(1,5,1,3));
        tfServer = new JTextField(host);
        tfPort = new JTextField("" + port);
        tfPort.setHorizontalAlignment(SwingConstants.RIGHT);

        serverPanel.add(new JLabel("Server: "));
        serverPanel.add(tfServer);
        serverPanel.add(new JLabel("Port: "));
        serverPanel.add(tfPort);
        serverPanel.add(new JLabel(""));
        bottomPanel.add(serverPanel);

        label1 = new JLabel("Enter your user name:", SwingConstants.CENTER);
        bottomPanel.add(label1);
        tf = new JTextField("Ghost");
        tf.setBackground(Color.WHITE);
        bottomPanel.add(tf);

        label2 = new JLabel("Enter name to send private message:", SwingConstants.CENTER);
        bottomPanel.add(label2);
        tfSend = new JTextField("All");
        tfSend.setBackground(Color.WHITE);
        bottomPanel.add(tfSend);

        add(bottomPanel, BorderLayout.SOUTH);

        chatRoom = new JTextArea("Welcome to Chat\n", 80, 80);
        JPanel centerPanel = new JPanel(new GridLayout(1, 1));
        centerPanel.add(new JScrollPane(chatRoom));
        chatRoom.setEditable(false);
        add(centerPanel, BorderLayout.CENTER);

        login = new JButton("Login");
        login.addActionListener(this);
        logout = new JButton("Logout");
        logout.addActionListener(this);
        logout.setEnabled(false);
        userList = new JButton("User List");
        userList.addActionListener(this);
        userList.setEnabled(false);

        JPanel topPanel = new JPanel();
        topPanel.add(login);
        topPanel.add(logout);
        topPanel.add(userList);
        add(topPanel, BorderLayout.NORTH);

        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setSize(600, 600);
        setVisible(true);
        tf.requestFocus();
    }

    void append(String str)
    {
        chatRoom.append(str);
        chatRoom.setCaretPosition(chatRoom.getText().length() - 1);
    }

    void connectionFailed()
    {
        login.setEnabled(true);
        logout.setEnabled(false);
        userList.setEnabled(false);
        label1.setText("Enter user name:");
        tf.setText("Ghost");
        tfPort.setText("" + defaultPort);
        tfServer.setText(defaultHost);
        tf.removeActionListener(this);
        connected = false;
    }

    public void actionPerformed(ActionEvent e)
    {
        Object o = e.getSource();
        if(o == logout)
        {
            client.sendMessage(new MyMessage(MyMessage.LOGOUT, ""));
            return;
        }
        if (o == userList)
        {
            client.sendMessage(new MyMessage(MyMessage.USERLIST, ""));
            return;
        }

        if (connected)
        {
            if (!tfSend.getText().equalsIgnoreCase("All"))
            {
                client.sendMessage(new MyMessage(MyMessage.MESSAGE, tf.getText(), tfSend.getText(), client.getUsername()));
            } else
            {
                client.sendMessage(new MyMessage(MyMessage.MESSAGE, tf.getText()));
            }
            tf.setText("");
            return;
        }

        if( o == login)
        {
            String userName = tf.getText().trim();
            if(userName.length() == 0)
            {
                return;
            }
            String server = tfServer.getText().trim();
            if(server.length() == 0)
            {
                return;
            }
            String portNumber = tfPort.getText().trim();
            if (portNumber.length() == 0)
            {
                return;
            }
            int port = 0;
            try
            {
                port = Integer.parseInt(portNumber);
            } catch(Exception ex)
            {
                return;
            }
            client = new Client(server, port, userName, this);

            if(!client.start())
            {
                return;
            }
            tf.setText("");
            label1.setText("Enter message to send:");
            connected = true;
            login.setEnabled(false);
            logout.setEnabled(true);
            userList.setEnabled(true);
            tfServer.setEditable(false);
            tfPort.setEditable(false);
            tf.addActionListener(this);
        }
    }

    public static void main(String[] args)
    {
        new ChatGUI("localhost", 3484);
    }
            




}
