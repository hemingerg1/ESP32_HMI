# ESP32_HMI
This project is an HMI for displaying data and interfacing with a separate microcontroller acting as a PLC. Specifically, this HMI is set up to work with my [ESP32AirQuality](https://github.com/hemingerg1/ESP32AirQuality) project. This is a highly customized project for my particular use case, so it may not be suitable as-is for everyone. However, it can serve as an example of how you might create your own HMI. You are encouraged to fork this repository to make your own versions.

This project was designed for a Sunton ESP32-8048S070C display board and uses the LVGL library for creating a UI. The UI was designed in Squarline Studio and the files are included in this repository.

<!--
<p align="center"><img src="images/Home_page.png"></p>
-->

## Hardware Requirements
To run this project, you will need the following hardware components:
-	Sunton ESP32-8048S070C
    -	Or any other microcontroller-based touch screen should be able to be made to work with modifications.
 
## Software Requirements
The project requires the following software dependencies:
- Platformio: used for compiling and flashing the firmware
    - Libraries:
        - lovyan03/LovyanGFX@^1.1.7
        - lvgl/lvgl@^8.3.7
        - tobiasschuerg/ESP8266 Influxdb@^3.13.1
        - fbiego/ESP32Time@^2.0.4
        - 256dpi/MQTT@^2.5.1
- Squarline Studio: used to create and modify the UI


<br>  
<br>  

<details>
<summary> Contributing</summary>  
Contributions to this project are welcome. However, this is a highly customized project for my particular use case. You are encouraged to fork this repository to make your desired changes.
</details>

<details>
<summary> License </summary>
This project is licensed under the GNU General Public License. Feel free to use, modify, and distribute the code for personal or commercial purposes.
</details>
