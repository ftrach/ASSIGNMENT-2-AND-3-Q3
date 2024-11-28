#pragma once
#include "RealEstate.h"

// CLASS TO REPRESENT THE BINARY SEARCH TREE OF PROPERTIES
class RealEstateTree {
private:
    // STRUCT TO REPRESENT A TREE NODE
    struct TreeNode {
        PropertyNode property;   // PROPERTY STORED IN THIS NODE
        TreeNode* left;          // POINTER TO LEFT CHILD
        TreeNode* right;         // POINTER TO RIGHT CHILD

        // CONSTRUCTOR FOR TREE NODE
        TreeNode(const PropertyNode& prop)
            : property(prop), left(nullptr), right(nullptr) {}
    };

    TreeNode* root;  // ROOT OF THE TREE

    // HELPER FUNCTIONS FOR TREE OPERATIONS
    void addNode(TreeNode*& node, const PropertyNode& property);
    TreeNode* findNode(TreeNode* node, int propId) const;
    void deleteNode(TreeNode*& node, int propId);
    void displayInOrder(TreeNode* node) const;

public:
    // CONSTRUCTOR AND DESTRUCTOR
    RealEstateTree() : root(nullptr) {}
    ~RealEstateTree() { clearTree(root); }

    // PUBLIC FUNCTIONS TO MANIPULATE THE TREE
    void addListing(int propId, string addr, double price, string type);
    PropertyNode* searchListing(int propId) const;
    void removeListing(int propId);
    void displayAllListings() const;

    // HELPER FUNCTION TO CLEAR THE TREE
    void clearTree(TreeNode* node);
};
