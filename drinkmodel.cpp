#include "drinkmodel.h"


DrinkModel::DrinkModel(QObject *parent)
{
    Settings *settings = Settings::getInstance();
    QString hostname = settings->getHostname();

    QNetworkAccessManager *networkManager = new QNetworkAccessManager(this);// utils->getNetworkManager();

    QUrl url(hostname + "/drinks.json");
    QNetworkRequest request;
    request.setUrl(url);

    //QObject::connect(networkManager, SIGNAL(finished(QNetworkReply*)),
    //        this, SLOT(replyFinished(QNetworkReply*)));

    QNetworkReply *reply = networkManager->get(request);
    QEventLoop loop;

    QObject::connect(networkManager, SIGNAL(finished(QNetworkReply*)), &loop, SLOT(quit()));
    loop.exec();

    if(reply->error() != QNetworkReply::NoError) {
        qDebug() << "Error: " + reply->error();
        return; // TODO
    }

    QString data = (QString) reply->readAll();
    QJsonDocument jsonResponse = QJsonDocument::fromJson(data.toUtf8());
    QJsonArray jsonArray = jsonResponse.array();

    //qDebug() << jsonArray.at(0).toObject()["name"].toString();

    //QByteArray bytes = reply->readAll();
    //QString str = QString::fromUtf8(bytes.data(), bytes.size());
    //int statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
    //qDebug() << str;
    //qDebug() << QVariant(statusCode).toString();

    for(int i=0; i < jsonArray.size(); i++) {
        Drink drink;
        drink.id = jsonArray.at(i).toObject()["id"].toString();
        drink.name = jsonArray.at(i).toObject()["name"].toString();
        drink.bottleSize = jsonArray.at(i).toObject()["bottle_size"].toString();
        drink.caffeine = jsonArray.at(i).toObject()["caffeine"].toString();
        drink.price = jsonArray.at(i).toObject()["price"].toString();
        drink.logoUrl = hostname + jsonArray.at(i).toObject()["logo_url"].toString();
        drink.createdAtRole.fromString(jsonArray.at(i).toObject()["created_at"].toString());
        drink.updatedAtRole.fromString(jsonArray.at(i).toObject()["updated_at"].toString());
        drinks.append(drink);
        //delete drink;
    }

    networkManager->~QNetworkAccessManager();
}

QVariant DrinkModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid()) {
        return QVariant();
    }
    if(role == IdRole) {
        return QVariant(drinks[index.row()].id);
    }
    if(role == NameRole) {
        return QVariant(drinks[index.row()].name);
    }
    if(role == BottleSizeRole) {
        return QVariant(drinks[index.row()].bottleSize);
    }
    if(role == CaffeineRole) {
        return QVariant(drinks[index.row()].caffeine);
    }
    if(role == PriceRole) {
        return QVariant(drinks[index.row()].price);
    }
    if(role == LogoUrl) {
        return QVariant(drinks[index.row()].logoUrl);
    }
    if(role == CreatedAtRole) {
        return QVariant(drinks[index.row()].createdAtRole);
    }
    if(role == UpdatedAtRole) {
        return QVariant(drinks[index.row()].updatedAtRole);
    }

    return QVariant();
}

QHash<int, QByteArray> DrinkModel::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[IdRole] = "id";
    roles[NameRole] = "name";
    roles[BottleSizeRole] = "bottleSize";
    roles[CaffeineRole] = "caffeine";
    roles[PriceRole] = "price";
    roles[LogoUrl] = "logoUrl";
    roles[CreatedAtRole] = "createdAtRole";
    roles[UpdatedAtRole] = "updatedAtRole";

    return roles;
}

void DrinkModel::activate(const int i) {
    if(i < 0 || i >= drinks.size()) {
        return;
    }
    Drink drink = drinks[i];

    Settings *settings = Settings::getInstance();
    QString hostname = settings->getHostname();

    QUrl url(hostname + "/users/" + "userId" + "/buy?drink=" + drink.id);
    QNetworkRequest request;
    request.setUrl(url);

}
