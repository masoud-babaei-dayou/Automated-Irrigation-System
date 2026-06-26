import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Item {
    RowLayout {
        anchors.fill: parent
        spacing: 20

        ColumnLayout {
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.preferredWidth: 2
            spacing: 20

            RowLayout {
                Layout.fillWidth: true
                spacing: 15

                SensorDisplay {
                    title: "SOIL MOISTURE"
                    value: "78%"
                    accentColor: "#2ecc71"
                }
                SensorDisplay {
                    title: "TEMPERATURE"
                    value: "23.5°C"
                    accentColor: "#e67e22"
                }
                SensorDisplay {
                    title: "HUMIDITY"
                    value: "55%"
                    accentColor: "#3498db"
                }
            }

            Rectangle {
                Layout.fillWidth: true
                Layout.fillHeight: true
                color: "white"
                radius: 12

                Text {
                    anchors.top: parent.top
                    anchors.left: parent.left
                    anchors.margins: 20
                    text: "Historical Data (Water Usage)"
                    font.pixelSize: 18
                    font.bold: true
                    color: "#2c3e50"
                }

                RowLayout {
                    anchors.bottom: parent.bottom
                    anchors.left: parent.left
                    anchors.right: parent.right
                    anchors.margins: 20
                    height: 150
                    spacing: 10

                    Repeater {
                        model: [80, 40, 90, 110, 150, 60, 40]
                        Rectangle {
                            Layout.fillWidth: true
                            Layout.alignment: Qt.AlignBottom
                            height: modelData
                            color: "#95a5a6"
                            radius: 5
                            opacity: 0.7
                        }
                    }
                }
            }
        }


        ControlPanel {
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.preferredWidth: 1
        }
    }
}