import javax.swing.*;
import java.awt.*;
import java.awt.event.*;


public class TestingDot extends JPanel
{
    private int x = -20, y = -20;

    public static void main(String[] args)
    {
        JFrame f = new JFrame("Dotty");
        f.setVisible(true);
        TestingDot mine = new TestingDot();
        f.setSize(700, 700);
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        f.add(mine);
    }

    public TestingDot()
    {
        addMouseListener(new MouseAdapter(){
            @Override
            public void mousePressed(MouseEvent e)
            {
                x = e.getX();
                y = e.getY();
                repaint();
            }
        });
    }
    @Override
    public void paintComponent(Graphics g)
    {
        super.paintComponent(g);
        setBackground(Color.WHITE);
        g.setColor(Color.RED);
        g.fillOval(x - 10, y - 10, 20, 20);
    }

}
