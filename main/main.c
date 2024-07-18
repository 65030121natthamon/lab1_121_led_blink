#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

void app_main(void)
{
    gpio_set_direction(5, GPIO_MODE_OUTPUT); //led1
    gpio_set_direction(GPIO_NUM_17, GPIO_MODE_INPUT); // button2   
    int button17  = 0;
    while (1) {
    
        // gpio_set_level(5,1);
        // vTaskDelay(500 / portTICK_PERIOD_MS);
        //  gpio_set_level(5,0);
        // vTaskDelay(500 / portTICK_PERIOD_MS);
        // printf("[%d] Hello world!\n", i);
        // i++;
        button17 = gpio_get_level(GPIO_NUM_17);
        printf("button 17 = %d\n", button17);
        if(button17 == 1)
        {
            gpio_set_level(5,1);
        }
        else
        {
            gpio_set_level(5,0);
        }
        vTaskDelay(500 / portTICK_PERIOD_MS);
    }
}
