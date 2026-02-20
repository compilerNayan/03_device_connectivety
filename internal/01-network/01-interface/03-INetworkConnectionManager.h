#ifndef INETWORKCONNECTIONMANAGER_H
#define INETWORKCONNECTIONMANAGER_H

#include <StandardDefines.h>

/**
 * Network connection: connect/disconnect, query status (minimal network-level API).
 */
DefineStandardPointers(INetworkConnectionManager)
class INetworkConnectionManager {
    Public Virtual ~INetworkConnectionManager() = default;

    Public Virtual Void ConnectNetwork() = 0;
    Public Virtual Void DisconnectNetwork() = 0;
    Public Virtual Bool IsNetworkConnected() = 0;
    Public Virtual ULong GetNetworkConnectionId() = 0;
};

#include "/Users/nkurude/src/personal/opensource/smart_board/other/esp4/.pio/libdeps/esp32dev/03_device_connectivity/internal/01-network/02-variant/03-NetworkConnectionManager.h"
#endif // INETWORKCONNECTIONMANAGER_H
