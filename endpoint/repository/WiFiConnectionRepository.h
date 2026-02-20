#ifndef _WIFI_CONNECTION_REPOSITORY_H_
#define _WIFI_CONNECTION_REPOSITORY_H_

#include <StandardDefines.h>
#include "CpaRepository.h"
#include "../entity/WiFiConnection.h"

/* @Repository */
DefineStandardPointers(WiFiConnectionRepository)
class WiFiConnectionRepository : public CpaRepository<WiFiConnection, int> {
    Public Virtual ~WiFiConnectionRepository() = default;
    
};

#include "/Users/nkurude/src/personal/opensource/smart_board/other/esp4/.pio/libdeps/esp32dev/springbootplusplus_data/src/repository/WiFiConnectionRepositoryImpl.h"
#endif // _WIFI_CONNECTION_REPOSITORY_H_

