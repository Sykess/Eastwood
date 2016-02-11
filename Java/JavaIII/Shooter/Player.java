import java.awt.Graphics;
import java.awt.Color;
import java.awt.event.KeyListener;
import java.awt.event.KeyEvent;

public class Player extends Unit implements KeyListener, ShotListener
{
    private Shot shot = new Shot();

    public Player()
    {
        setPosition(450, 570);
        setSize(30, 40);
        speed = 20;
        setBounds(0, 900, 570, 570);
    }

    public void paintUnit(Graphics g)
    {
        updatePosition(false);
        g.setColor(Color.blue);
        g.fillOval(x - width/2, y - height/2, width, height);
        shot.paintUnit(g);
    }

    public Shot getShot()
    {
        return shot;
    }

    public boolean shotMoved(ShotEvent e)
    {
        if(contains(e.getX(), e.getY()))
        {
            x = 450;
            Shooter.lives--;
            return true;
        }
        return false;
    }

    public void keyPressed(KeyEvent e)
    {
        if(e.getKeyCode() == KeyEvent.VK_LEFT)
        {
            xVel = -speed;
        }
        if(e.getKeyCode() == KeyEvent.VK_RIGHT)
        {
            xVel = speed;
        }
        if(e.getKeyCode() == KeyEvent.VK_SPACE)
        {
            shot.fire(x, y, false);;
        }
    }

    public void keyReleased(KeyEvent e)
    {
        xVel = 0;
    }

    public void keyTyped(KeyEvent e)
    {}
}
