import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Controls 1.4 as OldControls
import QtQuick.Controls.Styles 1.4 as OldStyles
import QtQuick.Controls.Material 2.0

Item {

    property alias nickname: txtNicknameView.text
    property alias password: txtPasswordView.text
    property alias btnLogIn: btnLogInView

    id: logIn
    width: 400
    height: 400

    Text {
        id: text1
        x: 88
        y: 119
        width: 70
        height: 20
        text: qsTr("nickname")
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize: 14

        OldControls.TextField {
            id: txtNicknameView
            objectName: "txtNickname"
            x: 88
            y: 0
            placeholderText: qsTr("Enter nickname")
            style: OldStyles.TextFieldStyle {
                textColor: "black"
                background: Rectangle {
                    radius: 3
                    implicitWidth: 110
                    implicitHeight: 20
                    border.color: "#333"
                    border.width: 1
                }
            }
        }
    }

    Text {
        id: text2
        x: 88
        y: 180
        width: 70
        height: 18
        text: qsTr("password")
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize: 14

        OldControls.TextField {
            id: txtPasswordView
            objectName: "txtPassword"
            echoMode: TextInput.Password
            x: 88
            y: 0
            placeholderText: qsTr("Enter password")
            style: OldStyles.TextFieldStyle {
                textColor: "black"
                background: Rectangle {
                    radius: 3
                    implicitWidth: 110
                    implicitHeight: 20
                    border.color: "#333"
                    border.width: 1
                }
            }
        }
    }

    OldControls.Button {
        id: btnLogInView
        objectName: "btnLogIn"
        x: 222
        y: 273
        width: 72
        height: 25
        text: "LogIn"
    }
}
