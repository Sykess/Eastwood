

import java.awt.Graphics;
import java.awt.Dimension;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.Color;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.JPanel;
import java.awt.BorderLayout;
import javax.swing.JSlider;
import javax.swing.JFrame;
import javax.swing.JTextField;
import javax.swing.SwingConstants;
import javax.swing.event.ChangeListener;
import javax.swing.event.ChangeEvent;


public class ColorChoose
{
	public static void main(String[] args)
	{
		SliderFrame slider = new SliderFrame();
		slider.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		slider.setSize(400, 600);
		slider.setVisible(true);
	}
}


class RectPanel extends JPanel
{
	public int x1,x2,y1,y2;
	private Color color = Color.BLACK;
	private int shape = 1;
	private int red = 0, green = 0, blue = 0;
	@Override
	public void paintComponent(Graphics g)
	{
		super.paintComponent(g);
		g.setColor(color);
		//g.fillRect(65, 150, 150, 150);
        if(shape == 1)
        {
            g.fillRect(x1, y1, x2, y2);
        }
        else if (shape == 2)
        {
            g.fillOval(x1,y1,x2,y2);
        }
        else
        {
            g.drawLine(x1,y1,x2,y2);
        }
	}

	public void setShape(int s)
	{
		shape = s;
	}

	public void setFillColor(Color c)
	{
		color = c;
		repaint();
	}

	public void setRed(int r)
	{
		red = r;
		color = new Color(red, green, blue);
		repaint();
	}

	public void setGreen(int g)
	{
		green = g;
		color = new Color(red, green, blue);
		repaint();
	}

	public void setBlue(int b)
	{
		blue = b;
		color = new Color(red, green, blue);
		repaint();
	}

    public RectPanel()
    {
        //setBackground(Color.WHITE);
        addMouseListener(new MouseAdapter()
        {
           public void mousePressed(MouseEvent m)
           {
               x1=m.getX();
               y1=m.getY();
               repaint();
           }
           public void mouseReleased(MouseEvent m)
           {
               x2=m.getX();
               y2=m.getY();
               repaint();
           }
         });
         addMouseMotionListener(new MouseMotionAdapter()
         {
           public void mouseDragged(MouseEvent m)
           {
              x2=m.getX();
              y2=m.getY();
              repaint();
           }
         });
      }

}

class SliderFrame extends JFrame
{
	private final JTextField txt1;
	private final JTextField txt2;
	private final JTextField txt3;
	private final JTextField txt4;
	private final JSlider slide1;
	private final JSlider slide2;
	private final JSlider slide3;
	private final JSlider shapeSelect;
	private final RectPanel myPanel;
	private int red = 0, blue = 0, green = 0, shape = 1;

	public SliderFrame()
	{
		super("Slider color chooser");

		txt1 = new JTextField("Red");
		txt2 = new JTextField("Grn");
		txt3 = new JTextField("Blu");
		txt4 = new JTextField("Shape");

		myPanel = new RectPanel();

		shapeSelect = new JSlider(SwingConstants.HORIZONTAL, 1, 3, 1);
		shapeSelect.setMajorTickSpacing(1);
		shapeSelect.setPaintTicks(true);
		shapeSelect.addChangeListener(
			new ChangeListener()
			{
				@Override
				public void stateChanged(ChangeEvent e)
				{
					shape = shapeSelect.getValue();
					myPanel.setShape(shape);
					if(shape == 1)
						txt4.setText("Rect");
					else if(shape == 2)
						txt4.setText("Oval");
					else if(shape == 3)
						txt4.setText("Line");

				}
			}
		);

		slide1 = new JSlider(SwingConstants.HORIZONTAL, 0, 255, 10);
		slide1.setMajorTickSpacing(10);
		slide1.setPaintTicks(true);
		slide1.addChangeListener(
			new ChangeListener()
			{
				@Override
				public void stateChanged(ChangeEvent e)
				{
					red = slide1.getValue();
					myPanel.setRed(red);
					//22.13 wanted to change from commented method
					//to above method
					//Color randomColor = new Color(red, green, blue);
					//myPanel.setFillColor(randomColor);
					txt1.setText("" + red);
				}
			}
		);

		txt1.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent e){
				int num;
				try
				{
					num = Integer.parseInt(txt1.getText());
				}
				catch(NumberFormatException ex)
				{
					System.out.print("Bad input");
					return;
				}
				red = num;
				slide1.setValue(num);
			}
		});

		slide2 = new JSlider(SwingConstants.HORIZONTAL, 0, 255, 10);
		slide2.setMajorTickSpacing(10);
		slide2.setPaintTicks(true);
		slide2.addChangeListener(
			new ChangeListener()
			{
				@Override
				public void stateChanged(ChangeEvent e)
				{
					green = slide2.getValue();
					myPanel.setGreen(green);
					//Color randomColor = new Color(red, green, blue);
					//myPanel.setFillColor(randomColor);
					txt2.setText("" + green);
				}
			}
		);

		txt2.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent e){
				int num;
				try
				{
					num = Integer.parseInt(txt2.getText());
				}
				catch(NumberFormatException ex)
				{
					System.out.print("Bad input");
					return;
				}
				green = num;
				slide2.setValue(num);
			}
		});

		slide3 = new JSlider(SwingConstants.HORIZONTAL, 0, 255, 10);
		slide3.setMajorTickSpacing(10);
		slide3.setPaintTicks(true);
		slide3.addChangeListener(
			new ChangeListener()
			{
				@Override
				public void stateChanged(ChangeEvent e)
				{
					blue = slide3.getValue();
					myPanel.setBlue(blue);
					//Color randomColor = new Color(red, green, blue);
					//myPanel.setFillColor(randomColor);
					txt3.setText("" + blue);
				}
			}
		);

		txt3.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent e){
				int num;
				try
				{
					num = Integer.parseInt(txt3.getText());
				}
				catch(NumberFormatException ex)
				{
					System.out.print("Bad input");
					return;
				}
				blue = num;
				slide3.setValue(num);
			}
		});


		add(myPanel);
		myPanel.add(slide1);
		myPanel.add(txt1);
		myPanel.add(slide2);
		myPanel.add(txt2);
		myPanel.add(slide3);
		myPanel.add(txt3);
		myPanel.add(shapeSelect);
		myPanel.add(txt4);
		//add(myPanel, BorderLayout.SOUTH);
	}//end constructor

}



