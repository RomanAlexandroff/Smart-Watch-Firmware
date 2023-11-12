/* ********************************************************************************************** */
/*                                                                                                */
/*   Smart Watch Firmware                                              :::::::::        :::       */
/*   diagnostic_screen_ui.cpp                                         :+:    :+:     :+: :+:      */
/*                                                                   +:+    +:+    +:+   +:+      */
/*   By: Roman Alexandrov <r.aleksandroff@gmail.com>                +#++:++#:    +#++:++#++:      */
/*                                                                 +#+    +#+   +#+     +#+       */
/*   Created: 2023/06/28 14:49:16                                 #+#    #+#   #+#     #+#        */
/*   Updated: 2023/11/12 13:48:41                                ###    ###   ###     ###         */
/*                                                                                                */
/*                                                                                                */
/*   The function outputs various diagnostic data onto the display. Initially, it was created     */
/*   solely as a debugging instrument, but turned out to be visually interesting and thus         */
/*   used as an ordinary widget.                                                                  */
/*                                                                                                */
/* ********************************************************************************************** */

#include "header.h"

void  ft_diagnostic_screen_ui(void)
{       
    display.drawLine(64, 51, 64, 12, WHITE);        // DIVIDING LINE BETWEEN THE UPPER AND LOWER SCREEN

    display.setTextSize(1);                         // TIME
    display.setTextColor(WHITE);
    display.setCursor(75, 3);
    display.printf("%d", rtcMng.hour);
        
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(92, 3);
    display.printf("%d", rtcMng.minute);

    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(109, 3);
    display.printf("%d", rtcMng.second);
    
    display.setTextSize(1);                         // ft_weather_ui – ACTUAL TEMPERATURE
    display.setTextColor(WHITE);
    display.setCursor(75, 15);
    display.println(int(rtcValues.temp));

    display.setTextSize(1);                         // ft_weather_ui – CODE FOR ft_weather_ui CONDITIONS
    display.setTextColor(WHITE);
    display.setCursor(109, 15);
    display.println(int(rtcValues.weather_id));

    display.setTextSize(1);                         // PROGRAMM CYCLES COUNTER
    display.setTextColor(WHITE);
    display.setCursor(75, 27);
    display.println(int(rtcMng.program_cycles));

    display.setTextSize(1);                         // ENCODER COUNTER STATUS
    display.setTextColor(WHITE);
    display.setCursor(109, 27);
    display.println(int(rtcMng.encoder_counter));

    display.setTextSize(1);                         // INACTIVITY OF CONTROLLS
    display.setTextColor(WHITE);
    display.setCursor(75, 39);
    display.println(int(rtcMng.controls_tracker));

    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(109, 39);
    display.println(ft_battery_level());            // BATTERY CHARGE LEVEL IN %

    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(75, 51);
    display.printf("v.1-%d%d", rtcValues.day, rtcValues.month);
}
 
