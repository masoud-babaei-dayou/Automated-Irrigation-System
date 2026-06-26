import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

ApplicationWindow {
    width: 1024
    height: 600
    visible: true
    title: qsTr("Smart Automated Garden")
    color: "#ecf0f1"

    Dashboard {
        anchors.fill: parent
        anchors.margins: 20
    }
}