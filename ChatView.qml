import QtQuick 2.7

ChatViewForm {

    btnSend.onClicked: {

        client.sendMessage(txtMessage)

        txtMessage = ""

    }


    connectedUser.onClicked: {

        client.sendChatRequest(txtNickname)
    }

}




