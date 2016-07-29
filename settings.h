#ifndef SETTINGS_H
#define SETTINGS_H

#include <QObject>
#include <QSettings>
#include <QDebug>

class Settings : public QObject
{
    Q_OBJECT

    Q_PROPERTY (QString hostname READ getHostname WRITE setHostname NOTIFY hostnameChanged)
    Q_PROPERTY (QString userId READ getUserId WRITE setUserId NOTIFY userIdChanged)

public:
    static Settings *getInstance();

    void setHostname(QString value);
    QString getHostname();

    void setUserId(QString value);
    QString getUserId();

signals:
    void hostnameChanged();
    void userIdChanged();

private:
    QSettings settings;
    static Settings *instance;

    explicit Settings(QObject *parent = 0);

public slots:
};

#endif // SETTINGS_H
