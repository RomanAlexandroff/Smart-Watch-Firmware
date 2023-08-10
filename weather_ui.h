/* ********************************************************************************************** */
/*                                                                                                */
/*   Smart Watch Firmware                                              :::::::::        :::       */
/*   weather_ui.h                                                     :+:    :+:     :+: :+:      */
/*                                                                   +:+    +:+    +:+   +:+      */
/*   By: Roman Alexandrov <r.aleksandroff@gmail.com>                +#++:++#:    +#++:++#++:      */
/*                                                                 +#+    +#+   +#+     +#+       */
/*   Created: 2023/06/28 14:49:16                                 #+#    #+#   #+#     #+#        */
/*   Updated: 2023/06/29 18:48:41                                ###    ###   ###     ###         */
/*                                                                                                */
/*                                                                                                */
/*   The function assembles all the weather related information in a correct order and puts       */
/*   it into a temporary memory for it to be displayed later.                                     */
/*                                                                                                */
/* ********************************************************************************************** */

void ft_weather_ui() { 
    x = 64;                                                                             // ВРЕМЕННАЯ ФИКСАЦИЯ ПОЛОЖЕНИЯ НА ЭКРАНЕ – УДАЛИТЬ КОГДА УЖЕ НЕ НУЖНО
    display.drawLine(64, 51, 64, 12, WHITE);                                            // DIVIDING LINE BETWEEN THE UPPER AND LOWER SCREEN 
    if (rtcValues.weather_id == 800)                                                                              // CLEAR
    {
        if (rtcMng.hour > 5 && rtcMng.hour < 22)
            display.drawBitmap(x+6, y+11, ClearDay, 30, 42, WHITE);
        else
            display.drawBitmap(x+6, y+11, ClearNight, 30, 42, WHITE);
    }
    if (rtcValues.weather_id == 801 || rtcValues.weather_id >= 701 && rtcValues.weather_id <= 781)                // CLOUDS
    {
        if (rtcMng.hour > 6 && rtcMng.hour < 22)
            display.drawBitmap(x+6, y+10, LightCloudsDay, 30, 42, WHITE);
        else
            display.drawBitmap(x+6, y+11, LightCloudsNight, 30, 42, WHITE);
    }         
    if (rtcValues.weather_id == 802 || rtcValues.weather_id == 803)
        display.drawBitmap(x+6, y+10, ModerateClouds, 30, 42, WHITE);
    if (rtcValues.weather_id == 804)
        display.drawBitmap(x+6, y+10, HeavyClouds, 30, 42, WHITE);
    if (rtcValues.weather_id >= 300 && rtcValues.weather_id <= 500 || rtcValues.weather_id == 520)                // RAIN
        display.drawBitmap(x+6, y+10, LightRain, 30, 42, WHITE);
    if (rtcValues.weather_id == 501 || rtcValues.weather_id == 521)
        display.drawBitmap(x+6, y+10, ModerateRain, 30, 42, WHITE);
    if (rtcValues.weather_id >= 502 && rtcValues.weather_id <= 504 || rtcValues.weather_id >= 522 && rtcValues.weather_id <= 531)
        display.drawBitmap(x+6, y+10, HeavyRain, 30, 42, WHITE);
    if (rtcValues.weather_id == 511 || rtcValues.weather_id >= 611 && rtcValues.weather_id <= 616)
        display.drawBitmap(x+6, y+10, RainWithSnow, 30, 42, WHITE);               
    if (rtcValues.weather_id >= 200 && rtcValues.weather_id <= 232)                                               // THUNDERSTORM
        display.drawBitmap(x+6, y+10, Storm, 30, 42, WHITE);
    if (rtcValues.weather_id == 600 || rtcValues.weather_id == 620)                                               // SNOW
        display.drawBitmap(x+6, y+10, LightSnow, 30, 42, WHITE);
    if (rtcValues.weather_id == 601 || rtcValues.weather_id == 621)
        display.drawBitmap(x+6, y+10, ModerateSnow, 30, 42, WHITE);          
    if (rtcValues.weather_id == 602 || rtcValues.weather_id == 622)
        display.drawBitmap(x+6, y+10, HeavySnow, 30, 42, WHITE);         
    switch(rtcValues.temp)
    {
       case -10:                                                                      // -10
            display.drawBitmap(x+42, y+46,  bit_minus, 19, 12, WHITE);
            display.drawBitmap(x+42, y+33,  bit_num1, 19, 12, WHITE);                 // Current temperature - Position1 
            display.drawBitmap(x+42, y+19,  bit_num0, 19, 12, WHITE);                 // Current temperature - Position2
            display.drawBitmap(x+43, y+5,  bit_celsius, 19, 12, WHITE);
            break; 
        case -9: 
            display.drawBitmap(x+42, y+38,  bit_minus, 19, 12, WHITE);
            display.drawBitmap(x+42, y+25,  bit_num9, 19, 12, WHITE);
            display.drawBitmap(x+43, y+11,  bit_celsius, 19, 12, WHITE);
            break; 
        case -8: 
            display.drawBitmap(x+42, y+38,  bit_minus, 19, 12, WHITE);
            display.drawBitmap(x+42, y+25,  bit_num8, 19, 12, WHITE);
            display.drawBitmap(x+43, y+11,  bit_celsius, 19, 12, WHITE);
            break; 
        case -7: 
            display.drawBitmap(x+42, y+38,  bit_minus, 19, 12, WHITE);
            display.drawBitmap(x+42, y+25,  bit_num7, 19, 12, WHITE);
            display.drawBitmap(x+43, y+11,  bit_celsius, 19, 12, WHITE);
            break; 
        case -6: 
            display.drawBitmap(x+42, y+38,  bit_minus, 19, 12, WHITE);
            display.drawBitmap(x+42, y+25,  bit_num6, 19, 12, WHITE);
            display.drawBitmap(x+43, y+11,  bit_celsius, 19, 12, WHITE);
            break; 
        case -5: 
            display.drawBitmap(x+42, y+38,  bit_minus, 19, 12, WHITE);
            display.drawBitmap(x+42, y+25,  bit_num5, 19, 12, WHITE);
            display.drawBitmap(x+43, y+11,  bit_celsius, 19, 12, WHITE);
            break; 
        case -4: 
            display.drawBitmap(x+42, y+38,  bit_minus, 19, 12, WHITE);
            display.drawBitmap(x+42, y+25,  bit_num4, 19, 12, WHITE);
            display.drawBitmap(x+43, y+11,  bit_celsius, 19, 12, WHITE);
            break; 
        case -3: 
            display.drawBitmap(x+42, y+38,  bit_minus, 19, 12, WHITE);
            display.drawBitmap(x+42, y+25,  bit_num3, 19, 12, WHITE);
            display.drawBitmap(x+43, y+11,  bit_celsius, 19, 12, WHITE);
            break; 
        case -2: 
            display.drawBitmap(x+42, y+38,  bit_minus, 19, 12, WHITE);
            display.drawBitmap(x+42, y+25,  bit_num2, 19, 12, WHITE);
            display.drawBitmap(x+43, y+11,  bit_celsius, 19, 12, WHITE);
            break;
        case -1: 
            display.drawBitmap(x+42, y+38,  bit_minus, 19, 12, WHITE);
            display.drawBitmap(x+42, y+25,  bit_num1, 19, 12, WHITE);
            display.drawBitmap(x+43, y+11,  bit_celsius, 19, 12, WHITE);
            break;
        case 0:                         
            display.drawBitmap(x+42, y+33,  bit_num0, 19, 12, WHITE);                 // Current temperature - ZERO
            display.drawBitmap(x+43, y+19,  bit_celsius, 19, 12, WHITE);
            break;
        case 1: 
            display.drawBitmap(x+42, y+38,  bit_plus, 19, 12, WHITE);
            display.drawBitmap(x+42, y+25,  bit_num1, 19, 12, WHITE);
            display.drawBitmap(x+43, y+11,  bit_celsius, 19, 12, WHITE);
            break;
        case 2: 
            display.drawBitmap(x+42, y+38,  bit_plus, 19, 12, WHITE);
            display.drawBitmap(x+42, y+25,  bit_num2, 19, 12, WHITE);
            display.drawBitmap(x+43, y+11,  bit_celsius, 19, 12, WHITE);
            break;
        case 3: 
            display.drawBitmap(x+42, y+38,  bit_plus, 19, 12, WHITE);
            display.drawBitmap(x+42, y+25,  bit_num3, 19, 12, WHITE);
            display.drawBitmap(x+43, y+11,  bit_celsius, 19, 12, WHITE);
            break;
        case 4: 
            display.drawBitmap(x+42, y+38,  bit_plus, 19, 12, WHITE);
            display.drawBitmap(x+42, y+25,  bit_num4, 19, 12, WHITE); 
            display.drawBitmap(x+43, y+11,  bit_celsius, 19, 12, WHITE);
            break;
        case 5: 
            display.drawBitmap(x+42, y+38,  bit_plus, 19, 12, WHITE);
            display.drawBitmap(x+42, y+25,  bit_num5, 19, 12, WHITE); 
            display.drawBitmap(x+43, y+11,  bit_celsius, 19, 12, WHITE);
            break;
        case 6: 
            display.drawBitmap(x+42, y+38,  bit_plus, 19, 12, WHITE);
            display.drawBitmap(x+42, y+25,  bit_num6, 19, 12, WHITE);
            display.drawBitmap(x+43, y+11,  bit_celsius, 19, 12, WHITE);
            break;
        case 7: 
            display.drawBitmap(x+42, y+38,  bit_plus, 19, 12, WHITE);
            display.drawBitmap(x+42, y+25,  bit_num7, 19, 12, WHITE); 
            display.drawBitmap(x+43, y+11,  bit_celsius, 19, 12, WHITE);
            break;
        case 8: 
            display.drawBitmap(x+42, y+38,  bit_plus, 19, 12, WHITE);
            display.drawBitmap(x+42, y+25,  bit_num8, 19, 12, WHITE);
            display.drawBitmap(x+43, y+11,  bit_celsius, 19, 12, WHITE);
            break;
        case 9: 
            display.drawBitmap(x+42, y+38,  bit_plus, 19, 12, WHITE);
            display.drawBitmap(x+42, y+25,  bit_num9, 19, 12, WHITE);
            display.drawBitmap(x+43, y+11,  bit_celsius, 19, 12, WHITE);
            break;
        case 10:                                                                      // +10
            display.drawBitmap(x+42, y+46,  bit_plus, 19, 12, WHITE);
            display.drawBitmap(x+42, y+33,  bit_num1, 19, 12, WHITE);
            display.drawBitmap(x+42, y+19,  bit_num0, 19, 12, WHITE);
            display.drawBitmap(x+43, y+5,  bit_celsius, 19, 12, WHITE);
            break;
        case 11: 
            display.drawBitmap(x+42, y+46,  bit_plus, 19, 12, WHITE);
            display.drawBitmap(x+42, y+33,  bit_num1, 19, 12, WHITE);
            display.drawBitmap(x+42, y+19,  bit_num1, 19, 12, WHITE);
            display.drawBitmap(x+43, y+5,  bit_celsius, 19, 12, WHITE);
            break;
        case 12: 
            display.drawBitmap(x+42, y+46,  bit_plus, 19, 12, WHITE);
            display.drawBitmap(x+42, y+33,  bit_num1, 19, 12, WHITE);
            display.drawBitmap(x+42, y+19,  bit_num2, 19, 12, WHITE);
            display.drawBitmap(x+43, y+5,  bit_celsius, 19, 12, WHITE);
            break;
        case 13: 
            display.drawBitmap(x+42, y+46,  bit_plus, 19, 12, WHITE);
            display.drawBitmap(x+42, y+33,  bit_num1, 19, 12, WHITE); 
            display.drawBitmap(x+42, y+19,  bit_num3, 19, 12, WHITE);
            display.drawBitmap(x+43, y+5,  bit_celsius, 19, 12, WHITE);
            break;
        case 14: 
            display.drawBitmap(x+42, y+46,  bit_plus, 19, 12, WHITE);
            display.drawBitmap(x+42, y+33,  bit_num1, 19, 12, WHITE); 
            display.drawBitmap(x+42, y+19,  bit_num4, 19, 12, WHITE);
            display.drawBitmap(x+43, y+5,  bit_celsius, 19, 12, WHITE);
            break;
        case 15: 
            display.drawBitmap(x+42, y+46,  bit_plus, 19, 12, WHITE);
            display.drawBitmap(x+42, y+33,  bit_num1, 19, 12, WHITE);
            display.drawBitmap(x+42, y+19,  bit_num5, 19, 12, WHITE);
            display.drawBitmap(x+43, y+5,  bit_celsius, 19, 12, WHITE);
            break;
        case 16: 
            display.drawBitmap(x+42, y+46,  bit_plus, 19, 12, WHITE);
            display.drawBitmap(x+42, y+33,  bit_num1, 19, 12, WHITE);
            display.drawBitmap(x+42, y+19,  bit_num6, 19, 12, WHITE);
            display.drawBitmap(x+43, y+5,  bit_celsius, 19, 12, WHITE);
            break;
        case 17: 
            display.drawBitmap(x+42, y+46,  bit_plus, 19, 12, WHITE);
            display.drawBitmap(x+42, y+33,  bit_num1, 19, 12, WHITE);
            display.drawBitmap(x+42, y+19,  bit_num7, 19, 12, WHITE);
            display.drawBitmap(x+43, y+5,  bit_celsius, 19, 12, WHITE);
            break;
        case 18: 
            display.drawBitmap(x+42, y+46,  bit_plus, 19, 12, WHITE);
            display.drawBitmap(x+42, y+33,  bit_num1, 19, 12, WHITE);
            display.drawBitmap(x+42, y+19,  bit_num8, 19, 12, WHITE);
            display.drawBitmap(x+43, y+5,  bit_celsius, 19, 12, WHITE);
            break;
        case 19: 
            display.drawBitmap(x+42, y+46,  bit_plus, 19, 12, WHITE);
            display.drawBitmap(x+42, y+33,  bit_num1, 19, 12, WHITE); 
            display.drawBitmap(x+42, y+19,  bit_num9, 19, 12, WHITE);
            display.drawBitmap(x+43, y+5,  bit_celsius, 19, 12, WHITE);
            break;
        case 20:                                                                      // +20 
            display.drawBitmap(x+42, y+46,  bit_plus, 19, 12, WHITE);
            display.drawBitmap(x+42, y+33,  bit_num2, 19, 12, WHITE);
            display.drawBitmap(x+42, y+19,  bit_num0, 19, 12, WHITE);
            display.drawBitmap(x+43, y+5,  bit_celsius, 19, 12, WHITE);
            break;
        case 21: 
            display.drawBitmap(x+42, y+46,  bit_plus, 19, 12, WHITE);
            display.drawBitmap(x+42, y+33,  bit_num2, 19, 12, WHITE);
            display.drawBitmap(x+42, y+19,  bit_num1, 19, 12, WHITE);
            display.drawBitmap(x+43, y+5,  bit_celsius, 19, 12, WHITE);
            break;
        case 22: 
            display.drawBitmap(x+42, y+46,  bit_plus, 19, 12, WHITE);
            display.drawBitmap(x+42, y+33,  bit_num2, 19, 12, WHITE); 
            display.drawBitmap(x+42, y+19,  bit_num2, 19, 12, WHITE);
            display.drawBitmap(x+43, y+5,  bit_celsius, 19, 12, WHITE);
            break;
        case 23: 
            display.drawBitmap(x+42, y+46,  bit_plus, 19, 12, WHITE);
            display.drawBitmap(x+42, y+33,  bit_num2, 19, 12, WHITE);
            display.drawBitmap(x+42, y+19,  bit_num3, 19, 12, WHITE);
            display.drawBitmap(x+43, y+5,  bit_celsius, 19, 12, WHITE);
            break;
        case 24: 
            display.drawBitmap(x+42, y+46,  bit_plus, 19, 12, WHITE);
            display.drawBitmap(x+42, y+33,  bit_num2, 19, 12, WHITE);
            display.drawBitmap(x+42, y+19,  bit_num4, 19, 12, WHITE);
            display.drawBitmap(x+43, y+5,  bit_celsius, 19, 12, WHITE);
            break;
        case 25: 
            display.drawBitmap(x+42, y+46,  bit_plus, 19, 12, WHITE);
            display.drawBitmap(x+42, y+33,  bit_num2, 19, 12, WHITE);
            display.drawBitmap(x+42, y+19,  bit_num5, 19, 12, WHITE);
            display.drawBitmap(x+43, y+5,  bit_celsius, 19, 12, WHITE);
            break;
        case 26: 
            display.drawBitmap(x+42, y+46,  bit_plus, 19, 12, WHITE);
            display.drawBitmap(x+42, y+33,  bit_num2, 19, 12, WHITE);
            display.drawBitmap(x+42, y+19,  bit_num6, 19, 12, WHITE);
            display.drawBitmap(x+43, y+5,  bit_celsius, 19, 12, WHITE);
            break;
        case 27: 
            display.drawBitmap(x+42, y+46,  bit_plus, 19, 12, WHITE);
            display.drawBitmap(x+42, y+33,  bit_num2, 19, 12, WHITE); 
            display.drawBitmap(x+42, y+19,  bit_num7, 19, 12, WHITE);
            display.drawBitmap(x+43, y+5,  bit_celsius, 19, 12, WHITE);
            break;
        case 28: 
            display.drawBitmap(x+42, y+46,  bit_plus, 19, 12, WHITE);
            display.drawBitmap(x+42, y+33,  bit_num2, 19, 12, WHITE); 
            display.drawBitmap(x+42, y+19,  bit_num8, 19, 12, WHITE);
            display.drawBitmap(x+43, y+5,  bit_celsius, 19, 12, WHITE);
            break;
        case 29: 
            display.drawBitmap(x+42, y+46,  bit_plus, 19, 12, WHITE);
            display.drawBitmap(x+42, y+33,  bit_num2, 19, 12, WHITE); 
            display.drawBitmap(x+42, y+19,  bit_num9, 19, 12, WHITE);
            display.drawBitmap(x+43, y+5,  bit_celsius, 19, 12, WHITE);
            break;
        case 30:                                                                      // +30 
            display.drawBitmap(x+42, y+46,  bit_plus, 19, 12, WHITE);
            display.drawBitmap(x+42, y+33,  bit_num3, 19, 12, WHITE);
            display.drawBitmap(x+42, y+19,  bit_num0, 19, 12, WHITE);
            display.drawBitmap(x+43, y+5,  bit_celsius, 19, 12, WHITE);
            break;
        case 31: 
            display.drawBitmap(x+42, y+46,  bit_plus, 19, 12, WHITE);
            display.drawBitmap(x+42, y+33,  bit_num3, 19, 12, WHITE);
            display.drawBitmap(x+42, y+19,  bit_num1, 19, 12, WHITE);
            display.drawBitmap(x+43, y+5,  bit_celsius, 19, 12, WHITE);
            break;
        case 32: 
            display.drawBitmap(x+42, y+46,  bit_plus, 19, 12, WHITE);
            display.drawBitmap(x+42, y+33,  bit_num3, 19, 12, WHITE); 
            display.drawBitmap(x+42, y+19,  bit_num2, 19, 12, WHITE);
            display.drawBitmap(x+43, y+5,  bit_celsius, 19, 12, WHITE);
            break;
        case 33: 
            display.drawBitmap(x+42, y+46,  bit_plus, 19, 12, WHITE);
            display.drawBitmap(x+42, y+33,  bit_num3, 19, 12, WHITE); 
            display.drawBitmap(x+42, y+19,  bit_num3, 19, 12, WHITE);
            display.drawBitmap(x+43, y+5,  bit_celsius, 19, 12, WHITE);
            break;
        case 34: 
            display.drawBitmap(x+42, y+46,  bit_plus, 19, 12, WHITE);
            display.drawBitmap(x+42, y+33,  bit_num3, 19, 12, WHITE); 
            display.drawBitmap(x+42, y+19,  bit_num4, 19, 12, WHITE);
            display.drawBitmap(x+43, y+5,  bit_celsius, 19, 12, WHITE);
            break;
        case 35: 
            display.drawBitmap(x+42, y+46,  bit_plus, 19, 12, WHITE);
            display.drawBitmap(x+42, y+33,  bit_num3, 19, 12, WHITE); 
            display.drawBitmap(x+42, y+19,  bit_num5, 19, 12, WHITE);
            display.drawBitmap(x+43, y+5,  bit_celsius, 19, 12, WHITE);
            break;
        case 36: 
            display.drawBitmap(x+42, y+46,  bit_plus, 19, 12, WHITE);
            display.drawBitmap(x+42, y+33,  bit_num3, 19, 12, WHITE); 
            display.drawBitmap(x+42, y+19,  bit_num6, 19, 12, WHITE);
            display.drawBitmap(x+43, y+5,  bit_celsius, 19, 12, WHITE);
            break;
        case 37: 
            display.drawBitmap(x+42, y+46,  bit_plus, 19, 12, WHITE);
            display.drawBitmap(x+42, y+33,  bit_num3, 19, 12, WHITE);
            display.drawBitmap(x+42, y+19,  bit_num7, 19, 12, WHITE);
            display.drawBitmap(x+43, y+5,  bit_celsius, 19, 12, WHITE);
            break;
        case 38: 
            display.drawBitmap(x+42, y+46,  bit_plus, 19, 12, WHITE);
            display.drawBitmap(x+42, y+33,  bit_num3, 19, 12, WHITE); 
            display.drawBitmap(x+42, y+19,  bit_num8, 19, 12, WHITE);
            display.drawBitmap(x+43, y+5,  bit_celsius, 19, 12, WHITE);
            break;
        case 39: 
            display.drawBitmap(x+42, y+46,  bit_plus, 19, 12, WHITE);
            display.drawBitmap(x+42, y+33,  bit_num3, 19, 12, WHITE);
            display.drawBitmap(x+42, y+19,  bit_num9, 19, 12, WHITE);
            display.drawBitmap(x+43, y+5,  bit_celsius, 19, 12, WHITE);
            break;
        case 40:                                                                      // +40 
            display.drawBitmap(x+42, y+46,  bit_plus, 19, 12, WHITE);
            display.drawBitmap(x+42, y+33,  bit_num4, 19, 12, WHITE);
            display.drawBitmap(x+42, y+19,  bit_num0, 19, 12, WHITE);
            display.drawBitmap(x+43, y+5,  bit_celsius, 19, 12, WHITE);
            break;
        case 41: 
            display.drawBitmap(x+42, y+46,  bit_plus, 19, 12, WHITE);
            display.drawBitmap(x+42, y+33,  bit_num4, 19, 12, WHITE); 
            display.drawBitmap(x+42, y+19,  bit_num1, 19, 12, WHITE);
            display.drawBitmap(x+43, y+5,  bit_celsius, 19, 12, WHITE);
            break;
        case 42: 
            display.drawBitmap(x+42, y+46,  bit_plus, 19, 12, WHITE);
            display.drawBitmap(x+42, y+33,  bit_num4, 19, 12, WHITE);
            display.drawBitmap(x+42, y+19,  bit_num2, 19, 12, WHITE);
            display.drawBitmap(x+43, y+5,  bit_celsius, 19, 12, WHITE);
            break;
        case 43: 
            display.drawBitmap(x+42, y+46,  bit_plus, 19, 12, WHITE);
            display.drawBitmap(x+42, y+33,  bit_num4, 19, 12, WHITE); 
            display.drawBitmap(x+42, y+19,  bit_num3, 19, 12, WHITE);
            display.drawBitmap(x+43, y+5,  bit_celsius, 19, 12, WHITE);
            break;
        case 44: 
            display.drawBitmap(x+42, y+46,  bit_plus, 19, 12, WHITE);
            display.drawBitmap(x+42, y+33,  bit_num4, 19, 12, WHITE);
            display.drawBitmap(x+42, y+19,  bit_num4, 19, 12, WHITE);
            display.drawBitmap(x+43, y+5,  bit_celsius, 19, 12, WHITE);
            break;
        case 45: 
            display.drawBitmap(x+42, y+46,  bit_plus, 19, 12, WHITE);
            display.drawBitmap(x+42, y+33,  bit_num4, 19, 12, WHITE); 
            display.drawBitmap(x+42, y+19,  bit_num5, 19, 12, WHITE);
            display.drawBitmap(x+43, y+5,  bit_celsius, 19, 12, WHITE);
            break;
        case 46: 
            display.drawBitmap(x+42, y+46,  bit_plus, 19, 12, WHITE);
            display.drawBitmap(x+42, y+33,  bit_num4, 19, 12, WHITE); 
            display.drawBitmap(x+42, y+19,  bit_num6, 19, 12, WHITE);
            display.drawBitmap(x+43, y+5,  bit_celsius, 19, 12, WHITE);
            break;
        case 47: 
            display.drawBitmap(x+42, y+46,  bit_plus, 19, 12, WHITE);
            display.drawBitmap(x+42, y+33,  bit_num4, 19, 12, WHITE); 
            display.drawBitmap(x+42, y+19,  bit_num7, 19, 12, WHITE);
            display.drawBitmap(x+43, y+5,  bit_celsius, 19, 12, WHITE);
            break;
        case 48: 
            display.drawBitmap(x+42, y+46,  bit_plus, 19, 12, WHITE);
            display.drawBitmap(x+42, y+33,  bit_num4, 19, 12, WHITE); 
            display.drawBitmap(x+42, y+19,  bit_num8, 19, 12, WHITE);
            display.drawBitmap(x+43, y+5,  bit_celsius, 19, 12, WHITE);
            break;
        case 49: 
            display.drawBitmap(x+42, y+46,  bit_plus, 19, 12, WHITE);
            display.drawBitmap(x+42, y+33,  bit_num4, 19, 12, WHITE); 
            display.drawBitmap(x+42, y+19,  bit_num9, 19, 12, WHITE);
            display.drawBitmap(x+43, y+5,  bit_celsius, 19, 12, WHITE);
            break;
        case 50:                                                                      // +50 
            display.drawBitmap(x+42, y+46,  bit_plus, 19, 12, WHITE);
            display.drawBitmap(x+42, y+33,  bit_num5, 19, 12, WHITE); 
            display.drawBitmap(x+42, y+19,  bit_num0, 19, 12, WHITE);
            display.drawBitmap(x+43, y+5,  bit_celsius, 19, 12, WHITE);
            break;
        default:                                                                      // Error message "--"  
            display.drawBitmap(x+42, y+33, bit_minus, 19, 12, WHITE);
            display.drawBitmap(x+42, y+19, bit_minus, 19, 12, WHITE);
    }          
}
 
