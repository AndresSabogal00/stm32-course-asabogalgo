#include "stm32f4xx.h"

#define LED_PIN 13U   /* PC13 = LED de la Black Pill */

static void delay(volatile uint32_t count)
{
    while (count--) {
        __NOP();
    }
}

int main(void)
{
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;          /* 1. Habilitar reloj de GPIOC */
    GPIOC->MODER &= ~(0x3U << (LED_PIN * 2));     /* 2. Limpiar bits de modo de PC13 */
    GPIOC->MODER |=  (0x1U << (LED_PIN * 2));     /* 3. PC13 como salida */

    while (1) {
        GPIOC->ODR ^= (1U << LED_PIN);            /* Alternar el LED */
        delay(1000000);
    }
}