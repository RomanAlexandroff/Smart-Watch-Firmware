/* ********************************************************************************************** */
/*                                                                                                */
/*   Smart Watch Firmware                                              :::::::::        :::       */
/*   ota_update.h                                                     :+:    :+:     :+: :+:      */
/*                                                                   +:+    +:+    +:+   +:+      */
/*   By: Roman Alexandrov <r.aleksandroff@gmail.com>                +#++:++#:    +#++:++#++:      */
/*                                                                 +#+    +#+   +#+     +#+       */
/*   Created: 2022/07/03 11:28:16                                 #+#    #+#   #+#     #+#        */
/*   Updated: 2023/03/15 23:08:41                                ###    ###   ###     ###         */
/*                                                                                                */
/*                                                                                                */
/*   Support file for Over The Air firmware update.                                               */
/*                                                                                                */
/* ********************************************************************************************** */

#include <ESP8266mDNS.h>                                      // does not work if included in header
#include <WiFiUdp.h>
#include <ArduinoOTA.h>

void  ft_setup_ota(const char* nameprefix, const char* ssid, const char* password) 
{
    uint16_t  maxlen;
    char*     fullhostname;
    uint8_t   mac[6];
    
    // Configure the hostname
    maxlen = strlen(nameprefix) + 7;
    fullhostname = new char[maxlen];
    WiFi.macAddress(mac);
    snprintf(fullhostname, maxlen, "%s-%02x%02x%02x", nameprefix, mac[3], mac[4], mac[5]);
    ArduinoOTA.setHostname(fullhostname);
    delete[] fullhostname;

  // Port defaults to 3232
  // ArduinoOTA.setPort(3232); // Use 8266 port if you are working in Sloeber IDE, it is fixed there and not adjustable

  // No authentication by default
  // ArduinoOTA.setPassword("admin");

  // Password can be set with it's md5 value as well
  // MD5(admin) = 21232f297a57a5a743894a0e4a801fc3
  // ArduinoOTA.setPasswordHash("21232f297a57a5a743894a0e4a801fc3");

    ArduinoOTA.onStart([]() {
	      //NOTE: make .detach() here for all functions called by Ticker.h library - not to interrupt transfer process in any way.
        String type;
        if (ArduinoOTA.getCommand() == U_FLASH)
            type = "sketch";
        else // U_SPIFFS
            type = "filesystem";

        // NOTE: if updating SPIFFS this would be the place to unmount SPIFFS using SPIFFS.end()
        DEBUG_PRINT("Start updating " + type);
    });
  
    ArduinoOTA.onEnd([]() {
        display.clearDisplay();
        ft_mini_analog_clock_ui();
        display.drawLine(64, 51, 64, 12, WHITE);
        display.drawBitmap(93, 37, bit_O, 7, 5, WHITE);
        display.drawBitmap(93, 29, bit_T, 7, 5, WHITE);
        display.drawBitmap(93, 21, bit_A, 7, 5, WHITE);
        display.drawBitmap(106, 51, bit_C, 7, 5, WHITE);
        display.drawBitmap(106, 45, bit_O, 7, 5, WHITE);
        display.drawBitmap(106, 39, bit_M, 7, 5, WHITE); 
        display.drawBitmap(106, 33, bit_P, 7, 5, WHITE);
        display.drawBitmap(106, 26, bit_L, 7, 5, WHITE);
        display.drawBitmap(106, 20, bit_E, 7, 5, WHITE);
        display.drawBitmap(106, 14, bit_T, 7, 5, WHITE);
        display.drawBitmap(106, 8, bit_E, 7, 5, WHITE);
        display.display();
        DEBUG_PRINT("\nEnd");
    });
  
    ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
        display.clearDisplay();
        ft_mini_analog_clock_ui();
        display.drawLine(64, 51, 64, 12, WHITE);
        display.drawBitmap(93, 37, bit_O, 7, 5, WHITE);
        display.drawBitmap(93, 29, bit_T, 7, 5, WHITE);
        display.drawBitmap(93, 21, bit_A, 7, 5, WHITE);
        display.drawRoundRect(106, 11, 7, 40, 4, WHITE);                                                            // loading outline
        display.fillRoundRect(106, (51 - (40 * progress / total)), 7, (40 * progress / total), 4, WHITE);           // loading
        display.display();
        DEBUG_PRINT("Progress: "); DEBUG_PRINT(progress);
    });
  
    ArduinoOTA.onError([](ota_error_t error) {
        display.clearDisplay();
        ft_mini_analog_clock_ui();
        display.drawLine(64, 51, 64, 12, WHITE);
        display.drawBitmap(93, 37, bit_O, 7, 5, WHITE);
        display.drawBitmap(93, 29, bit_T, 7, 5, WHITE);
        display.drawBitmap(93, 21, bit_A, 7, 5, WHITE);
        display.drawBitmap(106, y+44, bit_E, 7, 5, WHITE); 
        display.drawBitmap(106, y+37, bit_R, 7, 5, WHITE);
        display.drawBitmap(106, y+30, bit_R, 7, 5, WHITE);
        display.drawBitmap(106, y+23, bit_O, 7, 5, WHITE);
        display.drawBitmap(106, y+16, bit_R, 7, 5, WHITE);
        display.display();
        DEBUG_PRINT("Error: "); DEBUG_PRINT(error);
        if (error == OTA_AUTH_ERROR)
            DEBUG_PRINT("\nAuth Failed");
        if (error == OTA_BEGIN_ERROR)
            DEBUG_PRINT("\nBegin Failed");
        if (error == OTA_CONNECT_ERROR)
            DEBUG_PRINT("\nConnect Failed");
        if (error == OTA_RECEIVE_ERROR)
            DEBUG_PRINT("\nReceive Failed");
        if (error == OTA_END_ERROR)
            DEBUG_PRINT("\nEnd Failed");
    });

    ArduinoOTA.begin();

    DEBUG_PRINT("OTA Initialized");
    DEBUG_PRINT("IP address: "); DEBUG_PRINT(WiFi.localIP());
}

void  ft_ota_start_and_ui(void)
{
    if (g_icon_cycle > 15 || g_icon_cycle < 1)
        g_icon_cycle = 1; 
    ArduinoOTA.handle();
    rtcMng.controls_tracker = 0;                                           // Keeps the system awake during OTA
    display.drawLine(64, 51, 64, 12, WHITE);
    display.drawBitmap(93, 37, bit_O, 7, 5, WHITE);
    display.drawBitmap(93, 29, bit_T, 7, 5, WHITE);
    display.drawBitmap(93, 21, bit_A, 7, 5, WHITE);
    display.drawRoundRect(106, 11, 7, 40, 4, WHITE);
    if (g_icon_cycle == 1 || g_icon_cycle == 2)
        display.fillRect(109, 38, 1, 2, WHITE);
    if (g_icon_cycle == 3 || g_icon_cycle == 4)
        display.fillRect(109, 30, 1, 2, WHITE);
    if (g_icon_cycle == 5 || g_icon_cycle == 6)
        display.fillRect(109, 22, 1, 2, WHITE);
    g_icon_cycle++;
}
 
