/* ********************************************************************************************** */
/*                                                                                                */
/*   Smart Watch Firmware                                              :::::::::        :::       */
/*   get_weather.h                                                    :+:    :+:     :+: :+:      */
/*                                                                   +:+    +:+    +:+   +:+      */
/*   By: Roman Alexandrov <r.aleksandroff@gmail.com>                +#++:++#:    +#++:++#++:      */
/*                                                                 +#+    +#+   +#+     +#+       */
/*   Created: 2023/06/28 14:49:16                                 #+#    #+#   #+#     #+#        */
/*   Updated: 2023/06/29 18:48:41                                ###    ###   ###     ###         */
/*                                                                                                */
/*                                                                                                */
/*   This sketch retrieves weather values from the OpenWeather server and adapts them for         */
/*   further use.                                                                                 */
/*                                                                                                */
/* ********************************************************************************************** */

void  ft_get_weather(void)
{
    HTTPClient                http;
    String                    line;
    StaticJsonDocument<300>   doc;
    float                     temperature;
    
    DEBUG_PRINT("ft_get_weather function BEGIN");
    http.begin(client, (String(F("http://api.openweathermap.org/data/2.5/weather?lat="))
        + String(lat,2) + "&lon=" + String(lon,2)
        + String(F("&APPID=")) + api_key + String(F("&lang=en"))));
    http.addHeader(F("Content-Type"), F("text/plain"));
    auto httpCode = http.GET();
    line = http.getString();                                                     // get the response payload
    DEBUG_PRINT("Weather server response: ");
    DEBUG_PRINT(line);
    line.replace('[', ' ');
    line.replace(']', ' ');
    deserializeJson(doc, line);
    rtcValues.weather_id = doc[F("weather")][F("id")].as<int>();
    temperature = doc[F("main")][F("temp")].as<float>();
    rtcValues.temp = (ceil(temperature)) - 273;                                  // Kelvin to Celcius
    DEBUG_PRINT("ft_get_weather function FINISHED");
}
 
