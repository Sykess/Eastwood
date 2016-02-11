
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class Quizz extends JPanel implements KeyListener
{
    private int x = 250, y = 250, xVel = 0, yVel = 0;
    private Color purple = new Color(128, 0, 128);
    private Color darkPurple = new Color(255, 0, 255);

    public static void main(String[] args)
    {
        JFrame f = new JFrame("Quiz 2");
        Quizz block = new Quizz();
        f.setSize(300, 300);
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        f.setVisible(true);
        f.add(block);
    }

    public Quizz(){
        addKeyListener(this);
        setFocusable(true);

    }

    @Override
    public void paintComponent(Graphics g)
    {
        super.paintComponent(g);
        setBackground(Color.white);
        g.setColor(darkPurple);
        g.fillRect(x-10, y-10, 20, 20);

    }


    public void keyPressed(KeyEvent e){
        if(e.getKeyCode() == KeyEvent.VK_RIGHT){
            x += 10;
        }
        // Instead of up, could use VK_w
        if(e.getKeyCode() == KeyEvent.VK_UP){
            y -= 10;
        }
        if(e.getKeyCode() == KeyEvent.VK_LEFT){
            x -= 10;
        }
        if(e.getKeyCode() == KeyEvent.VK_DOWN){
            y += 10;
        }
        repaint();

    }

    public void keyReleased(KeyEvent e){
    
    }

    public void keyTyped(KeyEvent e){}





 
}


/* Tic tac toe game.  Class Cell with x and y, width and height, and knows how to paint itself
 * Cell knows if its been clicked on, and can only be modified once.  Once is X, can't become O
 * Separate cell, make array of those, connect etc.
 */ 


