# I2C-with-Adxl345
## **Project Overview**
_This project demonstrates an I2C communication interface between an STM32F411 microcontroller and the ADXL345 accelerometer. The implementation involves configuring the STM32 I2C peripheral to fetch real-time acceleration data in multiple axes using both bare-metal programming and HAL library approaches._

## **Purpose and Goals**</br>
The primary objective of this project is to establish and explore I2C communication between the STM32F411 microcontroller and the ADXL345 accelerometer. The project showcases two approaches:

**Bare-Metal Programming**: Directly accessing peripheral registers for precise control.</br>
**HAL Libraries**: Using STM32 HAL APIs for simplified and modular implementation.</br>

## **Key Features** </br>
a) Configured the STM32F411 I2C peripheral for accurate communication with the ADXL345 sensor.</br>
b) Set up the ADXL345 to operate in measurement mode and fetch acceleration data along X, Y, and Z axes.</br>
c) Utilized a polling-based mechanism to read data from the ADXL345.</br>
d) Designed reusable functions for I2C initialization, data transmission, and data reception.
Technical Highlights </br>

### I2C Peripheral Configuration: </br>
Configured clock speed, addressing modes, and data acknowledgment settings for proper I2C operation. </br>
### ADXL345 Setup: </br>
-Initialized control registers, including power management and data format settings.</br>
-Configured output data rate and measurement range for the accelerometer.</br>
-Read acceleration values directly from the ADXL345 data registers. </br>
-Converted raw register values into meaningful acceleration data for display or further processing. </br>
## Hardware Setup </br>
Microcontroller: [STM32F411](https://www.st.com/en/evaluation-tools/nucleo-f411re.html) </br>
Sensor: [ADXL345](https://thinkrobotics.com/products/adxl345-accelerometer-module?variant=16326328811592&country=IN&currency=INR) </br> 
![image](https://github.com/user-attachments/assets/c2ea2970-9e3c-4268-a730-2fb20c28a9bb)

## **Software Setup** <br>
STM32CubeIDE<br>
