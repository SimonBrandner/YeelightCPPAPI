#include <QCoreApplication>
#include <iostream>
#include "bulb.h"

int main()
{
    std::cout << std::boolalpha; // Set way to print bool

    YeelightAPI::Bulb bulb("10.0.0.39", "55443"); // Define Bulb instance
    bool connectionSuccessful;

    //connectionSuccessful = bulb.TestConnection();
    //connectionSuccessful = bulb.SetColorTemperature(1700, "smooth", 500);
    //connectionSuccessful = bulb.SetRGB(255, 0, 0, "smooth", 500);
    //connectionSuccessful = bulb.SetHSV(123, 75, "smooth", 500);
    //connectionSuccessful = bulb.SetBrightness(1, "smooth", 500);
    //connectionSuccessful = bulb.SetPower(true, "smooth", 1000);
    //connectionSuccessful = bulb.Toggle();
    //connectionSuccessful = bulb.SetDefault();


    std::cout << "connectionSuccessful = " << connectionSuccessful << std::endl; // Print connectionSuccessful
    return 0;
}
