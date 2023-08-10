/* ********************************************************************************************** */
/*                                                                                                */
/*   Smart Watch Firmware                                              :::::::::        :::       */
/*   wifi_list.h                                                      :+:    :+:     :+: :+:      */
/*                                                                   +:+    +:+    +:+   +:+      */
/*   By: Roman Alexandrov <r.aleksandroff@gmail.com>                +#++:++#:    +#++:++#++:      */
/*                                                                 +#+    +#+   +#+     +#+       */
/*   Created: 2023/06/28 14:49:16                                 #+#    #+#   #+#     #+#        */
/*   Updated: 2023/06/29 18:48:41                                ###    ###   ###     ###         */
/*                                                                                                */
/*                                                                                                */
/*   List of known Wi-Fi networks in accordance with the ESP8266WiFiMulti library. More           */
/*   networks credentials can be added in an identical fasion ("SSID", "password"). The           */
/*   list must be called before the wifiMulti.run() function, which initiates connection.         */
/*                                                                                                */
/* ********************************************************************************************** */

void  ft_wifi_list(void)
{
    wifiMulti.addAP("brok.jmnet.cz", "19S67MBA");
    wifiMulti.addAP("42p_guest", "guest.of.42");
    wifiMulti.addAP("brmlab.cz", "brmlabINSIDE!");
    wifiMulti.addAP("Roman_iPhone_8", "qweasdyxc123");
    wifiMulti.addAP("Stas118_2.4", "180915LK");
    wifiMulti.addAP("stas", "18091809");
    wifiMulti.addAP("O2-Internet-304", "SJd96Qux");
    wifiMulti.addAP("Parlor", "Iloveicecream2");
    wifiMulti.addAP("camppraha", "karelprager");
    wifiMulti.addAP("pavaon.cz", "pavaon11");
    wifiMulti.addAP("BERNARD", "jeseniova93");
}
 
