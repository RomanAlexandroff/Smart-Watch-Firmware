/* ********************************************************************************************** */
/*                                                                                                */
/*   Smart Watch Firmware                                              :::::::::        :::       */
/*   airplane_mode.h                                                  :+:    :+:     :+: :+:      */
/*                                                                   +:+    +:+    +:+   +:+      */
/*   By: Roman Alexandrov <r.aleksandroff@gmail.com>                +#++:++#:    +#++:++#++:      */
/*                                                                 +#+    +#+   +#+     +#+       */
/*   Created: 2023/06/28 14:49:16                                 #+#    #+#   #+#     #+#        */
/*   Updated: 2023/06/29 18:48:41                                ###    ###   ###     ###         */
/*                                                                                                */
/*                                                                                                */
/*   This sketch was intended to cut any radio comunication in case Airplane mode was on.         */
/*   During the development it was discovered that Wi-Fi signals are too weak to influence        */
/*   an airplane in any way, so the development of the function was stopped. The function         */
/*   yet could be useful in energy saving situations, so its development may later continue.      */
/*                                                                                                */
/* ********************************************************************************************** */

/*
void  ft_airplane_mode(void) 
{
    if (rtcValues.onPlane != rtcValues.onPlanePrevious) 
    {
        if (rtcValues.onPlane == 1)
        {
            if (клиент активен, то) client.stop(); //нужно ли это вообще?
            if (вай-фай модуль активен, то) вай-фай модуль стоп
        }
        if (rtcValues.onPlane == 0)
        {
            system_rtc_mem_write(64, &rtcMng, sizeof(rtcMng));                             // Save variables for Sleep Mode in RTC memory
            system_rtc_mem_write(RTCMEMORYSTART, &rtcValues, sizeof(rtcValues));           // Save variables for Work Mode in RTC memory
            ESP.deepSleep(10, WAKE_RF_DEFAULT);                                            // Exit infinite while loop with reboot, WI-FI MODULE ON
        }
    }
    if (rtcValues.onPlane == 1 && rtcMng.encoderCounter == 5)
        покажи большую икону "режим В Самолёте включён"
    if (rtcMng.encoderCounter == 5 && rtcValues.onPlane == 0)
        покажи большую икону "режим В Самолёте выключен"
    if (rtcValues.onPlane == 1)
        покажи маленькую икону "режим В Самолёте включён"
    rtcValues.onPlanePrevious = rtcValues.onPlane; 
} */
 
