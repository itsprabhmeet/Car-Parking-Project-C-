#include <iostream>
#include <string.h>

using namespace std;

// Base class for parking slots
class ParkingSlot {
public:
    virtual void parkCar(string carNumberPlate) = 0;
    virtual void vacateSlot() = 0;
    virtual string getParkedCar() = 0;  // Method to get the parked car's number plate
};

// Derived class for regular parking slots
class RegularSlot : public ParkingSlot {
private:
    string parkedCarNumberPlate;

public:
    void parkCar(string carNumberPlate) override {
        parkedCarNumberPlate = carNumberPlate;
        cout << "Car with number plate " << carNumberPlate << " parked in regular slot." << endl;
    }

    void vacateSlot() override {
        cout << "Regular slot vacated." << endl;
        parkedCarNumberPlate = "";
    }

    string getParkedCar() override {
        return parkedCarNumberPlate;  // Return the number plate of the parked car
    }
};

// Derived class for premium parking slots
class PremiumSlot : public ParkingSlot {
private:
    string parkedCarNumberPlate;

public:
    void parkCar(string carNumberPlate) override {
        parkedCarNumberPlate = carNumberPlate;
        cout << "Car with number plate " << carNumberPlate << " parked in premium slot." << endl;
    }

    void vacateSlot() override {
        cout << "Premium slot vacated." << endl;
        parkedCarNumberPlate = "";
    }

    string getParkedCar() override {
        return parkedCarNumberPlate;  // Return the number plate of the parked car
    }
};

// Class to represent a car
class Car {
private:
    string numberPlate;

public:
    Car(string numberPlate) : numberPlate(numberPlate) {}

    string getNumberPlate() const {
        return numberPlate;
    }
};

int main() {
    // Create parking lot with regular and premium slots
    RegularSlot regularSlots[10];
    PremiumSlot premiumSlots[5];

    int choice;
    string carNumber;
    int slotNumber;

    do {
        cout << "\nCar Parking Management System\n";
        cout << "1. Park Car\n";
        cout << "2. Vacate Slot\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter car number plate: ";
                cin >> carNumber;

                cout << "Choose parking type:\n";
                cout << "1. Regular Slot\n";
                cout << "2. Premium Slot\n";
                cout << "Enter your choice: ";
                int type;
                cin >> type;

                if (type == 1) {
                    cout << "Enter slot number (1-10): ";
                    cin >> slotNumber;
                    if (slotNumber >= 1 && slotNumber <= 10) {
                        Car car(carNumber);
                        regularSlots[slotNumber - 1].parkCar(carNumber);
                    } else {
                        cout << "Invalid slot number. Please enter a number between 1 and 10." << endl;
                    }
                } else if (type == 2) {
                    cout << "Enter slot number (1-5): ";
                    cin >> slotNumber;
                    if (slotNumber >= 1 && slotNumber <= 5) {
                        Car car(carNumber);
                        premiumSlots[slotNumber - 1].parkCar(carNumber);
                    } else {
                        cout << "Invalid slot number. Please enter a number between 1 and 5." << endl;
                    }
                } else {
                    cout << "Invalid parking type." << endl;
                }
                break;

            case 2:
                cout << "Enter car number plate to vacate: ";
                cin >> carNumber;

                cout << "Choose parking type:\n";
                cout << "1. Regular Slot\n";
                cout << "2. Premium Slot\n";
                cout << "Enter your choice: ";
                cin >> type;

                if (type == 1) {
                    cout << "Enter slot number (1-10): ";
                    cin >> slotNumber;
                    if (slotNumber >= 1 && slotNumber <= 10) {
                        if (regularSlots[slotNumber - 1].getParkedCar() == carNumber) {
                            regularSlots[slotNumber - 1].vacateSlot();
                        } else {
                            cout << "No slot assigned to car with number plate " << carNumber << "." << endl;
                        }
                    } else {
                        cout << "Invalid slot number. Please enter a number between 1 and 10." << endl;
                    }
                } else if (type == 2) {
                    cout << "Enter slot number (1-5): ";
                    cin >> slotNumber;
                    if (slotNumber >= 1 && slotNumber <= 5) {
                        if (premiumSlots[slotNumber - 1].getParkedCar() == carNumber) {
                            premiumSlots[slotNumber - 1].vacateSlot();
                        } else {
                            cout << "No slot assigned to car with number plate " << carNumber << "." << endl;
                        }
                    } else {
                        cout << "Invalid slot number. Please enter a number between 1 and 5." << endl;
                    }
                } else {
                    cout << "Invalid parking type." << endl;
                }
                break;

            case 3:
                cout << "Exiting program..." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 3);

    return 0;
}
