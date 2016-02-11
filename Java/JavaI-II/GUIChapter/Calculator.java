
import java.awt.GridLayout;
import java.awt.FlowLayout;
import java.awt.BorderLayout;
import javax.swing.JFrame;
import javax.swing.JTextField;
import javax.swing.JPanel;
import javax.swing.JButton;

public class Calculator extends JFrame
{
   private final JTextField textField;
   private final JPanel buttonJPanel; // panel to hold buttons
   private final JButton[] buttons;
   private static final String[] names = { "7", "8", "9", "/", "4", "5", "6",
   				"*", "1", "2", "3", "-", "0", ".", "=", "+" };

   // no-argument constructor
   public Calculator()
   {
      super("Calculator");
      setLayout(new FlowLayout());

      textField = new JTextField("", 16);
      add(textField);
      buttons = new JButton[16];
      buttonJPanel = new JPanel();
      buttonJPanel.setLayout(new GridLayout(4, 4, 5, 5)); // 4x4 grid with 5 spacing

      // create and add buttons
      for (int count = 0; count < buttons.length; count++)
      {
         buttons[count] = new JButton(names[count]);
         buttonJPanel.add(buttons[count]); // add button to panel
      }

      add(buttonJPanel, BorderLayout.SOUTH); // add panel to JFrame
   }
}
