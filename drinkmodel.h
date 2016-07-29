#ifndef DRINKMODEL_H
#define DRINKMODEL_H

#include <QAbstractListModel>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QEventLoop>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDateTime>

#include "settings.h"

class DrinkModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum DrinkRoles {
        IdRole,
        NameRole = Qt::UserRole + 1,
        BottleSizeRole, //= Qt::UserRole + 1,
        CaffeineRole,
        PriceRole,
        LogoUrl,
        CreatedAtRole,
        UpdatedAtRole,
    };

    explicit DrinkModel(QObject *parent = 0);

    virtual int rowCount(const QModelIndex&) const { return drinks.size(); }
    virtual QVariant data(const QModelIndex &index, int role) const;

    QHash<int, QByteArray> roleNames() const;

    Q_INVOKABLE void activate(const int i);

private:
    struct Drink {
        QString id;
        QString name;
        QString bottleSize;
        QString caffeine;
        QString price;
        QString logoUrl;
        QDateTime createdAtRole;
        QDateTime updatedAtRole;
    };

    QVector<Drink> drinks;
};

#endif // DRINKMODEL_H
