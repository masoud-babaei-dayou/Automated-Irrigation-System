import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Rectangle {
    property string title: "SENSOR"
    property string value: "0"
    property color accentColor: "#34495e"

    Layout.fillWidth: true
    height: 180
    color: "white"
    radius: 12

    Rectangle {
        width: parent.width
        height: 6
        color: accentColor
        anchors.bottom: parent.bottom
        radius: 12

        Rectangle {
            width: parent.width
            height: 3
            color: accentColor
            anchors.bottom: parent.bottom
        }
    }

    Column {
        anchors.centerIn: parent
        spacing: 10

        Text {
            text: title
            font.pixelSize: 14
            font.bold: true
            color: "#7f8c8d"
            anchors.horizontalCenter: parent.horizontalCenter
        }

        Rectangle {
            width: 100
            height: 100
            radius: 50
            color: "transparent"
            border.color: accentColor
            border.width: 6
            anchors.horizontalCenter: parent.horizontalCenter

            Text {
                text: value
                font.pixelSize: 26
                font.bold: true
                color: "#2c3e50"
                anchors.centerIn: parent
            }
        }
    }
}