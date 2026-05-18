#ifndef REQUESTOR_H
#define REQUESTOR_H

#include <string>

#include "../common/RemoteObjectRef.h"

class Requestor {

public:

    std::string doOperation(
        RemoteObjectRef objectRef,
        std::string methodID,
        std::string arguments
    );
};

#endif