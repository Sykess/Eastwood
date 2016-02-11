import javax.swing.*;
import java.awt.*;
import java.awt.event.*;



public class DotTest extends JPanel
{
    private int x = -20, y = -20;


    public static void main(String[] args)
    {
        JFrame f = new JFrame("My dot thingy");
        DotTest mine = new DotTest();
        f.setSize(500,500);
        f.setVisible(true);
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        f.add(mine);
    }



    public DotTest()
    {
        addMouseListener(new MouseAdapter(){
            @Override
            public void mousePressed(MouseEvent e){
                x = e.getX() - 10;
                y = e.getY() - 10;
                repaint();
            }
        });
    }

    @Override
    public void paintComponent(Graphics g)
    {
        super.paintComponent(g);
        setBackground(Color.BLACK);
        g.setColor(Color.RED);
        g.fillOval(x, y, 20, 20);
    }

}
