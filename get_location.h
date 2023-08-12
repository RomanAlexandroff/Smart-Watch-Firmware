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
    const char*         address_detail_city;                              // Default city name — Prague
    const char*         status;
    char                bssid[6];
    String              IP;
    String              jsonString;
    DynamicJsonDocument doc(264);

    IP = WiFi.localIP().toString();
    status = "Error";                                                     // Shows communication with server status
    DEBUG_PRINT("ft_get_location function BEGIN");
    DEBUG_PRINT("Current IP: "); DEBUG_PRINT(IP);
/*
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
    jsonString += ("}\n");
*/

//    client.setFingerprint(sslFingerprint);

    HTTPClient http;

    // configure traged server and url
    http.begin(client, server_name);
    DEBUG_PRINT("Target server: "); DEBUG_PRINT(server_name);
    http.addHeader("Content-Type", "application/json");
    int httpResponseCode = http.POST("{\n\"token\": \"pk.051929e8338d2971fa007db8ae5f45fe\",\n\"ip\": \"46.135.18.126\",\n\"fallbacks\": {\n\"ipf\": \"1\"\n},\n\"address\": 2\n}");
    DEBUG_PRINT("Outgoing request: "); DEBUG_PRINT(httpResponseCode);

/*
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
*/  
    while (client.available())
    {
        DEBUG_PRINT("Server connection SUCCESS");
        String line = client.readString();
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
    DEBUG_PRINT("Server connection FAILED");
    http.end();
    DEBUG_PRINT("ft_get_location function FINISHED");
}
 
