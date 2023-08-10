/* ********************************************************************************************** */
/*                                                                                                */
/*   Smart Watch Firmware                                              :::::::::        :::       */
/*   mini_analog_clock_ui.h                                           :+:    :+:     :+: :+:      */
/*                                                                   +:+    +:+    +:+   +:+      */
/*   By: Roman Alexandrov <r.aleksandroff@gmail.com>                +#++:++#:    +#++:++#++:      */
/*                                                                 +#+    +#+   +#+     +#+       */
/*   Created: 2023/06/28 14:49:16                                 #+#    #+#   #+#     #+#        */
/*   Updated: 2023/06/29 18:48:41                                ###    ###   ###     ###         */
/*                                                                                                */
/*                                                                                                */
/*   The file contains engine of the 64x64 pixels analog clock widget. The images for the         */
/*   widget are located in the bitmap_library file.                                               */
/*                                                                                                */
/*   The "hour - 3" and "minute - 15" expressions are needed to turn the arrows 90 degrees        */
/*   counter-clockwise.                                                                           */
/*                                                                                                */
/* ********************************************************************************************** */

int ft_size_x(int r, float alpha)
{
    return ((x + 32) + (float)r * cos(alpha));
}

int ft_size_y(int r, float alpha)
{
    return ((y + 31) + (float)r * sin(alpha));
}

void  ft_mini_analog_clock_ui(void)
{
    int   r;
    int   hr;
    int   min;
    float alpha;
    
    x = 0;
    r = 10;
    hr = rtcMng.hour - 3;
    min = rtcMng.minute - 15;
    display.drawBitmap(x+1, y, analog_clock_face, 64, 64, WHITE);
    display.fillRect(x+32, y+31, 2, 2, WHITE);
    if (hr <= 12)
        alpha = ((float)hr * (PI / 6) - (PI / 2)) + (((float)min / 12) * (PI / 30));       // HOURS HAND determining the angle of the line with respect to vertical
    if (hr > 12)
        alpha = (((float)hr - 12) * (PI / 6) - (PI / 2)) + (((float)min / 12) * (PI / 30));
    display.drawLine(x+32, y+31, ft_size_x(r, alpha), ft_size_y(r, alpha), WHITE);
    r = 16;
    alpha = ((float)min * (PI / 30) - (PI / 2));                                          // MINUTES HAND determining the angle of the line with respect to vertical
    display.drawLine(x+32, y+31, ft_size_x(r, alpha), ft_size_y(r, alpha), WHITE);
}
 
