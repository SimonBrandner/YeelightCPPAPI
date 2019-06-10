#include <QString>
#include <QTcpSocket>
#include <QTimer>

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
        bool PowerOn();
        bool PowerOff();
        bool Toggle();
        // Member functions
};}
