
import java.util.*;



public class ListTest
{
    public static void main(String[] args)
    {
        ArrayList<String> list = new ArrayList<>();
        ArrayList<Integer> list2 = new ArrayList<>();
        list2.add(5);
        list2.add(6);
        list.add("7");
        System.out.println(list.get(0).getClass().getName());
        //list.add(0);
        //list.add(4);
        list.add("bob");

        //System.out.println(list.size());
        //System.out.println(list.get(3));
        String a = (String)list.get(0);
        System.out.println(a);






    }




}
