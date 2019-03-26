import QtQuick 2.0
import QtQuick.Controls 1.0

import "."

ApplicationWindow
{
    visible: true
    width: 640
    height: 480
    title: qsTr("BackEnd")

    SettingsServerCard{
        id: settingsServer
        visible: false
    }

    Button {
        id: button
        x: 37
        y: 26
        text: qsTr("Show Settings Server")

        onClicked:
        {
            if(settingsServer.visible)
            {
                settingsServer.visible = false
                button.text = qsTr("Show Settings Server")
            }
            else
            {
               settingsServer.visible = true
               button.text = qsTr("Hide Settings Server")
            }
        }
    }
}
