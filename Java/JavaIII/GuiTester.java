import javax.swing.*;
import java.awt.*;
import java.awt.event.*;




public class GuiTester implements ActionListener
{
    private JButton button;
    private JButton button2;

    public static void main(String[] args)
    {
        new GuiTester();
    }

    public GuiTester()
    {
        JPanel panel = new JPanel();
        JFrame frame = new JFrame();
        frame.setVisible(true);
        frame.add(panel);
        frame.setSize(400, 400);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        panel.setLayout(null); // Don't use layout mngr (flow by default)

        button = new JButton("Howdy");
        button.setSize(140, 20);
        button.setLocation(50, 50);
        button.addActionListener(this);
        panel.add(button);
        
        button2 = new JButton("Partner");
        button2.setSize(140, 20);
        button2.setLocation(50, 80);
        button2.addActionListener(this);
        panel.add(button2);


    }

    public void actionPerformed(ActionEvent e)
    {
        if(e.getSource() == button)
            System.out.println("Howdy");
        else
            System.out.println("Partner");
        //System.out.println("Button Clicked");
    }


}
