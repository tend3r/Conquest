#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "gameManager.h"


int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling, Qt::MSWindowsFixedSizeDialogHint);

    QGuiApplication app(argc, argv);


    qmlRegisterType<gameManager>("GameManager", 1, 0, "GameManager");

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
