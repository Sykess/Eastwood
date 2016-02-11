

import java.awt.Graphics;
import java.awt.Dimension;
import java.awt.Color;
import javax.swing.JPanel;
import java.awt.BorderLayout;
import javax.swing.JSlider;
import javax.swing.JFrame;
import javax.swing.SwingConstants;
import javax.swing.event.ChangeListener;
import javax.swing.event.ChangeEvent;


public class RectPanel extends JPanel
{
	private Color color = Color.BLACK;
	@Override
	public void paintComponent(Graphics g)
	{
		super.paintComponent(g);
		g.setColor(color);
		g.fillRect(10, 10, 10, 10);
	}

	public void setFillColor(Color c)
	{
		color = c;
	}

}

class SliderFrame extends JFrame
{
	private final JSlider slide1;
	//private final JSlider slide2;
	//private final JSlider slide3;
	private final RectPanel myPanel;
	private int red = 0, blue = 0, green = 0;

	public SliderFrame()
	{
		super("Slider color choose");



		myPanel = new RectPanel();

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
					Color randomColor = new Color(red, green, blue);
					myPanel.setFillColor(randomColor);
				}
			}
		);
	}

}

