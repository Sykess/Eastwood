
import javax.swing.JFrame;

public class CalcDemo extends JFrame
{
   public static void main(String[] args)
   {
      Calculator calc = new Calculator();
      calc.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
      calc.setSize(205, 200);
      calc.setVisible(true);
   }
}

