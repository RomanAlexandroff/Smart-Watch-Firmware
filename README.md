# The Smart Watch Firmware

## About the Project
  
This firmware was developed with the goal of providing a simple yet powerful foundation for building a customizable smart watch with some unique features.


## Key Features

Widgets Galore
I've implemented a range of widgets to enhance the functionality of your smart watch. You'll find both analog and digital clocks to suit your personal style, a calendar widget to keep track of important dates, and a weather widget to keep you informed about the current conditions. Additionally, I've included a widget that displays the phases of the Moon, adding a touch of celestial charm to your device.

Power-Save Mode
I understand the importance of maximizing battery life on a wearable device. With my firmware, you can take advantage of a power-save mode that intelligently manages power consumption. Enjoy extended battery life without compromising the core functionality of your smart watch.

Over The Air Firmware Update
Keeping your smart watch up to date has never been easier. I've designed the firmware to support Over The Air (OTA) firmware updates, ensuring that you can easily install the latest features and bug fixes without the need for complicated manual procedures. Stay ahead of the curve and enjoy the benefits of ongoing firmware improvements.

Seamless Wi-Fi Connectivity
Connectivity is a crucial aspect of any smart watch. My firmware provides seamless support for multiple Wi-Fi networks, allowing you to stay connected no matter where you are. Effortlessly switch between networks and enjoy uninterrupted access to online services and data synchronization.

Intuitive User Inputs
Interacting with your smart watch should be a breeze. That's why I've incorporated support for a scroll wheel, a button, and a tilt detector into the firmware. Navigate through menus, scroll through widgets, and trigger actions with ease. Enjoy a seamless user experience that's tailored to your preferences.

Vertical 128x64 Pixels OLED Display
Break away from the traditional horizontal display orientation. My firmware enables you to utilize a 128x64 pixels OLED display vertically, opening up new design possibilities for your smart watch. Custom-made icons and symbols ensure that the display remains clear and easy to read, regardless of its uncommon orientation.
 
 
## Hardware

A single device requires the following components:
- Ai-Thinker ESP–01M module;
- OLED display, 128x64, SSD1306 controller, white pixels, I2C bus;
- LiPol Battery, 230mAh, 3.7V;
- Rotary encoder;
- Button;
- SW-520D tilt detector; 

 
## Contributions
 
Contributions to the project are welcome! If you have any enhancements, bug fixes, or new features to contribute, please submit a pull request. Additionally, feel free to open issues for any questions, suggestions, or bug reports.

 
## License

This firmware is released under the MIT License. Please review the license file for more details.  
 

## Example of the credentials.h File

```  
const String token = "xx.xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";   // UnwiredLabs API token
const String api_key = "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";    // OpenWeather API key

#define SSID1         "home_wifi_name"
#define PASSWORD1     "home_wifi_password"
    
#define SSID2         "university_wifi_name"
#define PASSWORD2     "university_wifi_password"
    
#define SSID3         "office_wifi_name"
#define PASSWORD3     "office_wifi_password"
```
 
 
## Calculating Constants for the Battery Charge Function

You will need to check the following little utility:
https://github.com/RomanAlexandroff/ESP-Battery-Charge-Utility
      
It was designed to be a universal solution for battery charge level detection in ESP-based projects and has all the instructions inside of it.