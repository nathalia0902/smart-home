#include <iostream>
#include "SmartHomeProxy.h"

int main() {

    SmartHomeProxy proxy;

    std::cout << "==== SMART HOME CLIENT ====" << std::endl;

    std::cout << proxy.turnOn(1) << std::endl;

    std::cout << proxy.turnOff(1) << std::endl;

    std::cout << "Temperature: "
              << proxy.getTemperature(2)
              << " C"
              << std::endl;

    std::cout << "Brightness set to: "
              << proxy.setBrightness(1, 80)
              << std::endl;

    return 0;
}