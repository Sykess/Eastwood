
import java.awt.*;
import java.util.*;
import javax.swing.table.*;


public class FieldsTableModel extends AbstractTableModel
{
    private String[] columnNames = { "Name", "Age", "Occupation", "Phone number", "Email"};
    ArrayList<Fields> list = null;

    FieldsTableModel(ArrayList<Fields> list)
    {
        this.list = list;
    }

    public int getColumnCount()
    {
        return columnNames.length;
    }

    public int getRowCount()
    {
        return list.size();
    }

    public String getColumnName(int col)
    {
        return columnNames[col];
    }

    public Object getValueAt(int row, int col)
    {
        Fields object = list.get(row);

        switch(col)
        {
            case 0:
                return object.getName();
            case 1:
                return object.getAge();
            case 2:
                return object.getOccupation();
            case 3:
                return object.getPhoneNumber();
            case 4:
                return object.getEmail();
            default:
                return "unkown";
        }
    }

    public Class getColumnClass(int c)
    {
        return getValueAt(0, c).getClass();
    }





}
