#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

// Base Class with a Virtual Function
class Sensor {
protected:
    string sensorID;

public:
    Sensor(string id) : sensorID(id) {}
    
    // Virtual destructor is vital for polymorphic base classes
    virtual ~Sensor() {}

    // Virtual function to be overridden
    virtual void readData() const {
        cout << "Generic Sensor [" << sensorID << "]: Reading raw data...\n";
    }

    string getID() const { return sensorID; }
};

// Derived Class 1: Temperature Sensor
class TemperatureSensor : public Sensor {
private:
    double temperatureCelsius;

public:
    TemperatureSensor(string id, double temp) : Sensor(id), temperatureCelsius(temp) {}

    // Override virtual function
    void readData() const override {
        cout << fixed << setprecision(1);
        cout << "Temperature Sensor [" << sensorID << "]: " << temperatureCelsius << " °C\n";
    }
};

// Derived Class 2: Voltage Sensor
class VoltageSensor : public Sensor {
private:
    double voltageVolts;

public:
    VoltageSensor(string id, double volts) : Sensor(id), voltageVolts(volts) {}

    // Override virtual function
    void readData() const override {
        cout << fixed << setprecision(2);
        cout << "Voltage Sensor     [" << sensorID << "]: " << voltageVolts << " V\n";
    }
};

int main() {
    cout << "=== Demonstrating Runtime Polymorphism ===\n\n";

    // Create base class pointers pointing to different derived objects
    Sensor* s1 = new TemperatureSensor("TMP-01", 28.5);
    Sensor* s2 = new VoltageSensor("VOLT-02", 12.6);
    Sensor* s3 = new TemperatureSensor("TMP-02", 45.2);

    // Store pointers in a collection
    vector<Sensor*> sensorNetwork = {s1, s2, s3};

    cout << "Iterating through sensor network using base-class pointers:\n";
    cout << "--------------------------------------------------------\n";
    
    for (const Sensor* sensor : sensorNetwork) {
        // Same function call produces different behaviors dynamically at runtime
        sensor->readData();
    }

    // Clean up dynamically allocated memory
    for (Sensor* sensor : sensorNetwork) {
        delete sensor;
    }

    return 0;
}