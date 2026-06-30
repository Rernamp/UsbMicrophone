#include <ch32v30x.h>
#include <system_ch32v30x.h>

volatile uint32_t system_ticks = 0;
void SysTick_Handler_impl();
void SysTick_Handler(void) __attribute__((naked));
void SysTick_Handler(void) {
    __asm volatile("call SysTick_Handler_impl; mret");
}

__attribute__((used)) void SysTick_Handler_impl(void) {
    uint32_t srBefore = SysTick->SR;
    SysTick->SR = 0;
    system_ticks++;
}

uint32_t SysTick_Config(uint32_t ticks) {
    NVIC_EnableIRQ(SysTicK_IRQn);
    SysTick->CTLR = 0;
    SysTick->SR = 0;
    SysTick->CNT = 0;
    SysTick->CMP = ticks - 1;
    SysTick->CTLR = 0xF;
    return 0;
    }