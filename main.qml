import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Controls 1.4 as OldControls
import QtQuick.Controls.Material 2.0
import client 1.0

ApplicationWindow {

    id: rootWindow
    visible: true
    width: 640
    height: 480
    title: qsTr("Chat Client")
    minimumHeight: 480
    maximumHeight: 480
    minimumWidth: 640
    maximumWidth: 640

    Material.theme: Material.Dark
    Material.accent: Material.color(Material.DeepPurple)

    Client {
        id: client
        objectName: "client"
    }

    SwipeView {
        id: swipeView
        anchors.fill: parent
        currentIndex: tabBar.currentIndex

        Presentation {
            id: presentationView
        }

        Login {
            id: logIn
        }

        ChatView {

            id: chatView
        }

    }

    footer: TabBar {
        id: tabBar
        currentIndex: swipeView.currentIndex

        TabButton {
            id: btnInf
            objectName: "btnInfo"
            text: qsTr("Welcome")
            onClicked:
            {

                //removeItem(presentationView)
            }

        }

        TabButton {
            id: btnInit
            objectName: "btnInit"
            text: qsTr("LogIn")
            onClicked:
            {
                if(btnInit.text == "LogIn")
                {
                    btnInit.text = "Client"

                     client.setChatView(rootWindow)

                    //Create an instance of a client and then start it.
                    client.init()
                }
            }
        }

        TabButton {
            id: btnChat
            objectName: "btnChat"
            text: qsTr("Chat")
            onClicked:
            {
                if(btnChat.text == "Chat")
                {
                    btnChat.text = ""
                }

            }

        }
    }
}
