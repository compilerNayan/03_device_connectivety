#ifndef WIFI_CREDENTIALS_CONTROLLER_H
#define WIFI_CREDENTIALS_CONTROLLER_H

#include <StandardDefines.h>
// #include "IWiFiCredentialsController.h"
#include "../service/IWiFiService.h"
#include "../entity/WiFiCredentials.h"

/*--@Component--*/
/*--@RequestMapping("/wifi-credentials")--*/
class WiFiCredentialsController : public IWiFiCredentialsController {
    Public
        /*--@Autowired--*/
IWiFiServicePtr wiFiService = Implementation<IWiFiService>::type::GetInstance();

        // Create - Add new WiFi credentials
        /* @PostMapping("") */
        Public Virtual WiFiCredentials CreateWiFiCredentials(/* @RequestBody */ WiFiCredentials credentials) override {
            return wiFiService->AddWiFiCredentials(credentials);
        }

        // Read - Get WiFi credentials by SSID
        /*--@GetMapping("/{ssid}")--*/
        Public Virtual WiFiCredentials GetWiFiCredentials(/* @PathVariable("ssid") */ StdString ssid) override {
            if (ssid.empty()) {
                return WiFiCredentials();
            }
            return wiFiService->GetWiFiCredentials(ssid);
        }

        // Read All - Get all WiFi credentials
        /* @GetMapping("") */
        Public Virtual StdVector<WiFiCredentials> GetAllWiFiCredentials() override {
            return wiFiService->GetAllWiFiCredentials();
        }

        // Update - Update existing WiFi credentials
        /* @PutMapping("") */
        Public Virtual WiFiCredentials UpdateWiFiCredentials(/* @RequestBody */ WiFiCredentials credentials) override {
            return wiFiService->UpdateWiFiCredentials(credentials);
        }

        // Delete - Delete WiFi credentials by SSID
        /*--@DeleteMapping("/{ssid}")--*/
        Public Virtual Void DeleteWiFiCredentials(/* @PathVariable("ssid") */ StdString ssid) override {
            if (!ssid.empty()) {
                wiFiService->DeleteWiFiCredentials(ssid);
            }
        }

        // Get last connected WiFi
        /*--@GetMapping("/last-connected")--*/
        Public Virtual optional<WiFiCredentials> GetLastConnectedWiFi() override {
            return wiFiService->GetLastConnectedWiFi();
        }
        public: static IWiFiCredentialsControllerPtr GetInstance() {
            static IWiFiCredentialsControllerPtr instance(new WiFiCredentialsController());
            return instance;
        }
};

template <>
struct Implementation<IWiFiCredentialsController> {
    using type = WiFiCredentialsController;
};

template <>
struct Implementation<IWiFiCredentialsController*> {
    using type = WiFiCredentialsController*;
};

#endif // WIFI_CREDENTIALS_CONTROLLER_H

