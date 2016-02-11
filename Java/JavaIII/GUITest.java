
// ASSIGNMENT DUE NEXT MONDAY:
//
// Assignment that stores some stuff, can add new stuff, can see stuff in there. Does not need to remove stuff
// Do not need to be able to search.  Similar to his contacts program but similar.  Store things in text file.
// Need delimiters to be  able to tell which thing ends and next begins. EX semicolon between things.
// Needs to be GUI.  Doesn't matter what you store, but should have several fields, around 4+.
//
// JSpinner, JComboBox, jlist, possible useful things

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.io.*;


public class GUITest implements ActionListener
{
    private JButton button, button2;
    private JCheckBox check1, check2;
    private JRadioButton radio1, radio2;
    private JTextField field;
    private JTextArea area;

    public static void main(String[] args)
    {
        new GUITest();
    }

    public GUITest()
    {
        try{
            UIManager.setLookAndFeel(UIManager.getSystemLookAndFeelClassName());
            //UIManager.setLookAndFeel(Nimbus.getClassName());
        }catch(Exception e){ 
            e.printStackTrace();
        }

        FlowLayout layout = new FlowLayout();


        JPanel panel = new JPanel();
        JFrame frame = new JFrame();

        frame.add(panel);
        frame.setSize(400, 400);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        //panel.setLayout(null);
        panel.setLayout(layout);

        button = new JButton("Howdy");
        button.setSize(140, 20);
        button.setLocation(50, 50);
        button.addActionListener(this);
        panel.add(button);

        button2 = new JButton("Pardner");
        button2.setSize(140, 20);
        button2.setLocation(50, 80);
        button2.addActionListener(this);
        panel.add(button2);

        check1 = new JCheckBox("Hey");
        check1.setSize(50, 20);
        check1.setLocation(200, 50);
        panel.add(check1);

        check2 = new JCheckBox("Greetings");
        check2.setSize(80, 20);
        check2.setLocation(200, 80);
        panel.add(check2);

        radio1 = new JRadioButton("Colleague");
        radio1.setSize(150, 20);
        radio1.setLocation(200, 110);
        radio1.setSelected(true);
        panel.add(radio1);

        radio2 = new JRadioButton("Amigo");
        radio2.setSize(150, 20);
        radio2.setLocation(200, 140);
        panel.add(radio2);

        ButtonGroup group = new ButtonGroup();
        group.add(radio1);
        group.add(radio2);

        Color background = new Color(150, 180, 250);
        panel.setBackground(background);
        radio2.setBackground(background);

        field = new JTextField();
        field.setPreferredSize(20);
        field.setSize(200, 20);
        field.setLocation(50, 200);
        panel.add(field);

        area = new JTextArea();
        JScrollPane pane = new JScrollPane(area,ScrollPaneConstants.VERTICAL_SCROLLBAR_ALWAYS ,ScrollPaneConstants.HORIZONTAL_SCROLLBAR_ALWAYS );
        // Also has SCROLLBAR_AS_NEED, and SCROLLBAR_NEVER
        //System.out.println(ScrollPaneConstants.VERTICAL_SCROLLBAR_ALWAYS); // 22
        //System.out.println(ScrollPaneConstants.HORIZONTAL_SCROLLBAR_ALWAYS); // 32
        //pane.setHorizontalScrollBarPolicy()
        //area.setSize(200, 60);
        //area.setLocation(50, 240);
        pane.setSize(200, 60);
        pane.setLocation(50, 240);
        area.setLineWrap(true);
        area.setWrapStyleWord(true);
        //panel.add(area);
        panel.add(pane);




        frame.setVisible(true);

        }

        public void actionPerformed(ActionEvent e)
        {
            if(e.getSource() == button){
                JFileChooser fc = new JFileChooser();
                int response = fc.showOpenDialog(null);
                // Also fc.showSaveDialog(null);
                if(response == JFileChooser.APPROVE_OPTION) // There's also CANCEL_OPTION
                {
                    File f = fc.getSelectedFile();
                    System.out.println("Open File: " + f.getName());
                }



                System.out.println(field.getText());
                if(check1.isSelected())
                    System.out.println("Hey");
                if(check2.isSelected())
                    System.out.println("Greetings");
                //System.out.println("Howdy");
            }
            if(e.getSource() == button2){
                if(radio1.isSelected())
                    System.out.println("Colleague");
                if(radio2.isSelected())
                    System.out.println("Amigo");
                //System.out.println("Pardner");
            }

        }


}
