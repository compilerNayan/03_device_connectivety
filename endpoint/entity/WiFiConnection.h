#ifndef WIFI_CONNECTION_ENTITY_H
#define WIFI_CONNECTION_ENTITY_H

#include <StandardDefines.h>

/*--@Entity--*/
class WiFiConnection {

    /* @Id */
    /* @NotNull */
    Public optional<int> id;

    Public optional<StdString> lastConnectedSsid;

        // Serialization method
        Public StdString Serialize() const {
            // Create JSON document
            JsonDocument doc;

            // Serialize optional field: id
            if (id.has_value()) {
                doc["id"] = id.value();
            } else {
                doc["id"] = nullptr;
            }
            // Serialize optional field: lastConnectedSsid
            if (lastConnectedSsid.has_value()) {
                doc["lastConnectedSsid"] = lastConnectedSsid.value().c_str();
            } else {
                doc["lastConnectedSsid"] = nullptr;
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
        Public Static WiFiConnection Deserialize(const StdString& input) {
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
            WiFiConnection obj;

            // Assign values from JSON if present (only optional fields)
            // Deserialize optional field: id
            if (!doc["id"].isNull()) {
                obj.id = doc["id"].as<int>();
            }
            // Deserialize optional field: lastConnectedSsid
            if (!doc["lastConnectedSsid"].isNull()) {
                obj.lastConnectedSsid = StdString(doc["lastConnectedSsid"].as<const char*>());
            }

            return obj;
        }

        // Primary key methods
        inline optional<int> GetPrimaryKey() {
            return id;
        }

        inline Static StdString GetPrimaryKeyName() {
            return "id";
        }

        inline Static StdString GetTableName() {
            return "WiFiConnection";
        }
};

#endif

