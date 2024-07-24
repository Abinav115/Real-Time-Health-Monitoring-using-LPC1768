### Real-time Health Monitoring System using LPC1768

This project implements a real-time health monitoring system using the LPC1768 microcontroller. It simulates sensor data for temperature, oxygen levels, heart rate, and blood pressure, displaying readings on an LCD and transmitting data via UART. Critical values trigger visual alerts using GPIO-controlled LEDs.

#### Features:

1. **Sensor Simulation**:
    - Default values: Temperature (`098`), Oxygen (`097`), Heart Rate (`085`), Blood Pressure (`105`).

2. **LCD Display**:
    - Displays health parameters and status ("Normal" or "Critical").

3. **UART Communication**:
    - Configured for 9600 bps baud rate.
    - Transmits health status over UART.

4. **GPIO Control**:
    - LEDs indicate critical conditions.

#### Code Overview:

1. **Main Function**:
    - Initializes LCD and UART.
    - Simulates sensor data, performs health checks, and updates status in a loop.

2. **Sensor Data Handling**:
    - Converts simulated data to integers.
    - Checks if values are within normal ranges.

3. **LCD Functions**:
    - `lcd_init()`: Initializes the LCD.
    - `lcd_cmd_write(char cmd)`: Sends commands to the LCD.
    - `lcd_data_write(char dat)`: Writes data to the LCD.
    - `lcd_str_write(char *str)`: Writes strings to the LCD.

4. **UART Functions**:
    - `uart_config()`: Configures the UART.
    - `uart_data(unsigned char d)`: Sends a byte over UART.
    - `uart_str(unsigned char *ptr)`: Sends a string over UART.
    - `uart_rx()`: Receives a byte from UART.
    - `uart_num(unsigned int num)`: Sends a number over UART.
    - `delay(unsigned int a)`: Generates delays.

#### Files:

1. **main.c**: Main logic for health monitoring.
2. **uart.h**: UART configuration and functions.
3. **lcd.h**: LCD function declarations.
4. **lcd.c**: LCD function implementations.

#### Future Enhancements:

- **Real Sensor Integration**: Replace simulated data with real sensors.
- **Enhanced Interface**: Improve display readability.
- **Data Logging**: Implement data storage for analysis.
- **Wireless Communication**: Add support for Bluetooth or Wi-Fi.

This project provides a foundation for advanced health monitoring systems with real-time data acquisition and analysis capabilities.
