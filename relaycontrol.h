#ifndef RELAYCONTROL_H
#define RELAYCONTROL_H

#include <QObject>
#include <QTimer>
#include "GPIOController.h"

class RelayControl : public QObject
{
    Q_OBJECT
public:
    explicit RelayControl(int pin, GPIOController* gpioController, QObject *parent = nullptr);

public slots:
    void turnOn(int durationMs = 0);
    void turnOff();

signals:
    void stateChanged(bool isOn);

private slots:
    void autoTurnOff();

private:
    int m_pin;
    bool m_isOn;
    GPIOController* m_gpio;
    QTimer m_safetyTimer;
};

#endif // RELAYCONTROL_H