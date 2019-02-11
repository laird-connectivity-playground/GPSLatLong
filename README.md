# Laird GPSLatLong

## About

This is a small, simple application which was used for range testing Laird BL654 modules. It is a simple Qt-based application which runs on Android devices and is used to note the location of a range test which can be then be exported for further analysis or processing. Note that the android application itself does not make any Bluetooth connections and requires an external device (for testing, two BL654 modules were used), this application is only for getting the GPS location that a module was able to communicate at.

No support is provided for this project. The code is available under the GPLv3 license and it is hoped that it may be of use to you.

To minimise interferance when testing, it is advised to turn all other 2.4GHz radios off on devices which are not being used for range testing, including Wi-Fi and Bluetooth on the Android device.

## Usage

To use, install the APK on an android device, enable location services and launch it. There will be 4 radio buttons and an input text box, select the desired radio button to indicate which data rate is being tested, and type a message in the input box to indicate what is being tested and what has happened, e.g. +8dBm connection lost, then hit the "Get Location" button to fetch the current location and add a message into the text view. Continue until testing has finished. Once finished, the data can be exported to another application (e.g. an email application) by clicking the "Export to Clipboard" button, you can then paste the data and use it as desired.

## Releases

A pre-built Android ARMv7a APK is provided under the [Releases](https://github.com/laird-connectivity-playground/GPSLatLong/releases) tab.

## License

GPSLatLong is released under the [GPLv3 license](https://github.com/laird-connectivity-playground/GPSLatLong/blob/master/LICENSE).