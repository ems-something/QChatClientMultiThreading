import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Controls 1.4 as OldControls
import QtQuick.Controls.Styles 1.4 as OldStyles
import QtQuick.Controls.Material 2.0


LoginForm {

   btnLogIn.onClicked: {

       client.sendAuthenticationRequest(nickname, password)
    }
}
