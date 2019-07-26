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

        // Member functions
        bool TestConnection();
        bool SetColorTemperature(int temperature, QString effect, int duration);
        bool SetRGB(int red, int green, int blue, QString effect, int duration);
        bool SetHSV(int hue, int sat, QString effect, int duration);
        bool SetBrightness(int brightness, QString effect, int duration);
        bool SetPower(bool power, QString effect, int duration);
        bool Toggle();
        bool SetDefault();
        bool StartColorFlow(int count, int action, QString flowExpression);
        bool StopColorFlow();
        bool SetScene(QString sceneClass, int val1, int val2);
        bool SetScene(QString sceneClass, int val1, int val2, int val3);
        bool AddCron(int type, int value);
        bool GetCron(int type);
        bool DeleteCron(int type);
        bool SetAdjust(QString action, QString properties);
        bool SetMusic(int action, QString host, int port);
        // Member functions
};}
