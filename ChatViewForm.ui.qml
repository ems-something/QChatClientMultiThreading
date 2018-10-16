import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Controls 1.4 as OldControls
import QtQuick.Controls.Styles 1.4 as OldStyles
import QtQuick.Controls.Material 2.0

Item {

    property alias btnSend: btnSendView
    property alias txtMessage: txtMessageView.text
    property alias connectedUser: itemUserView
    property alias txtNickname: itemUserView.text

    id: chatView
    visible: true
    width: 400
    height: 400

    ToolBar {
        id: toolBarView
        x: 0
        y: 0
        width: 259
        height: 20

        Label {
            id: file
            text: qsTr("File")
            horizontalAlignment: Text.AlignHCenter //upload new file/ read file/ edit file
            font.pixelSize: 14
            width: 55
            height: 20
            color: "#000000"
        }

        Label {
            id: group
            x: 56
            y: 0 //create new group/ leave group
            text: qsTr("Group")
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 14
            width: 55
            height: 20
            color: "#000000"
        }

        Label {
            id: history
            x: 112
            y: 0
            text: qsTr("History")
            horizontalAlignment: Text.AlignHCenter //filter by date/ filter by nickname/ filter by name group
            font.pixelSize: 14
            width: 55
            height: 20
            color: "#000000"
        }
    }

    OldControls.TextField {
        id: txtMessageView
        objectName: "txtMessage"
        x: 22
        y: 360
        width: 229
        height: 20
        style: OldStyles.TextFieldStyle {
            textColor: "#000000"
            background: Rectangle {
                radius: 3
                implicitWidth: 110
                implicitHeight: 20
                border.color: "#333"
                border.width: 1
            }
        }
    }

    OldControls.Button {
        id: btnSendView
        objectName: "btnSend"
        x: 283
        y: 360
        width: 72
        height: 25
        text: "Send"
    }

    OldControls.ScrollView {
        id: scrollMessagesView
        x: 22
        y: 39

        ListView {
            id: messagesListView
            objectName: "messagesListView"
            width: 200
            height: 350
            /*anchors.bottomMargin: -253
            anchors.leftMargin: 501
            anchors.topMargin: 103
            anchors.rightMargin: -483*/
            delegate: Rectangle {
                id: recMessagetView
                width: parent.width
                height: 25
                color: "#9E9E9E"
                border.color: "#EEEEEE"
                border.width: 3

                Text {
                    id: txtMessagesView
                    objectName: "txtMessagesList"
                    color: "#000000"
                    text: modelData
                    font.pixelSize: 12
                }
            }
        }
    }

    OldControls.ScrollView {
        id: scrollUsersView
        x: 283
        y: 20
        ListView {
            id: usersListView
            objectName: "usersListView"
            width: 100
            height: 25

            /*spacing: 10
            anchors.bottomMargin: -53
            anchors.leftMargin: 883
            anchors.topMargin: -115
            anchors.rightMargin: -725*/
            header: Label {
                text: qsTr("Contacts")
                font.pixelSize: 14
                horizontalAlignment: Text.AlignHCenter
                width: parent.width
                color: "#000000"
            }

            delegate: ItemDelegate {
                id: itemUserView
                text: modelData
                width: parent.width
                height: 20

                /*Image {
                    id: avatar
                    source: "qrc:/" + modelData.replace(" ", "_") + ".png"
                }*/
            }
        }
    }
}
