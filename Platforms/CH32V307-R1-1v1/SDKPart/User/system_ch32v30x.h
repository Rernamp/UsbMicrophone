#ifndef __SYSTEM_CH32V30x_H 
#define __SYSTEM_CH32V30x_H

#ifdef __cplusplus
 extern "C" {
#endif 

extern uint32_t SystemCoreClock;

/* System_Exported_Functions */  
extern void SystemInit(void);
extern void SystemCoreClockUpdate(void);
uint32_t SysTick_Config(uint32_t ticks);

#ifdef __cplusplus
}
#endif

#endif /*__CH32V30x_SYSTEM_H */



