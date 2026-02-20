#ifndef IINTERNETCONNECTIONSTATUSSTORE_H
#define IINTERNETCONNECTIONSTATUSSTORE_H

#include <StandardDefines.h>

/**
 * Thread-safe store for internet connection status.
 */
DefineStandardPointers(IInternetConnectionStatusStore)
class IInternetConnectionStatusStore {
    Public Virtual ~IInternetConnectionStatusStore() = default;

    Public Virtual Bool IsInternetConnected() const = 0;
    Public Virtual ULong GetInternetConnectionId() const = 0;

    /** Set connection state in one transaction (thread-safe atomic update). */
    Public Virtual Void SetState(Bool internetConnected, ULong internetConnectionId) = 0;
};

#include "/Users/nkurude/src/personal/opensource/smart_board/other/esp4/.pio/libdeps/esp32dev/03_device_connectivity/internal/03-internet/02-variant/01-InternetConnectionStatusStore.h"
#endif // IINTERNETCONNECTIONSTATUSSTORE_H
