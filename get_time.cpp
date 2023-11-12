/* ********************************************************************************************** */
/*                                                                                                */
/*   Smart Watch Firmware                                              :::::::::        :::       */
/*   get_time.cpp                                                     :+:    :+:     :+: :+:      */
/*                                                                   +:+    +:+    +:+   +:+      */
/*   By: Roman Alexandrov <r.aleksandroff@gmail.com>                +#++:++#:    +#++:++#++:      */
/*                                                                 +#+    +#+   +#+     +#+       */
/*   Created: 2023/06/28 14:49:16                                 #+#    #+#   #+#     #+#        */
/*   Updated: 2023/11/12 13:48:41                                ###    ###   ###     ###         */
/*                                                                                                */
/*                                                                                                */
/*   This sketch retrieves time values from the Google server and adapts them for further use.    */
/*                                                                                                */
/* ********************************************************************************************** */

#include "header.h"

void  ft_get_time(void)
{
    int     i;
    String  line;
    String  getWeekDay;
    String  getMonth;

    i = 0;
    DEBUG_PRINT("ft_get_time function BEGIN");
    if (!client.connect("www.google.com", 80))
    {
        DEBUG_PRINT("Google server connection FAILED");
        return;
    }
    DEBUG_PRINT("Google server connection SUCCESS");
    client.print(String("GET / HTTP/1.1\r\n") +
        String("Host: www.google.com\r\n") +
        String("Connection: close\r\n\r\n"));           
    while (!client.available() && i < 10)
    {
        delay(500);
        DEBUG_PRINT("Retreiving data...");
        i++;
    }
    client.setNoDelay(false);
    while (client.connected() && client.available())
    {
        line = client.readStringUntil('\n');
        line.toUpperCase();
        if (line.startsWith("DATE: "))
        {
            getWeekDay = line.substring(6, 9);
            rtcValues.day = line.substring(11, 13).toInt();
            getMonth = line.substring(14, 17);
            rtcMng.hour = (line.substring(23, 25).toInt()) + rtcValues.time_zone;
            rtcMng.minute = line.substring(26, 28).toInt();
            rtcMng.second = line.substring(29, 31).toInt();
            if (getWeekDay == "MON") rtcValues.week_day = 1;                           // Adapting data for ft_system_clock – days of the week
            if (getWeekDay == "TUE") rtcValues.week_day = 2;
            if (getWeekDay == "WED") rtcValues.week_day = 3;
            if (getWeekDay == "THU") rtcValues.week_day = 4;
            if (getWeekDay == "FRI") rtcValues.week_day = 5;
            if (getWeekDay == "SAT") rtcValues.week_day = 6;
            if (getWeekDay == "SUN") rtcValues.week_day = 7;
            if (getMonth == "JAN") rtcValues.month = 1;                               // Adapting data for ft_system_clock – months
            if (getMonth == "FEB") rtcValues.month = 2;
            if (getMonth == "MAR") rtcValues.month = 3;
            if (getMonth == "APR") rtcValues.month = 4;
            if (getMonth == "MAY") rtcValues.month = 5;
            if (getMonth == "JUN") rtcValues.month = 6;
            if (getMonth == "JUL") rtcValues.month = 7;
            if (getMonth == "AUG") rtcValues.month = 8;
            if (getMonth == "SEP") rtcValues.month = 9;
            if (getMonth == "OCT") rtcValues.month = 10;
            if (getMonth == "NOV") rtcValues.month = 11;
            if (getMonth == "DEC") rtcValues.month = 12;
            if (rtcValues.month >= 11 || rtcValues.month <= 3)                        // winter time correction
                rtcMng.hour -= 1;
            DEBUG_PRINT("Data retrieved: ");
            DEBUG_PRINT(rtcMng.hour);
            DEBUG_PRINT(rtcMng.minute);
            DEBUG_PRINT(rtcMng.second);
            DEBUG_PRINT(getWeekDay);
            DEBUG_PRINT(getMonth);
        }
    }
    DEBUG_PRINT("ft_get_time function FINISHED");
}
 
