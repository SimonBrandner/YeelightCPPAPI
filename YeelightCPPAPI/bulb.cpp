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


bool Bulb::SetPower(bool power, QString effect, int duration) // SetPower member function
{
    // Variable init
    QString command;
    if (power)
    {
        command = "{ \"id\": 1, \"method\": \"set_power\", \"params\":[\"on\", \"" + effect + "\"," + QString::number(duration) + "]}\r\n\r\n\r\n";
    }
    else
    {
        command = "{ \"id\": 1, \"method\": \"set_power\", \"params\":[\"off\", \"" + effect + "\"," + QString::number(duration) + "]}\r\n\r\n\r\n";
    }

    QByteArray bacommand;
    bacommand.append(command);

    QTcpSocket *socketVar = new QTcpSocket();
    socketVar->connectToHost(IpAddress, Port.toUShort());
    // Variable init

    if(socketVar->waitForConnected(3000)) // Connected
    {
        qDebug() << "Connected in SetPower"; // Print "Connected in SetPower" to qDebug()

        socketVar->write(bacommand); // Write first command

        if(socketVar->waitForBytesWritten(3000)) // SetPower command written
        {
            qDebug() << "SetPower command written"; // Print "SetPower command written" to qDebug()

        }
        else // SetPower command not written
        {
            qDebug() << "SetPower command not written"; // Print "SetPower command not written" to qDebug()
            return false;
        }

        socketVar->close(); // Close connection

        return true;
    }

    else
    {
        qDebug() << "Not connected in SetPower"; // Print "Not connected in SetPower" to qDebug()
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

bool Bulb::SetRGB(int red, int green, int blue, QString effect, int duration) // SetRGB member function
{
    // Variable init
    int RGB = (red * 65536) + (green * 256) + blue;

    QString command = "{\"id\":1,\"method\":\"set_rgb\",\"params\":[" + QString::number(RGB) + ",\"" + effect + "\"," + QString::number(duration) + "]}\r\n\r\n\r\n";
    QByteArray bacommand;
    bacommand.append(command);

    QTcpSocket *socketVar = new QTcpSocket();
    socketVar->connectToHost(IpAddress, Port.toUShort());
    // Variable init

    if(socketVar->waitForConnected(3000)) // Connected
    {
        qDebug() << "Connected in SetRGB"; // Print "Connected in SetRGB" to qDebug()

        socketVar->write(bacommand); // Write first command

        if(socketVar->waitForBytesWritten(3000)) // SetRGB command written
        {
            qDebug() << "SetRGB command written"; // Print "SetRGB command written" to qDebug()

        }
        else // SetPower command not written
        {
            qDebug() << "SetRGB command not written"; // Print "SetRGB command not written" to qDebug()
            return false;
        }

        socketVar->close(); // Close connection

        return true;
    }

    else
    {
        qDebug() << "Not connected in SetRGB"; // Print "Not connected in SetRGB" to qDebug()
        return false;
    }
}

bool Bulb::SetColorTemperature(int temperature, QString effect, int duration) // SetColorTemperature member function
{
    // Variable init
    QString command = "{\"id\":1,\"method\":\"set_ct_abx\",\"params\":[" + QString::number(temperature) + ",\"" + effect + "\"," + QString::number(duration) + "]}\r\n\r\n\r\n";
    QByteArray bacommand;
    bacommand.append(command);

    QTcpSocket *socketVar = new QTcpSocket();
    socketVar->connectToHost(IpAddress, Port.toUShort());
    // Variable init

    if(socketVar->waitForConnected(3000)) // Connected
    {
        qDebug() << "Connected in SetColorTemperature"; // Print "Connected in SetColorTemperature" to qDebug()

        socketVar->write(bacommand); // Write first command

        if(socketVar->waitForBytesWritten(3000)) // SetColorTemperature command written
        {
            qDebug() << "SetColorTemperature command written"; // Print "SetColorTemperature command written" to qDebug()

        }
        else // SetColorTemperature command not written
        {
            qDebug() << "SetColorTemperature command not written"; // Print "SetColorTemperature command not written" to qDebug()
            return false;
        }

        socketVar->close(); // Close connection

        return true;
    }

    else
    {
        qDebug() << "Not connected in SetColorTemperature"; // Print "Not connected in SetColorTemperature" to qDebug()
        return false;
    }
}

bool Bulb::SetHSV(int hue, int sat, QString effect, int duration) // SetHSV member function
{
    // Variable init
    QString command = "{\"id\":1,\"method\":\"set_hsv\",\"params\":[" + QString::number(hue) + "," + QString::number(sat) + ",\"" + effect + "\"," + QString::number(duration) + "]}\r\n\r\n\r\n";
    QByteArray bacommand;
    bacommand.append(command);

    QTcpSocket *socketVar = new QTcpSocket();
    socketVar->connectToHost(IpAddress, Port.toUShort());
    // Variable init

    if(socketVar->waitForConnected(3000)) // Connected
    {
        qDebug() << "Connected in SetHSV"; // Print "Connected in SetHSV" to qDebug()

        socketVar->write(bacommand); // Write first command

        if(socketVar->waitForBytesWritten(3000)) // SetHSV command written
        {
            qDebug() << "SetHSV command written"; // Print "SetHSV command written" to qDebug()

        }
        else // SetPower command not written
        {
            qDebug() << "SetHSV command not written"; // Print "SetHSV command not written" to qDebug()
            return false;
        }

        socketVar->close(); // Close connection

        return true;
    }

    else
    {
        qDebug() << "Not connected in SetRGB"; // Print "Not connected in SetRGB" to qDebug()
        return false;
    }
}

bool Bulb::SetBrightness(int brightness, QString effect, int duration) // SetBrightness member function
{
    // Variable init
    QString command = "{\"id\":1,\"method\":\"set_bright\",\"params\":[" + QString::number(brightness) + ",\"" + effect + "\"," + QString::number(duration) + "]}\r\n\r\n\r\n";
    QByteArray bacommand;
    bacommand.append(command);

    QTcpSocket *socketVar = new QTcpSocket();
    socketVar->connectToHost(IpAddress, Port.toUShort());
    // Variable init

    if(socketVar->waitForConnected(3000)) // Connected
    {
        qDebug() << "Connected in SetBrightness"; // Print "Connected in SetBrightness" to qDebug()

        socketVar->write(bacommand); // Write first command

        if(socketVar->waitForBytesWritten(3000)) // SetBrightness command written
        {
            qDebug() << "SetBrightness command written"; // Print "SetBrightness command written" to qDebug()

        }
        else // SetColorTemperature command not written
        {
            qDebug() << "SetBrightness command not written"; // Print "SetBrightness command not written" to qDebug()
            return false;
        }

        socketVar->close(); // Close connection

        return true;
    }

    else
    {
        qDebug() << "Not connected in SetBrightness"; // Print "Not connected in SetBrightness" to qDebug()
        return false;
    }
}

bool Bulb::SetDefault() // SetDefault member function
{
    // Variable init
    QString command = "{ \"id\": 1, \"method\": \"set_default\", \"params\":[]}\r\n\r\n\r\n";
    QByteArray bacommand;
    bacommand.append(command);

    QTcpSocket *socketVar = new QTcpSocket();
    socketVar->connectToHost(IpAddress, Port.toUShort());
    // Variable init



    if(socketVar->waitForConnected(3000)) // Connected
    {
        qDebug() << "Connected in SetDefault"; // Print "Connected in SetDefault" to qDebug()

        socketVar->write(bacommand); // Write first command

        if(socketVar->waitForBytesWritten(3000)) // SetDefault command written
        {
            qDebug() << "SetDefault command written"; // Print "SetDefault command written" to qDebug()

        }
        else // PowerOn command not written
        {
            qDebug() << "SetDefault command not written"; // Print "SetDefault command not written" to qDebug()
            return false;
        }

        socketVar->close(); // Close connection

        return true;
    }

    else
    {
        qDebug() << "Not connected in SetDefault"; // Print "Not connected in SetDefault" to qDebug()
        return false;
    }
}

}
