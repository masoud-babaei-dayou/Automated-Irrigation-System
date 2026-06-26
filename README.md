# 🌱 Smart Automated Garden System (IoT)

[![C++](https://img.shields.io/badge/C%2B%2B-17+-blue.svg)](https://cplusplus.com/)
[![Qt](https://img.shields.io/badge/Qt-5%20%2F%206-green.svg)](https://www.qt.io/)
[![License](https://img.shields.io/badge/License-MIT-yellow.svg)](#license)
[![Platform](https://img.shields.io/badge/Platform-Linux%20%2F%20Raspberry%20Pi-red.svg)](#system-requirements)

A powerful, production-grade Internet of Things (IoT) system for automating gardens and greenhouses. Built entirely with **C++** and **Qt/QML**, this system combines embedded hardware control with cloud connectivity for remote monitoring and automation.

## 🎯 Quick Overview

| Feature | Details |
|---------|---------|
| **Processing** | Embedded Linux (Raspberry Pi 3/4/5) |
| **Sensors** | Soil moisture, temperature, humidity (DHT22) |
| **UI** | Modern QML dashboard with real-time charts |
| **Remote Control** | MQTT protocol with cloud integration |
| **Data** | Local SQLite database for history tracking |
| **Language** | C++ with Qt 5/6 framework |

## ✨ Key Features

### 🧠 Intelligent Processing
- **Embedded Linux Support**: Optimized for Raspberry Pi 3, 4, and 5
- **Real-time Decision Making**: Automated watering based on soil moisture and weather conditions
- **Efficient Resource Usage**: Lightweight C++ implementation with minimal overhead

### 📊 Real-time Monitoring
- **Environmental Sensors**: Accurate soil moisture, temperature, and humidity readings
- **Live Data Visualization**: Interactive charts and gauges on the local dashboard
- **Historical Data Tracking**: Complete watering and climate logs in SQLite database

### 🖥️ Local User Interface
- **Modern QML Dashboard**: Sleek, responsive interface with smooth animations
- **Real-time Feedback**: Direct C++ backend integration via Qt Property bindings
- **Touch-optimized**: Designed for touchscreen and desktop displays

### ☁️ Cloud Remote Control
- **MQTT Protocol**: Industry-standard communication with cloud brokers
- **Remote Monitoring**: View sensor status from anywhere via web or mobile apps
- **Manual Override**: Send watering commands remotely with automatic fallback
- **Multi-device Support**: Scale from single garden to multiple properties

### 💾 Data Persistence
- **Lightweight SQLite Database**: Fast local storage with minimal resource usage
- **Event Logging**: Track all watering cycles, sensor readings, and system events
- **Analytics Ready**: Export historical data for trend analysis and optimization

## 🏗️ System Architecture

The project uses a **modular, layered architecture** for flexibility and scalability:

```
┌─────────────────────────────────────────────────────┐
│              Cloud / MQTT Broker                    │
│              (Network Layer)                        │
└────────────────┬────────────────────────────────────┘
                 │ (MQTT Publish/Subscribe)
┌────────────────┴────────────────────────────────────┐
│         C++ Backend Brain                           │
│    (Logic, Automation, Database)                    │
│     - GPIO Control (libgpiod)                       │
│     - Sensor Data Processing                        │
│     - Automation Rules Engine                       │
└────────────────┬────────────────────────────────────┘
         ┌───────┴────────┐
         │                │
┌────────▼──────┐   ┌─────▼──────────┐
│  QML Frontend │   │  Hardware I/O  │
│  (Local UI)   │   │  - Relays      │
│  - Charts     │   │  - GPIO Pins   │
│  - Gauges     │   │  - Sensors     │
└───────────────┘   └────────────────┘
```

### Four Integrated Layers

1. **Hardware Layer** 🔌
   - Soil moisture sensors (analog/digital)
   - DHT22 temperature & humidity sensors
   - Relay modules (5V/12V) for water pumps and grow lights
   - GPIO pin control via libgpiod

2. **Backend Layer** 🧠
   - C++ core logic and automation engine
   - Sensor data reading and calibration
   - Watering schedule management
   - MQTT client for cloud communication
   - SQLite database operations

3. **Frontend Layer** 🎨
   - Qt Quick/QML responsive interface
   - Real-time sensor data visualization
   - Manual control panel
   - System status and alerts
   - Property-based data binding

4. **Network Layer** ☁️
   - MQTT publish/subscribe communication
   - Cloud broker integration
   - Remote device management
   - Multi-client support

## 🛠️ Technology Stack

| Component | Technology | Version |
|-----------|-----------|---------|
| **Language** | C++ | C++11 and above |
| **UI Framework** | Qt | 5 or 6 (Qt Quick/QML) |
| **Database** | SQLite | Latest (via `QSqlDatabase`) |
| **GPIO Control** | libgpiod | - |
| **Network** | MQTT | Standard protocol |
| **Platform** | Linux | Raspberry Pi OS, Ubuntu, etc. |

## 📋 System Requirements

### Hardware
- **Processor**: ARM-based (Raspberry Pi 3/4/5 recommended)
- **Memory**: Minimum 512MB RAM (1GB+ recommended)
- **Storage**: 2GB+ SD card
- **GPIO Pins**: Available for sensor and relay connections
- **Sensors**: DHT22, soil moisture sensor(s)
- **Relays**: 5V or 12V relay modules for pump/light control

### Software
- **OS**: Raspberry Pi OS, Ubuntu 20.04+, or compatible Linux
- **Qt**: Version 5.15+ or 6.x
- **Compiler**: GCC 7+ or Clang with C++11 support
- **Libraries**: libgpiod-dev, libmosquitto-dev (optional for MQTT)

## 🚀 Getting Started

### Installation

1. **Clone the repository**
   ```bash
   git clone https://github.com/masoud-babaei-dayou/Automated-Irrigation-System.git
   cd Automated-Irrigation-System
   ```

2. **Install dependencies**
   ```bash
   sudo apt-get update
   sudo apt-get install qt5-qmake qt5-default libgpiod-dev sqlite3
   ```

3. **Build the project**
   ```bash
   mkdir build && cd build
   cmake .. # or qmake ..
   make -j4
   ```

4. **Run the application**
   ```bash
   ./AutomatedIrrigation
   ```

## 📚 Project Structure

```
Automated-Irrigation-System/
├── src/                          # C++ source files
│   ├── main.cpp
│   ├── backend/                  # Core logic
│   │   ├── SensorReader.cpp
│   │   ├── AutomationEngine.cpp
│   │   └── MQTTClient.cpp
│   ├── hardware/                 # Hardware abstraction
│   │   ├── GPIOController.cpp
│   │   └── RelayControl.cpp
│   └── database/                 # Database operations
│       └── DataLogger.cpp
├── qml/                          # Qt QML files
│   ├── main.qml
│   ├── Dashboard.qml
│   ├── SensorDisplay.qml
│   └── ControlPanel.qml
├── resources/                    # Assets, icons, etc.
├── CMakeLists.txt or .pro       # Build configuration
└── README.md
```

## 🔧 Configuration

Edit the configuration file (typically `config.json` or `config.ini`) to customize:

- MQTT broker address and credentials
- Sensor calibration values
- Watering schedule thresholds
- Database location
- UI preferences

## 📖 Usage

### Monitoring Sensors
- Real-time charts display soil moisture, temperature, and humidity
- Historical data trends help optimize watering schedules

### Manual Control
- Override automatic watering from the local touch interface
- Send commands remotely via MQTT for cloud-based control

### Automated Watering
- Define rules based on soil moisture thresholds
- Automatic pump control with time-based safety limits
- Grow light scheduling for optimal plant growth

## 🤝 Contributing

We welcome contributions! Here's how you can help:

1. Fork the repository
2. Create a feature branch (`git checkout -b feature/amazing-feature`)
3. Commit your changes (`git commit -m 'Add amazing feature'`)
4. Push to the branch (`git push origin feature/amazing-feature`)
5. Open a Pull Request

## 📝 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## 🐛 Known Issues & Limitations

- Temperature sensor may need calibration on first run
- MQTT connection requires stable internet for remote control
- Relay modules should be rated for water pump current draw

## 🗺️ Roadmap

- [ ] Mobile app for iOS/Android
- [ ] Advanced machine learning for optimal watering schedules
- [ ] Energy consumption monitoring
- [ ] Integration with weather APIs
- [ ] Multi-zone support for larger gardens

## 💬 Support & Questions

For questions or issues:
- Open a [GitHub Issue](https://github.com/masoud-babaei-dayou/Automated-Irrigation-System/issues)
- Check existing documentation in the `docs/` folder
- Review the `examples/` directory for usage patterns

## 👏 Acknowledgments

- Qt Framework community for excellent documentation
- Raspberry Pi Foundation for the platform
- MQTT community for the protocol standard

---

**Made with 🌱 by Masoud Babaei Dayou**

⭐ If this project helped you, please consider giving it a star!
