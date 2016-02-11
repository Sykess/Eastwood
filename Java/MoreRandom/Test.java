
import javax.swing.JFrame;



public class Test
{
    public static void main(String[] args)
    {
        Square mine = new Square();
        JFrame frame = new JFrame();
        frame.setVisible(true);
        frame.setSize(400, 400);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.add(mine);
    }
}
