#ifndef REMOTE_OBJECT_REF_H
#define REMOTE_OBJECT_REF_H

#include <string>

class RemoteObjectRef {

public:

    std::string host;

    int port;

    std::string objectName;
};

#endif