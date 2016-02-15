public interface MessageListener
{
	public void deliverMessage(String s);
	public void deliverMessage(String s, String name);
	public void removeMe();
}