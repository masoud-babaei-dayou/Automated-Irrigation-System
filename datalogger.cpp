#include "DataLogger.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

DataLogger::DataLogger(QObject *parent) : QObject(parent)
{
    initDatabase();
}

DataLogger::~DataLogger()
{
    if (m_db.isOpen()) {
        m_db.close();
    }
}

bool DataLogger::initDatabase()
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName("garden_history.db");

    if (!m_db.open()) {
        qDebug() << "❌ Database Error: Failed to open database!" << m_db.lastError().text();
        return false;
    }

    QSqlQuery query;
    bool success = query.exec("CREATE TABLE IF NOT EXISTS sensor_logs ("
                              "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                              "timestamp DATETIME DEFAULT CURRENT_TIMESTAMP, "
                              "temperature REAL, "
                              "humidity REAL, "
                              "soil_moisture INTEGER)");

    success &= query.exec("CREATE TABLE IF NOT EXISTS watering_logs ("
                          "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                          "timestamp DATETIME DEFAULT CURRENT_TIMESTAMP, "
                          "duration_ms INTEGER)");

    if (success) {
        qDebug() << "🗄️ Database and tables initialized successfully.";
    } else {
        qDebug() << "❌ Database Error:" << query.lastError().text();
    }
    return success;
}

void DataLogger::logSensorData(double temperature, double humidity, int soilMoisture)
{
    QSqlQuery query;
    query.prepare("INSERT INTO sensor_logs (temperature, humidity, soil_moisture) VALUES (:t, :h, :m)");
    query.bindValue(":t", temperature);
    query.bindValue(":h", humidity);
    query.bindValue(":m", soilMoisture);
    query.exec();
}

void DataLogger::logWateringEvent(int durationMs)
{
    QSqlQuery query;
    query.prepare("INSERT INTO watering_logs (duration_ms) VALUES (:d)");
    query.bindValue(":d", durationMs);

    if (query.exec()) {
        qDebug() << "📝 Watering event logged (" << durationMs << "ms ) to database.";
    }
}