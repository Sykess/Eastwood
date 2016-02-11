#include <iostream>
#include "VehicleInheritance.h"


int main()
{
    Vehicle veh;
    Car car;
    Motorcycle mot;
    std::cout << veh.GetNumOfWheels() << std::endl;
    std::cout << car.GetNumOfWheels() << std::endl;
    std::cout << mot.GetNumOfWheels() << std::endl;



    return 0;
}




