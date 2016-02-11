import java.awt.*;

import java.awt.event.ActionEvent;

import java.awt.event.ActionListener;

import java.awt.event.KeyEvent;

import java.awt.event.KeyListener;



import javax.swing.*;



public class KeyBoardTutor extends JFrame implements KeyListener {

    private String[] button={"~","1","2","3","4","5","6","7","8","9","0","-","+","BackSpace","\t","Q","W","E","R","T","Y","U","I","O","P","[","]","","Caps","A","S","D","F","G","H","J","K","L",":","\"","Enter","Shift","Z","X","C","V","B","N","M",",",".","?","\0"};

    private JButton [] buttons=new JButton[button.length];

    private JLabel line1,line2;

    private JTextArea text;

    private String Input;

    private int x;

    public KeyBoardTutor(){

        super("Virtual KeyBoard");

        setLayout(new FlowLayout());

        line1=new JLabel ("Type some text using your keyboard. The keys you press will be highlighted and the text will be displayed");

        add (line1);

        line2=new JLabel ("Note: Clicking the buttons with your mouse will not perform any action");

        add(line2);

        text=new JTextArea(10,60);

        text.setEditable(true);

        add(text);

        for(int i=0;i<button.length;i++)

        {

            buttons[i]=new JButton(button[i]);

            add(buttons[i]);

            buttons[i].addKeyListener(this);

        }

    }

    public void keyPressed(KeyEvent e) {

        Input=String.format("%s",KeyEvent.getKeyText(e.getKeyCode()));

        for(x=0;x<button.length;x++)

        {

            if(Input.equals(button[x]))

            {

                buttons[x].getBackground();

                buttons[x].setBackground(Color.RED);

            }

            if(Input.equals("\0"))

                buttons[13].setBackground(Color.red);

        }

    }

    public void keyReleased(KeyEvent e) {

        Input=String.format("%s",KeyEvent.getKeyText(e.getKeyCode()));

        buttons[x].setBackground(getBackground());

    }

    public void keyTyped(KeyEvent e) {

        Input= String.format("%s", e.getKeyChar());

        text.append(String.format("%s",Input));

    }

}








