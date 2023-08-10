/* ********************************************************************************************** */
/*                                                                                                */
/*   Smart Watch Firmware                                              :::::::::        :::       */
/*   moon_phases_ui.h                                                 :+:    :+:     :+: :+:      */
/*                                                                   +:+    +:+    +:+   +:+      */
/*   By: Roman Alexandrov <r.aleksandroff@gmail.com>                +#++:++#:    +#++:++#++:      */
/*                                                                 +#+    +#+   +#+     +#+       */
/*   Created: 2023/06/28 14:49:16                                 #+#    #+#   #+#     #+#        */
/*   Updated: 2023/06/29 18:48:41                                ###    ###   ###     ###         */
/*                                                                                                */
/*                                                                                                */
/*   The file contains engine of the Phases of the Moon widget. The images for the widget         */
/*   are located in the bitmap_library file.                                                      */
/*                                                                                                */
/* ********************************************************************************************** */

void ft_moon_phases_ui() {         
  // GETTING VALUES – yet to be implemented

  // MOON PHASES UI
    x=64;                                                             // ВРЕМЕННАЯ ФИКСАЦИЯ ПОЛОЖЕНИЯ НА ЭКРАНЕ – УДАЛИТЬ КОГДА УЖЕ НЕ НУЖНО
    if (x >= 63) display.drawLine(64, 51, 64, 12, WHITE);             // DIVIDING LINE BETWEEN THE UPPER AND LOWER SCREEN 
    if (rtcMng.minute >= 0 && rtcMng.minute <= 5)                                   // НЕ НАСТОЯЩИЕ ДАННЫЕ ФАЗ ЛУНЫ, А ПРОСТО ВРЕМЕННЫЙ МЕХАНИЗМ ДЛЯ ПОЛЬЗОВАТЕЛЬСКОГО ИНТЕРФЕЙСА
        display.drawBitmap(x+2, y, moon2, 64, 64, WHITE);
    if (rtcMng.minute >= 6 && rtcMng.minute <= 10)
        display.drawBitmap(x+2, y, moon3, 64, 64, WHITE);
    if (rtcMng.minute >= 11 && rtcMng.minute <= 15)
        display.drawBitmap(x+2, y, moon4, 64, 64, WHITE);
    if (rtcMng.minute >= 16 && rtcMng.minute <= 20)
        display.drawBitmap(x+2, y, moon5, 64, 64, WHITE);                                                        
    if (rtcMng.minute >= 21 && rtcMng.minute <= 25)                                            
        display.drawBitmap(x+2, y, moon6, 64, 64, WHITE);
    if (rtcMng.minute >= 26 && rtcMng.minute <= 30)
        display.drawBitmap(x+2, y, moon7, 64, 64, WHITE);
    if (rtcMng.minute >= 31 && rtcMng.minute <= 35)
        display.drawBitmap(x+2, y, moon8, 64, 64, WHITE);
    if (rtcMng.minute >= 36 && rtcMng.minute <= 40)
        display.drawBitmap(x+2, y, moon9, 64, 64, WHITE);                                                                    
    if (rtcMng.minute >= 41 && rtcMng.minute <= 45)                                            
        display.drawBitmap(x+2, y, moon10, 64, 64, WHITE);
    if (rtcMng.minute >= 46 && rtcMng.minute <= 50)
        display.drawBitmap(x+2, y, moon11, 64, 64, WHITE);
    if (rtcMng.minute >= 51 && rtcMng.minute <= 55)
        display.drawBitmap(x+2, y, moon12, 64, 64, WHITE);
    if (rtcMng.minute >= 56 && rtcMng.minute <= 60)
        display.drawBitmap(x+2, y, moon1, 64, 64, WHITE);      

}        
