#pragma once
#include <string>
#include <iostream>
using namespace std;

// CLASS TO REPRESENT A SINGLE PROPERTY
class PropertyNode {
public:
    // MEMBER VARIABLES
    int id;               // PROPERTY ID
    string location;      // PROPERTY ADDRESS
    double value;         // PROPERTY PRICE
    string category;      // PROPERTY TYPE (E.G., HOUSE, APARTMENT, COMMERCIAL)

    // CONSTRUCTOR
    PropertyNode(int propId, string addr, double price, string type)
        : id(propId), location(addr), value(price), category(type) {}

    // GETTER FUNCTIONS
    int getId() const { return id; }
    string getLocation() const { return location; }
    double getValue() const { return value; }
    string getCategory() const { return category; }

    // SETTER FUNCTIONS
    void setId(int propId) { id = propId; }
    void setLocation(const string& addr) { location = addr; }
    void setValue(double price) { value = price; }
    void setCategory(const string& type) { category = type; }

    // DISPLAY FUNCTION (TO SHOW DETAILS OF THE PROPERTY)
    void displayDetails() const {
        cout << "ID: " << id << ", Address: " << location
             << ", Price: $" << value << ", Type: " << category << endl;
    }
};
