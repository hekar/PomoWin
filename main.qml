import QtQuick 2.4
import QtQuick.Window 2.2
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4

ApplicationWindow {
    id: window
    flags: Qt.FramelessWindowHint
    visible: true
    title: qsTr("PomoWin")
    width: 284
    height: 142
    x: (Screen.width - width - 12)
    y: 24
    color: "transparent"

    Rectangle {
        color: "#000000"
        anchors.fill: parent

        Text {
            objectName: "title"
            x: 12
            y: 12
            width: 96
            height: 24
            text: "PomoWin"
            font.family: "Calibri,Droid Sans,Helvetica,Arial"
            color: "#fff"
            font.pointSize: 12
        }

        Button {
            objectName: "timer"
            x: 12
            y: 36
            width: 96
            height: 96
            text: "fadsfsdf"

            style: ButtonStyle {
                label: Text {
                    renderType: Text.NativeRendering
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                    font.family: "Calibri,Droid Sans,Helvetica,Arial"
                    font.pointSize: 18
                    color: "#fff"
                    text: control.text
                }

                background: Rectangle {
                    border.width: 1
                    border.color: control.activeFocus ? "#abb4bb" : "#abb4bb"
                    radius: 0
                    color: control.pressed ? "#730" : "#000000"
                }
            }
        }

        Button {
            id: close
            objectName: "close"
            x: 224
            y: 0
            width: 42
            height: 28

            style: ButtonStyle {
                label: Image {
                    source: "resources/app_close.png"
                    smooth: true
                    anchors.centerIn: parent
                    fillMode: Image.Pad
                }

                background: Rectangle {
                    radius: 0
                    color: control.activeFocus || control.pressed ? "#AC193D" : "#000000"
                }
            }
        }

        Button {
            objectName: "short_break"
            x: 132
            y: 36
            width: 48
            height: 48

            style: ButtonStyle {
                label: Image {
                    source: "resources/show_break.png"
                    smooth: true
                    anchors.centerIn: parent
                    fillMode: Image.Pad
                }

                background: Rectangle {
                    radius: 0
                    border.width: 2
                    border.color: control.pressed ? "#2672EC" : (control.activeFocus ? "#abb4bb" : "#000")
                    color: control.pressed ? "#2672EC" : "#000000"
                }
            }
        }

        Button {
            objectName: "start"
            x: 196
            y: 36
            width: 48
            height: 48

            style: ButtonStyle {
                label: Image {
                    source: "resources/start.png"
                    smooth: true
                    anchors.centerIn: parent
                    fillMode: Image.Pad
                }

                background: Rectangle {
                    radius: 0
                    border.width: 2
                    border.color: control.pressed ? "#BF1E4B" : (control.activeFocus ? "#abb4bb" : "#000")
                    color: control.pressed ? "#BF1E4B" : "#000"
                }
            }
        }

        Button {
            objectName: "long_break"
            x: 132
            y: 84
            width: 48
            height: 48

            style: ButtonStyle {
                label: Image {
                    source: "resources/long_break.png"
                    smooth: true
                    anchors.centerIn: parent
                    fillMode: Image.Pad
                }

                background: Rectangle {
                    radius: 0
                    border.width: 2
                    border.color: control.pressed ? "#094AB2" : (control.activeFocus ? "#abb4bb" : "#000")
                    color: control.pressed ? "#094AB2" : "#000"
                }
            }
        }

        Button {
            objectName: "pin"
            x: 196
            y: 84
            width: 48
            height: 48
            checked: true
            checkable: true

            style: ButtonStyle {
                label: Image {
                    source: "resources/pin.png"
                    smooth: true
                    anchors.centerIn: parent
                    fillMode: Image.Pad
                }

                background: Rectangle {
                    border.width: 2
                    border.color: control.activeFocus || control.pressed ? "#abb4bb" : "#000"
                    radius: 0
                    color: control.checked ? "#0A5BC4" : "#000000"
                }
            }
        }
    }
}
