
import java.util.*;
import java.net.*;
import java.io.*;

public class Client
{
    public static void main(String[] args) throws Exception
    {
        String request = "";
        Scanner keys = new Scanner(System.in);
        //Socket socket = new Socket("10.110.202.21", 4324);
        //Socket socket = new Socket("10.42.102.221", 4324);
        //Socket socket = new Socket("localhost",4324);
        Socket socket = new Socket("localhost", 4324);
        //Socket socket = new Socket("127.0.0.1", 4324);

		//Order of these two has to be different client-server
        ObjectOutputStream oos = new ObjectOutputStream(socket.getOutputStream());
        ObjectInputStream ois = new ObjectInputStream(socket.getInputStream());

        while(!request.equals("bye"))
        {
            request = keys.nextLine();
            //System.out.println("Sending request");
            oos.writeObject(request);
            //System.out.println("Request sent");
            String response = (String)ois.readObject();

            System.out.println(response);



            //get request

            //send request

            //receive request

            //print response


        }


    }



}
