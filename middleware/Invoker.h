#ifndef INVOKER_H
#define INVOKER_H

#include <string>

#include "../server/SmartHomeService.h"

class Invoker {

private:

    SmartHomeService* service;

public:

    Invoker(SmartHomeService* service);

    std::string invoke(std::string requestData);
};

#endif