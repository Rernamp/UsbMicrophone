#include "Platform.h"

namespace Platform {

    bool clockInit() {
        bool result{true};

        return result;
    }

    bool init() {
        bool result{true};

        return result;
    }

    bool initAfterConfigureTinyusbStack() {
        bool result{true};

        return result;
    }
} // namespace Platform

extern "C" void _fini() {}
extern "C" void _init() {}