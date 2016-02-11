import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import java.text.NumberFormat;
import javax.swing.*;
import javax.swing.event.*;
//import net.miginfocom.swing.MigLayout;

public class SSCCE {
    public static void main(String[] args) {
        JFrame frame = new JFrame("SSCCE JSlider + JTextField");
        JPanel panel = new JPanel();

        final JSlider js = new JSlider();
        final JFormattedTextField tf = new JFormattedTextField(NumberFormat.getNumberInstance());

        js.addChangeListener(new ChangeListener() {
            @Override
            public void stateChanged(ChangeEvent e) {
                tf.setText(String.valueOf(js.getValue()));
            }
        });
        tf.addKeyListener(new KeyAdapter() {
            @Override
            public void keyReleased(KeyEvent ke) {
                String typed = tf.getText();
                js.setValue(0);
                if (!typed.matches("\\d+")) {
                    return;
                }
                int value = Integer.parseInt(typed);
                js.setValue(value);
            }
        });
        js.setMinorTickSpacing(10);
        js.setSnapToTicks(true);

        panel.add(js);
        panel.add(tf, "grow");
        frame.add(panel);
        frame.pack();
        frame.setVisible(true);
    }
}