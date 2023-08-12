/* ********************************************************************************************** */
/*                                                                                                */
/*   Smart Watch Firmware                                              :::::::::        :::       */
/*   calendar_ui.h                                                    :+:    :+:     :+: :+:      */
/*                                                                   +:+    +:+    +:+   +:+      */
/*   By: Roman Alexandrov <r.aleksandroff@gmail.com>                +#++:++#:    +#++:++#++:      */
/*                                                                 +#+    +#+   +#+     +#+       */
/*   Created: 2023/06/28 14:49:16                                 #+#    #+#   #+#     #+#        */
/*   Updated: 2023/06/29 18:48:41                                ###    ###   ###     ###         */
/*                                                                                                */
/*                                                                                                */
/*   The function assembles all the calendar related information in a correct order and puts      */
/*   it into a temporary memory for it to be displayed later.                                     */
/*                                                                                                */
/* ********************************************************************************************** */

void  ft_calendar_ui(void)
{
    x = 64;                                                                 // ВРЕМЕННАЯ ФИКСАЦИЯ ПОЛОЖЕНИЯ НА ЭКРАНЕ – УДАЛИТЬ КОГДА УЖЕ НЕ НУЖНО
    display.drawRoundRect(x+4, y+2, 60, 60, 8, WHITE);                      // OUTLINE
    display.drawRoundRect(x+4, y+2, 15, 60, 7, WHITE);                      // MONTH OUTLINE         
        switch(rtcValues.month)
        {
            case 1:                                                         // January 
              display.drawBitmap(x+8, y+38, bit_J, 7, 5, WHITE); 
              display.drawBitmap(x+8, y+30, bit_A, 7, 5, WHITE);
              display.drawBitmap(x+8, y+22, bit_N, 7, 5, WHITE);
              break;
            case 2:                                                         // February 
              display.drawBitmap(x+8, y+38, bit_F, 7, 5, WHITE);
              display.drawBitmap(x+8, y+30, bit_E, 7, 5, WHITE);
              display.drawBitmap(x+8, y+22, bit_B, 7, 5, WHITE);
              break;
            case 3:                                                         // March 
              display.drawBitmap(x+8, y+44, bit_M, 7, 5, WHITE); 
              display.drawBitmap(x+8, y+37, bit_A, 7, 5, WHITE);
              display.drawBitmap(x+8, y+30, bit_R, 7, 5, WHITE);
              display.drawBitmap(x+8, y+23, bit_C, 7, 5, WHITE);
              display.drawBitmap(x+8, y+16, bit_H, 7, 5, WHITE);
              break;
            case 4:                                                         // April 
              display.drawBitmap(x+8, y+44, bit_A, 7, 5, WHITE); 
              display.drawBitmap(x+8, y+37, bit_P, 7, 5, WHITE);
              display.drawBitmap(x+8, y+30, bit_R, 7, 5, WHITE);
              display.drawBitmap(x+8, y+23, bit_I, 7, 5, WHITE);
              display.drawBitmap(x+8, y+16, bit_L, 7, 5, WHITE);
              break;
            case 5:                                                         // May 
              display.drawBitmap(x+8, y+38, bit_M, 7, 5, WHITE); 
              display.drawBitmap(x+8, y+30, bit_A, 7, 5, WHITE);
              display.drawBitmap(x+8, y+22, bit_Y, 7, 5, WHITE);
              break;
            case 6:                                                         // June 
              display.drawBitmap(x+8, y+40, bit_J, 7, 5, WHITE); 
              display.drawBitmap(x+8, y+33, bit_U, 7, 5, WHITE);
              display.drawBitmap(x+8, y+26, bit_N, 7, 5, WHITE);
              display.drawBitmap(x+8, y+19, bit_E, 7, 5, WHITE);
              break;
            case 7:                                                         // July 
              display.drawBitmap(x+8, y+40, bit_J, 7, 5, WHITE); 
              display.drawBitmap(x+8, y+33, bit_U, 7, 5, WHITE);
              display.drawBitmap(x+8, y+26, bit_L, 7, 5, WHITE);
              display.drawBitmap(x+8, y+19, bit_Y, 7, 5, WHITE);
              break;
            case 8:                                                         // August 
              display.drawBitmap(x+8, y+38, bit_A, 7, 5, WHITE); 
              display.drawBitmap(x+8, y+30, bit_U, 7, 5, WHITE);
              display.drawBitmap(x+8, y+22, bit_G, 7, 5, WHITE);
              break;
            case 9:                                                         // September 
              display.drawBitmap(x+8, y+40, bit_S, 7, 5, WHITE); 
              display.drawBitmap(x+8, y+33, bit_E, 7, 5, WHITE);
              display.drawBitmap(x+8, y+26, bit_P, 7, 5, WHITE);
              display.drawBitmap(x+8, y+19, bit_T, 7, 5, WHITE);
              break;
            case 10:                                                        // October 
              display.drawBitmap(x+8, y+38, bit_O, 7, 5, WHITE);
              display.drawBitmap(x+8, y+30, bit_C, 7, 5, WHITE);
              display.drawBitmap(x+8, y+22, bit_T, 7, 5, WHITE);
              break;
            case 11:                                                        // November 
              display.drawBitmap(x+8, y+38, bit_N, 7, 5, WHITE);
              display.drawBitmap(x+8, y+30, bit_O, 7, 5, WHITE);
              display.drawBitmap(x+8, y+22, bit_V, 7, 5, WHITE);
              break;
            case 12:                                                        // December
              display.drawBitmap(x+8, y+38, bit_D, 7, 5, WHITE); 
              display.drawBitmap(x+8, y+30, bit_E, 7, 5, WHITE);
              display.drawBitmap(x+8, y+22, bit_C, 7, 5, WHITE);
              break;
            default:                                                        // Error message
              display.drawBitmap(x+8, y+44, bit_E, 7, 5, WHITE); 
              display.drawBitmap(x+8, y+37, bit_R, 7, 5, WHITE);
              display.drawBitmap(x+8, y+30, bit_R, 7, 5, WHITE);
              display.drawBitmap(x+8, y+23, bit_O, 7, 5, WHITE);
              display.drawBitmap(x+8, y+16, bit_R, 7, 5, WHITE);
        }        
        switch(rtcValues.day)
        {
            case 1: 
              display.drawBitmap(x+24, y+33,  bit_num0, 19, 12, WHITE);     // Days-Position1 
              display.drawBitmap(x+24, y+19,  bit_num1, 19, 12, WHITE);     // Days-Position2
              break;
            case 2: 
              display.drawBitmap(x+24, y+33,  bit_num0, 19, 12, WHITE);   
              display.drawBitmap(x+24, y+19,  bit_num2, 19, 12, WHITE);  
              break;
            case 3: 
              display.drawBitmap(x+24, y+33,  bit_num0, 19, 12, WHITE);   
              display.drawBitmap(x+24, y+19,  bit_num3, 19, 12, WHITE);  
              break;
            case 4: 
              display.drawBitmap(x+24, y+33,  bit_num0, 19, 12, WHITE);   
              display.drawBitmap(x+24, y+19,  bit_num4, 19, 12, WHITE);  
              break;
            case 5: 
              display.drawBitmap(x+24, y+33,  bit_num0, 19, 12, WHITE);   
              display.drawBitmap(x+24, y+19,  bit_num5, 19, 12, WHITE);  
              break;
            case 6: 
              display.drawBitmap(x+24, y+33,  bit_num0, 19, 12, WHITE);   
              display.drawBitmap(x+24, y+19,  bit_num6, 19, 12, WHITE);  
              break;
            case 7: 
              display.drawBitmap(x+24, y+33,  bit_num0, 19, 12, WHITE);   
              display.drawBitmap(x+24, y+19,  bit_num7, 19, 12, WHITE);  
              break;
            case 8: 
              display.drawBitmap(x+24, y+33,  bit_num0, 19, 12, WHITE);   
              display.drawBitmap(x+24, y+19,  bit_num8, 19, 12, WHITE);  
              break;
            case 9: 
              display.drawBitmap(x+24, y+33,  bit_num0, 19, 12, WHITE);   
              display.drawBitmap(x+24, y+19,  bit_num9, 19, 12, WHITE);  
              break;
            case 10: 
              display.drawBitmap(x+24, y+33,  bit_num1, 19, 12, WHITE);   
              display.drawBitmap(x+24, y+19,  bit_num0, 19, 12, WHITE);  
              break;
            case 11: 
              display.drawBitmap(x+24, y+33,  bit_num1, 19, 12, WHITE);   
              display.drawBitmap(x+24, y+19,  bit_num1, 19, 12, WHITE);  
              break;
            case 12: 
              display.drawBitmap(x+24, y+33,  bit_num1, 19, 12, WHITE);   
              display.drawBitmap(x+24, y+19,  bit_num2, 19, 12, WHITE);  
              break;
            case 13: 
              display.drawBitmap(x+24, y+33,  bit_num1, 19, 12, WHITE);   
              display.drawBitmap(x+24, y+19,  bit_num3, 19, 12, WHITE);  
              break;
            case 14: 
              display.drawBitmap(x+24, y+33,  bit_num1, 19, 12, WHITE);   
              display.drawBitmap(x+24, y+19,  bit_num4, 19, 12, WHITE);  
              break;
            case 15: 
              display.drawBitmap(x+24, y+33,  bit_num1, 19, 12, WHITE);   
              display.drawBitmap(x+24, y+19,  bit_num5, 19, 12, WHITE);  
              break;
            case 16: 
              display.drawBitmap(x+24, y+33,  bit_num1, 19, 12, WHITE);   
              display.drawBitmap(x+24, y+19,  bit_num6, 19, 12, WHITE);  
              break;
            case 17: 
              display.drawBitmap(x+24, y+33,  bit_num1, 19, 12, WHITE);   
              display.drawBitmap(x+24, y+19,  bit_num7, 19, 12, WHITE);  
              break;
            case 18: 
              display.drawBitmap(x+24, y+33,  bit_num1, 19, 12, WHITE);   
              display.drawBitmap(x+24, y+19,  bit_num8, 19, 12, WHITE);  
              break;
            case 19: 
              display.drawBitmap(x+24, y+33,  bit_num1, 19, 12, WHITE);   
              display.drawBitmap(x+24, y+19,  bit_num9, 19, 12, WHITE);  
              break;
            case 20: 
              display.drawBitmap(x+24, y+33,  bit_num2, 19, 12, WHITE);   
              display.drawBitmap(x+24, y+19,  bit_num0, 19, 12, WHITE);  
              break;
            case 21: 
              display.drawBitmap(x+24, y+33,  bit_num2, 19, 12, WHITE);   
              display.drawBitmap(x+24, y+19,  bit_num1, 19, 12, WHITE);  
              break;
            case 22: 
              display.drawBitmap(x+24, y+33,  bit_num2, 19, 12, WHITE);   
              display.drawBitmap(x+24, y+19,  bit_num2, 19, 12, WHITE);  
              break;
            case 23: 
              display.drawBitmap(x+24, y+33,  bit_num2, 19, 12, WHITE);   
              display.drawBitmap(x+24, y+19,  bit_num3, 19, 12, WHITE);  
              break;
            case 24: 
              display.drawBitmap(x+24, y+33,  bit_num2, 19, 12, WHITE);   
              display.drawBitmap(x+24, y+19,  bit_num4, 19, 12, WHITE);  
              break;
            case 25: 
              display.drawBitmap(x+24, y+33,  bit_num2, 19, 12, WHITE);   
              display.drawBitmap(x+24, y+19,  bit_num5, 19, 12, WHITE);  
              break;
            case 26: 
              display.drawBitmap(x+24, y+33,  bit_num2, 19, 12, WHITE);   
              display.drawBitmap(x+24, y+19,  bit_num6, 19, 12, WHITE);  
              break;
            case 27: 
              display.drawBitmap(x+24, y+33,  bit_num2, 19, 12, WHITE);   
              display.drawBitmap(x+24, y+19,  bit_num7, 19, 12, WHITE);  
              break;
            case 28: 
              display.drawBitmap(x+24, y+33,  bit_num2, 19, 12, WHITE);   
              display.drawBitmap(x+24, y+19,  bit_num8, 19, 12, WHITE);  
              break;
            case 29: 
              display.drawBitmap(x+24, y+33,  bit_num2, 19, 12, WHITE);   
              display.drawBitmap(x+24, y+19,  bit_num9, 19, 12, WHITE);  
              break;
            case 30: 
              display.drawBitmap(x+24, y+33,  bit_num3, 19, 12, WHITE);   
              display.drawBitmap(x+24, y+19,  bit_num0, 19, 12, WHITE);  
              break;
            case 31: 
              display.drawBitmap(x+24, y+33,  bit_num3, 19, 12, WHITE);   
              display.drawBitmap(x+24, y+19,  bit_num1, 19, 12, WHITE);  
              break;
            default:                                                       // Error message "00"
              display.drawBitmap(x+24, y+33,  bit_num0, 19, 12, WHITE); 
              display.drawBitmap(x+24, y+19,  bit_num0, 19, 12, WHITE);
        }         
        switch(rtcValues.week_day)
        {
            case 1:                                                        //MONDAY
              display.drawBitmap(x+49, y+47, bit_M, 7, 5, WHITE);
              display.drawBitmap(x+49, y+40, bit_O, 7, 5, WHITE); 
              display.drawBitmap(x+49, y+33, bit_N, 7, 5, WHITE);
              display.drawBitmap(x+49, y+26, bit_D, 7, 5, WHITE);
              display.drawBitmap(x+49, y+19, bit_A, 7, 5, WHITE);
              display.drawBitmap(x+49, y+12, bit_Y, 7, 5, WHITE);
              break;
            case 2:                                                        //TUESDAY 
              display.drawBitmap(x+49, y+51, bit_T, 7, 5, WHITE);
              display.drawBitmap(x+49, y+44, bit_U, 7, 5, WHITE); 
              display.drawBitmap(x+49, y+37, bit_E, 7, 5, WHITE);
              display.drawBitmap(x+49, y+30, bit_S, 7, 5, WHITE);
              display.drawBitmap(x+49, y+23, bit_D, 7, 5, WHITE);
              display.drawBitmap(x+49, y+16, bit_A, 7, 5, WHITE);
              display.drawBitmap(x+49, y+9, bit_Y, 7, 5, WHITE);
              break;
            case 3:                                                        //WEDNESDAY 
              display.drawBitmap(x+49, y+54, bit_W, 7, 5, WHITE);
              display.drawBitmap(x+49, y+48, bit_E, 7, 5, WHITE);
              display.drawBitmap(x+49, y+42, bit_D, 7, 5, WHITE); 
              display.drawBitmap(x+49, y+36, bit_N, 7, 5, WHITE);
              display.drawBitmap(x+49, y+30, bit_E, 7, 5, WHITE);
              display.drawBitmap(x+49, y+24, bit_S, 7, 5, WHITE);
              display.drawBitmap(x+49, y+18, bit_D, 7, 5, WHITE);
              display.drawBitmap(x+49, y+12, bit_A, 7, 5, WHITE);
              display.drawBitmap(x+49, y+6, bit_Y, 7, 5, WHITE);
              break;
            case 4:                                                        //THURSDAY 
              display.drawBitmap(x+49, y+51, bit_T, 7, 5, WHITE);
              display.drawBitmap(x+49, y+45, bit_H, 7, 5, WHITE);
              display.drawBitmap(x+49, y+39, bit_U, 7, 5, WHITE); 
              display.drawBitmap(x+49, y+33, bit_R, 7, 5, WHITE);
              display.drawBitmap(x+49, y+26, bit_S, 7, 5, WHITE);
              display.drawBitmap(x+49, y+20, bit_D, 7, 5, WHITE);
              display.drawBitmap(x+49, y+14, bit_A, 7, 5, WHITE);
              display.drawBitmap(x+49, y+8, bit_Y, 7, 5, WHITE);
              break;
            case 5:                                                        //FRIDAY 
              display.drawBitmap(x+49, y+47, bit_F, 7, 5, WHITE);
              display.drawBitmap(x+49, y+40, bit_R, 7, 5, WHITE); 
              display.drawBitmap(x+49, y+33, bit_I, 7, 5, WHITE);
              display.drawBitmap(x+49, y+26, bit_D, 7, 5, WHITE);
              display.drawBitmap(x+49, y+19, bit_A, 7, 5, WHITE);
              display.drawBitmap(x+49, y+12, bit_Y, 7, 5, WHITE);
              break;
            case 6:                                                        //SATURDAY 
              display.drawBitmap(x+49, y+51, bit_S, 7, 5, WHITE);
              display.drawBitmap(x+49, y+45, bit_A, 7, 5, WHITE);
              display.drawBitmap(x+49, y+39, bit_T, 7, 5, WHITE); 
              display.drawBitmap(x+49, y+33, bit_U, 7, 5, WHITE);
              display.drawBitmap(x+49, y+26, bit_R, 7, 5, WHITE);
              display.drawBitmap(x+49, y+20, bit_D, 7, 5, WHITE);
              display.drawBitmap(x+49, y+14, bit_A, 7, 5, WHITE);
              display.drawBitmap(x+49, y+8, bit_Y, 7, 5, WHITE);
              break;
            case 7:                                                        //SUNDAY 
              display.drawBitmap(x+49, y+47, bit_S, 7, 5, WHITE);
              display.drawBitmap(x+49, y+40, bit_U, 7, 5, WHITE); 
              display.drawBitmap(x+49, y+33, bit_N, 7, 5, WHITE);
              display.drawBitmap(x+49, y+26, bit_D, 7, 5, WHITE);
              display.drawBitmap(x+49, y+19, bit_A, 7, 5, WHITE);
              display.drawBitmap(x+49, y+12, bit_Y, 7, 5, WHITE);
              break;
            default:                                                       // Error message "error"
              display.drawBitmap(x+49, y+44, bit_E, 7, 5, WHITE);
              display.drawBitmap(x+49, y+37, bit_R, 7, 5, WHITE);
              display.drawBitmap(x+49, y+30, bit_R, 7, 5, WHITE);
              display.drawBitmap(x+49, y+23, bit_O, 7, 5, WHITE);
              display.drawBitmap(x+49, y+16, bit_R, 7, 5, WHITE);
        }
}
 
