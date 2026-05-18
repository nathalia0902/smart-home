#include "Serializer.h"

std::string Serializer::serialize(json j) {
    return j.dump();
}

json Serializer::deserialize(std::string data) {
    return json::parse(data);
}