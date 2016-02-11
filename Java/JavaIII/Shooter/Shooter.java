import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.Timer;
import java.awt.Graphics;
import java.awt.Color;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

public class Shooter extends JPanel implements ActionListener
{
    public static int score = 0;
    public static int lives = 3;

    private Player player = new Player();
    private Enemy[] enemy = new Enemy[10];

    public static void main(String[] args)
    {
        JFrame frame = new JFrame("Shooter");
        frame.setSize(906, 633);
        frame.setResizable(false);
        frame.add(new Shooter());
        frame.setVisible(true);
    }

    public Shooter()
    {
        setFocusable(true);
        addKeyListener(player);
        for(int i = 0; i < enemy.length; i++)
        {
            enemy[i] = new Enemy();
            player.getShot().addShotListener(enemy[i]);
            enemy[i].getShot().addShotListener(player);
        }
        Timer timer = new Timer(50, this);
        timer.start();
    }

    public void paintComponent(Graphics g)
    {
        g.setColor(Color.black);
        g.fillRect(0, 0, 900, 600);
        player.paintUnit(g);
        for(int i = 0; i < enemy.length; i++)
        {
            enemy[i].paintUnit(g);
        }
        g.setColor(Color.green);
        g.drawString("Score: " + Shooter.score, 50, 580);
        g.drawString("Lives: " + Shooter.lives, 800, 580);
    }

    public void actionPerformed(ActionEvent e)
    {
        repaint();
    }
}
