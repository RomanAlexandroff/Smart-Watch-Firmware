/* ********************************************************************************************** */
/*                                                                                                */
/*   Smart Watch Firmware                                              :::::::::        :::       */
/*   globals.cpp                                                      :+:    :+:     :+: :+:      */
/*                                                                   +:+    +:+    +:+   +:+      */
/*   By: Roman Alexandrov <r.aleksandroff@gmail.com>                +#++:++#:    +#++:++#++:      */
/*                                                                 +#+    +#+   +#+     +#+       */
/*   Created: 2023/10/31 14:49:16                                 #+#    #+#   #+#     #+#        */
/*   Updated: 2023/11/12 13:48:41                                ###    ###   ###     ###         */
/*                                                                                                */
/*                                                                                                */
/*   Global variables and objects initialization                                                  */
/*                                                                                                */
/* ********************************************************************************************** */

#include "globals.h"

Encoder myEnc(9, 10);
Adafruit_SSD1306 display(128, 64, &Wire, 1);      // OLED display – SCREEN_WIDTH, SCREEN_HEIGHT, I2C interface, OLED_RESET
ADC_MODE(ADC_VCC);                                // battery charge measuring congig
ESP8266WiFiMulti wifiMulti;
WiFiClient client;

rtcManagementStruc rtcMng;
rtcStore rtcValues;

unsigned short  g_icon_cycle = 1;
short           x = 0;
short           y = 0;
float           lat = 50.0596696;                  // default latitude — Prague
float           lon = 14.4656239;                  // default longitude — Prague
 
