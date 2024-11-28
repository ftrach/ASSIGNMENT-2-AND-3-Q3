#include "RealEstateTree.h"
#include <iostream>
using namespace std;

int main() {
    RealEstateTree estateTree;

    // ADD PROPERTY LISTINGS
    estateTree.addListing(201, "432 River Rd", 350000, "House");
    estateTree.addListing(202, "876 Pine Ave", 275000, "Condo");
    estateTree.addListing(203, "101 Maple Blvd", 550000, "Commercial");

    // DISPLAY ALL LISTINGS IN ORDER
    cout << "PROPERTY LISTINGS IN ORDER:" << endl;
    estateTree.displayAllListings();

    // SEARCH FOR A SPECIFIC PROPERTY
    cout << "\nSEARCHING FOR PROPERTY ID 202:" << endl;
    PropertyNode* listing = estateTree.searchListing(202);
    if (listing) {
        listing->displayDetails();
    } else {
        cout << "LISTING NOT FOUND!" << endl;
    }

    // REMOVE A PROPERTY BY ID
    cout << "\nREMOVING LISTING ID 201." << endl;
    estateTree.removeListing(201);

    // DISPLAY ALL LISTINGS AFTER REMOVAL
    cout << "\nPROPERTY LISTINGS AFTER REMOVAL:" << endl;
    estateTree.displayAllListings();

    return 0;
}
