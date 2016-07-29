#ifndef USERMODEL_H
#define USERMODEL_H

#include <QObject>
#include <QDateTime>
#include <QAbstractListModel>

class UserModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum UserRoles {
        IdRole,
        NameRole,
        EmailRole,
        BalanceRole,
        ActiveRole,
        AuditRole,
        CreatedAtRole,
        UpdatedAtRole,
        AvatarRole,
    };

    explicit UserModel(QObject *parent = 0);

    virtual int rowCount(const QModelIndex&) const { return users.size(); }
    virtual QVariant data(const QModelIndex &index, int role) const;

    QHash<int, QByteArray> roleNames() const;

    Q_INVOKABLE void activate(const int i);

private:
    struct User {
        QString id;
        QString name;
        QString email;
        QString balance;
        bool active;
        bool audit;
        QDateTime createdAt;
        QDateTime updatedAt;
        QString avatar;
    };

    QVector<User> users;

signals:

public slots:
};

#endif // USERMODEL_H
