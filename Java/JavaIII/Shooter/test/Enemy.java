import java.awt.Graphics;
import java.awt.Color;
import java.util.Random;

public class Enemy extends Unit implements ShotListener
{
    private boolean destroyed = false;
    private Shot shot = new Shot();
    private Random random = new Random();

    public Enemy()
    {
        setPosition(450, 50);
        setVelocity(random.nextInt(21)-10, -(random.nextInt(6)+3));
        setSize(50, 30);
        setBounds(900, 500);
    }

    public void paintUnit(Graphics g)
    {
        if(!destroyed)
        {
            updatePosition(true);
            g.setColor(Color.red);
            g.fillRoundRect(x-width/2, y-height/2, width, height, 25, 15);
            if(random.nextInt(100) < 10)
            {
                shot.fire(x, y, true);
            }
            shot.paintUnit(g);
        }
    }

    public Shot getShot()
    {
        return shot;
    }

    public boolean shotMoved(ShotEvent e)
    {
        if(contains(e.getX(), e.getY()) && !destroyed)
        {
            destroyed = true;
            Shooter.score++;
            return true;
        }
        return false;
    }
}
