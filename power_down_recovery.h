/* ********************************************************************************************** */
/*                                                                                                */
/*   Smart Watch Firmware                                              :::::::::        :::       */
/*   power_down_recovery.h                                            :+:    :+:     :+: :+:      */
/*                                                                   +:+    +:+    +:+   +:+      */
/*   By: Roman Alexandrov <r.aleksandroff@gmail.com>                +#++:++#:    +#++:++#++:      */
/*                                                                 +#+    +#+   +#+     +#+       */
/*   Created: 2023/06/28 14:49:16                                 #+#    #+#   #+#     #+#        */
/*   Updated: 2023/06/29 18:48:41                                ###    ###   ###     ###         */
/*                                                                                                */
/*                                                                                                */
/*   This function resets RTC memory variables after a power loss.                                */
/*                                                                                                */
/* ********************************************************************************************** */

void  ft_power_down_recovery(void)
{
        rtcMng.state_switch = WORK;                                                  // go to Work mode after reboot
        rtcMng.program_cycles = 0;
        rtcMng.controls_tracker = 0;                                                // inactivity timer state
        rtcMng.tilt_switch = 0;
        rtcMng.hour = 0;
        rtcMng.minute = 0;
        rtcMng.second = 0;
        rtcValues.old_position = -999;                                               // encoder
        rtcValues.on_plane = 0;
        rtcValues.on_planePrevious = 0;
        rtcValues.time_zone = 2;                                                     // 2 == time zone correction for Prague
        rtcValues.day = 0;
        rtcValues.week_day = 0;
        rtcValues.month = 0;
        rtcValues.weather_id = 0;
        rtcValues.temp = 0;
        system_rtc_mem_write(64, &rtcMng, sizeof(rtcMng));                          // save variables in RTC memory
        system_rtc_mem_write(RTCMEMORYSTART, &rtcValues, sizeof(rtcValues));        // save variables in RTC memory
        ESP.deepSleep(100, WAKE_RF_DEFAULT);                                        // Reboot, no Wi-Fi sync needed
}
