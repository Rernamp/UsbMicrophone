#include "Platform.h"

#include <ch32v30x.h>
#include <ch32v30x_rcc.h>
#include <system_ch32v30x.h>

namespace Platform {

    bool initOsSpecific() { return true; }
} // namespace Platform