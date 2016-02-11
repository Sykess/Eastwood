
import java.awt.Graphics;
import java.awt.Color;
import java.util.Random;
import java.awt.image.*;
import java.io.*;
import javax.imageio.*;


public class Brick extends Sprite implements BallListener
{
    private boolean destroyed, graphicsOn;
    private int hits;
    public static int bricksAlive = 0;
    private BufferedImage threeHits, twoHits, oneHit;

    public Brick(int xPos, int yPos, int hits)
    {
        destroyed = false;
        graphicsOn = true;
        bricksAlive++;
        this.hits = hits;
        setSize(80, 20);
        setPosition(xPos, yPos);
        try{
            threeHits = ImageIO.read(new File("threeHits.png"));
            twoHits = ImageIO.read(new File("twoHits.png"));
            oneHit = ImageIO.read(new File("oneHit.png"));
        }catch(IOException e){
            System.out.println("Could not open images, turning images off!");
            graphicsOn = false;
        }
    }

    public Brick(int xPos, int yPos)
    {
        destroyed = false;
        bricksAlive++;
        hits = 1;
        setSize(80, 20);
        setPosition(xPos, yPos);
    }

    public void reset(int hits)
    {
        destroyed = false;
        bricksAlive++;
        this.hits = hits;
    }

    public void setGraphics(boolean choice)
    {
        graphicsOn = choice;
    }

    public void reset()
    {
        destroyed = false;
        bricksAlive++;
        hits = 1;
    }

    public void paintSprite(Graphics g)
    {
        if(!destroyed)
        {
            if(graphicsOn){
                if(hits == 3)
                    g.drawImage(threeHits, x-width/2, y-height/2, width, height, null);
                if(hits == 2)
                    g.drawImage(twoHits, x-width/2, y-height/2, width, height, null);
                if(hits == 1)
                    g.drawImage(oneHit, x-width/2, y-height/2, width, height, null);

            }else{
                g.setColor(getCurrentColor());
                g.fillRect(x-width/2, y-height/2, width, height);
            }
        }
    }

    public Color getCurrentColor()
    {
        switch(hits)
        {
            case 1:
                return Color.GREEN;
            case 2:
                return Color.BLUE;
            case 3:
                return Color.BLACK;
            default:
                return Color.GREEN;
        }
    }

    public boolean ballMoved(BallEvent e)
    {
        if(contains(e.getX(), e.getY()) && !destroyed){
            if(--hits <= 0){
                destroyed = true;
                bricksAlive--;
            }
            Breakout.score += 10;
            return true;
        }
        return false;
    }

    public int sideHit(BallEvent e)
    {
        SideHit current = whichSide(e.getX(), e.getY());
        return convertToSideNum(current);
        //return convertToSideNum(SideHit.BOTTOM);
    }



}
