#include <iostream>
/* A node is a data structure that contains a data and a pointer to the next node */
class Node
{
/* Declaring the data and the next and previous nodes. */
private:
    int data;
    Node *next;
    Node *previous;

/* A constructor. */
public:
    /**
     * The constructor for the Node class takes an integer as a parameter and sets the data value of
     * the node to the parameter, and sets the next and previous pointers to NULL
     * 
     * @param data The data that the node will hold.
     */
    Node(int data)
    {
        this->next = NULL;
        this->previous = NULL;
        this->data = data;
    };

/* A public method that returns the data of the node. */
public:
    /**
     * The function getData() returns the value of the data member of the object that calls it
     * 
     * @return The data member of the object.
     */
    int getData()
    {
        return this->data;
    }

/* A public method that sets the data of the node. */
public:
    /**
     * The function setData() takes an integer as an argument and sets the data member of the object to
     * the value of the argument
     * 
     * @param data The data to be stored in the node.
     */
    void setData(int data)
    {
        this->data = data;
    }

/* A public method that returns the next node. */
public:
    /**
     * Returns the next node in the list.
     * 
     * @return The next node in the list.
     */
    Node *getNext()
    {
        return this->next;
    }

/* A public method that returns the previous node. */
public:
    /**
     * This function returns the previous node
     * 
     * @return The previous node.
     */
    Node *getPrevious()
    {
        return this->previous;
    }

/* Setting the next node. */
public:
    /**
     * This function sets the next node of the current node to the node passed in as a parameter
     * 
     * @param node The node to set as the next node.
     */
    void setNext(Node *node)
    {
        this->next = node;
    }

/* Setting the previous node. */
public:
    /**
     * This function sets the previous node of the current node to the node passed in as a parameter
     * 
     * @param node The node to set as the previous node.
     */
    void setPrevious(Node *node)
    {
        this->previous = node;
    }
};
