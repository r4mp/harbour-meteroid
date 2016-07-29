import QtQuick 2.0
import Sailfish.Silica 1.0

import QtQuick.LocalStorage 2.0


Page {
    id: settingsPage

    // Source: http://dzone.com/snippets/validate-url-regexp
    function isUrlValid() {
        var re = /(http|https):\/\/(\w+:{0,1}\w*@)?(\S+)(:[0-9]+)?(\/|\/([\w#!:.?+=&%@!\-\/]))?/;
        hostnameErrorLabel.visible = hostnameField.text !== "" && !re.test(hostnameField.text);

        return !hostnameErrorLabel.visible;
    }

    Column {
        width: parent.width
        PageHeader { title: "Settings" }
        Label {
            id: hostnameErrorLabel
            visible: false
            anchors {left: parent.left; right: parent.right; leftMargin: Theme.paddingLarge;rightMargin: Theme.paddingLarge}
            color: "Red"
            text: qsTr("URL is invalid!")
            wrapMode: Text.WordWrap
        }
        TextField {
            id: hostnameField
            width: parent.width
            label: qsTr("Hostname")
            placeholderText: qsTr("Hostname") //"http(s)://..."
            inputMethodHints: Qt.ImhUrlCharactersOnly
            Component.onCompleted: {
                text = settings.hostname
            }
            onTextChanged: {
            //onEditingFinished: {
                isUrlValid()
                settings.hostname = text
            }
        }
    }

}
