#pragma once

#include <cstdint>
namespace Platform {
    bool init();
    bool initOsSpecific();
    bool initAfterConfigureTinyusbStack();
    namespace SystemTimer {
        uint32_t now_ms();
    }
    
}