#ifndef DATALOGGER_H
#define DATALOGGER_H

#include <QObject>
#include <QSqlDatabase>

class DataLogger : public QObject
{
    Q_OBJECT
public:
    explicit DataLogger(QObject *parent = nullptr);
    ~DataLogger();

    bool initDatabase();

public slots:
    void logSensorData(double temperature, double humidity, int soilMoisture);
    void logWateringEvent(int durationMs);

private:
    QSqlDatabase m_db;
};

#endif // DATALOGGER_H