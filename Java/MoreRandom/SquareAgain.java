
import java.awt.*;
import javax.swing.*;


public class SquareAgain extends JPanel
{
    public static void main(String[] args)
    {
        SquareAgain mine = new SquareAgain();
        JFrame frame = new JFrame();
        frame.setVisible(true);
        frame.setSize(400, 400);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.add(mine);
    }

    public void paint(Graphics g)
    {
        super.paint(g);
        setBackground(Color.blue);
        g.setColor(Color.white);
        g.fillRect(135, 135, 100, 100);
    }

    /*
    @Override
    public void paintComponent(Graphics g)
    {
        super.paintComponent(g);
        setBackground(Color.white);
        g.setColor(Color.red);
        g.fillRect(136, 136, 100, 100);
    }
    */
}




