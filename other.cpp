/* ********************************************************************************************** */
/*                                                                                                */
/*   Smart Watch Firmware                                              :::::::::        :::       */
/*   other.cpp                                                        :+:    :+:     :+: :+:      */
/*                                                                   +:+    +:+    +:+   +:+      */
/*   By: Roman Alexandrov <r.aleksandroff@gmail.com>                +#++:++#:    +#++:++#++:      */
/*                                                                 +#+    +#+   +#+     +#+       */
/*   Created: 2023/06/28 14:49:16                                 #+#    #+#   #+#     #+#        */
/*   Updated: 2023/11/12 13:48:41                                ###    ###   ###     ###         */
/*                                                                                                */
/*                                                                                                */
/*   This file contains all the little utility functions that are not too important to have       */
/*   their own personal files. They are not necesarrily connected with each other logically.      */
/*                                                                                                */
/* ********************************************************************************************** */

#include "header.h"

void ft_button_handle(void) 
{            
    rtcMng.controls_tracker = 0;                                           // Wakes up the system
    rtcMng.encoder_counter += 1;
    if (rtcMng.encoder_counter >= 7) rtcMng.encoder_counter = 1;           
}

void ft_encoder_handle(void)
{
    volatile long newPosition = myEnc.read();
    if (newPosition != rtcValues.old_position)
    {
        if (newPosition > rtcValues.old_position) 
        {
            rtcMng.encoder_counter += 1;
            if (rtcMng.encoder_counter >= 7) rtcMng.encoder_counter = 1;
        }
        if (newPosition < rtcValues.old_position)
        {
            rtcMng.encoder_counter -= 1;
            if (rtcMng.encoder_counter <= 0) rtcMng.encoder_counter = 6;
        }
        rtcValues.old_position = newPosition;
        rtcMng.controls_tracker = 0;                                        // Wakes up the system
    }
}

void ft_tilt_detector_handle(void)
{
    rtcMng.tilt_switch = !rtcMng.tilt_switch;
    if (rtcMng.tilt_switch)
        rtcMng.controls_tracker = 0;                                        // Wakes up the system
    if (!rtcMng.tilt_switch)
        rtcMng.controls_tracker = INACTIVITY;                               // Puts the system to sleep
}


// ADC measures VCC level internally. Do not connect ADC pin to anything and leave it floating!
// Full formula to convert ADC measurements into Battery charge percentage %: 
// 100 * (ADC_Reading - Battery_Minimal_Reading) / (Battery_Maximal_Reading - Battery_Minimal_Reading).
// For LiPol Battery, 230mAh, 3.7V: Battery_Maximal_Reading = 4264, Battery_Minimal_Reading = 3235;
// For LiPol Battery, 230mAh, 3.7V: after ADC_Reading decends to the level of Battery_Minimal_Reading, there are 2 mins 12 sec before the battery turns off 

short ft_battery_level(void)
{
    short battery;
    
    battery = ceil((ESP.getVcc() - 3235) / 10.29);                          // Removes fractual part from raw % and makes it a whole number
    if (battery <= 0)
        battery = 0;
    if (battery >= 100)
        battery = 100;
    return (battery);
}

void ft_battery_level_ui(short battery) 
{
    short oldBattery;
    
//    if (oldBattery != battery)
//    {                         // Charging icon toggle on/off
//        if (oldBattery < battery)
//            { ПОКАЗАТЬ_ИКОНКУ_ЗАРЯДКИ; }
//        else
//            { УБРАТЬ_ИКОНКУ_ЗАРЯДКИ; }
//        oldBattery = battery;
//    }
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0, 0);
    display.println(int(battery));
}
 
