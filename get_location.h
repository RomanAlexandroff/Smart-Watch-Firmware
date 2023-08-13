/* ********************************************************************************************** */
/*                                                                                                */
/*   Smart Watch Firmware                                              :::::::::        :::       */
/*   get_location.h                                                   :+:    :+:     :+: :+:      */
/*                                                                   +:+    +:+    +:+   +:+      */
/*   By: Roman Alexandrov <r.aleksandroff@gmail.com>                +#++:++#:    +#++:++#++:      */
/*                                                                 +#+    +#+   +#+     +#+       */
/*   Created: 2023/06/28 14:49:16                                 #+#    #+#   #+#     #+#        */
/*   Updated: 2023/06/29 18:48:41                                ###    ###   ###     ###         */
/*                                                                                                */
/*                                                                                                */
/*   This sketch retrieves location values from the UnwiredLabs server.                           */
/*                                                                                                */
/* ********************************************************************************************** */

void  ft_get_location(void)
{
    const char*         server_name;
    int                 http_response;
    char                bssid[6];
    String              IP;
    String              jsonString;
    DynamicJsonDocument doc(264);
    String              line;
    const char*         status;
    const char*         address_detail_city;

    server_name = "https://ap1.unwiredlabs.com/v2/process.php";
    status = "Error";
    IP = WiFi.localIP().toString();
    DEBUG_PRINT("ft_get_location function BEGIN");
    DEBUG_PRINT("Current IP: "); DEBUG_PRINT(IP);
    jsonString = "{\n";
    jsonString += "\"token\": \"";
    jsonString += token;
    jsonString += "\",\n";
    jsonString += "\"ip\": \"";
    jsonString += IP;
    jsonString += "\",\n";
    jsonString += "\"fallbacks\": {\n";
    jsonString += "\"ipf\" : \"1\"\n";
    jsonString += "},\n";        
    jsonString += "\"address\": 2\n";    
    jsonString += "}\n";
    client.setFingerprint(sslFingerprint);
    HTTPClient http;
    http.begin(client, server_name);
    DEBUG_PRINT("Target server: ");
    DEBUG_PRINT(server_name);
    http.addHeader("Content-Type", "application/json");
    http_response = http.POST(jsonString);
    DEBUG_PRINT("Outgoing request: ");
    DEBUG_PRINT(http_response);
    if (client.connect(Host, 443))                                          // Connect to the client and make the api call 
    {
        DEBUG_PRINT("Server connection SUCCESS");
        client.println("POST " + endpoint + " HTTP/1.1");
        client.println("Host: " + (String)Host);
        client.println("Connection: close");
        client.println("Content-Type: application/json");
        client.println("User-Agent: Arduino/1.0");
        client.println("Content-Length: ");
        client.println(jsonString.length());
        client.println();
        client.print(jsonString);
        delay(500);                                                         // Approx. real time gap is 250-380 ms
    }
    else
    {
        DEBUG_PRINT("Server connection FAILED");
        return;
    }
    while (client.available())
    {
        DEBUG_PRINT("Server connection SUCCESS");
        line = client.readString();
        StaticJsonDocument<384> doc;
        DeserializationError error = deserializeJson(doc, line);
        if (error)
        {
            DEBUG_PRINT("Deserialization error");
            return;
        }
        DEBUG_PRINT("Deserialization successful");
        status = doc["status"];
        lat = doc["lat"];
        lon = doc["lon"];
        JsonObject address_detail = doc["address_detail"];
        address_detail_city = address_detail["city"];
        DEBUG_PRINT(status);
        DEBUG_PRINT(lat);
        DEBUG_PRINT(lon);
        DEBUG_PRINT(address_detail_city);
    }
    http.end();
    DEBUG_PRINT("ft_get_location function FINISHED");
}
 
