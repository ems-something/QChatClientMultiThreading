import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0

Item {
    id: welcomeView

    Text {
        id: txtWelcomeView
        x: 80
        y: 129
        width: 481
        height: 54
        color: "#ffffff"
        text: qsTr("Welcome to the Chat Client!")
        font.pixelSize: 32
    }
}


