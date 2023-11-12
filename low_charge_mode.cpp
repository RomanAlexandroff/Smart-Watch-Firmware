/* ********************************************************************************************** */
/*                                                                                                */
/*   Smart Watch Firmware                                              :::::::::        :::       */
/*   low_charge_mode.cpp                                              :+:    :+:     :+: :+:      */
/*                                                                   +:+    +:+    +:+   +:+      */
/*   By: Roman Alexandrov <r.aleksandroff@gmail.com>                +#++:++#:    +#++:++#++:      */
/*                                                                 +#+    +#+   +#+     +#+       */
/*   Created: 2023/06/28 14:49:16                                 #+#    #+#   #+#     #+#        */
/*   Updated: 2023/11/12 13:48:41                                ###    ###   ###     ###         */
/*                                                                                                */
/*                                                                                                */
/*   This mode is designed to prevent loosing RTC variables when battery level is very low.       */
/*   The mode makes the watch act as a powered-down device. In the mode the watch sleeps all      */
/*   the time. Only once per minute it wakes up to check battery level and update time values.    */
/*                                                                                                */
/* ********************************************************************************************** */

#include "header.h"

void  ft_low_charge_mode(void)
{
    display.clearDisplay(); 
    rtcMng.minute += 1;
    ft_system_clock();
    if (ft_battery_level() >= 10)
        rtcMng.state_switch = WORK;
    system_rtc_mem_write(64, &rtcMng, sizeof(rtcMng));             // save variables in RTC memory
    ESP.deepSleep(((60000 - millis()) * 1000), WAKE_RF_DEFAULT);   // go to sleep, keep the work/sleep cycle within 1 minute (60000 millis), no Wi-Fi sync needed
}
