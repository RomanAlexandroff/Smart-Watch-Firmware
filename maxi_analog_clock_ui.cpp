/* ********************************************************************************************** */
/*                                                                                                */
/*   Smart Watch Firmware                                              :::::::::        :::       */
/*   maxi_analog_clock_ui.cpp                                         :+:    :+:     :+: :+:      */
/*                                                                   +:+    +:+    +:+   +:+      */
/*   By: Roman Alexandrov <r.aleksandroff@gmail.com>                +#++:++#:    +#++:++#++:      */
/*                                                                 +#+    +#+   +#+     +#+       */
/*   Created: 2023/06/28 14:49:16                                 #+#    #+#   #+#     #+#        */
/*   Updated: 2023/11/12 13:48:41                                ###    ###   ###     ###         */
/*                                                                                                */
/*                                                                                                */
/*   The file contains engine of the 128x64 pixels analog clock widget. The images for the        */
/*   widget are located in the bitmap_library file.                                               */
/*                                                                                                */
/*   The "hour - 3" and "minute - 15" expressions are needed to turn the arrows 90 degrees        */
/*   counter-clockwise to fit the vertical screen.                                                */
/*                                                                                                */
/* ********************************************************************************************** */

#include "header.h"

void  ft_maxi_analog_clock_ui()
{
    int   r;
    int   hr;
    int   min;
    float alpha;

    r = 25;
    hr = rtcMng.hour - 3;
    min = rtcMng.minute - 15;
    display.drawBitmap(0, 0, analog_full_screen_top, 24, 64, WHITE);
    display.drawBitmap(103, 0, analog_full_screen_bottom, 25, 64, WHITE);
    display.fillRect(63, 30, 4, 4, WHITE);    
    if (hr <= 12)
        alpha = (hr * (PI / 6) - (PI / 2)) + ((min / 12) * (PI / 30));               // HOURS HAND determining the angle of the line with respect to vertical
    if (hr > 12)
        alpha = ((hr - 12) * (PI / 6) - (PI / 2)) + ((min / 12) * (PI / 30));
    display.drawLine(63, 31, (63+r*cos(alpha)), (31+r*sin(alpha)), WHITE);
    r = 40;
    alpha = (min * (PI / 30) - (PI / 2));                                            // MINUTES HAND determining the angle of the line with respect to vertical
    display.drawLine(63, 31, (63+r*cos(alpha)), (31+r*sin(alpha)), WHITE);
}
 
