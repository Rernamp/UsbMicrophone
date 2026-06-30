#include "Platform.h"

#if defined(CFG_TUSB_OS)
#include "tusb_option.h"

#if CFG_TUSB_OS == OPT_OS_FREERTOS
#include "FreeRTOS.h"
#include "task.h"
namespace Platform::SystemTimer {
    uint32_t now_ms() {
        return (xTaskGetTickCount() * portTICK_PERIOD_MS);
    }
} // namespace Platform::SystemTimer
#endif

#endif