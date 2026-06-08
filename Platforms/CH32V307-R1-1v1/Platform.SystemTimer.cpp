#include "Platform.h"

#include "FreeRTOS.h"
#include "task.h"

namespace Platform::SystemTimer {
    uint32_t now_ms() {
        return (xTaskGetTickCount() * portTICK_PERIOD_MS);
    }
} // namespace Platform::SystemTimer
