
import java.io.*;


public class Fields implements Serializable
{
    private String name, occupation, email, phoneNumber;
    private int age;

    Fields() {}
    Fields(String name, int age, String occupation, String phoneNumber, String email)
    {
        this.name = name;
        this.age = age;
        this.occupation = occupation;
        this.phoneNumber = phoneNumber;
        this.email = email;
    }

    public String getName() { return name; }
    public String getOccupation() { return occupation; }
    public String getEmail() { return email; }
    public String getPhoneNumber() { return phoneNumber; }
    public int getAge() { return age; }
    public void setName(String name) { this.name = name; }
    public void setOccupation(String occupation) { this.occupation = occupation; }
    public void setEmail(String email) { this.email = email; }
    public void setAge(int age) { this.age = age; }
    public void setPhoneNumber(String phoneNumber) { this.phoneNumber = phoneNumber; }

    @Override
    public String toString()
    {
        return "Name: " + getName() + "\nOccupation: " + getOccupation()
            + "\nEmail: " + getEmail() + "\nAge: " + getAge();

    }






}
