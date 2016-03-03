
import java.io.*;


public class MyMessage implements Serializable
{
    static final int USERLIST = 0, MESSAGE = 1, LOGOUT = 2;
    private int type;
    private String message, recipient, user;

    MyMessage(int type, String message)
    {
        this.type = type;
        this.message = message;
        this.recipient = "All";
    }

    MyMessage(int type, String message, String recipient, String user)
    {
        this.type = type;
        this.message = message;
        this.recipient = recipient;
        this.user = user;
    }

    String getRecipient() { return recipient; }
    String getUser() { return user; }
    int getType() { return type; }
    String getMessage() { return message; }








}
