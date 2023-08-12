/* ********************************************************************************************** */
/*                                                                                                */
/*   Smart Watch Firmware                                              :::::::::        :::       */
/*   header.h                                                         :+:    :+:     :+: :+:      */
/*                                                                   +:+    +:+    +:+   +:+      */
/*   By: Roman Alexandrov <r.aleksandroff@gmail.com>                +#++:++#:    +#++:++#++:      */
/*                                                                 +#+    +#+   +#+     +#+       */
/*   Created: 2023/06/28 14:49:16                                 #+#    #+#   #+#     #+#        */
/*   Updated: 2023/06/29 18:48:41                                ###    ###   ###     ###         */
/*                                                                                                */
/*                                                                                                */
/* ********************************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266WebServer.h>
#include <ESP8266HTTPClient.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>                                   // drawing User Interface (UI)
#include <Adafruit_SSD1306.h>                               // edited version of the standard Adafruit_SSD1306.h
#include <ArduinoJson.h>
#include <Encoder.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include "bitmap_library.h"
extern "C" {
    #include "user_interface.h"                             // RTC memory read/write functions
}

//#define DEBUG                                               // comment out this line to turn off Serial output
#ifdef DEBUG
  #define DEBUG_PRINT(d) \
          Serial.print(millis()); \
          Serial.print(": "); \
          Serial.print(__FUNCTION__); \
          Serial.print(" in line "); \
          Serial.print(__LINE__); \
          Serial.print(" : "); \
          Serial.println(d);
#else
  #define DEBUG_PRINT(d)
#endif
#define RTCMEMORYSTART  90                                   // RTC memory – starting memory chunk address for rtcValues structure (1 chunk == 4 bytes)
#define SLEEP           17                                   // SLEEP MODE: system wakes up once per second to update clock on display 
#define WORK            66                                   // WORK MODE: system stays awake, all functions available
#define LOWCHARGE       95                                   // LOW CHARGE MODE: system wakes up once per minute to update time, display constantly off
#define INACTIVITY      250                                  // If no controlls were touched within 1 minute, the system goes into Sleep Mode
//#define SLEEPTIME       727320                               // duration of deepSleep in Sleep Mode = 1 second
//#define LOWTIME         60000000                             // duration of deepSleep in Low Charge Mode = 1 minute
#define BUTTON_PIN      4
#define TILT_PIN        5

Encoder myEnc(9, 10);
Adafruit_SSD1306 display(128, 64, &Wire, 1);                // OLED display – SCREEN_WIDTH, SCREEN_HEIGHT, I2C interface, OLED_RESET
ADC_MODE(ADC_VCC);                                          // battery charge measuring
ESP8266WiFiMulti wifiMulti;
WiFiClient client;

typedef struct {
  int             state_switch;                             // value 17 for Sleep mode; 66 for Work mode; 95 for Low Charge; any other value toggles after-power-down recovery
  int             program_cycles;                           // keeps track of time instead of Millis
  short           hour;
  short           minute;
  short           second;
  volatile int    controls_tracker;                         // inactivity timer. Can be changed by Button, Encoder and Tilt Detector
  volatile byte   encoder_counter;                          // encoder
  volatile bool   tilt_switch;                              // tilt detector
} rtcManagementStruc;
rtcManagementStruc rtcMng;                                  // this struct is for bidirectional data transfer between SLEEP and WORK modes via RTC memory

typedef struct {
  volatile long   old_position;                             // encoder
  volatile bool   on_plane;                                 // Airplane Mode flag. 0 == off, 1 == on
  bool            on_planePrevious;
  signed int      time_zone;
  short           day;
  short           week_day;
  short           month;
  int             weather_id;
  signed int      temp;
} rtcStore;
rtcStore rtcValues;                                         // WORK mode RTC memory struct

unsigned short  g_icon_cycle = 1;
const uint32_t  g_connect_timeout = 5000;                                     // Wi-Fi connect timeout per each AP
short           x = 0;
short           y = 0;
const char*     server_name = "https://ap1.unwiredlabs.com/v2/process.php";
const String    token = "pk.051929e8338d2971fa007db8ae5f45fe";                // UnwiredLabs API token 
float           lat = 50.0596696;                                             // default latitude — Prague
float           lon = 14.4656239;                                             // default longitude — Prague
const String    api_key = "876dcc47a263d9592d6512f43f844417";                 // OpenWeather

void  ft_airplane_mode(void);
short ft_battery_level(void);
void  ft_battery_level_ui(short);
void  IRAM_ATTR ft_button_handle(void);
void  ft_calendar_ui(void);
void  ft_default_mode(void);
void  ft_diagnostic_screen_ui(void);
void  IRAM_ATTR ft_encoder_handle(void);
void  ft_get_location(void);
void  ft_get_time(void);
void  ft_get_weather(void);                                          // from OpenWeatherMap.org
void  ft_low_charge_mode(void);
void  ft_maxi_analog_clock_ui(void);                                 // Analog Clock UI -- Full screen (64x128) version
void  ft_mini_analog_clock_ui(void);                                 // Analog Clock UI -- Standard (64x64) version
void  ft_mini_digital_clock_ui(void);                                // Digital Clock UI -- Standard (64x64) version
void  ft_moon_phases_ui(void);
void  ft_power_down_recovery(void);
void  ft_ota_start_and_ui(void);
void  ft_setup_ota(const char* nameprefix, const char* ssid, const char* password);
void  ft_sleep_mode(void);
int   ft_size_x(int r, float alpha);
int   ft_size_y(int r, float alpha);
void  ft_system_clock(void);
void  IRAM_ATTR ft_tilt_detector_handle(void);     
void  ft_weather_ui(void);
void  ft_wifi_init(void);
void  ft_wifi_list(void);

#include "ota_update.h"
#include "airplane_mode.h"
#include "calendar_ui.h"
#include "default_mode.h"
#include "get_location.h"
#include "get_time.h"
#include "get_weather.h"
#include "low_charge_mode.h"
#include "maxi_analog_clock_ui.h"
#include "mini_analog_clock_ui.h"
#include "mini_digital_clock_ui.h"
#include "diagnostic_screen_ui.h"
#include "moon_phases_ui.h"
#include "other.h"
#include "power_down_recovery.h"
#include "sleep_mode.h"
#include "system_clock.h"
#include "weather_ui.h"
#include "wifi_initialize.h"
#include "wifi_list.h"
        
#endif
 
