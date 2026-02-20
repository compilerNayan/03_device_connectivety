#ifndef NETWORKSTATUSPROVIDER_H
#define NETWORKSTATUSPROVIDER_H

// #include "../01-interface/02-INetworkStatusProvider.h"
#include "../01-interface/01-INetworkStatusStore.h"
#include <StandardDefines.h>

/**
 * Implementation that reads network status from INetworkStatusStore.
 */
/*--@Component--*/
class NetworkStatusProvider : public INetworkStatusProvider {
    /*--@Autowired--*/
INetworkStatusStorePtr store = Implementation<INetworkStatusStore>::type::GetInstance();

    Public Bool IsNetworkConnected() const override {
        return store->IsNetworkConnected();
    }

    Public ULong GetNetworkConnectionId() const override {
        return store->GetNetworkConnectionId();
    }
        public: static INetworkStatusProviderPtr GetInstance() {
            static INetworkStatusProviderPtr instance(new NetworkStatusProvider());
            return instance;
        }
};

template <>
struct Implementation<INetworkStatusProvider> {
    using type = NetworkStatusProvider;
};

template <>
struct Implementation<INetworkStatusProvider*> {
    using type = NetworkStatusProvider*;
};

#endif // NETWORKSTATUSPROVIDER_H
