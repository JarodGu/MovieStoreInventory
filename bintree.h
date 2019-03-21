// ------------- bintree.h --------------------------------------------------
// Jarod Guerrero, Ajeet Dhaliwal, Kaib Cropley CSS 343 C
// Created 1/27/19
// Last Modified 3/20/19
// -------------------------------------------------------------------------
// Binary Search Tree header file modified to support the movie store
// -------------------------------------------------------------------------
// The Binary Search Tree contains Nodes with string data
// Header file contains several private helper functions to recursively
// implement public functions.
// Node is also implemented here. It contains a NodeData* and Node* to
// a left and right child.
// -------------------------------------------------------------------------

#ifndef ASSIGNMENT2_BINTREE_H
#define ASSIGNMENT2_BINTREE_H

#include "nodedata.h"
#include <iostream>
#include <fstream>
class BinTree
{
    friend std::ostream& operator<<(std::ostream &outStream, const BinTree &b);

public:
    BinTree();
    BinTree(BinTree &b);
    ~BinTree();

    void bstreeToArray(NodeData* arr[]);
    void arrayToBSTree(NodeData* arr[]);

    bool isEmpty() const;
    void makeEmpty();
    bool retrieve(const NodeData &target, NodeData* &pTarget);

    bool retrieveComedy(string &title, int releaseYear, NodeData* &pTarget);
    bool retrieveDrama(string &director, string &title, NodeData* &pTarget);
    bool retrieveClassic(int releaseMonth, int releaseYear, string &actorFirst,
            string &actorLast, NodeData* &pTarget);

    bool insert(NodeData* item);
    int getHeight(const NodeData &n) const;
    void displaySideways() const;

    // Overload operators
    BinTree& operator=(const BinTree &b);
    bool operator==(const BinTree &b) const;
    bool operator!=(const BinTree &b) const;

private:
    struct Node
    {
        NodeData* data;
        Node* left;
        Node* right;

    };
    Node* root;

    // Movie specific utility functions
    void comedyHelper(Node *current, string &title, int releaseYear, NodeData* &pTarget);
    void dramaHelper(Node *current, string &director, string &title, NodeData* &pTarget);
    void classicHelper(Node *current, int releaseMonth, int releaseYear, string &actorFirst,
                        string &actorLast, NodeData* &pTarget);
    // Utility functions
    void inorderHelper(Node* current, int &index, NodeData* arr[]) const;
    Node* arrayToBSTHelper(int low, int high, NodeData* arr[]);
    void copyHelper(Node* current, const Node *other);
    void deleteHelper(Node* current);
    Node* retrieveHelper(Node* current, const NodeData &target) const;
    int heightHelper(const Node* current) const;
    bool insertHelper(Node* current, NodeData* item);
    bool equalityHelper(const Node* current, const Node* other) const;
    void sideways(Node* current, int level) const;
    void coutHelper(std::ostream &outStream, const Node* current) const;
};
#endif //ASSIGNMENT2_BINTREE_H
