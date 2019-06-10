#include "bulb.h"

namespace YeelightAPI {

Bulb::Bulb(QString ipAddress, QString port) // Constructor
{
    IpAddress = ipAddress;
    Port = port;
}

bool Bulb::TestConnection() //Test connection member function
{
    // Variable init
    QString command1 = "{ \"id\": 1, \"method\": \"set_power\", \"params\":[\"off\", \"smooth\", 500]}\r\n\r\n\r\n";
    QString command2 = "{ \"id\": 1, \"method\": \"set_power\", \"params\":[\"on\", \"smooth\", 500]}\r\n\r\n\r\n";
    QByteArray bacommand1;
    QByteArray bacommand2;
    bacommand1.append(command1);
    bacommand2.append(command2);

    QTcpSocket *socketVar = new QTcpSocket();
    socketVar->connectToHost(IpAddress, Port.toUShort());
    // Variable init



    if(socketVar->waitForConnected(3000)) // Connected
    {
        qDebug() << "Test connection successful"; // Print "Test connection successful" to qDebug()

        socketVar->write(bacommand1); // Write first command

        if(socketVar->waitForBytesWritten(3000)) // First command written
        {
            qDebug() << "First command written"; // Print "First command written" to qDebug()

        }
        else // First command not written
        {
            qDebug() << "First command not written"; // Print "First command not written" to qDebug()
            return false;
        }

        socketVar->write(bacommand2);

        if(socketVar->waitForBytesWritten(3000)) // Second command written
        {
            qDebug() << "Second command written"; // Print "Second command written" to qDebug()

        }
        else // Second command not written
        {
            qDebug() << "Second command not written"; // Print "Second command not written" to qDebug()
            return false;
        }

        socketVar->close(); // Close connection

        return true;
    }

    else
    {
        qDebug() << "Test connection not successful"; // Print "Test connection not successful" to qDebug()
        return false;
    }
}


bool Bulb::PowerOn() // PowerOn member function
{
    // Variable init
    QString command = "{ \"id\": 1, \"method\": \"set_power\", \"params\":[\"on\", \"smooth\", 500]}\r\n\r\n\r\n";
    QByteArray bacommand;
    bacommand.append(command);

    QTcpSocket *socketVar = new QTcpSocket();
    socketVar->connectToHost(IpAddress, Port.toUShort());
    // Variable init



    if(socketVar->waitForConnected(3000)) // Connected
    {
        qDebug() << "Connected in PowerOn"; // Print "Connected in PowerOn" to qDebug()

        socketVar->write(bacommand); // Write first command

        if(socketVar->waitForBytesWritten(3000)) // PowerOn command written
        {
            qDebug() << "PowerOn command written"; // Print "PowerOn command written" to qDebug()

        }
        else // PowerOn command not written
        {
            qDebug() << "PowerOn command not written"; // Print "PowerOn command not written" to qDebug()
            return false;
        }

        socketVar->close(); // Close connection

        return true;
    }

    else
    {
        qDebug() << "Not connected in PowerOn"; // Print "Not connected in PowerOn" to qDebug()
        return false;
    }
}

bool Bulb::PowerOff() // PowerOff member function
{
    // Variable init
    QString command = "{ \"id\": 1, \"method\": \"set_power\", \"params\":[\"off\", \"smooth\", 500]}\r\n\r\n\r\n";
    QByteArray bacommand;
    bacommand.append(command);

    QTcpSocket *socketVar = new QTcpSocket();
    socketVar->connectToHost(IpAddress, Port.toUShort());
    // Variable init



    if(socketVar->waitForConnected(3000)) // Connected
    {
        qDebug() << "Connected in PowerOff"; // Print "Connected in PowerOff" to qDebug()

        socketVar->write(bacommand); // Write first command

        if(socketVar->waitForBytesWritten(3000)) // PowerOff command written
        {
            qDebug() << "PowerOff command written"; // Print "PowerOff command written" to qDebug()

        }
        else // PowerOn command not written
        {
            qDebug() << "PowerOff command not written"; // Print "PowerOff command not written" to qDebug()
            return false;
        }

        socketVar->close(); // Close connection

        return true;
    }

    else
    {
        qDebug() << "Not connected in PowerOff"; // Print "Not connected in PowerOff" to qDebug()
        return false;
    }
}

bool Bulb::Toggle() // Toggle member function
{
    // Variable init
    QString command = "{ \"id\": 1, \"method\": \"toggle\", \"params\":[]}\r\n\r\n\r\n";
    QByteArray bacommand;
    bacommand.append(command);

    QTcpSocket *socketVar = new QTcpSocket();
    socketVar->connectToHost(IpAddress, Port.toUShort());
    // Variable init



    if(socketVar->waitForConnected(3000)) // Connected
    {
        qDebug() << "Connected in Toggle"; // Print "Connected in Toggle" to qDebug()

        socketVar->write(bacommand); // Write first command

        if(socketVar->waitForBytesWritten(3000)) // Toggle command written
        {
            qDebug() << "Toggle command written"; // Print "Toggle command written" to qDebug()

        }
        else // PowerOn command not written
        {
            qDebug() << "Toggle command not written"; // Print "Toggle command not written" to qDebug()
            return false;
        }

        socketVar->close(); // Close connection

        return true;
    }

    else
    {
        qDebug() << "Not connected in Toggle"; // Print "Not connected in Toggle" to qDebug()
        return false;
    }
}

}
