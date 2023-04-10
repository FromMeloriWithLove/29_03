#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Device {
protected:
    string manufacturer;
    string model;
    int amount;
    double price;
    string color;
public:
    Device(string m, string md, int a, double p, string c) :
        manufacturer(m), model(md), amount(a), price(p), color(c) {}
    string GetManufacturer() {
        return manufacturer;
    }
    string GetModel() {
        return model;
    }
    int GetAmount() {
        return amount;
    }
    double GetPrice() {
        return price;
    }
    string GetColor() {
        return color;
    }

    virtual ~Device() {}
    virtual void PrintInfo() = 0;
};

class MobilePhone : public Device {
private:
    int amount_of_reviews;
public:
    MobilePhone(string m, string md, int a, double p, string c, int a_o_r) :
        Device(m, md, a, p, c), amount_of_reviews(a_o_r) {}
    void PrintInfo() override {
        cout << "Mobile Phone" << endl;
        cout << "Manufacturer: " << manufacturer << endl;
        cout << "Model: " << model << endl;
        cout << "Quantity: " << amount << endl;
        cout << "Price: " << price << endl;
        cout << "Color: " << color << endl;
        cout << "Amount of reviews: " << amount_of_reviews << "\n\n";
    }
};

class Laptop : public Device {
private:
    int amount_of_reviews;
public:
    Laptop(string m, string md, int a, double p, string c, int a_o_r) :
        Device(m, md, a, p, c), amount_of_reviews(a_o_r) {}
    void PrintInfo() override {
        cout << "Laptop" << endl;
        cout << "Manufacturer: " << manufacturer << endl;
        cout << "Model: " << model << endl;
        cout << "Quantity: " << amount << endl;
        cout << "Price: " << price << endl;
        cout << "Color: " << color << endl;
        cout << "Amount of reviews: " << amount_of_reviews << "\n\n";
    }
};

class Tablet : public Device {
private:
    int amount_of_reviews;
public:
    Tablet(string m, string md, int a, double p, string c, int a_o_r) :
        Device(m, md, a, p, c), amount_of_reviews(a_o_r) {}
    void PrintInfo() override {
        cout << "Tablet" << endl;
        cout << "Manufacturer: " << manufacturer << endl;
        cout << "Model: " << model << endl;
        cout << "Quantity: " << amount << endl;
        cout << "Price: " << price << endl;
        cout << "Color: " << color << endl;
        cout << "Amount of reviews: " << amount_of_reviews << "\n\n";
    }
};

class Shop {
private:
    vector<Device*> devices;
public:
    void addDevice(Device* device) {
        devices.push_back(device);
    }

    void removeDevice(string manufacturer, string model, int amount, double price, string color) {
        devices.erase(remove_if(devices.begin(), devices.end(), [&](Device* device) {
            return (device->GetManufacturer() == manufacturer && device->GetModel() == model && device->GetAmount() == amount 
                && device->GetPrice() == price && device->GetColor() == color);
            }), devices.end());
    }

    void printDevices() {
        cout << "List of devices:\n";
        for (Device* device : devices) {
            device->PrintInfo();
        }
    }

    vector<Device*> searchDevices(string manufacturer, string model, int amount, double price, string color) {
        vector<Device*> result;
        for (Device* device : devices) {
            if (device->GetManufacturer() == manufacturer && device->GetModel() == model && device->GetAmount() == amount
                && device->GetPrice() == price && device->GetColor() == color) {
                result.push_back(device);
            }
        }
        return result;
    }
};

int main() {
    Shop shop;
    MobilePhone mp("Mobile", "Model of mobile", 10, 20, "blue", 50);
    Laptop laptop("Laptop", "Model of laptop", 15, 10000, "red", 100);
    Tablet tablet("Tablet", "Model of tablet", 40, 7000, "green", 200);

    shop.addDevice(&mp);
    shop.addDevice(&laptop);
    shop.addDevice(&tablet);

    shop.printDevices();

    shop.removeDevice("Mobile", "Model of mobile", 10, 20, "blue");

    shop.printDevices();

    vector<Device*> searchResult = shop.searchDevices("Tablet", "Model of tablet", 40, 7000, "green");
    if (searchResult.empty()) {
        cout << "No devices found\n";
    }
    else {
        cout << "Search results:\n";
        for (Device* device : searchResult) {
            device->PrintInfo();
        }
    }

    return 0;
}
