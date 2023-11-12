/* ********************************************************************************************** */
/*                                                                                                */
/*   Smart Watch Firmware                                              :::::::::        :::       */
/*   mini_digital_clock_ui.cpp                                        :+:    :+:     :+: :+:      */
/*                                                                   +:+    +:+    +:+   +:+      */
/*   By: Roman Alexandrov <r.aleksandroff@gmail.com>                +#++:++#:    +#++:++#++:      */
/*                                                                 +#+    +#+   +#+     +#+       */
/*   Created: 2023/06/28 14:49:16                                 #+#    #+#   #+#     #+#        */
/*   Updated: 2023/11/12 13:48:41                                ###    ###   ###     ###         */
/*                                                                                                */
/*                                                                                                */
/*   The file contains engine of the 64x64 pixels digital clock widget. The images for the        */
/*   widget are located in the bitmap_library file.                                               */
/*                                                                                                */
/* ********************************************************************************************** */

#include "header.h"

void ft_mini_digital_clock_ui()
{
        x = 64;
        if (x >= 63)
            display.drawLine(64, 51, 64, 12, WHITE);                        // DIVIDING LINE BETWEEN THE UPPER AND LOWER SCREEN
        if (rtcMng.second % 2 == 0)
        {
            display.fillRect(x+27, y+31, 2, 2, WHITE);
            display.fillRect(x+34, y+31, 2, 2, WHITE);
        }  
        switch(rtcMng.hour)
        {
            case 0: 
              display.drawBitmap(x+22, y+51,  bit_num0, 19, 12, WHITE);     // Hours-Position1
              display.drawBitmap(x+22, y+37,  bit_num0, 19, 12, WHITE);     // Hours-Position2      
              break;
            case 1: 
              display.drawBitmap(x+22, y+51,  bit_num0, 19, 12, WHITE);  
              display.drawBitmap(x+22, y+37,  bit_num1, 19, 12, WHITE);  
              break;
            case 2:  
              display.drawBitmap(x+22, y+51,  bit_num0, 19, 12, WHITE);  
              display.drawBitmap(x+22, y+37,  bit_num2, 19, 12, WHITE);  
              break;
            case 3:  
              display.drawBitmap(x+22, y+51,  bit_num0, 19, 12, WHITE);  
              display.drawBitmap(x+22, y+37,  bit_num3, 19, 12, WHITE);  
              break;
            case 4:  
              display.drawBitmap(x+22, y+51,  bit_num0, 19, 12, WHITE);  
              display.drawBitmap(x+22, y+37,  bit_num4, 19, 12, WHITE);  
              break;
            case 5:  
              display.drawBitmap(x+22, y+51,  bit_num0, 19, 12, WHITE);  
              display.drawBitmap(x+22, y+37,  bit_num5, 19, 12, WHITE);  
              break;
            case 6:  
              display.drawBitmap(x+22, y+51,  bit_num0, 19, 12, WHITE);  
              display.drawBitmap(x+22, y+37,  bit_num6, 19, 12, WHITE);  
              break;
            case 7:  
              display.drawBitmap(x+22, y+51,  bit_num0, 19, 12, WHITE);  
              display.drawBitmap(x+22, y+37,  bit_num7, 19, 12, WHITE);  
              break;
            case 8:  
              display.drawBitmap(x+22, y+51,  bit_num0, 19, 12, WHITE);  
              display.drawBitmap(x+22, y+37,  bit_num8, 19, 12, WHITE);  
              break;
            case 9:  
              display.drawBitmap(x+22, y+51,  bit_num0, 19, 12, WHITE);  
              display.drawBitmap(x+22, y+37,  bit_num9, 19, 12, WHITE);  
              break;
            case 10:  
              display.drawBitmap(x+22, y+51,  bit_num1, 19, 12, WHITE);  
              display.drawBitmap(x+22, y+37,  bit_num0, 19, 12, WHITE);  
              break;
            case 11:  
              display.drawBitmap(x+22, y+51,  bit_num1, 19, 12, WHITE);  
              display.drawBitmap(x+22, y+37,  bit_num1, 19, 12, WHITE);  
              break;
            case 12:  
              display.drawBitmap(x+22, y+51,  bit_num1, 19, 12, WHITE);  
              display.drawBitmap(x+22, y+37,  bit_num2, 19, 12, WHITE);  
              break;
            case 13:  
              display.drawBitmap(x+22, y+51,  bit_num1, 19, 12, WHITE);  
              display.drawBitmap(x+22, y+37,  bit_num3, 19, 12, WHITE);  
              break;
            case 14:  
              display.drawBitmap(x+22, y+51,  bit_num1, 19, 12, WHITE);  
              display.drawBitmap(x+22, y+37,  bit_num4, 19, 12, WHITE);  
              break;
            case 15:  
              display.drawBitmap(x+22, y+51,  bit_num1, 19, 12, WHITE);  
              display.drawBitmap(x+22, y+37,  bit_num5, 19, 12, WHITE);  
              break;
            case 16:  
              display.drawBitmap(x+22, y+51,  bit_num1, 19, 12, WHITE);  
              display.drawBitmap(x+22, y+37,  bit_num6, 19, 12, WHITE);  
              break;
            case 17:  
              display.drawBitmap(x+22, y+51,  bit_num1, 19, 12, WHITE);  
              display.drawBitmap(x+22, y+37,  bit_num7, 19, 12, WHITE);  
              break;
            case 18:  
              display.drawBitmap(x+22, y+51,  bit_num1, 19, 12, WHITE);  
              display.drawBitmap(x+22, y+37,  bit_num8, 19, 12, WHITE);  
              break;
            case 19:  
              display.drawBitmap(x+22, y+51,  bit_num1, 19, 12, WHITE);  
              display.drawBitmap(x+22, y+37,  bit_num9, 19, 12, WHITE);  
              break;
            case 20:  
              display.drawBitmap(x+22, y+51,  bit_num2, 19, 12, WHITE);  
              display.drawBitmap(x+22, y+37,  bit_num0, 19, 12, WHITE);  
              break;
            case 21:  
              display.drawBitmap(x+22, y+51,  bit_num2, 19, 12, WHITE);  
              display.drawBitmap(x+22, y+37,  bit_num1, 19, 12, WHITE);  
              break;
            case 22:  
              display.drawBitmap(x+22, y+51,  bit_num2, 19, 12, WHITE);  
              display.drawBitmap(x+22, y+37,  bit_num2, 19, 12, WHITE);  
              break;
            case 23:  
              display.drawBitmap(x+22, y+51,  bit_num2, 19, 12, WHITE);  
              display.drawBitmap(x+22, y+37,  bit_num3, 19, 12, WHITE);  
              break;
            default:                                                        // Error message "99"  
              display.drawBitmap(x+22, y+51,  bit_num9, 19, 12, WHITE);
              display.drawBitmap(x+22, y+37,  bit_num9, 19, 12, WHITE);
        }        
        switch(rtcMng.minute)
        {
            case 0:                                                         // 00
              display.drawBitmap(x+22, y+15,  bit_num0, 19, 12, WHITE);     // Minutes-Position1 
              display.drawBitmap(x+22, y+1,  bit_num0, 19, 12, WHITE);      // Minutes-Position2
              break;
            case 1: 
              display.drawBitmap(x+22, y+15,  bit_num0, 19, 12, WHITE);   
              display.drawBitmap(x+22, y+1,  bit_num1, 19, 12, WHITE);   
              break;
            case 2: 
              display.drawBitmap(x+22, y+15,  bit_num0, 19, 12, WHITE);   
              display.drawBitmap(x+22, y+1,  bit_num2, 19, 12, WHITE);   
              break;
            case 3: 
              display.drawBitmap(x+22, y+15,  bit_num0, 19, 12, WHITE);   
              display.drawBitmap(x+22, y+1,  bit_num3, 19, 12, WHITE);   
              break;
            case 4: 
              display.drawBitmap(x+22, y+15,  bit_num0, 19, 12, WHITE);   
              display.drawBitmap(x+22, y+1,  bit_num4, 19, 12, WHITE);   
              break;
            case 5: 
              display.drawBitmap(x+22, y+15,  bit_num0, 19, 12, WHITE);   
              display.drawBitmap(x+22, y+1,  bit_num5, 19, 12, WHITE);   
              break;
            case 6: 
              display.drawBitmap(x+22, y+15,  bit_num0, 19, 12, WHITE);   
              display.drawBitmap(x+22, y+1,  bit_num6, 19, 12, WHITE);   
              break;
            case 7: 
              display.drawBitmap(x+22, y+15,  bit_num0, 19, 12, WHITE);   
              display.drawBitmap(x+22, y+1,  bit_num7, 19, 12, WHITE);   
              break;
            case 8: 
              display.drawBitmap(x+22, y+15,  bit_num0, 19, 12, WHITE);   
              display.drawBitmap(x+22, y+1,  bit_num8, 19, 12, WHITE);   
              break;
            case 9: 
              display.drawBitmap(x+22, y+15,  bit_num0, 19, 12, WHITE);   
              display.drawBitmap(x+22, y+1,  bit_num9, 19, 12, WHITE);   
              break;
            case 10:                                                        // 10
              display.drawBitmap(x+22, y+15,  bit_num1, 19, 12, WHITE);   
              display.drawBitmap(x+22, y+1,  bit_num0, 19, 12, WHITE);   
              break;
            case 11: 
              display.drawBitmap(x+22, y+15,  bit_num1, 19, 12, WHITE);   
              display.drawBitmap(x+22, y+1,  bit_num1, 19, 12, WHITE);   
              break;
            case 12: 
              display.drawBitmap(x+22, y+15,  bit_num1, 19, 12, WHITE);   
              display.drawBitmap(x+22, y+1,  bit_num2, 19, 12, WHITE);   
              break;
            case 13: 
              display.drawBitmap(x+22, y+15,  bit_num1, 19, 12, WHITE);   
              display.drawBitmap(x+22, y+1,  bit_num3, 19, 12, WHITE);   
              break;
            case 14: 
              display.drawBitmap(x+22, y+15,  bit_num1, 19, 12, WHITE);   
              display.drawBitmap(x+22, y+1,  bit_num4, 19, 12, WHITE);   
              break;
            case 15: 
              display.drawBitmap(x+22, y+15,  bit_num1, 19, 12, WHITE);   
              display.drawBitmap(x+22, y+1,  bit_num5, 19, 12, WHITE);   
              break;
            case 16: 
              display.drawBitmap(x+22, y+15,  bit_num1, 19, 12, WHITE);   
              display.drawBitmap(x+22, y+1,  bit_num6, 19, 12, WHITE);   
              break;
            case 17: 
              display.drawBitmap(x+22, y+15,  bit_num1, 19, 12, WHITE);   
              display.drawBitmap(x+22, y+1,  bit_num7, 19, 12, WHITE);   
              break;
            case 18: 
              display.drawBitmap(x+22, y+15,  bit_num1, 19, 12, WHITE);   
              display.drawBitmap(x+22, y+1,  bit_num8, 19, 12, WHITE);   
              break;
            case 19: 
              display.drawBitmap(x+22, y+15,  bit_num1, 19, 12, WHITE);   
              display.drawBitmap(x+22, y+1,  bit_num9, 19, 12, WHITE);   
              break;
            case 20:                                                        // 20
              display.drawBitmap(x+22, y+15,  bit_num2, 19, 12, WHITE);   
              display.drawBitmap(x+22, y+1,  bit_num0, 19, 12, WHITE);   
              break;
            case 21: 
              display.drawBitmap(x+22, y+15,  bit_num2, 19, 12, WHITE);   
              display.drawBitmap(x+22, y+1,  bit_num1, 19, 12, WHITE);   
              break;
            case 22: 
              display.drawBitmap(x+22, y+15,  bit_num2, 19, 12, WHITE);   
              display.drawBitmap(x+22, y+1,  bit_num2, 19, 12, WHITE);   
              break;
            case 23: 
              display.drawBitmap(x+22, y+15,  bit_num2, 19, 12, WHITE);   
              display.drawBitmap(x+22, y+1,  bit_num3, 19, 12, WHITE);   
              break;
            case 24: 
              display.drawBitmap(x+22, y+15,  bit_num2, 19, 12, WHITE);   
              display.drawBitmap(x+22, y+1,  bit_num4, 19, 12, WHITE);   
              break;
            case 25: 
              display.drawBitmap(x+22, y+15,  bit_num2, 19, 12, WHITE);   
              display.drawBitmap(x+22, y+1,  bit_num5, 19, 12, WHITE);   
              break;
            case 26: 
              display.drawBitmap(x+22, y+15,  bit_num2, 19, 12, WHITE);   
              display.drawBitmap(x+22, y+1,  bit_num6, 19, 12, WHITE);   
              break;
            case 27: 
              display.drawBitmap(x+22, y+15,  bit_num2, 19, 12, WHITE);   
              display.drawBitmap(x+22, y+1,  bit_num7, 19, 12, WHITE);   
              break;
            case 28: 
              display.drawBitmap(x+22, y+15,  bit_num2, 19, 12, WHITE);   
              display.drawBitmap(x+22, y+1,  bit_num8, 19, 12, WHITE);   
              break;
            case 29: 
              display.drawBitmap(x+22, y+15,  bit_num2, 19, 12, WHITE);   
              display.drawBitmap(x+22, y+1,  bit_num9, 19, 12, WHITE);   
              break;
            case 30:                                                        // 30
              display.drawBitmap(x+22, y+15,  bit_num3, 19, 12, WHITE);   
              display.drawBitmap(x+22, y+1,  bit_num0, 19, 12, WHITE);   
              break;
            case 31: 
              display.drawBitmap(x+22, y+15,  bit_num3, 19, 12, WHITE);   
              display.drawBitmap(x+22, y+1,  bit_num1, 19, 12, WHITE);   
              break;
            case 32: 
              display.drawBitmap(x+22, y+15,  bit_num3, 19, 12, WHITE);   
              display.drawBitmap(x+22, y+1,  bit_num2, 19, 12, WHITE);   
              break;
            case 33: 
              display.drawBitmap(x+22, y+15,  bit_num3, 19, 12, WHITE);   
              display.drawBitmap(x+22, y+1,  bit_num3, 19, 12, WHITE);   
              break;
            case 34: 
              display.drawBitmap(x+22, y+15,  bit_num3, 19, 12, WHITE);   
              display.drawBitmap(x+22, y+1,  bit_num4, 19, 12, WHITE);   
              break;
            case 35: 
              display.drawBitmap(x+22, y+15,  bit_num3, 19, 12, WHITE);   
              display.drawBitmap(x+22, y+1,  bit_num5, 19, 12, WHITE);   
              break;
            case 36: 
              display.drawBitmap(x+22, y+15,  bit_num3, 19, 12, WHITE);   
              display.drawBitmap(x+22, y+1,  bit_num6, 19, 12, WHITE);   
              break;
            case 37: 
              display.drawBitmap(x+22, y+15,  bit_num3, 19, 12, WHITE);   
              display.drawBitmap(x+22, y+1,  bit_num7, 19, 12, WHITE);   
              break;
            case 38: 
              display.drawBitmap(x+22, y+15,  bit_num3, 19, 12, WHITE);   
              display.drawBitmap(x+22, y+1,  bit_num8, 19, 12, WHITE);   
              break;
            case 39: 
              display.drawBitmap(x+22, y+15,  bit_num3, 19, 12, WHITE);   
              display.drawBitmap(x+22, y+1,  bit_num9, 19, 12, WHITE);   
              break;
            case 40:                                                        // 40
              display.drawBitmap(x+22, y+15,  bit_num4, 19, 12, WHITE);   
              display.drawBitmap(x+22, y+1,  bit_num0, 19, 12, WHITE);   
              break;
            case 41: 
              display.drawBitmap(x+22, y+15,  bit_num4, 19, 12, WHITE);   
              display.drawBitmap(x+22, y+1,  bit_num1, 19, 12, WHITE);   
              break;
            case 42: 
              display.drawBitmap(x+22, y+15,  bit_num4, 19, 12, WHITE);   
              display.drawBitmap(x+22, y+1,  bit_num2, 19, 12, WHITE);   
              break;
            case 43: 
              display.drawBitmap(x+22, y+15,  bit_num4, 19, 12, WHITE);   
              display.drawBitmap(x+22, y+1,  bit_num3, 19, 12, WHITE);   
              break;
            case 44: 
              display.drawBitmap(x+22, y+15,  bit_num4, 19, 12, WHITE);   
              display.drawBitmap(x+22, y+1,  bit_num4, 19, 12, WHITE);   
              break;
            case 45: 
              display.drawBitmap(x+22, y+15,  bit_num4, 19, 12, WHITE);   
              display.drawBitmap(x+22, y+1,  bit_num5, 19, 12, WHITE);   
              break;
            case 46: 
              display.drawBitmap(x+22, y+15,  bit_num4, 19, 12, WHITE);   
              display.drawBitmap(x+22, y+1,  bit_num6, 19, 12, WHITE);   
              break;
            case 47: 
              display.drawBitmap(x+22, y+15,  bit_num4, 19, 12, WHITE);   
              display.drawBitmap(x+22, y+1,  bit_num7, 19, 12, WHITE);   
              break;
            case 48: 
              display.drawBitmap(x+22, y+15,  bit_num4, 19, 12, WHITE);   
              display.drawBitmap(x+22, y+1,  bit_num8, 19, 12, WHITE);   
              break;
            case 49: 
              display.drawBitmap(x+22, y+15,  bit_num4, 19, 12, WHITE);   
              display.drawBitmap(x+22, y+1,  bit_num9, 19, 12, WHITE);   
              break;
            case 50:                                                        // 50
              display.drawBitmap(x+22, y+15,  bit_num5, 19, 12, WHITE);   
              display.drawBitmap(x+22, y+1,  bit_num0, 19, 12, WHITE);   
              break;
            case 51: 
              display.drawBitmap(x+22, y+15,  bit_num5, 19, 12, WHITE);   
              display.drawBitmap(x+22, y+1,  bit_num1, 19, 12, WHITE);   
              break;
            case 52: 
              display.drawBitmap(x+22, y+15,  bit_num5, 19, 12, WHITE);   
              display.drawBitmap(x+22, y+1,  bit_num2, 19, 12, WHITE);   
              break;
            case 53: 
              display.drawBitmap(x+22, y+15,  bit_num5, 19, 12, WHITE);   
              display.drawBitmap(x+22, y+1,  bit_num3, 19, 12, WHITE);   
              break;
            case 54: 
              display.drawBitmap(x+22, y+15,  bit_num5, 19, 12, WHITE);   
              display.drawBitmap(x+22, y+1,  bit_num4, 19, 12, WHITE);   
              break;
            case 55: 
              display.drawBitmap(x+22, y+15,  bit_num5, 19, 12, WHITE);   
              display.drawBitmap(x+22, y+1,  bit_num5, 19, 12, WHITE);   
              break;
            case 56: 
              display.drawBitmap(x+22, y+15,  bit_num5, 19, 12, WHITE);   
              display.drawBitmap(x+22, y+1,  bit_num6, 19, 12, WHITE);   
              break;
            case 57: 
              display.drawBitmap(x+22, y+15,  bit_num5, 19, 12, WHITE);   
              display.drawBitmap(x+22, y+1,  bit_num7, 19, 12, WHITE);   
              break;
            case 58: 
              display.drawBitmap(x+22, y+15,  bit_num5, 19, 12, WHITE);   
              display.drawBitmap(x+22, y+1,  bit_num8, 19, 12, WHITE);   
              break;
            case 59:                                                        // 59
              display.drawBitmap(x+22, y+15,  bit_num5, 19, 12, WHITE);   
              display.drawBitmap(x+22, y+1,  bit_num9, 19, 12, WHITE);   
              break;
            default:                                                        // Error message "99" 
              display.drawBitmap(x+22, y+15,  bit_num9, 19, 12, WHITE);  
              display.drawBitmap(x+22, y+1,  bit_num9, 19, 12, WHITE); 
        }  
}
 
