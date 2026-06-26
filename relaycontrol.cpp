#include "RelayControl.h"
#include <QDebug>

RelayControl::RelayControl(int pin, GPIOController* gpioController, QObject *parent)
    : QObject(parent), m_pin(pin), m_isOn(false), m_gpio(gpioController)
{
    if (m_gpio) {
        m_gpio->initPin(m_pin, true);
    }

    m_safetyTimer.setSingleShot(true);
    connect(&m_safetyTimer, &QTimer::timeout, this, &RelayControl::autoTurnOff);
}

void RelayControl::turnOn(int durationMs)
{
    if (!m_isOn) {
        m_isOn = true;
        if (m_gpio) m_gpio->writePin(m_pin, true);

        emit stateChanged(true);
        qDebug() << "💦 Relay on pin" << m_pin << "turned ON.";

        if (durationMs > 0) {
            m_safetyTimer.start(durationMs);
        }
    }
}

void RelayControl::turnOff()
{
    if (m_isOn) {
        m_isOn = false;
        m_safetyTimer.stop();

        if (m_gpio) m_gpio->writePin(m_pin, false);

        emit stateChanged(false);
        qDebug() << "🛑 Relay on pin" << m_pin << "turned OFF.";
    }
}

void RelayControl::autoTurnOff()
{
    qDebug() << "⚠️ Safety timer triggered! Auto-shutting down the pump.";
    turnOff();
}