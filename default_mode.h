/* ********************************************************************************************** */
/*                                                                                                */
/*   Smart Watch Firmware                                              :::::::::        :::       */
/*   default_mode.h                                                   :+:    :+:     :+: :+:      */
/*                                                                   +:+    +:+    +:+   +:+      */
/*   By: Roman Alexandrov <r.aleksandroff@gmail.com>                +#++:++#:    +#++:++#++:      */
/*                                                                 +#+    +#+   +#+     +#+       */
/*   Created: 2023/06/28 14:49:16                                 #+#    #+#   #+#     #+#        */
/*   Updated: 2023/06/29 18:48:41                                ###    ###   ###     ###         */
/*                                                                                                */
/*                                                                                                */
/*   Default working mode. Calls necessary functions to gather or manage information, then        */
/*   outputs that information onto a screen in a shape of 64x64 pixels widgets.                   */
/*                                                                                                */
/* ********************************************************************************************** */

void  ft_default_mode(void)
{
    unsigned long millis_counter_1;
    unsigned long millis_counter_2;

    millis_counter_1 = 0;
    millis_counter_2 = 0;
    system_rtc_mem_read(RTCMEMORYSTART, &rtcValues, sizeof(rtcValues));                   // restore variables from RTC memory
    ft_wifi_init();
    ft_get_location();                                                                          
    ft_get_weather();                                      
    ft_get_time();
    ft_setup_ota("Roman's Watch", WiFi.SSID().c_str(), WiFi.psk().c_str());
    while (1) 
    {
        if (millis() - millis_counter_1 > 995)
        {
            ft_system_clock();
            rtcMng.programmCycles++;
            millis_counter_1 = millis(); 
        }
        if (millis() - millis_counter_2 > 350)                                               // loop & display update delay
        {
            ft_encoder_handle();
            display.clearDisplay();
            if ((rtcMng.programmCycles % 1200 == 0) && rtcValues.onPlane == 0)             // toggle these functions once every 20 mins 
            {
                ft_get_location();                                                                          
                ft_get_weather();                                       
                ft_get_time();      
            }
//            ft_battery_level_ui(ft_battery_level());
            if (rtcMng.second == 0)
            {
                if (ft_battery_level() < 10)
                    rtcMng.stateSwitch = LOWCHARGE; 
            }
            switch (rtcMng.encoderCounter) 
            {
                case 1:   ft_mini_analog_clock_ui();      ft_mini_digital_clock_ui(); break;
                case 2:   ft_mini_analog_clock_ui();      ft_calendar_ui();           break;
                case 3:   ft_mini_analog_clock_ui();      ft_weather_ui();            break;
                case 4:   ft_mini_analog_clock_ui();      ft_moon_phases_ui();        break;
                case 5:   ft_mini_analog_clock_ui();      ft_ota_start_and_ui();      break; 
                case 6:   ft_mini_analog_clock_ui();      ft_diagnostic_screen_ui();  break;
            }
            display.display();
            rtcMng.controllsTracker++;
            ft_encoder_handle();
            millis_counter_2 = millis();
        }
        if (rtcMng.controllsTracker == INACTIVITY || rtcMng.stateSwitch == LOWCHARGE)      // Go to Sleep Mode if inactive or low battery 
        {
            rtcMng.stateSwitch = SLEEP;
            system_rtc_mem_write(64, &rtcMng, sizeof(rtcMng));                             // save variables for Sleep Mode in RTC memory
            system_rtc_mem_write(RTCMEMORYSTART, &rtcValues, sizeof(rtcValues));           // save variables for Work Mode in RTC memory
            ESP.deepSleep(100, WAKE_RF_DEFAULT);                                           // exit infinite while loop with reboot, no Wi-Fi sync needed
        }
    }
}
 
