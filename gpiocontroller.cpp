#include "GPIOController.h"
#include <QDebug>

GPIOController::GPIOController(QObject *parent)
    : QObject(parent), m_isSimulationMode(true)
{
    setupHardware();
}

void GPIOController::setupHardware()
{
    m_isSimulationMode = true;
    qDebug() << "💻 PC Mode: Running GPIO in Simulation Mode.";
}

bool GPIOController::initPin(int pinNumber, bool isOutput)
{
    if (m_isSimulationMode) {
        m_mockPinStates[pinNumber] = false;
        qDebug() << "Mock GPIO: Pin" << pinNumber << "initialized as" << (isOutput ? "OUTPUT" : "INPUT");
        return true;
    }
    return false;
}

bool GPIOController::writePin(int pinNumber, bool state)
{
    if (m_isSimulationMode) {
        m_mockPinStates[pinNumber] = state;
        emit pinStateChanged(pinNumber, state);
        qDebug() << "Mock GPIO: Pin" << pinNumber << "set to" << (state ? "HIGH (ON)" : "LOW (OFF)");
        return true;
    }
    return false;
}

bool GPIOController::readPin(int pinNumber)
{
    if (m_isSimulationMode) {
        return m_mockPinStates.value(pinNumber, false);
    }
    return false;
}