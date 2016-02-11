

import java.awt.Graphics;
import java.awt.Dimension;
import java.awt.Color;
import javax.swing.JPanel;


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




}