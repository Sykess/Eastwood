
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class RoboBlock extends JPanel implements KeyListener, ActionListener, MouseListener
{
    private int x = 250, y = 250, xVel = 0, yVel = 0;
    private Color purple = new Color(128, 0, 128);
    private Color darkPurple = new Color(255, 0, 255);
    private int dim = 3;
    private Cell[] cell = new Cell[dim * dim];

    public static void main(String[] args)
    {
        JFrame f = new JFrame("RoboBlock!!!!");
        RoboBlock block = new RoboBlock();
        f.setSize(320, 350);
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        f.setVisible(true);
        f.add(block);
    }

    public RoboBlock(){
        addKeyListener(this);
        setFocusable(true);
        addMouseListener(this);

        for(int i = 0; i < cell.length; ++i){
            cell[i] = new Cell(i % dim * 100, i / dim * 100);
            addMouseListener(cell[i]);
        }


        Timer t = new Timer(50, this);
        t.start();
    }

    @Override
    public void paintComponent(Graphics g)
    {
        super.paintComponent(g);
        setBackground(Color.white);
        g.setColor(darkPurple);
        g.fillRect(x-10, y-10, 20, 20);

        // Stuff working with cells:
        //cell.paintCell(g);
        for(int i = 0; i < cell.length; ++i){
            cell[i].paintCell(g);
        }
    }

    public void actionPerformed(ActionEvent e){
        x += xVel;
        y += yVel;
        repaint();

    }

    public void keyPressed(KeyEvent e){
        if(e.getKeyCode() == KeyEvent.VK_RIGHT){
            //x += 10;
            xVel = 10;
        }
        // Instead of up, could use VK_w
        if(e.getKeyCode() == KeyEvent.VK_UP){
            yVel = -10;
            //y -= 10;
        }
        if(e.getKeyCode() == KeyEvent.VK_LEFT){
            //x -= 10;
            xVel = -10;
        }
        if(e.getKeyCode() == KeyEvent.VK_DOWN){
            yVel = 10;
            //y += 10;
        }
        //repaint();

    }

    public void keyReleased(KeyEvent e){
        xVel = 0;
        yVel = 0;
    
    }

    public void keyTyped(KeyEvent e){}


    public void mousePressed(MouseEvent e){
        System.out.println("x = " + e.getX() + ", y = " + e.getY());

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


/* Tic tac toe game.  Class Cell with x and y, width and height, and knows how to paint itself
 * Cell knows if its been clicked on, and can only be modified once.  Once is X, can't become O
 * Separate cell, make array of those, connect etc.
 */ 


