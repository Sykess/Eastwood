
import java.awt.*;
import java.awt.event.*;


/* Could want mouselistener, setters, getters.
 *
 * static method in roboblock to be 0 or 1 for x or o.
 * check cell see if its set, see whose turn, set it properly, turn static var.
 */

public class Cell implements MouseListener
{
    private int x = 0;
    private int y = 0;
    private int size = 100;
    private Color cellColor = Color.blue;
     
    public Cell(int xStart, int yStart)
    {
        x = xStart;
        y = yStart;

    }

    public void paintCell(Graphics g){
        g.setColor(cellColor);
        g.fillRect(x, y, size, size);
        g.setColor(Color.black);
        g.drawRect(x, y, size, size);
    }


    public void mousePressed(MouseEvent e){
        if(e.getX() > x && e.getX() < x + size && e.getY() > y && e.getY() < y + size)
        {
            cellColor = Color.green;
        }
    }
    public void mouseReleased(MouseEvent e){

    }
    public void mouseClicked(MouseEvent e){

    }   

    public void mouseEntered(MouseEvent e){

    }

    public void mouseExited(MouseEvent e){

    }




}







