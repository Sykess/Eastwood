
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class Quiz2 extends JPanel
{
    private int x = 250, y = 250;
    Color purple = new Color(128,0,128);

    public static void main(String[] args)
    {
        JFrame f = new JFrame("Quiz 2");
        Quiz2 mine = new Quiz2();
        f.setSize(500, 500);
        f.setVisible(true);
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        f.add(mine);
    }

    public Quiz2()
    {
        addKeyListener(new KeyAdapter()
        {
            public void keyPressed(KeyEvent e)
            {
                int keys = e.getKeyCode();
                System.out.println(keys);
                if(e.getKeyCode() == KeyEvent.VK_UP)
                    y -= 10;
                if(e.getKeyCode() == KeyEvent.VK_DOWN)
                    y += 10;
                if(e.getKeyCode() == KeyEvent.VK_LEFT)
                    x -= 10;
                if(e.getKeyCode() == KeyEvent.VK_RIGHT)
                    x += 10;
                repaint();
            }
        });
        setFocusable(true);
    }

    @Override
    public void paintComponent(Graphics g)
    {
        super.paintComponent(g);
        setBackground(Color.black);
        g.setColor(purple);
        g.fillRect(x-10, y-10, 20, 20);
    }

}
