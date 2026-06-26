import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Rectangle {
    color: Theme.card
    radius: 12

    ColumnLayout {
        anchors.fill: parent
        anchors.margins: 25
        spacing: 20

        Text {
            text: "AUTOMATION STATUS"
            font.pixelSize: 18
            font.bold: true
            color: Theme.textMain
        }

        RowLayout {
            Layout.fillWidth: true
            Text {
                text: "Pump 1"
                font.pixelSize: 16
                color: Theme.textMain
                Layout.fillWidth: true
            }
            Text {
                text: "OFF"
                font.pixelSize: 16
                font.bold: true
                color: Theme.danger
            }
        }

        Rectangle { Layout.fillWidth: true; height: 1; color: Theme.divider }

        ColumnLayout {
            Layout.fillWidth: true
            spacing: 10

            Text {
                text: "Target Moisture (Auto-Watering)"
                font.pixelSize: 14
                color: Theme.textMuted
            }

            RowLayout {
                Layout.fillWidth: true
                Slider {
                    id: targetSlider
                    from: 0
                    to: 100
                    value: 60
                    Layout.fillWidth: true
                }
                Text {
                    text: Math.round(targetSlider.value) + "%"
                    font.pixelSize: 16
                    font.bold: true
                    color: Theme.textMain
                }
            }
        }

        Item { Layout.fillHeight: true }

        RowLayout {
            Layout.fillWidth: true
            Text {
                text: "Cloud MQTT Status:"
                font.pixelSize: 14
                color: Theme.textMuted
            }
            Text {
                text: "DISCONNECTED"
                font.pixelSize: 14
                font.bold: true
                color: Theme.danger
                Layout.alignment: Qt.AlignRight
            }
        }

        Button {
            Layout.fillWidth: true
            Layout.preferredHeight: 70

            background: Rectangle {
                color: parent.down ? Theme.primaryBtnPressed : Theme.primaryBtn
                radius: 10
            }

            contentItem: Text {
                text: "MANUAL OVERRIDE\nWATER PLANT (10s)"
                color: "white"
                font.pixelSize: 16
                font.bold: true
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }

            onClicked: {
                console.log("Manual water triggered from UI!")
            }
        }
    }
}