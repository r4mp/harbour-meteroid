#ifdef QT_QML_DEBUG
#include <QtQuick>
#endif

#include <sailfishapp.h>
#include <QQmlContext>

#include "usermodel.h"
#include "drinkmodel.h"
#include "settings.h"


int main(int argc, char *argv[])
{
    QScopedPointer<QGuiApplication> app(SailfishApp::application(argc, argv));

    QScopedPointer<QQuickView> view(SailfishApp::createView());

    Settings *settings = Settings::getInstance();
    view->rootContext()->setContextProperty("settings", settings);

    qmlRegisterType<DrinkModel>("de.r4mp.harbour.meteroid", 1, 0, "DrinkModel");

    view->setSource(SailfishApp::pathTo("qml/harbour-meteroid.qml"));
    view->show();

    return app->exec();
}

