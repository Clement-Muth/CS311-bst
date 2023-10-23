/**
 * Implementation of BST class.
 */
// You must complete the TODO parts and then complete LinkedList.cpp. Delete "TODO" after you are done.
// You should always comments to each function to describe its PURPOSE and PARAMETERS

// =======================================================
// Your name: ??? (TODO: Add your name)
// Compiler:  g++
// File type: cpp file BST.cpp
// @brief This class implements a BST search tree
//=======================================================

#include "BST.h"
#include <vector>
#include <iostream>

/**
 * Implement the BST constructor
 */
BST::BST()
{
    root = nullptr;
    numElements = 0;
}

/**
 * Implement the BST destructor
 */
BST::~BST()
{
    // Must release memory correctly to avoid memory leaks
    clear();
}

/**
 * Implement size() correctly
 */
unsigned int BST::size() const
{
    return numElements;
}

/**
 * Implement clear() correctly without memory leaks
 */
void BST::clear()
{
    release(root);
    numElements = 0;
    root = nullptr;
}

void BST::release(Node *node)
{

    if (node == nullptr) return;
    release(node->leftChild);
    release(node->rightChild);
    delete node;
}

/**
 * Implement insert() correctly
 */
bool BST::insert(T element)
{
    Node *parent = nullptr;
    Node *curr = root;

    while (curr != nullptr) {
        parent = curr;
        if (element < curr->data) curr = curr->leftChild;
        else if (element > curr->data) curr = curr->rightChild;
        else return false;
    }

    Node *newNode = new Node(element);
    numElements++;

    if (parent == nullptr) root = newNode;
    else if (element < parent->data) parent->leftChild = newNode;
    else parent->rightChild = newNode;
    return true;
}

/**
 * Implement find() correctly
 */
bool BST::find(const T &query) const
{
    Node *curr = root;

    while (curr != nullptr) {
        if (query == curr->data) return true;
        curr = query < curr->data ? curr->leftChild : curr->rightChild;
    }
    return false;
}

/**
 * Implement the height() function correctly
 */
int BST::height() const
{
    return height(root);
}

int BST::height(Node *node) const
{
    return node == nullptr ? -1 : 1 + std::max(height(node->leftChild), height(node->rightChild));
}

/**
 * Implement the getRoot() function correctly
 */
BST::Node *BST::getRoot()
{
    return root;
}

/**
 * @brief Print the subtree at node using inorder traversal
 * @param node a pointer to node in BST
 */
void BST::printInorder(Node *node)
{
    if (node == nullptr) return;
    printInorder(node->leftChild);
    std::cout << node->data << " ";
    printInorder(node->rightChild);
}

/**
 * @brief Print the subtree at node using preorder traversal
 * @param node a pointer to node in BST
 */
void BST::printPreorder(Node *node)
{
    if (node == nullptr) return;
    std::cout << node->data << " ";
    printPreorder(node->leftChild);
    printPreorder(node->rightChild);
}

/**
 * @brief Print the subtree at node using postorder traversal
 * @param node a pointer to node in BST
 */
void BST::printPostorder(Node *node)
{
    if (node == nullptr) return;
    printPostorder(node->leftChild);
    printPostorder(node->rightChild);
    std::cout << node->data << " ";
}

/**
 * Implement the getLeftMostNode() function correctly
 */
BST::Node *BST::getLeftMostNode()
{

    return getLeftMostNode(root);
}

BST::Node *BST::getLeftMostNode(BST::Node *node)
{
    if (node == nullptr) return nullptr;
    while (node->leftChild != nullptr) node = node->leftChild;
    return node;
}

/**
 * Implement the BST successor function correctly
 */
BST::Node *BST::successor(Node *node)
{
    if (node == nullptr) return nullptr;
    if (node->rightChild != nullptr) return getLeftMostNode(node->rightChild);
    Node *successor = nullptr;
    Node *curr = root;

    while (curr != nullptr) {
        if (node->data < curr->data) {
            successor = curr;
            curr = curr->leftChild;
        } else if (node->data > curr->data) curr = curr->rightChild;
        else break;
    }
    return successor;
}
