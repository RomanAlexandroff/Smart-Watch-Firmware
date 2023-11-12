/* ********************************************************************************************** */
/*                                                                                                */
/*   Smart Watch Firmware                                              :::::::::        :::       */
/*   globals.h                                                        :+:    :+:     :+: :+:      */
/*                                                                   +:+    +:+    +:+   +:+      */
/*   By: Roman Alexandrov <r.aleksandroff@gmail.com>                +#++:++#:    +#++:++#++:      */
/*                                                                 +#+    +#+   +#+     +#+       */
/*   Created: 2023/10/31 14:49:16                                 #+#    #+#   #+#     #+#        */
/*   Updated: 2023/11/12 13:48:41                                ###    ###   ###     ###         */
/*                                                                                                */
/*                                                                                                */
/*   Global variables and objects declaration                                                     */
/*                                                                                                */
/* ********************************************************************************************** */

#ifndef GLOBALS_H_
#define GLOBALS_H_

#include <Encoder.h>
#include <Adafruit_SSD1306.h>                               // edited version of the standard Adafruit_SSD1306.h
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266WebServer.h>
#include "credentials.h"

extern Encoder myEnc;
extern Adafruit_SSD1306 display;
extern ESP8266WiFiMulti wifiMulti;
extern WiFiClient client;

typedef struct {
  int             state_switch;                   // value 17 for Sleep mode; 66 for Work mode; 95 for Low Charge; any other value toggles after-power-down recovery
  int             program_cycles;                 // keeps track of time instead of Millis
  short           hour;
  short           minute;
  short           second;
  volatile int    controls_tracker;               // inactivity timer
  volatile byte   encoder_counter;                // encoder
  volatile bool   tilt_switch;                    // tilt detector
} rtcManagementStruc;
extern rtcManagementStruc rtcMng;                 // this struct is for bidirectional data transfer between SLEEP and WORK modes via RTC memory

typedef struct {
  volatile long   old_position;                   // encoder
  signed int      time_zone;
  short           day;
  short           week_day;
  short           month;
  int             weather_id;
  signed int      temp;
} rtcStore;
extern rtcStore rtcValues;                        // WORK mode RTC memory struct

extern unsigned short  g_icon_cycle;
extern short           x;
extern short           y;
extern float           lat;                       // default latitude — Prague
extern float           lon;                       // default longitude — Prague

#endif
 
