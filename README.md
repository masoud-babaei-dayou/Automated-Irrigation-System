# 🌱 Smart Automated Garden System (IoT)

[cite_start]This project is a powerful Internet of Things (IoT) system for automating a garden and greenhouse, developed entirely using C++ and Qt/QML[cite: 125]. [cite_start]This system can continuously monitor soil moisture and automatically turn on water pumps when needed[cite: 126].

## ✨ Key Features

* [cite_start]**Powerful Processing Brain:** Designed to run on embedded Linux environments (like Raspberry Pi versions 3, 4, or 5)[cite: 127].
* [cite_start]**Real-time Monitoring:** Accurate reading of environmental data through soil moisture and temperature/humidity sensors (like DHT22)[cite: 128].
* [cite_start]**Touch User Interface (Local UI):** Features a modern and fluid dashboard built with QML, connected to the backend via the `Q_PROPERTY` mechanism[cite: 129].
* [cite_start]**Cloud Remote Control:** Supports the standard MQTT protocol using the `QtMQTT` module to view sensor status (Publish) and send manual watering commands (Subscribe) over the internet[cite: 130].
* [cite_start]**Data Persistence:** Logs watering history and temperature fluctuations in a lightweight local SQLite database[cite: 131].

## 🏗️ System Architecture

[cite_start]This project is divided into 4 main, completely separate layers[cite: 132]:

1. [cite_start]**The Hardware Layer (The Muscles):** Includes sensors as inputs and relay modules (5V / 12V) to control the electrical current of water pumps and grow lights as outputs[cite: 132].
2. [cite_start]**The Backend Layer (C++ Brain):** The logical core of the system responsible for reading hardware data (GPIO), processing automation logic (e.g., watering for 10 seconds if the soil is dry), and managing the database[cite: 133].
3. [cite_start]**The Frontend Layer (QML Face):** Local display of data as sleek visual charts and gauges on a monitor connected to the hardware[cite: 134].
4. [cite_start]**The Network Layer (Cloud):** Communicates with a cloud broker to connect the local system to mobile applications or web dashboards[cite: 135].

## 🛠️ Tech Stack

* [cite_start]**Programming Language:** C++ (Standard 11 and above) [cite: 136]
* [cite_start]**UI Framework:** Qt 5 / Qt 6 (Qt Quick and QML modules) [cite: 136]
* [cite_start]**Hardware Communication:** `libgpiod` (for controlling GPIO pins) [cite: 136]
* [cite_start]**Database:** SQLite (via the `QSqlDatabase` class) [cite: 136]
* [cite_start]**Network Protocol:** MQTT [cite: 136]
