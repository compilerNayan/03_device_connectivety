#ifndef WIFICREDENTIALS_H
#define WIFICREDENTIALS_H

#include <StandardDefines.h>

/*--@Entity--*/
class WiFiCredentials {

    /* @Id */
    /* @NotNull */
    Public optional<StdString> ssid;

    Public optional<StdString> password;

        // Serialization method
        Public StdString Serialize() const {
            // Create JSON document
            JsonDocument doc;

            // Serialize optional field: ssid
            if (ssid.has_value()) {
                doc["ssid"] = ssid.value().c_str();
            } else {
                doc["ssid"] = nullptr;
            }
            // Serialize optional field: password
            if (password.has_value()) {
                doc["password"] = password.value().c_str();
            } else {
                doc["password"] = nullptr;
            }

            // Serialize to string
            StdString output;
            serializeJson(doc, output);

            return StdString(output.c_str());
        }

            // Validation method for all validation macros
            #pragma GCC diagnostic push
            #pragma GCC diagnostic ignored "-Wunused-parameter"
            Public template<typename DocType>
            Static StdString ValidateFields(DocType& doc) {
            StdString validationErrors;

            // No validation macros defined for this class

            return validationErrors;
        }
            #pragma GCC diagnostic pop

        // Deserialization method
        Public Static WiFiCredentials Deserialize(const StdString& input) {
            // Create JSON document
            JsonDocument doc;

            // Deserialize JSON string
            DeserializationError error = deserializeJson(doc, input.c_str());

            if (error) {
                StdString errorMsg = "JSON parse error: ";
                errorMsg += error.c_str();
                throw std::runtime_error(errorMsg.c_str());
            }

            // Validate all fields with validation macros
            StdString validationErrors = ValidateFields(doc);
            if (!validationErrors.empty()) {
                throw std::runtime_error(validationErrors.c_str());
            }

            // Create object with default constructor
            WiFiCredentials obj;

            // Assign values from JSON if present (only optional fields)
            // Deserialize optional field: ssid
            if (!doc["ssid"].isNull()) {
                obj.ssid = StdString(doc["ssid"].as<const char*>());
            }
            // Deserialize optional field: password
            if (!doc["password"].isNull()) {
                obj.password = StdString(doc["password"].as<const char*>());
            }

            return obj;
        }

        // Primary key methods
        inline optional<StdString> GetPrimaryKey() {
            return ssid;
        }

        inline Static StdString GetPrimaryKeyName() {
            return "ssid";
        }

        inline Static StdString GetTableName() {
            return "WiFiCredentials";
        }
};

#endif
