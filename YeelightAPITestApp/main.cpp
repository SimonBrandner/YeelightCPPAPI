#include <QCoreApplication>
#include <iostream>
#include "bulb.h"

int main()
{
    std::cout << std::boolalpha; // Set way to print bool

    YeelightAPI::Bulb bulb("10.0.0.39", "55443"); // Define Bulb instance
    bool connectionSuccessful;

    //connectionSuccessful = bulb.TestConnection();
    connectionSuccessful = bulb.Toggle(); // Toggle bulb and save bool to connectionSuccessful


    std::cout << "connectionSuccessful = " << connectionSuccessful << std::endl; // Print connectionSuccessful
    return 0;
}
