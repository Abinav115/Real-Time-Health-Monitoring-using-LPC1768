#include <lpc17xx.h>
#include <string.h>
#include "uart.h"
#include "lcd.h"
#include "lcd.c"

int main() {
    int i = 0, val1, val2, val3, val4, k = 0, j = 0;
    char temperature[3], oxygen[3], heartrate[3], bp[3], temp[12];

    // Initialize default values for simulation
    strcpy(temperature, "098");
    strcpy(oxygen, "097");
    strcpy(heartrate, "085");
    strcpy(bp, "105");

    lcd_init();
    lcd_cmd_write(0x0C);
    uart_config();

    while (1) {
        // Simulated input from sensors (default values)
        val1 = atoi(temperature);
        val2 = atoi(oxygen);
        val3 = atoi(heartrate);
        val4 = atoi(bp);

        if (val1 >= 94 && val1 <= 98) {
            lcd_str_write("Normal Temperature");
            uart_str("Normal Temperature\n");
            lcd_cmd_write(0xc0);
            for (i = 0; i < 3; i++)
                lcd_data_write(temperature[i]);
            delay(1000);
        } else {
            lcd_str_write("Critical Temperature");
            uart_str("Critical Temperature\n");
            lcd_cmd_write(0xc0);
            for (i = 0; i < 3; i++)
                lcd_data_write(temperature[i]);
            delay(1000);
            for (j = 0; j < 2; j++) {
                LPC_GPIO1->FIOSET |= (0xFF << 19);
                delay(100);
                LPC_GPIO1->FIOCLR |= (0xFF << 19);
                delay(100);
            }
            for (j = 0; j < 2; j++) {
                LPC_GPIO1->FIOSET |= (0x01 << 27);
                delay(100);
                LPC_GPIO1->FIOCLR |= (0x01 << 27);
                delay(100);
            }
        }
        // Similar checks for other vital signs (omitted for brevity)

        lcd_cmd_write(0x01);
}}
