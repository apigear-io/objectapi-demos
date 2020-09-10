import QtQuick 2.14
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import apigear.calc 1.0

ApplicationWindow {
    id: root
    visible: true
    width: 320
    height: 320
    title: qsTr("Calculator")

    Calculator {
        id: calc
    }

    property string operation
    property string display

    GridLayout {
        anchors.fill: parent
        columns: 4
        TextField {
            id: field
            Layout.columnSpan: 3
            Layout.fillWidth: true
            focus: true
        }

        Button {
            text: 'CLEAR'
            Layout.fillWidth: true
            onClicked: root.process(text)
        }
        Button {
            text: 'DIV'
            Layout.fillWidth: true
            onClicked: root.process(text)
        }
        Button {
            text: 'MUL'
            Layout.fillWidth: true
            onClicked: root.process(text)
        }
        Button {
            text: 'SUB'
            Layout.fillWidth: true
            onClicked: root.process(text)
        }
        Button {
            text: 'ADD'
            Layout.fillWidth: true
            onClicked: root.process(text)
        }
        ListView {
            id: view
            model: ListModel {}
            Layout.columnSpan: 4
            Layout.fillWidth: true
            Layout.fillHeight: true
            delegate: ItemDelegate {
                text: model.text
                width: ListView.view.width
            }

        }
    }

    function process(op) {
        var num = parseInt(field.text)
        switch(op) {
        case 'CLEAR':
            calc.clear()
            break
        case 'MUL':
            calc.multiply(num)
            break
        case 'DIV':
            calc.divide(num)
            break
        case 'ADD':
            calc.add(num)
            break
        case 'SUB':
            calc.substract(num)
            break
        }
        view.model.append({text: calc.total.toString()})
        field.text = ''
        field.focus = true
    }
}
