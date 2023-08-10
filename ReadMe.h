/* ********************************************************************************************** */
/*                                                                                                */
/*   Smart Watch Firmware                                              :::::::::        :::       */
/*   ReadMe.h                                                         :+:    :+:     :+: :+:      */
/*                                                                   +:+    +:+    +:+   +:+      */
/*   By: Roman Alexandrov <r.aleksandroff@gmail.com>                +#++:++#:    +#++:++#++:      */
/*                                                                 +#+    +#+   +#+     +#+       */
/*   Created: 2023/06/28 14:49:16                                 #+#    #+#   #+#     #+#        */
/*   Updated: 2023/06/29 18:48:41                                ###    ###   ###     ###         */
/*                                                                                                */
/*                                                                                                */
/*   This file contains only notes and no code.                                                   */
/*                                                                                                */
/* ********************************************************************************************** */
/*
/*    PROJECT NOTES:
/*
/*    This firmware allows User to track an approximate location of ESP8285 based devices via
/*    Telegram chat notifications. Using this firmware the device connects to already known
/*    Wi-Fi networks and informs a pre-set Telegram chat of that fact. User of the device must
/*    manually input the credentials of the Wi-Fi networks he wishes to be notified of, as well
/*    as the Telegram chat ID he wishes to be notified to. User also should add a personalized 
/*    note to every inputed Wi-Fi network to indicate the network location. The device would
/*    check its connection status at most as frequently as once per hour and notify the chat if
/*    anything changes. The firmware does not allow access to any other means of locating.
/*    Considering all the above, the firmware provides a solid layer of privacy to anything or  
/*    anyone tracked by such a device, at the same time it reliably notifies User of the tracked
/*    items or persons' movements.
/*    What applications can it have:
/*        - parents can be sure their younger children successfully reached school and         
/*          then came back home after the lessons without invading their privacy,
/*        - companies can track location of their property without compromising the
/*          privacy of the employees who are being in possesion of the property,
/*        - senders can be notified of their valuable parcels having reached the intended
/*          destination without need of a confirmation from the receivers, etc.
/*    
/*    This sketch was firstly written as a toy for my Embedded Development group chat in
/*    Telegram. It would allow the group chat members to track where I was without discovering
/*    my precise location. The project was based on Brian Lough's Universal Telegram Bot Library:
/*    https://github.com/witnessmenow/Universal-Arduino-Telegram-Bot
/*     
/*    Triggering the OTA mode with an interrupt seems to be very unstable. Possibly, I could
/*    do that with battery charge level instead. When plugged in, ADC module outputs very 
/*    distinctive level of charge. I could use that to make the device understand, that it
/*    is being charged and that it is time to turn on the OTA mode. Experiments required.
/*    Possibly, I could make the device activate ability to be controlled from the Telegram
/*    chat when it is above 99% of battery charge. Then, by sending a special command to the
/*    device I make the device switch to OTA mode.
/*    Could it be easier to engineer UART into microUSB instead?? 
/*     
/*    The device reliably fails to connect to certain Wi-Fi hotspots. I've already tried 
/*    increasing connectTimeoutMs up to 10000 — no positive effect. I assume, that the problem
/*    may be in the WiFi.persistent(false) function that forbids the device to save WiFi
/*    configuration in flash. I have it turned "true" throughout the code now. Need to try it.
/*
/*    I tried implementing SPIFFS file system in order to store all the data managed by the code 
/*    in a single data.txt file. Unfortunatelly, implementation of this functionality occupied
/*    so much memory space, that the OTA update was no longer able to work. The functionality
/*    thus was discarted and RTC memory was used to store the data instead.
/*     
/*    WARNING! Do not call ft_go_to_sleep() function from ft_check_incomming_messages(), 
/*    ft_new_messages() and ft_OTAmode() functions! It causes the Telegram bot messages queue
/*    to get stuck on the same last message!
/*     
/*    IMPORTANT! Firmware file shall not to exeed 50% of the microprocessor memory. Otherwise 
/*    the OTA update functionality may no longer be able to perform the update. For ESP8285
/*    max firmware file size equals to 522232 bytes.
/*
/*
/************************************************************************************************ */
/*    
/*    ISSUES LOG:
/*
/*    UNSOLVED! If I write a command to the bot using reply function, it stops responding 
/*    to any commands at all. Other than that it continues properly working and continues reporting 
/*    its location to the chat. So far I was unable to fix the issue even by reflashing the firmware.
/*    I'm not aware how, but the problem fixes itself within 24 hours. Suddenly the device becomes
/*    responsive and answers all the comands that had been sent to it within its unavailability. 
/* 
/*
/*
/*
/*
/* 
/************************************************************************************************ */
