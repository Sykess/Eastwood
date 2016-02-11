import java.awt.Graphics;
import java.awt.Color;
import java.awt.event.*;
import java.awt.image.*;
import java.io.*;
import javax.imageio.*;

public class Paddle extends Sprite implements KeyListener, BallListener
{
    private BufferedImage paddleImage;
    private boolean graphicsOn;

    public Paddle()
    {
        graphicsOn = true;
        try{
            paddleImage = ImageIO.read(new File("paddle.png"));
        }catch(IOException e){
            System.out.println("Could not open images, turning images off!");
            graphicsOn = false;
        }
        setPosition(400, 850);
        setSize(150, 25);
        speed = 20;
        setBounds(0, 800, 850, 850);
    }

    public void paintSprite(Graphics g)
    {
        updatePosition(false);
        if(graphicsOn){
            g.drawImage(paddleImage, x-width/2, y-height/2, width, height, null);

        }else{
            g.setColor(Color.BLACK);
            g.fillRect(x - width/2, y - height/2, width, height);
        }
    }

    public void setGraphics(boolean choice)
    {
        graphicsOn = choice;
    }

    public void setSpeed(int speed)
    {
        this.speed = speed;
    }

    public boolean ballMoved(BallEvent e)
    {
        if(contains(e.getX(), e.getY())){
            return true;
        }
        return false;
    }

    public int sideHit(BallEvent e)
    {
        // if side is hit, always top side, so return 2 for top
        return 2;
        //SideHit current = whichSide(e.getX(), e.getY());
        //return convertToSideNum(current);
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
    }

    public void keyReleased(KeyEvent e)
    {
        xVel = 0;
    }

    public void keyTyped(KeyEvent e)
    {}


}
