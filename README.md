# YeelightCPPAPI
Yeelight C++ API is API for Yeelight bulbs. It's created with Qt. You can use YeelightAPITestApp as an example.

## Install
+ Clone the repository.
```
git clone https://github.com/SimonBrandner/YeelightCPPAPI
```
+ Install Qt

## New project
+ Install Qt Creator
+ Create new project in the Qt Creator
+ Add this to your .pro file: `QT += network`
+ Add this to your .pro file: 
```
INCLUDEPATH += "<PATH TO "YeelightCPPAPI" directory>"
LIBS += "PATH TO "YeelightCPPAPI/build/libYeelightCPPAPI.a" file>"
```
Example:
```
INCLUDEPATH += "../YeelightCPPAPI/"
LIBS += "/home/simon/GIT/SmartHome/YeelightCPPAPI.d/YeelightCPPAPI/build/libYeelightCPPAPI.a"
```
