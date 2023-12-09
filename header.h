/* ********************************************************************************************** */
/*                                                                                                */
/*   Smart Watch Firmware                                              :::::::::        :::       */
/*   header.h                                                         :+:    :+:     :+: :+:      */
/*                                                                   +:+    +:+    +:+   +:+      */
/*   By: Roman Alexandrov <r.aleksandroff@gmail.com>                +#++:++#:    +#++:++#++:      */
/*                                                                 +#+    +#+   +#+     +#+       */
/*   Created: 2023/06/28 14:49:16                                 #+#    #+#   #+#     #+#        */
/*   Updated: 2023/11/12 13:48:41                                ###    ###   ###     ###         */
/*                                                                                                */
/*                                                                                                */
/* ********************************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <ESP8266HTTPClient.h>
#include <ESP8266mDNS.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>
#include <ArduinoJson.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include "bitmap_library.h"
extern "C" {
    #include "user_interface.h"                             // RTC memory read/write functions
}
#include "globals.h"

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
#define CONNECT_TIMEOUT 5000                                 // WiFi timeout per each AP, in milliseconds. Increase if cannot connect.
#define BUTTON_PIN      4
#define TILT_PIN        5

short       ft_battery_level(void);
void        ft_battery_level_ui(short);
void        IRAM_ATTR ft_button_handle(void);
void        ft_calendar_ui(void);
void        ft_default_mode(void);
void        ft_diagnostic_screen_ui(void);
void        IRAM_ATTR ft_encoder_handle(void);
//void        ft_get_location(void);                                // yet in production
static void ft_time_correction(void);
void        ft_get_time(void);
void        ft_get_weather(void);
void        ft_low_charge_mode(void);
void        ft_maxi_analog_clock_ui(void);
void        ft_mini_analog_clock_ui(void);
void        ft_mini_digital_clock_ui(void);
void        ft_moon_phases_ui(void);
void        ft_power_down_recovery(void);
void        ft_ota_start_and_ui(short battery_charge);
void        ft_setup_ota(const char* nameprefix, const char* ssid, const char* password);
void        ft_sleep_mode(void);
int         ft_size_x(int r, float alpha);
int         ft_size_y(int r, float alpha);
void        ft_system_clock(void);
void        IRAM_ATTR ft_tilt_detector_handle(void);     
void        ft_weather_ui(void);
void        ft_wifi_init(void);
void        ft_wifi_list(void);

#endif
 
