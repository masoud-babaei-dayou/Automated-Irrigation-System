pragma Singleton
import QtQuick

QtObject {
    property bool isDark: false

    property color background: isDark ? "#121212" : "#ecf0f1"
    property color card: isDark ? "#1e1e1e" : "white"
    property color divider: isDark ? "#333333" : "#ecf0f1"

    property color textMain: isDark ? "#ffffff" : "#2c3e50"
    property color textMuted: isDark ? "#aaaaaa" : "#7f8c8d"

    property color primaryBtn: isDark ? "#2980b9" : "#34495e"
    property color primaryBtnPressed: isDark ? "#3498db" : "#2980b9"
    property color danger: "#e74c3c"
}