#ifndef GPIOCONTROLLER_H
#define GPIOCONTROLLER_H

#include <QObject>
#include <QMap>
#include <QString>

class GPIOController : public QObject
{
    Q_OBJECT
public:
    explicit GPIOController(QObject *parent = nullptr);

    bool initPin(int pinNumber, bool isOutput);
    bool writePin(int pinNumber, bool state);
    bool readPin(int pinNumber);

    bool isSimulationMode() const { return m_isSimulationMode; }

signals:
    void pinStateChanged(int pinNumber, bool newState);

private:
    QMap<int, bool> m_mockPinStates;
    void setupHardware();
    bool m_isSimulationMode;
};

#endif // GPIOCONTROLLER_H