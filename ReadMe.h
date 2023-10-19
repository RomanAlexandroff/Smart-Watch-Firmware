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
/* ************************************************************************************************


        ABOUT THIS PROJECT

      Welcome to my firmware repository for an innovative smart watch! I've developed this firmware 
      with the goal of providing a simple yet powerful solution for building a customizable smart 
      watch with unique features. If you're a hobbyist, tinkerer, or developer looking to create 
      your own wearable device, this firmware offers a solid foundation to bring your ideas to life.

        
        KEY FEATURES

      Widgets Galore
      I've implemented a range of widgets to enhance the functionality of your smart watch. You'll 
      find both analog and digital clocks to suit your personal style, a calendar widget to keep 
      track of important dates, and a weather widget to keep you informed about the current 
      conditions. Additionally, I've included a widget that displays the phases of the Moon, adding 
      a touch of celestial charm to your device.

      Power-Save Mode
      I understand the importance of maximizing battery life on a wearable device. With my firmware, 
      you can take advantage of a power-save mode that intelligently manages power consumption. 
      Enjoy extended battery life without compromising the core functionality of your smart watch.

      Over The Air Firmware Update
      Keeping your smart watch up to date has never been easier. I've designed the firmware to 
      support Over The Air (OTA) firmware updates, ensuring that you can easily install the latest 
      features and bug fixes without the need for complicated manual procedures. Stay ahead of the 
      curve and enjoy the benefits of ongoing firmware improvements.

      Seamless Wi-Fi Connectivity
      Connectivity is a crucial aspect of any smart watch. My firmware provides seamless support for 
      multiple Wi-Fi networks, allowing you to stay connected no matter where you are. Effortlessly 
      switch between networks and enjoy uninterrupted access to online services and data synchronization.

      Intuitive User Inputs
      Interacting with your smart watch should be a breeze. That's why I've incorporated support for
      a scroll wheel, a button, and a tilt detector into the firmware. Navigate through menus, scroll 
      through widgets, and trigger actions with ease. Enjoy a seamless user experience that's tailored
      to your preferences.

      Vertical 128x64 Pixels OLED Display
      Break away from the traditional horizontal display orientation. My firmware enables you to utilize
      a 128x64 pixels OLED display vertically, opening up new design possibilities for your smart watch. 
      Custom-made icons and symbols ensure that the display remains clear and easy to read, regardless 
      of its uncommon orientation.


        CONTRIBUTE

      I've worked on this firmware alone, but I welcome contributions from the community. If you have 
      ideas for new features, bug fixes, or optimizations, feel free to submit a pull request. Together, 
      we can make this firmware even better.


        LICENSE

      This firmware is released under the MIT License. Please review the license file for more details.


        CONTACT

      If you have any questions, feedback, or suggestions, don't hesitate to reach out to me. You can 
      contact me through r.aleksandroff@gmail.com. I'm here to support you on your smart watch
      development journey.

      I hope you find my firmware project exciting and useful. Happy hacking!



  ***********************************************************************************************

  
        PROJECT NOTES:

      The hardware:
    
      Ai-Thinker ESP–01M module;
      OLED display, 128x64, controller SSD1306, white pixels, I2C bus;
      LiPol Battery, 230mAh, 3.7V;
      Rotary encoder;
      Button [ VCC———INTERNAL_PULLUP_RESISTOR———GPIO———BUTTON———GND ];
      SW-520D tilt detector;    


  ***********************************************************************************************


        CALCULATING CONSTANTS FOR BATTERY CHARGE FUNCTION:

      You will need to check the following little utility:
      https://github.com/RomanAlexandroff/ESP-Battery-Charge-Utility
      
      It was designed to be a universal solution for battery charge level detection in ESP-based
      projects and has all the instructions inside of it.

  
  *********************************************************************************************** */
