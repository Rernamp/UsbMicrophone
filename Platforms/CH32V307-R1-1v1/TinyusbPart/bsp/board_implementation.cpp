#include <bsp/board_api.h>

#include <cstdint>
#include <numeric>

#include "Platform.h"

void board_init(void) {
    Platform::init();
}

void board_init_after_tusb(void) {
    Platform::initAfterConfigureTinyusbStack();
}

void board_reset_to_bootloader(void) {
}

void board_led_write(bool state) {
}

size_t board_get_unique_id(uint8_t id[], size_t max_len) {
    volatile uint32_t* ch32_uuid = (volatile uint32_t*)0x1FFFF7E8UL;
    uint32_t* serial_32 = (uint32_t*)id;
    static constexpr size_t ChipIdSize = 12;
    size_t copy_bytes = (max_len < ChipIdSize) ? max_len : ChipIdSize;
    size_t copy_words = copy_bytes / sizeof(uint32_t);
    
    for (size_t i = 0; i < copy_words; i++) {
        serial_32[i] = ch32_uuid[i];
    }
    
    return copy_bytes;
}