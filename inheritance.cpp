#include <iostream>
#include <string>

using namespace std;

// 1. Base Class
class ElectronicDevice {
protected:
    string brand;
    int powerRatingWatts;

public:
    ElectronicDevice(string b, int power) : brand(b), powerRatingWatts(power) {
        cout << "[ElectronicDevice Constructor] Initialized " << brand << " (" << powerRatingWatts << "W)\n";
    }

    void turnOn() {
        cout << brand << " is now powered ON.\n";
    }

    void turnOff() {
        cout << brand << " is now powered OFF.\n";
    }
};

// 2. Intermediate Derived Class
class Microcontroller : public ElectronicDevice {
protected:
    string architecture;
    int flashMemoryKB;

public:
    Microcontroller(string b, int power, string arch, int flash) 
        : ElectronicDevice(b, power), architecture(arch), flashMemoryKB(flash) {
        cout << "[Microcontroller Constructor] Architecture: " << architecture << ", Flash: " << flashMemoryKB << "KB\n";
    }

    void flashFirmware() {
        cout << "Flashing new firmware onto " << architecture << " microcontroller...\n";
    }
};

// 3. Leaf Derived Class
class SmartIoTController : public Microcontroller {
private:
    string wirelessProtocol;
    bool isConnected;

public:
    SmartIoTController(string b, int power, string arch, int flash, string protocol)
        : Microcontroller(b, power, arch, flash), wirelessProtocol(protocol), isConnected(false) {
        cout << "[SmartIoTController Constructor] Wireless Protocol: " << wirelessProtocol << "\n";
    }

    void connectToCloud() {
        isConnected = true;
        cout << brand << " connected to the cloud via " << wirelessProtocol << ".\n";
    }

    void displaySmartSpecs() {
        cout << "\n--- Smart IoT Controller Specifications ---\n";
        cout << "Brand: " << brand << "\n";
        cout << "Power Rating: " << powerRatingWatts << "W\n";
        cout << "Architecture: " << architecture << "\n";
        cout << "Flash Memory: " << flashMemoryKB << " KB\n";
        cout << "Wireless Protocol: " << wirelessProtocol << "\n";
        cout << "Cloud Status: " << (isConnected ? "Online" : "Offline") << "\n";
    }
};

int main() {
    cout << "=== Demonstrating Chained Inheritance ===\n";
    
    // Create an object of the deepest derived class
    SmartIoTController myController("Espressif", 5, "ARM Cortex-M4", 512, "Wi-Fi / BLE");
    
    cout << "\n--- Testing Inherited and Local Members ---\n";
    myController.turnOn();          // Inherited from ElectronicDevice
    myController.flashFirmware();   // Inherited from Microcontroller
    myController.connectToCloud();  // Defined locally in SmartIoTController
    myController.displaySmartSpecs();
    myController.turnOff();         // Inherited from ElectronicDevice

    return 0;
}