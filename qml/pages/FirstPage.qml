import QtQuick 2.0
import Sailfish.Silica 1.0
import de.r4mp.harbour.meteroid 1.0

Page {
    id: page

    SilicaListView {
        id: listView
        model: DrinkModel {
            id: drinks
        }
        //opacity: drinks.ready ? 1.0 : 0.0
        Behavior on opacity { FadeAnimation {} }
        anchors.fill: parent
        header: PageHeader {
            title: qsTr("Buy drink")
        }
        section {
            delegate: SectionHeader {
                text: qsTr("User")
            }
        }
        Item {
            id: userDelegate
            Image {
                id: userImage
                source: avatar ? avatar : "./assets/drink-default.png"
                anchors.left: parent.left
                anchors.leftMargin: userImage.width / 3
            }
            Label {
                x: Theme.paddingLarge
                //width: parent.width - image.width
                text: qsTr("Name")
                anchors {
                    left: userImage.right
                    leftMargin: userImage.width / 3
                    verticalCenter: parent.verticalCenter
                }
                color: Theme.primaryColor
            }
        }
        VerticalScrollDecorator {}
        section {
            delegate: SectionHeader {
                text: qsTr("Drink")
            }
        }
        delegate: BackgroundItem {
            id: delegate
            Image {
                id: image
                width: parent.height - 10
                height: parent.height - 10
                source: logoUrl ? logoUrl : "./assets/drink-default.png"
                anchors.left: parent.left
                anchors.leftMargin: image.width / 3
                anchors.verticalCenter: parent.verticalCenter
            }
            Label {
                id: drinkName
                x: Theme.paddingLarge
                width: parent.width - image.width - 80
                text: model.name ? model.name : "name"
                anchors {
                    left: image.right
                    leftMargin: image.width / 3
                    verticalCenter: parent.verticalCenter
                }
                color: delegate.highlighted ? Theme.highlightColor : Theme.primaryColor
            }
            Label {
                x: Theme.paddingLarge
                width: parent.width - image.width - drinkName.width
                text: model.price ? model.price : "price"
                horizontalAlignment: Text.AlignRight
                anchors {
                    right: parent.right
                    rightMargin: image.width / 3
                    verticalCenter: parent.verticalCenter
                }
            }

            onClicked: drinks.activate(index/*, model.id, user.id*/)
        }
        VerticalScrollDecorator {}

        PullDownMenu {
            MenuItem {
                text: qsTr("Settings")
                onClicked: pageStack.push(Qt.resolvedUrl("SettingsPage.qml"))
            }
            MenuItem {
                text: qsTr("Refresh")
                //onClicked: // refresh
            }
        }
    }
}
