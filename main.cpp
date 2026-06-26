#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickStyle>

int main(int argc, char *argv[])
{
    QQuickStyle::setStyle("Basic");
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    // مسیر جدید بر اساس فایل منابع qrc
    const QUrl url(QStringLiteral("qrc:/main.qml"));

    engine.load(url);
    return app.exec();
}