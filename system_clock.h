/* ********************************************************************************************** */
/*                                                                                                */
/*   Smart Watch Firmware                                              :::::::::        :::       */
/*   system_clock.h                                                   :+:    :+:     :+: :+:      */
/*                                                                   +:+    +:+    +:+   +:+      */
/*   By: Roman Alexandrov <r.aleksandroff@gmail.com>                +#++:++#:    +#++:++#++:      */
/*                                                                 +#+    +#+   +#+     +#+       */
/*   Created: 2023/06/28 14:49:16                                 #+#    #+#   #+#     #+#        */
/*   Updated: 2023/06/29 18:48:41                                ###    ###   ###     ###         */
/*                                                                                                */
/*                                                                                                */
/*   The function updates values of seconds, minutes, hours, days of the week, days of the        */
/*   months, months itselves.                                                                     */
/*                                                                                                */
/*   Leap year correction is not yet implemented!                                                 */
/*                                                                                                */
/* ********************************************************************************************** */

void  ft_system_clock(void)
{         
    rtcMng.second += 1;
    if (rtcMng.second == 60)
    {
        rtcMng.minute += 1;
        rtcMng.second = 0;
    }
    if (rtcMng.minute == 60)
    {
        rtcMng.hour += 1;
        rtcMng.minute = 0;
    }
    if (rtcMng.hour == 24)
    {
        rtcValues.day += 1;
        rtcValues.week_day += 1;
        rtcMng.hour = 0;
        rtcMng.minute = 0;
        rtcMng.second = 0;
    }
    if (rtcValues.week_day == 8)
        rtcValues.week_day = 1;
    switch (rtcValues.month)
    {
        case 1:   if (rtcValues.day == 32) { rtcValues.day=1; rtcValues.month+=1; }
         break;
        case 2:   if (rtcValues.day == 29) { rtcValues.day=1; rtcValues.month+=1; }
         break;
        case 3:   if (rtcValues.day == 32) { rtcValues.day=1; rtcValues.month+=1; }
         break;
        case 4:   if (rtcValues.day == 31) { rtcValues.day=1; rtcValues.month+=1; }
         break;
        case 5:   if (rtcValues.day == 32) { rtcValues.day=1; rtcValues.month+=1; }
         break;
        case 6:   if (rtcValues.day == 31) { rtcValues.day=1; rtcValues.month+=1; }
         break;
        case 7:   if (rtcValues.day == 32) { rtcValues.day=1; rtcValues.month+=1; }
         break;
        case 8:   if (rtcValues.day == 32) { rtcValues.day=1; rtcValues.month+=1; }
         break;
        case 9:   if (rtcValues.day == 31) { rtcValues.day=1; rtcValues.month+=1; }
         break;
        case 10:  if (rtcValues.day == 32) { rtcValues.day=1; rtcValues.month+=1; }
         break;
        case 11:  if (rtcValues.day == 31) { rtcValues.day=1; rtcValues.month+=1; }
         break;
        case 12:  if (rtcValues.day == 32) { rtcValues.day=1; rtcValues.month+=1; }
         break;
    }
    if (rtcValues.month == 13) rtcValues.month = 1;
}        
 
