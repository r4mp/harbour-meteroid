#include "usermodel.h"

UserModel::UserModel(QObject *parent)
{

}

QVariant UserModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid()) {
        return QVariant();
    }
    if(role == IdRole) {
        return QVariant(users[index.row()].id);
    }
    if(role == NameRole) {
        return QVariant(users[index.row()].name);
    }
    if(role == EmailRole) {
        return QVariant(users[index.row()].email);
    }
    if(role == BalanceRole) {
        return QVariant(users[index.row()].balance);
    }
    if(role == ActiveRole) {
        return QVariant(users[index.row()].active);
    }
    if(role == AuditRole) {
        return QVariant(users[index.row()].audit);
    }
    if(role == CreatedAtRole) {
        return QVariant(users[index.row()].createdAt);
    }
    if(role == UpdatedAtRole) {
        return QVariant(users[index.row()].updatedAt);
    }
    if(role == AvatarRole) {
        return QVariant(users[index.row()].avatar);
    }

    return QVariant();
}

QHash<int, QByteArray> UserModel::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[IdRole] = "id";
    roles[NameRole] = "name";
    roles[EmailRole] = "email";
    roles[BalanceRole] = "balance";
    roles[ActiveRole] = "active";
    roles[AuditRole] = "audit";
    roles[CreatedAtRole] = "createdAt";
    roles[UpdatedAtRole] = "updatedAt";
    roles[AvatarRole] = "avatar";

    return roles;
}

void UserModel::activate(const int i) {
    if(i < 0 || i >= users.size()) {
        return;
    }
}
