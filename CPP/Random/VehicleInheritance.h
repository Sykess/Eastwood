
class Vehicle
{
    protected:
        unsigned int m_numOfWheels;
    public:
        Vehicle();
        unsigned int GetNumOfWheels() const;
};

class Car : public Vehicle
{
    public:
        Car();
};

class Motorcycle : public Vehicle
{
    public:
        Motorcycle();
};

////////////////////////////////////////////////////////

Vehicle::Vehicle() : m_numOfWheels(0)
{
}

unsigned int Vehicle::GetNumOfWheels() const
{
    return m_numOfWheels;
}

Car::Car() 
{
    m_numOfWheels = 4;
}

Motorcycle::Motorcycle()
{
    m_numOfWheels = 2;
}
