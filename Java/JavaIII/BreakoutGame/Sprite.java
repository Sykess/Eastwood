/** Class to be extended by all objects to be drawn */


import java.awt.Graphics;

public abstract class Sprite
{
    protected int x = 0, y = 0, xVel = 0, yVel = 0, speed = 0, width = 10,
                  height = 10, eastBound = 0, westBound = 0, northBound = 0,
                  southBound = 0;
    protected enum SideHit { TOP, BOTTOM, LEFT, RIGHT, NONE };

    public void paintSprite(Graphics g) {}

    public void setBounds(int l, int r, int t, int b)
    {
        westBound = l;
        eastBound = r;
        northBound = t;
        southBound = b;
    }

    public void setBounds(int r, int b)
    {
        eastBound = r;
        southBound = b;
    }

    public void setPosition(int x, int y)
    {
        this.x = x;
        this.y = y;
    }

    public void setVelocity(int xVel, int yVel)
    {
        this.xVel = xVel;
        this.yVel = yVel;
    }

    public void setSize(int width, int height)
    {
        this.width = width;
        this.height = height;
    }

    public boolean contains(int testX, int testY)
    {
        // hit left
        if(testX+8 >= x - width/2 && testY >= y - height/2 &&
           testX+8 <= x + width/2 && testY <= y + height/2){
            return true;
        }
        //hit right
        if(testX-8 >= x - width/2 && testY >= y - height/2 && 
           testX-8 <= x + width/2 && testY <= y + height/2){
            return true;
        }
        //hit top
        if(testX >= x - width/2 && testY+8 >= y - height/2 &&
           testX <= x + width/2 && testY+8 <= y + height/2){
            return true;
        }
        //hit bottom
        if(testX >= x - width/2 && testY-8 >= y - height/2 &&
           testX <= x + width/2 && testY-8 <= y + height/2){
            return true;
        }
        
        //ball's diags
        //hit bottom diagonally from left
        if(testX+4 >= x - width/2 && testY-4 >= y - height/2 &&
           testX+4 <= x + width/2 && testY-4 <= y + height/2){
            return true;
        }
        //hit bottom diag from right
        if(testX-4 >= x - width/2 && testY-4 >= y - height/2 &&
           testX-4 <= x + width/2 && testY-4 <= y + height/2){
            return true;
        }
        //hit top diag from left
        if(testX+4 >= x - width/2 && testY+4 >= y - height/2 &&
           testX+4 <= x + width/2 && testY+4 <= y + height/2){
            return true;
        }
        //hit top diag from right
        if(testX-4 >= x - width/2 && testY+4 >= y - height/2 &&
           testX-4 <= x + width/2 && testY+4 <= y + height/2){
            return true;
        }

        return false;
    }

    public SideHit whichSide(int testX, int testY)
    {
        if(testX >= x - width/2 && testY-8 >= y - height/2 &&
           testX <= x + width/2 && testY-8 <= y + height/2){
            return SideHit.BOTTOM;
        }
        //hit bottom diagonally from left
        if(testX+4 >= x - width/2 && testY-4 >= y - height/2 &&
           testX+4 <= x + width/2 && testY-4 <= y + height/2){
            return SideHit.BOTTOM;
        }
        //hit bottom diag from right
        if(testX-4 >= x - width/2 && testY-4 >= y - height/2 &&
           testX-4 <= x + width/2 && testY-4 <= y + height/2){
            return SideHit.BOTTOM;
        }


        //if(testX < x + width/2 && testY < y && testX > x - width/2)
        if(testX >= x - width/2 && testY+8 >= y - height/2 &&
           testX <= x + width/2 && testY+8 <= y + height/2){
            return SideHit.TOP;
        }
        //hit top diag from left
        if(testX+4 >= x - width/2 && testY+4 >= y - height/2 &&
           testX+4 <= x + width/2 && testY+4 <= y + height/2){
            return SideHit.TOP;
        }
        //hit top diag from right
        if(testX-4 >= x - width/2 && testY+4 >= y - height/2 &&
           testX-4 <= x + width/2 && testY+4 <= y + height/2){
            return SideHit.TOP;
        }


        //if(testX > x)
        if(testX-8 >= x - width/2 && testY >= y - height/2 && 
           testX-8 <= x + width/2 && testY <= y + height/2){
            return SideHit.RIGHT;
        }
        //if(testX < x)
        if(testX+8 >= x - width/2 && testY >= y - height/2 &&
           testX+8 <= x + width/2 && testY <= y + height/2){
            return SideHit.LEFT;
        }
        return SideHit.NONE;

    }

    protected void updatePosition(boolean bounce)
    {
        x = x + xVel;
        y = y + yVel;

        if(x - width/2 < westBound){
            x = width/2 + westBound;
            if(bounce){
                xVel = Math.abs(xVel);
            }
        }

        if(y - height/2 < northBound){
            y = height/2 + northBound;
            if(bounce){
                yVel = Math.abs(yVel);
            }
        }

        if(x + width/2 > eastBound){
            x = eastBound - width/2;
            if(bounce){
                xVel = -Math.abs(xVel);
            }
        }

        if(y + height/2 > southBound){
            y = southBound - height/2;
            if(bounce){
                yVel = -Math.abs(yVel);
            }
        }
    }


    public SideHit convertToSideHit(int sideNum)
    {
        if(sideNum == 1){
            return SideHit.LEFT;
        }else if(sideNum == 2){
            return SideHit.TOP;
        }else if(sideNum == 3){
            return SideHit.RIGHT;
        }else if(sideNum == 4){
            return SideHit.BOTTOM;
        }else{
            return SideHit.NONE;
        }
    }

    public int convertToSideNum(SideHit side)
    {
        if(side == SideHit.LEFT)
            return 1;
        if(side == SideHit.TOP)
            return 2;
        if(side == SideHit.RIGHT)
            return 3;
        if(side == SideHit.BOTTOM)
            return 4;
        return 0;
    }

}
