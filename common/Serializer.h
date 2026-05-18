#include <nlohmann/json.hpp>

using json = nlohmann::json;

class Serializer {
public:
    static std::string serialize(json j);

    static json deserialize(std::string data);
};