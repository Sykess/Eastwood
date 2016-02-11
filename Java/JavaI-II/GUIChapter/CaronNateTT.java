
/*
 Program Name: CaronNateTT.java
 Author: Nathan Caron
 Assignment # 12
 Date:12/10/2014
 Purpose: Create typing tutor.
*/

import java.awt.Color;
import java.awt.event.KeyListener;
import java.awt.event.KeyEvent;
import java.awt.FlowLayout;
import javax.swing.JLabel;
import javax.swing.JFrame;
import javax.swing.JTextArea;
import javax.swing.JButton;


public class CaronNateTT extends JFrame implements KeyListener
{
	private final JTextArea textArea;
	private String input = "";
	private Color background;
	private final JLabel label1, label2;
	private String[] keys = {"~","1","2","3","4","5","6","7"
		,"8","9","0","-","+","BackSpace","Tab","Q","W","E","R"
		,"T","Y","U","I","O","P","[","]","\\","Caps","A","S","D"
		,"F","G","H","J","K","L",":","\"","Enter","Shift","Z"
		,"X","C","V","B","N","M",",",".","?","\0"};
	private JButton [] buttons = new JButton[keys.length];


	public CaronNateTT()
	{
		super("Typing Application");

		setLayout(new FlowLayout());

		label1 = new JLabel("Type some text using your keyboard.  The keys you press will be "
			+"highlighted and the text will be displayed.");
		add(label1);
		label2 = new JLabel("Note: Clicking the buttons with your "
			+"mouse will not perform any action.");
		add(label2);

		textArea = new JTextArea(10, 60);
		textArea.setLineWrap(true);
		textArea.setEnabled(false);
		textArea.setDisabledTextColor(Color.BLACK);
		add(textArea);

        for(int x = 0; x < keys.length; x++)
        {
            buttons[x]= new JButton(keys[x]);
            add(buttons[x]);

            buttons[x].addKeyListener(this);
        }
        background = buttons[0].getBackground();
	}

	@Override
	public void keyPressed(KeyEvent event)
	{
		input = (KeyEvent.getKeyText(event.getKeyCode()));

		// It types  out words instead of performing backspace, shift
		// etc, so I just eliminated them from displaying.
		if(input == "Backspace" || input == "Shift")
		{
		}
		else if(input == "Space")
		{
			textArea.append(" ");
		}
		else if(input == "Enter")
		{
			textArea.append("\n");
		}
		else
			textArea.append(input);


		for(int x = 0; x < buttons.length; x++)
		{
			//sets pressed button to green
			if(input.equals(keys[x]))
				buttons[x].setBackground(Color.GREEN);
		}

	}

	@Override
	public void keyReleased(KeyEvent event)
	{

		input = KeyEvent.getKeyText(event.getKeyCode());

		for(int x = 0; x < buttons.length; x++)
		{
			// resets button to original color
			if(input.equals(keys[x]))
				buttons[x].setBackground(background);
		}

	}

	@Override
	public void keyTyped(KeyEvent event)
	{
	}
}