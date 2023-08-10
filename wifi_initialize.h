/* ********************************************************************************************** */
/*                                                                                                */
/*   Smart Watch Firmware                                              :::::::::        :::       */
/*   wifi_initialize.h                                                :+:    :+:     :+: :+:      */
/*                                                                   +:+    +:+    +:+   +:+      */
/*   By: Roman Alexandrov <r.aleksandroff@gmail.com>                +#++:++#:    +#++:++#++:      */
/*                                                                 +#+    +#+   +#+     +#+       */
/*   Created: 2023/06/28 14:49:16                                 #+#    #+#   #+#     #+#        */
/*   Updated: 2023/06/29 18:48:41                                ###    ###   ###     ###         */
/*                                                                                                */
/*                                                                                                */
/*   Setting up and initialisig Wi-Fi connection in accordance with the ESP8266WiFiMulti          */
/*   library. The ft_wifi_list() function containing all the known Wi-Fi networks credentials     */
/*   must be called beforehand.                                                                   */
/*                                                                                                */
/* ********************************************************************************************** */

void  ft_wifi_init(void)
{
    WiFi.persistent(true);
    WiFi.mode(WIFI_STA);
    WiFi.hostname("Roman's Watch");
    ft_wifi_list();
    if (wifiMulti.run(g_connect_timeout) == WL_CONNECTED) 
    {
        DEBUG_PRINT("Successfully connected to Wi-Fi network");
    }
    else
    {
        DEBUG_PRINT("Unable to connect to Wi-Fi network. Proceeding without connection");
    }     
}
