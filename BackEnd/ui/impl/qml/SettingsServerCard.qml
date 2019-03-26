import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import QtQuick.Dialogs 1.2

Item
{
    visible: true
    width: 640
    height: 480

    property string host: "127.0.0.1"
    property int port: 1111
    property bool connectServerStatus: false

    Connections {
        target: ServerSettingsCardCPP

        onConnectinStatus:{
         connectServerStatus = status
            if(connectServerStatus)
            {
               element2.text = "Connected"
            }
            else
            {
                 element2.text = "Not connected"
            }
        }
    }

    TextField {
        id: textField
        x: 124
        y: 79
        placeholderText: qsTr("172.0.0.1")
    }

    Text {
        id: element
        x: 20
        y: 79
        width: 98
        height: 23
        text: qsTr("Host")
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        font.pixelSize: 18
    }

    TextField {
        id: textField1
        x: 124
        y: 113
        placeholderText: qsTr("1111")
    }

    Text {
        id: element1
        x: 20
        y: 108
        width: 98
        height: 23
        text: qsTr("Port")
        font.pixelSize: 18
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
    }

    Text {
        id: element2
        x: 124
        y: 142
        width: 102
        height: 15
        text: qsTr("Not connected")
        font.pixelSize: 12
    }

    Button {
        id: button
        x: 43
        y: 163
        text: qsTr("Connect")

        onClicked: {
            if(textField.text.length != 0)
            {
                host = textField.text
            }

            if(textField1.text.length != 0)
            {
                port = textField1.text
            }
            ServerSettingsCardCPP.receivedHostAndPort(host, port)
        }
    }
}
