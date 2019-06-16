#include <QString>
#include <QTcpSocket>
#include <QTimer>
#include <cmath>
#include <iostream>

namespace YeelightAPI {

class Bulb
{
    private:
        // Members
        QString IpAddress;
        QString Port;
        // Members

    public:
        Bulb(QString ipAddress, QString port); // Constructor

        bool TestConnection(); //Test connection member function

        // Member functions
        bool SetColorTemperature(int temperature, QString effect, int duration);
        bool SetRGB(int red, int green, int blue, QString effect, int duration);
        bool SetHSV(int hue, int sat, QString effect, int duration);
        bool SetBrightness(int brightness, QString effect, int duration);
        bool SetPower(bool power, QString effect, int duration);
        bool Toggle();
        bool SetDefault();
        // Member functions
};}
