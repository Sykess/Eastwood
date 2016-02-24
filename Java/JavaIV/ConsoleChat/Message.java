


public class Message
{
	String sender, recipient, message;

	public Message(String send, String rec, String mess)
	{
		sender = send; recipient = rec; message = mess;
	}
	public String getSender() { return sender; }
	public String getRecipient() { return recipient; }
	public String getMessage() { return message; }
	public void setSender(String s) { sender = s; }
	public void setRecipient(String r) { recipient = r; }
	public void setMessage(String m) { message = m; }


}