#include "bulb.h"

namespace YeelightAPI
{

Bulb::Bulb(QString ipAddress, QString port) // Constructor
{
    IpAddress = ipAddress;
    Port = port;
}

bool Bulb::TestConnection() // Test connection member function
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

        socketVar->write(bacommand1); // Write the the first command

        if(socketVar->waitForBytesWritten(3000)) // The the first command written
        {
            qDebug() << "The the first command written"; // Print "The the first command written" to qDebug()

        }
        else // The the first command not written
        {
            qDebug() << "The the first command not written"; // Print "The the first command not written" to qDebug()
            return false;
        }

        socketVar->write(bacommand2);

        if(socketVar->waitForBytesWritten(3000)) // The second command written
        {
            qDebug() << "The second command written"; // Print "The second command written" to qDebug()

        }
        else // The second command not written
        {
            qDebug() << "The second command not written"; // Print "The second command not written" to qDebug()
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
    // Assemble command
    if (power)
    {
        command = "{ \"id\": 1, \"method\": \"set_power\", \"params\":[\"on\", \"" + effect + "\"," + QString::number(duration) + "]}\r\n\r\n\r\n";
    }
    else
    {
        command = "{ \"id\": 1, \"method\": \"set_power\", \"params\":[\"off\", \"" + effect + "\"," + QString::number(duration) + "]}\r\n\r\n\r\n";
    }
    // Assemble command

    QByteArray bacommand;
    bacommand.append(command); // Append command into bacommand

    QTcpSocket *socketVar = new QTcpSocket();
    socketVar->connectToHost(IpAddress, Port.toUShort());
    // Variable init

    if(socketVar->waitForConnected(3000)) // Connected
    {
        qDebug() << "Connected within SetPower"; // Print "Connected within SetPower" to qDebug()

        socketVar->write(bacommand); // Write the first command

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
        qDebug() << "Not connected within SetPower"; // Print "Not connected within SetPower" to qDebug()
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
        qDebug() << "Connected within Toggle"; // Print "Connected within Toggle" to qDebug()

        socketVar->write(bacommand); // Write the first command

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
        qDebug() << "Not connected within Toggle"; // Print "Not connected within Toggle" to qDebug()
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
        qDebug() << "Connected within SetRGB"; // Print "Connected within SetRGB" to qDebug()

        socketVar->write(bacommand); // Write the first command

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
        qDebug() << "Not connected within SetRGB"; // Print "Not connected within SetRGB" to qDebug()
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
        qDebug() << "Connected within SetColorTemperature"; // Print "Connected within SetColorTemperature" to qDebug()

        socketVar->write(bacommand); // Write the first command

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
        qDebug() << "Not connected within SetColorTemperature"; // Print "Not connected within SetColorTemperature" to qDebug()
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
        qDebug() << "Connected in SetHSV"; // Print "Connected within SetHSV" to qDebug()

        socketVar->write(bacommand); // Write the first command

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
        qDebug() << "Not connected within SetRGB"; // Print "Not connected within SetRGB" to qDebug()
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
        qDebug() << "Connected within SetBrightness"; // Print "Connected within SetBrightness" to qDebug()

        socketVar->write(bacommand); // Write the first command

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
        qDebug() << "Not connected within SetBrightness"; // Print "Not connected within SetBrightness" to qDebug()
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
        qDebug() << "Connected within SetDefault"; // Print "Connected within SetDefault" to qDebug()

        socketVar->write(bacommand); // Write the first command

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
        qDebug() << "Not connected within SetDefault"; // Print "Not connected within SetDefault" to qDebug()
        return false;
    }
}

bool Bulb::StartColorFlow(int count, int action, QString flowExpression) // StartColorFlow member function
{
    // Variable init
    QString command = "{\"id\":1,\"method\":\"start_cf\",\"params\":[" + QString::number(count) + "," + QString::number(action) + ",\"" + flowExpression + "\"]}\r\n\r\n\r\n";
    QByteArray bacommand;
    bacommand.append(command);

    QTcpSocket *socketVar = new QTcpSocket();
    socketVar->connectToHost(IpAddress, Port.toUShort());
    // Variable init



    if(socketVar->waitForConnected(3000)) // Connected
    {
        qDebug() << "Connected within StartColorFlow"; // Print "Connected within StartColorFlow" to qDebug()

        socketVar->write(bacommand); // Write the first command

        if(socketVar->waitForBytesWritten(3000)) // StartColorFlow command written
        {
            qDebug() << "StartColorFlow command written"; // Print "StartColorFlow command written" to qDebug()

        }
        else // StartColorFlow command not written
        {
            qDebug() << "StartColorFlow command not written"; // Print "StartColorFlow command not written" to qDebug()
            return false;
        }

        socketVar->close(); // Close connection

        return true;
    }

    else
    {
        qDebug() << "Not connected within StartColorFlow"; // Print "Not connected within StartColorFlow" to qDebug()
        return false;
    }
}

bool Bulb::StopColorFlow() // StopColorFlow member function
{
    // Variable init
    QString command = "{ \"id\": 1, \"method\": \"stop_cf\", \"params\":[]}\r\n\r\n\r\n";
    QByteArray bacommand;
    bacommand.append(command);

    QTcpSocket *socketVar = new QTcpSocket();
    socketVar->connectToHost(IpAddress, Port.toUShort());
    // Variable init



    if(socketVar->waitForConnected(3000)) // Connected
    {
        qDebug() << "Connected within StopColorFlow"; // Print "Connected within StopColorFlow" to qDebug()

        socketVar->write(bacommand); // Write the first command

        if(socketVar->waitForBytesWritten(3000)) // StopColorFlow command written
        {
            qDebug() << "StopColorFlow command written"; // Print "StopColorFlow command written" to qDebug()

        }
        else // StopColorFlow command not written
        {
            qDebug() << "StopColorFlow command not written"; // Print "StopColorFlow command not written" to qDebug()
            return false;
        }

        socketVar->close(); // Close connection

        return true;
    }

    else
    {
        qDebug() << "Not connected within StopColorFlow"; // Print "Not connected within StopColorFlow" to qDebug()
        return false;
    }
}

bool Bulb::SetScene(QString sceneClass, int val1, int val2) // SetScene member function
{
    // Variable init
    QString command = "{\"id\":1,\"method\":\"set_scene\",\"params\":[\"" + sceneClass + "\"," + QString::number(val1) + "," + QString::number(val2) + "]}\r\n\r\n\r\n";
    QByteArray bacommand;
    bacommand.append(command);

    QTcpSocket *socketVar = new QTcpSocket();
    socketVar->connectToHost(IpAddress, Port.toUShort());
    // Variable init



    if(socketVar->waitForConnected(3000)) // Connected
    {
        qDebug() << "Connected within SetScene"; // Print "Connected within SetScene" to qDebug()

        socketVar->write(bacommand); // Write the first command

        if(socketVar->waitForBytesWritten(3000)) // SetScene command written
        {
            qDebug() << "SetScene command written"; // Print "SetScene command written" to qDebug()

        }
        else // StartColorFlow command not written
        {
            qDebug() << "SetScene command not written"; // Print "SetScene command not written" to qDebug()
            return false;
        }

        socketVar->close(); // Close connection

        return true;
    }

    else
    {
        qDebug() << "Not connected within SetScene"; // Print "Not connected within SetScene" to qDebug()
        return false;
    }
}

bool Bulb::SetScene(QString sceneClass, int val1, int val2, int val3) // SetScene member function
{
    // Variable init
    QString command = "{\"id\":1,\"method\":\"set_scene\",\"params\":[\"" + sceneClass + "\"," + QString::number(val1) + "," + QString::number(val2) + "," + QString::number(val3) + "]}\r\n\r\n\r\n";
    QByteArray bacommand;
    bacommand.append(command);

    QTcpSocket *socketVar = new QTcpSocket();
    socketVar->connectToHost(IpAddress, Port.toUShort());
    // Variable init



    if(socketVar->waitForConnected(3000)) // Connected
    {
        qDebug() << "Connected within SetScene"; // Print "Connected within SetScene" to qDebug()

        socketVar->write(bacommand); // Write the first command

        if(socketVar->waitForBytesWritten(3000)) // SetScene command written
        {
            qDebug() << "SetScene command written"; // Print "SetScene command written" to qDebug()

        }
        else // SetScene command not written
        {
            qDebug() << "SetScene command not written"; // Print "SetScene command not written" to qDebug()
            return false;
        }

        socketVar->close(); // Close connection

        return true;
    }

    else
    {
        qDebug() << "Not connected within SetScene"; // Print "Not connected within SetScene" to qDebug()
        return false;
    }
}


bool Bulb::AddCron(int type, int value) // SetCron member function
{
    // Variable init
    QString command = "{\"id\":1,\"method\":\"cron_add\",\"params\":[" + QString::number(type) + "," + QString::number(value) + "]}\r\n\r\n\r\n";
    QByteArray bacommand;
    bacommand.append(command);

    QTcpSocket *socketVar = new QTcpSocket();
    socketVar->connectToHost(IpAddress, Port.toUShort());
    // Variable init



    if(socketVar->waitForConnected(3000)) // Connected
    {
        qDebug() << "Connected within AddCron"; // Print "Connected within AddCron" to qDebug()

        socketVar->write(bacommand); // Write the first command

        if(socketVar->waitForBytesWritten(3000)) // AddCron command written
        {
            qDebug() << "AddCron command written"; // Print "AddCron command written" to qDebug()

        }
        else // SetCron command not written
        {
            qDebug() << "AddCron command not written"; // Print "AddCron command not written" to qDebug()
            return false;
        }

        socketVar->close(); // Close connection

        return true;
    }

    else
    {
        qDebug() << "Not connected within AddCron"; // Print "Not connected within AddCron" to qDebug()
        return false;
    }
}

bool Bulb::GetCron(int type) // GetCron member function
{
    // Variable init
    QString command = "{\"id\":1,\"method\":\"cron_get\",\"params\":[" + QString::number(type) + "]}\r\n\r\n\r\n";
    QByteArray bacommand;
    bacommand.append(command);

    QTcpSocket *socketVar = new QTcpSocket();
    socketVar->connectToHost(IpAddress, Port.toUShort());
    // Variable init



    if(socketVar->waitForConnected(3000)) // Connected
    {
        qDebug() << "Connected within GetCron"; // Print "Connected within GetCron" to qDebug()

        socketVar->write(bacommand); // Write the first command

        if(socketVar->waitForBytesWritten(3000)) // GetCron command written
        {
            qDebug() << "GetCron command written"; // Print "GetCron command written" to qDebug()

        }
        else // GetCron command not written
        {
            qDebug() << "GetCron command not written"; // Print "GetCron command not written" to qDebug()
            return false;
        }

        socketVar->close(); // Close connection

        return true;
    }

    else
    {
        qDebug() << "Not connected within GetCron"; // Print "Not connected within GetCron" to qDebug()
        return false;
    }
}

bool Bulb::DeleteCron(int type) // DeleteCron member function
{
    // Variable init
    QString command = "{\"id\":1,\"method\":\"cron_del\",\"params\":[" + QString::number(type) + "]}\r\n\r\n\r\n";
    QByteArray bacommand;
    bacommand.append(command);

    QTcpSocket *socketVar = new QTcpSocket();
    socketVar->connectToHost(IpAddress, Port.toUShort());
    // Variable init



    if(socketVar->waitForConnected(3000)) // Connected
    {
        qDebug() << "Connected within DeleteCron"; // Print "Connected within DeleteCron" to qDebug()

        socketVar->write(bacommand); // Write the first command

        if(socketVar->waitForBytesWritten(3000)) // DeleteCron command written
        {
            qDebug() << "DeleteCron command written"; // Print "DeleteCron command written" to qDebug()

        }
        else // GetCron command not written
        {
            qDebug() << "DeleteCron command not written"; // Print "DeleteCron command not written" to qDebug()
            return false;
        }

        socketVar->close(); // Close connection

        return true;
    }

    else
    {
        qDebug() << "Not connected within DeleteCron"; // Print "Not connected within DeleteCron" to qDebug()
        return false;
    }
}

bool Bulb::SetMusic(int action, QString host, int port) // SetMusic member function
{
    // Variable init
    QString command = "{\"id\":1,\"method\":\"set_music\",\"params\":[" + QString::number(action) + ",\"" + host + "\"," + QString::number(port) + "]}\r\n\r\n\r\n";
    QByteArray bacommand;
    bacommand.append(command);

    QTcpSocket *socketVar = new QTcpSocket();
    socketVar->connectToHost(IpAddress, Port.toUShort());
    // Variable init



    if(socketVar->waitForConnected(3000)) // Connected
    {
        qDebug() << "Connected within SetMusic"; // Print "Connected within SetMusic" to qDebug()

        socketVar->write(bacommand); // Write the first command

        if(socketVar->waitForBytesWritten(3000)) // SetMusic command written
        {
            qDebug() << "SetMusic command written"; // Print "SetMusic command written" to qDebug()

        }
        else // SetMusic command not written
        {
            qDebug() << "SetMusic command not written"; // Print "SetMusic command not written" to qDebug()
            return false;
        }

        socketVar->close(); // Close connection

        return true;
    }

    else
    {
        qDebug() << "Not connected within SetMusic"; // Print "Not connected within SetMusic" to qDebug()
        return false;
    }
}

}
