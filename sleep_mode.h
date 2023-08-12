/* ********************************************************************************************** */
/*                                                                                                */
/*   Smart Watch Firmware                                              :::::::::        :::       */
/*   sleep_mode.h                                                     :+:    :+:     :+: :+:      */
/*                                                                   +:+    +:+    +:+   +:+      */
/*   By: Roman Alexandrov <r.aleksandroff@gmail.com>                +#++:++#:    +#++:++#++:      */
/*                                                                 +#+    +#+   +#+     +#+       */
/*   Created: 2023/06/28 14:49:16                                 #+#    #+#   #+#     #+#        */
/*   Updated: 2023/06/29 18:48:41                                ###    ###   ###     ###         */
/*                                                                                                */
/*                                                                                                */
/*   This mode turns on during the user's incativity. It shows full-screen analog clock and       */
/*   updates it once every minute. The mode is adapted to be as power-saving as possible, so      */
/*   everything Wi-Fi related is unavailable. In this mode the watch sleeps almost all the time.  */
/*                                                                                                */
/* ********************************************************************************************** */

void  ft_sleep_mode(void)
{
    int sleep_time;

    ft_encoder_handle();
    ft_system_clock();
    if (rtcMng.second == 0)
    {
        if (ft_battery_level() < 10)
            rtcMng.state_switch = LOWCHARGE; 
    }
    display.clearDisplay();
    ft_maxi_analog_clock_ui();  
    display.display();
    ft_encoder_handle();
    if (rtcMng.state_switch != LOWCHARGE && rtcMng.controls_tracker == 0)
        rtcMng.state_switch = WORK;
    system_rtc_mem_write(64, &rtcMng, sizeof(rtcMng));        // save variables in RTC memory
    sleep_time = (1000 - millis()) * 1000;
    ESP.deepSleep(sleep_time, WAKE_RF_DEFAULT);               // go to sleep, keep the work/sleep cycle within 1 second (1000 millis), no Wi-Fi sync needed
}
 
