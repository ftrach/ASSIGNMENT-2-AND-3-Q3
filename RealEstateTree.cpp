#include "RealEstateTree.h"

// ADD A NEW PROPERTY LISTING
void RealEstateTree::addListing(int propId, string addr, double price, string type) {
    PropertyNode newProperty(propId, addr, price, type);
    addNode(root, newProperty);
}

// RECURSIVELY ADD A NODE TO THE TREE
void RealEstateTree::addNode(TreeNode*& node, const PropertyNode& property) {
    if (!node) {
        node = new TreeNode(property);  // CREATE A NEW NODE
    } else if (property.id < node->property.id) {
        addNode(node->left, property); // INSERT INTO LEFT SUBTREE
    } else {
        addNode(node->right, property); // INSERT INTO RIGHT SUBTREE
    }
}

// SEARCH FOR A PROPERTY BY ID
PropertyNode* RealEstateTree::searchListing(int propId) const {
    TreeNode* result = findNode(root, propId);
    return result ? &result->property : nullptr;
}

// RECURSIVELY SEARCH FOR A NODE
RealEstateTree::TreeNode* RealEstateTree::findNode(TreeNode* node, int propId) const {
    if (!node || node->property.id == propId) {
        return node;  // RETURN NODE IF FOUND OR NULL IF NOT FOUND
    }
    if (propId < node->property.id) {
        return findNode(node->left, propId);  // SEARCH LEFT SUBTREE
    }
    return findNode(node->right, propId);    // SEARCH RIGHT SUBTREE
}

// REMOVE A PROPERTY FROM THE TREE
void RealEstateTree::removeListing(int propId) {
    deleteNode(root, propId);
}

// RECURSIVELY DELETE A NODE FROM THE TREE
void RealEstateTree::deleteNode(TreeNode*& node, int propId) {
    if (!node) return;
    if (propId < node->property.id) {
        deleteNode(node->left, propId);  // DELETE FROM LEFT SUBTREE
    } else if (propId > node->property.id) {
        deleteNode(node->right, propId); // DELETE FROM RIGHT SUBTREE
    } else {
        TreeNode* temp = nullptr;
        if (!node->left) {
            temp = node;
            node = node->right;  // REPLACE WITH RIGHT SUBTREE
        } else if (!node->right) {
            temp = node;
            node = node->left;   // REPLACE WITH LEFT SUBTREE
        } else {
            TreeNode* successor = node->right;
            while (successor->left) successor = successor->left;
            node->property = successor->property; // COPY SUCCESSOR'S DATA
            deleteNode(node->right, successor->property.id); // DELETE SUCCESSOR
            return;
        }
        delete temp; // DELETE THE NODE
    }
}

// DISPLAY ALL PROPERTIES IN ORDER
void RealEstateTree::displayAllListings() const {
    displayInOrder(root);
}

// RECURSIVELY DISPLAY NODES IN ORDER
void RealEstateTree::displayInOrder(TreeNode* node) const {
    if (node) {
        displayInOrder(node->left);       // DISPLAY LEFT SUBTREE
        node->property.displayDetails(); // DISPLAY CURRENT NODE
        displayInOrder(node->right);     // DISPLAY RIGHT SUBTREE
    }
}

// CLEAR THE TREE
void RealEstateTree::clearTree(TreeNode* node) {
    if (node) {
        clearTree(node->left);  // CLEAR LEFT SUBTREE
        clearTree(node->right); // CLEAR RIGHT SUBTREE
        delete node;            // DELETE CURRENT NODE
    }
}
