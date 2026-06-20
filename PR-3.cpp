#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Vehicle {
private:
    string vehicleID;
    string manufacturer;
    string model;
    int year;

public:
   
    static int totalVehicles;

    Vehicle() : vehicleID(""), manufacturer(""), model(""), year(0) {
        totalVehicles++;
    }

    Vehicle(string id, string mfg, string mdl, int yr) 
        : vehicleID(id), manufacturer(mfg), model(mdl), year(yr) {
        totalVehicles++;
    }

    virtual ~Vehicle() {
        totalVehicles--;
    }

    string getVehicleID() const { return vehicleID; }
    void setVehicleID(string id) { vehicleID = id; }

    string getManufacturer() const { return manufacturer; }
    void setManufacturer(string mfg) { manufacturer = mfg; }

    string getModel() const { return model; }
    void setModel(string mdl) { model = mdl; }

    int getYear() const { return year; }
    void setYear(int yr) { year = yr; }


    virtual void display() const {
        cout << "ID: " << vehicleID 
             << " | Brand: " << manufacturer 
             << " | Model: " << model 
             << " | Year: " << year;
    }
};


int Vehicle::totalVehicles = 0;


class Car : virtual public Vehicle {
private:
    string fuelType;

public:
    Car() : Vehicle(), fuelType("") {}
    Car(string id, string mfg, string mdl, int yr, string fuel)
        : Vehicle(id, mfg, mdl, yr), fuelType(fuel) {}

    string getFuelType() const { return fuelType; }
    void setFuelType(string fuel) { fuelType = fuel; }

    void display() const override {
        Vehicle::display();
        cout << " | Fuel: " << fuelType;
    }
};


class ElectricCar : public Car {
private:
    int batteryCapacity; 

public:
    ElectricCar() : Car(), batteryCapacity(0) {}
    ElectricCar(string id, string mfg, string mdl, int yr, string fuel, int battery)
        : Car(id, mfg, mdl, yr, fuel), batteryCapacity(battery) {}

    int getBatteryCapacity() const { return batteryCapacity; }
    void setBatteryCapacity(int battery) { batteryCapacity = battery; }

    void display() const override {
        Car::display();
        cout << " | Battery: " << batteryCapacity << " kWh";
    }
};


class SportsCar : public ElectricCar {
private:
    int topSpeed; 

public:
    SportsCar() : ElectricCar(), topSpeed(0) {}
    SportsCar(string id, string mfg, string mdl, int yr, string fuel, int battery, int speed)
        : ElectricCar(id, mfg, mdl, yr, fuel, battery), topSpeed(speed) {}

    int getTopSpeed() const { return topSpeed; }
    void setTopSpeed(int speed) { topSpeed = speed; }

    void display() const override {
        ElectricCar::display();
        cout << " | Top Speed: " << topSpeed << " km/h";
    }
};

class Sedan : public Car {
public:
    Sedan() : Car() {}
    Sedan(string id, string mfg, string mdl, int yr, string fuel)
        : Car(id, mfg, mdl, yr, fuel) {}

    void display() const override {
        cout << "[Sedan] ";
        Car::display();
    }
};

class SUV : public Car {

public:
    SUV() : Car() {}
    SUV(string id, string mfg, string mdl, int yr, string fuel)
        : Car(id, mfg, mdl, yr, fuel) {}

    void display() const override {
        cout << "[SUV] ";
        Car::display();
    }
};

class Aircraft {
private:
    int flightRange; // in km

public:
    Aircraft() : flightRange(0) {}
    Aircraft(int range) : flightRange(range) {}
    virtual ~Aircraft() {}

    int getFlightRange() const { return flightRange; }
    void setFlightRange(int range) { flightRange = range; }

    void displayAircraft() const {
        cout << " | Flight Range: " << flightRange << " km";
    }
};

class FlyingCar : public Car, public Aircraft {
public:
    FlyingCar() : Car(), Aircraft() {}
    FlyingCar(string id, string mfg, string mdl, int yr, string fuel, int range)
        : Car(id, mfg, mdl, yr, fuel), Aircraft(range) {}

    void display() const override {
        cout << "[Flying Car] ";
        Car::display();
        Aircraft::displayAircraft();
    }
};



class VehicleRegistry {
private:
    vector<Vehicle*> registry; 
public:
   
    ~VehicleRegistry() {
        for (Vehicle* v : registry) {
            delete v;
        }
        registry.clear();
    }

 
    void addVehicle(Vehicle* v) {
        registry.push_back(v);
        cout << "Vehicle successfully added to the registry!\n";
    }

  
    void displayAllVehicles() const {
        if (registry.empty()) {
            cout << "\nRegistry is empty.\n";
            return;
        }
        cout << "\n--- Registry Records (Total active vehicles: " << Vehicle::totalVehicles << ") ---\n";
        for (const auto& v : registry) {
            v->display();
            cout << "\n";
        }
        cout << "-------------------------------------------\n";
    }

    void searchVehicleById(const string& id) const {
        bool found = false;
        for (const auto& v : registry) {
            if (v->getVehicleID() == id) {
                cout << "\nVehicle Found:\n";
                v->display();
                cout << "\n";
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "\nVehicle with ID '" << id << "' not found.\n";
        }
    }
};

int main() {
    VehicleRegistry myRegistry;
    int choice;

    do {
        cout << "\n===== VEHICLE REGISTRY SYSTEM =====\n";
        cout << "1. Add a Vehicle\n";
        cout << "2. View All Vehicles\n";
        cout << "3. Search by Vehicle ID\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            int typeChoice;
            string id, mfg, model, fuel;
            int year, battery, speed, range;

            cout << "\nSelect Vehicle Type to Add:\n";
            cout << "1. Sedan (Hierarchical from Car)\n";
            cout << "2. SUV (Hierarchical from Car)\n";
            cout << "3. Electric Car (Multilevel from Car)\n";
            cout << "4. Sports Car (Multilevel from Electric Car)\n";
            cout << "5. Flying Car (Multiple Inheritance from Car & Aircraft)\n";
            cout << "Enter type: ";
            cin >> typeChoice;

            cout << "Enter Vehicle ID: "; cin >> id;
            cout << "Enter Manufacturer: "; cin >> mfg;
            cout << "Enter Model: "; cin >> model;
            cout << "Enter Year: "; cin >> year;

            if (typeChoice >= 1 && typeChoice <= 4) {
                cout << "Enter Fuel Type (e.g., Petrol/Electric): "; cin >> fuel;
            }

            switch (typeChoice) {
                case 1:
                    myRegistry.addVehicle(new Sedan(id, mfg, model, year, fuel));
                    break;
                case 2:
                    myRegistry.addVehicle(new SUV(id, mfg, model, year, fuel));
                    break;
                case 3:
                    cout << "Enter Battery Capacity (kWh): "; cin >> battery;
                    myRegistry.addVehicle(new ElectricCar(id, mfg, model, year, fuel, battery));
                    break;
                case 4:
                    cout << "Enter Battery Capacity (kWh): "; cin >> battery;
                    cout << "Enter Top Speed (km/h): "; cin >> speed;
                    myRegistry.addVehicle(new SportsCar(id, mfg, model, year, fuel, battery, speed));
                    break;
                case 5:
                    cout << "Enter Fuel Type: "; cin >> fuel;
                    cout << "Enter Flight Range (km): "; cin >> range;
                    myRegistry.addVehicle(new FlyingCar(id, mfg, model, year, fuel, range));
                    break;
                default:
                    cout << "Invalid vehicle type selection.\n";
            }

        } else if (choice == 2) {
            myRegistry.displayAllVehicles();
        } else if (choice == 3) {
            string searchId;
            cout << "Enter Vehicle ID to search: ";
            cin >> searchId;
            myRegistry.searchVehicleById(searchId);
        } else if (choice == 4) {
            cout << "Exiting System. Thank you!\n";
        } else {
            cout << "Invalid choice! Please try again.\n";
        }

    } while (choice != 4);

}
/*
===== VEHICLE REGISTRY SYSTEM =====
1. Add a Vehicle
2. View All Vehicles
3. Search by Vehicle ID
4. Exit
Enter your choice: 1

Select Vehicle Type to Add:
1. Sedan (Hierarchical from Car)
2. SUV (Hierarchical from Car)
3. Electric Car (Multilevel from Car)
4. Sports Car (Multilevel from Electric Car)
5. Flying Car (Multiple Inheritance from Car & Aircraft)
Enter type: 3
Enter Vehicle ID: EV101
Enter Manufacturer: Tesla
Enter Model: Model3
Enter Year: 2024
Enter Fuel Type (e.g., Petrol/Electric): Electric
Enter Battery Capacity (kWh): 75
Vehicle successfully added to the registry!

===== VEHICLE REGISTRY SYSTEM =====
1. Add a Vehicle
2. View All Vehicles
3. Search by Vehicle ID
4. Exit
Enter your choice: 1

Select Vehicle Type to Add:
1. Sedan (Hierarchical from Car)
2. SUV (Hierarchical from Car)
3. Electric Car (Multilevel from Car)
4. Sports Car (Multilevel from Electric Car)
5. Flying Car (Multiple Inheritance from Car & Aircraft)
Enter type: 5
Enter Vehicle ID: FLY77
Enter Manufacturer: AeroMobil
Enter Model: V4.0
Enter Year: 2026
Enter Fuel Type: Premium
Enter Flight Range (km): 750
Vehicle successfully added to the registry!

===== VEHICLE REGISTRY SYSTEM =====
1. Add a Vehicle
2. View All Vehicles
3. Search by Vehicle ID
4. Exit
Enter your choice: 2

--- Registry Records (Total active vehicles: 2) ---
ID: EV101 | Brand: Tesla | Model: Model3 | Year: 2024 | Fuel: Electric | Battery: 75 kWh
[Flying Car] ID: FLY77 | Brand: AeroMobil | Model: V4.0 | Year: 2026 | Fuel: Premium | Flight Range: 750 km
-------------------------------------------

===== VEHICLE REGISTRY SYSTEM =====
1. Add a Vehicle
2. View All Vehicles
3. Search by Vehicle ID
4. Exit
Enter your choice: 3
Enter Vehicle ID to search: EV101

Vehicle Found:
ID: EV101 | Brand: Tesla | Model: Model3 | Year: 2024 | Fuel: Electric | Battery: 75 kWh

===== VEHICLE REGISTRY SYSTEM =====
1. Add a Vehicle
2. View All Vehicles
3. Search by Vehicle ID
4. Exit
Enter your choice: 4
Exiting System. Thank you!
*/