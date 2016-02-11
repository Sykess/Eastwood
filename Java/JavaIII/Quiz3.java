import javax.swing.*;
import java.awt.*;
import java.awt.event.*;


public class Quiz3 extends JPanel
{
    private int x = -20, y = -20;

    public static void main(String[] args)
    {
        JFrame f = new JFrame("Quiz 3");
        Quiz3 mine = new Quiz3();
        f.setSize(500, 500);
        f.setVisible(true);
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        f.add(mine);
    }

    @Override
    public void paintComponent(Graphics g)
    {
        super.paintComponent(g);
        setBackground(Color.GRAY);
        g.setColor(Color.RED);
        g.fillOval(x-10, y-10, 20, 20);
    }

    public Quiz3()
    {

        addMouseListener(new MouseAdapter(){
            public void mousePressed(MouseEvent e)
            {
                x = e.getX();
                y = e.getY();
                repaint();
            }
        });
    }
}
