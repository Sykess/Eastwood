/*
 * Author: Nathan Caron
 * Program name: SavingInfo.java
 * Last Modified: 11/14/2015
 * Purpose: To enter some user info into a GUI application
 *			and save them to an ArrayList.  The ArrayList is
 *			displayed in a table on a separate tab.  The user
 *			can manually choose if/when to save the data to
 *			a file. To clear all data, simply delete saveData.dat.
 */

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.UIManager.*;
import javax.swing.GroupLayout.*;
import java.util.*;
import java.io.*;




public class SavingInfo
{
    final static String ENTER = "Enter";
    final static String VIEW = "View";
    JTextField nameField, ageField, emailField,
    	occupationField, phoneNumberField;

    public void addComponentToPane(Container pane)
    {
        JTabbedPane tabbedPane = new JTabbedPane();


        JPanel enterPanel = new JPanel() {
            @Override
            public Dimension getPreferredSize(){
                Dimension size = super.getPreferredSize();
                size.width += 200;
                return size;
            }
        };


        JLabel nameLabel = new JLabel("Name: ");
        JLabel ageLabel = new JLabel("Age:   ");
        JLabel occupationLabel = new JLabel("Occupation: ");
        JLabel phoneNumberLabel = new JLabel("Phone Number: ");
        JLabel emailLabel = new JLabel("Email: ");

        nameField = new JTextField(20);
        ageField = new JTextField(20);
        occupationField = new JTextField(20);
        phoneNumberField = new JTextField(20);
        emailField = new JTextField(20);

        JButton enterButton, clearButton, saveButton;
        enterButton = new JButton("Enter");
        clearButton = new JButton("Clear");
        saveButton = new JButton("Save");

        clearButton.addActionListener(new ActionListener(){
			@Override
			public void actionPerformed(ActionEvent e){
				nameField.setText(null);
				ageField.setText(null);
				occupationField.setText(null);
				phoneNumberField.setText(null);
				emailField.setText(null);
			}
		});


		// Setup and use group layout to nicely align the textfields and labels
        GroupLayout layout = new GroupLayout(enterPanel);
        enterPanel.setLayout(layout);

        layout.setAutoCreateGaps(true);
        layout.setAutoCreateContainerGaps(true);

        GroupLayout.SequentialGroup hGroup = layout.createSequentialGroup();

        hGroup.addGroup(layout.createParallelGroup()
                .addComponent(nameLabel)
                .addComponent(ageLabel)
                .addComponent(occupationLabel)
                .addComponent(phoneNumberLabel)
                .addComponent(emailLabel));
        hGroup.addGroup(layout.createParallelGroup()
                .addComponent(nameField)
                .addComponent(ageField)
                .addComponent(occupationField)
                .addComponent(phoneNumberField)
                .addComponent(emailField).addGroup(layout.createSequentialGroup()
                    .addComponent(enterButton)
                    .addComponent(clearButton)
                    .addComponent(saveButton)));
        layout.setHorizontalGroup(hGroup);


        GroupLayout.SequentialGroup vGroup = layout.createSequentialGroup();

        vGroup.addGroup(layout.createParallelGroup(GroupLayout.Alignment.LEADING, false)
                .addComponent(nameLabel)
                .addComponent(nameField));
        vGroup.addGroup(layout.createParallelGroup(GroupLayout.Alignment.LEADING, false)
                .addComponent(ageLabel)
                .addComponent(ageField));
        vGroup.addGroup(layout.createParallelGroup(GroupLayout.Alignment.LEADING, false)
        		.addComponent(occupationLabel)
        		.addComponent(occupationField));
        vGroup.addGroup(layout.createParallelGroup(GroupLayout.Alignment.LEADING, false)
        		.addComponent(phoneNumberLabel)
        		.addComponent(phoneNumberField));
        vGroup.addGroup(layout.createParallelGroup(GroupLayout.Alignment.LEADING, false)
                .addComponent(emailLabel)
                .addComponent(emailField));
        vGroup.addGroup(layout.createParallelGroup()
                .addComponent(enterButton)
                .addComponent(clearButton)
                .addComponent(saveButton));
        layout.setVerticalGroup(vGroup);




        JPanel viewPanel = new JPanel(new GridLayout(1, 0));
        ArrayList<Fields> list = new ArrayList<Fields>();
        try{
        	load("saveData.dat", list);
		}catch(Exception e){
			JOptionPane.showMessageDialog(enterPanel, "Could not open saveData.dat");
		}

        JTable table = new JTable(new FieldsTableModel(list));
        table.setPreferredScrollableViewportSize(enterPanel.getPreferredSize());
        table.setFillsViewportHeight(true);

        enterButton.addActionListener(new ActionListener(){
			@Override
			public void actionPerformed(ActionEvent e)
			{
				int age;
				try{
					if(ageField.getText().length() != 0){
						age = Integer.parseInt(ageField.getText());
					}else{
						age = 0;
					}
				}catch(Exception ex){
					JOptionPane.showMessageDialog(enterPanel, "Age must be an Integer!");
					ageField.setText(null);
					return;
				}
				if(nameField.getText().length() == 0)
				{
					JOptionPane.showMessageDialog(enterPanel, "Must enter a name!");
					return;
				}
				Fields fields = new Fields();
				fields.setName(nameField.getText());
				fields.setAge(age);
				fields.setOccupation(occupationField.getText());
				String phone = phoneNumberField.getText();
				// will convert 10 digit number to (xxx)-xxx-xxxx
				if(phone.length() == 10){
					phone = String.valueOf(phone)
						.replaceFirst("(\\d{3})(\\d{3})(\\d+)", "($1)-$2-$3");
				}
				fields.setPhoneNumber(phone);
				fields.setEmail(emailField.getText());
				list.add(fields);
				nameField.setText(null);
				ageField.setText(null);
				occupationField.setText(null);
				phoneNumberField.setText(null);
				emailField.setText(null);
			}
		});

		saveButton.addActionListener(new ActionListener(){
			@Override
			public void actionPerformed(ActionEvent e)
			{
				try{
					save("saveData.dat", list);
					JOptionPane.showMessageDialog(enterPanel, "Saved successfully to saveData.dat");
				}catch(Exception ex){
					ex.printStackTrace();
				}
			}
		});

        table.setAutoResizeMode(JTable.AUTO_RESIZE_OFF);
        table.getColumnModel().getColumn(0).setPreferredWidth(75);
        table.getColumnModel().getColumn(1).setPreferredWidth(35);
        table.getColumnModel().getColumn(2).setPreferredWidth(99);
        table.getColumnModel().getColumn(3).setPreferredWidth(100);
        table.getColumnModel().getColumn(4).setPreferredWidth(230);

        JScrollPane scrollPane = new JScrollPane(table);
        viewPanel.add(scrollPane);

        tabbedPane.addTab(ENTER, enterPanel);
        tabbedPane.addTab(VIEW, viewPanel);
        pane.add(tabbedPane, BorderLayout.CENTER);

    }

    private static void createAndShowGUI()
    {
        JFrame frame = new JFrame("Info Saver");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        SavingInfo demo = new SavingInfo();
        demo.addComponentToPane(frame.getContentPane());

        frame.pack();
        frame.setVisible(true);
    }

    public static void save(String fileName, ArrayList al) throws FileNotFoundException
    {
        try
        {
            FileOutputStream fout = new FileOutputStream(fileName);
            ObjectOutputStream oos = new ObjectOutputStream(fout);
            oos.writeObject(al);
            fout.close();
        }catch(Exception e){
            e.printStackTrace();
        }
    }

    @SuppressWarnings("unchecked")
    public static void load(String fileName, ArrayList<Fields> fl) throws Exception
    {
        try
        {
            FileInputStream fin = new FileInputStream(fileName);
            ObjectInputStream ois = new ObjectInputStream(fin);
            ArrayList<Fields> al = (ArrayList<Fields>)ois.readObject();
            for(Fields obj : al)
            {
				fl.add(obj);
			}
            ois.close();
        }catch(Exception e){
            //e.printStackTrace();
            throw e;
            //JOptionPane.showMessageDialog(
        }

    }

    public static void main(String[] args)
    {
        try{
            for(LookAndFeelInfo info : UIManager.getInstalledLookAndFeels()){
                if("Nimbus".equals(info.getName())){
                    UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        }catch(Exception e){
            e.printStackTrace();
        }
        javax.swing.SwingUtilities.invokeLater(new Runnable() {
            public void run() {
                createAndShowGUI();
            }
        });
    }
}
