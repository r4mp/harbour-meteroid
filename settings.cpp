#include "settings.h"

Settings *Settings::instance = 0;

Settings::Settings(QObject *parent) : QObject(parent), settings()
{

}

Settings *Settings::getInstance()
{
    if (Settings::instance == NULL) {
        Settings::instance = new Settings();
    }

    return Settings::instance;
}

void Settings::setHostname(QString value)
{
    if(getHostname() != value) {
        settings.setValue("hostname", value);
        emit hostnameChanged();
        //qDebug() << "setHostname: " << value;
    }
}

QString Settings::getHostname()
{
    //qDebug() << "getHostname";
    return settings.value("hostname", "http://mete").toString();
}

void Settings::setUserId(QString value)
{
    if(getUserId() != value) {
        settings.setValue("userId", value);
        emit userIdChanged();
    }
}

QString Settings::getUserId()
{
    return settings.value("userId", "-99").toString();
}
