/* ********************************************************************************************** */
/*                                                                                                */
/*   Smart Watch Firmware                                              :::::::::        :::       */
/*   Smart_Watch_Firmware.ino (main file)                             :+:    :+:     :+: :+:      */
/*                                                                   +:+    +:+    +:+   +:+      */
/*   By: Roman Alexandrov <r.aleksandroff@gmail.com>                +#++:++#:    +#++:++#++:      */
/*                                                                 +#+    +#+   +#+     +#+       */
/*   Created: 2022/07/03 11:28:16                                 #+#    #+#   #+#     #+#        */
/*   Updated: 2023/03/15 23:08:41                                ###    ###   ###     ###         */
/*                                                                                                */
/*                                                                                                */
/*   The main file of the project.                                                                */
/*   TARGETED HARDWARE:                                                                           */
/*      Ai-Thinker ESP–01M module;                                                                */
/*      OLED display, 128x64, controller SSD1306, white pixels, I2C bus;                          */
/*      LiPol Battery, 230mAh, 3.7V;                                                              */
/*      Rotary encoder;                                                                           */
/*      Button [ VCC———INTERNAL_PULLUP_RESISTOR———GPIO———BUTTON———GND ];                          */
/*      SW-520D tilt detector;                                                                    */
/*                                                                                                */
/*   NOTES:                                                                                       */
/*      ESP–01M does not support external interrupt for deep sleep wake up.                       */
/*      System wakes itself up with timer & checks controlls status.                              */
/*                                                                                                */
/* ********************************************************************************************** */

#include "header.h"

void setup(void)
{
    #ifdef DEBUG
        Serial.begin(115200);
    #endif 
    DEBUG_PRINT("Power ON");
    pinMode(BUTTON_PIN, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), ft_button_handle, FALLING);
    pinMode(TILT_PIN, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(TILT_PIN), ft_tilt_detector_handle, CHANGE);
    Wire.begin(2,0);                                                                      // I2C display interface initialisation (SDA pin; SCK pin)
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);                                            // OLED display initialisation (ssd1306 128x64)
    system_rtc_mem_read(64, &rtcMng, sizeof(rtcMng));                                     // restore variables from RTC memory after reboot
    display.clearDisplay();
    if (rtcMng.stateSwitch == WORK) 
        ft_default_mode();
    else if (rtcMng.stateSwitch == SLEEP)
        ft_sleep_mode();
    else if (rtcMng.stateSwitch == LOWCHARGE) 
        ft_low_charge_mode();
    else
        ft_power_down_recovery();
}

void loop(void) { /* NOTHING IS HERE */ }                                                                               
 
