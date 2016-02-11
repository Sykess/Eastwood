
import java.awt.Graphics;
import java.awt.Color;
import java.awt.image.*;
import java.io.*;
import javax.imageio.*;

public class Ball extends Sprite
{
    private boolean rolling, graphicsOn;
    private BallListener[] listener;
    private int listenerCount, sideNum, incSpeed, speedCounter;
    private SideHit side;
    private BufferedImage redBall;

    public Ball()
    {
        speedCounter = 10;
        rolling = false;
        graphicsOn = true;
        side = SideHit.NONE;
        sideNum = 0;
        incSpeed = 0;
        listener = new BallListener[100];
        listenerCount = 0;
        setBounds(0, 800, 0, 880);
        setPosition(400, 450);
        setSize(16,16);
        speed = 12;
        try{
            redBall = ImageIO.read(new File("redBall.png"));
        }catch(IOException e){
            System.out.println("Could not open images, turning images off!");
            graphicsOn = false;
        }
    }

    public void changeSpeedCounter(int num)
    {
        speedCounter = num;
    }

    public void incrementSpeedCounter(int num)
    {
        speedCounter += num;
    }

    public void setGraphics(boolean choice)
    {
        graphicsOn = choice;
    }

    public void roll(int launchX, int launchY, boolean down)
    {
        if(!rolling && Breakout.lives > 0){
            rolling = true;
            setPosition(launchX, launchY);

            if(down){
                yVel = speed;
                xVel = speed;
            }else{
                yVel = -speed;
                xVel = speed;
            }
        }
    }

    public void addBallListener(BallListener l)
    {
        listener[listenerCount++] = l;
    }

    public void paintSprite(Graphics g)
    {
        if(rolling){
            updatePosition(true);

            if(graphicsOn){
                g.drawImage(redBall, x-width/2, y-height/2, width, height, null);
            }else{
                g.setColor(Color.RED);
                g.fillOval(x-width/2, y-height/2, width, height);
            }
            checkForPit();
            if(rolling){
                callListeners();
            }
        }else{
            if(graphicsOn){
                g.drawImage(redBall, 400, 450, width, height, null);
            }else{
                g.setColor(Color.RED);
                g.fillOval(400, 450, width, height);
            }
        }
    }

    public void stopRolling()
    {
        rolling = false;
    }

    private void checkForPit()
    {
        if(y + 15 >= southBound){
            rolling = false;
            Breakout.lives--;
        }

    }

    private void callListeners()
    {
        for(int i = 0; i < listenerCount; ++i){
            if(listener[i].ballMoved(new BallEvent(x, y))){
                sideNum = listener[i].sideHit(new BallEvent(x, y));
                changeDirection();
                incSpeed++;
                if(incSpeed == speedCounter){
                    //increase speed
                    if(xVel < 0){
                        xVel--;
                    }else{
                        xVel++;
                    }
                    if(yVel < 0){
                        yVel--;
                    }else{
                        yVel++;
                    }
                    incSpeed = 0;
                }
            }
        }
    }

    private void changeDirection()
    {
        side = convertToSideHit(sideNum);
        switch(side)
        {
            case LEFT:
                xVel *= -1;
                break;
            case RIGHT:
                xVel *= -1;
                break;
            case TOP:
                yVel *= -1;
                break;
            case BOTTOM:
                yVel *= -1;
                break;
            default:
                break;
        }
    }




}
