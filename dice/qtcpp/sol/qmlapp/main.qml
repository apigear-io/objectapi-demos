import QtQuick 2.14
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import apigear.game 1.0

ApplicationWindow {
    id: root
    visible: true
    width: 320
    height: 320
    title: qsTr("Dice")

    Dice {
        id: dice
    }

    property string operation
    property string display

    GridLayout {
        anchors.fill: parent
        columns: 4
        Label {
            id: field
            Layout.columnSpan: 4
            Layout.fillWidth: true
            text: dice.value.toString()
            font.pixelSize: 96
            horizontalAlignment: Text.AlignHCenter
        }

        Button {
            text: 'TOSS'
            Layout.columnSpan: 4
            Layout.fillWidth: true
            Layout.fillHeight: true
            onClicked: dice.toss()
        }
    }
}
