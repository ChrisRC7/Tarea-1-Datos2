#include <bits/stdc++.h>
#include <iostream>
#include "Node.cpp" 

class Collector
{

public:
   
    /**
     * @brief function `instance()` returns a pointer to a `Collector` object
     * 
     * @return A pointer to the instance of the Collector class.
     */
    static Collector* instance()
    {  
        static Collector* instance= new Collector();
        return instance;
    };

    /**
     * @brief It returns true if the size of the list is 0, otherwise it returns false.
     * 
     * @return A boolean value.
     */
    bool isEmpty()
    {
        return this->size == 0;
    };

    /**
     * @brief It returns the size of the array.
     * 
     * @return The size of the array.
     */
    int Size()
    {
        return this->size;
    };

    /**
     * @brief It inserts a new node at the beginning of the list.
     * 
     * @param newNode The node that you want to insert into the list.
     */
    void insertFirst(Node *newNode)
    {
        newNode->setNext(this->head);
        this->head = newNode;
        this->size++;
    };

    /**
     * @brief It deletes the first node in the linked list.
     * 
     * @return The first node in the list.
     */
    Node *deleteFirst()
    {
        if (this->head != NULL)
        {
            Node *temp = this->head;
            this->head = this->head->getNext();
            this->size--;
            return temp;
        }
        else
        {
            return NULL;
        }
    };

    /**
     * @brief It prints the list.
     */
    void displayList()
    {
        Node *current = this->head;
        while (current != NULL)
        {
            printf("%d", current->getData());
            current = current->getNext();
        }
    };

    private:
    /**
     * @brief A constructor for the Collector class. It initializes the head pointer to NULL and the size to
     * 0.
     */
    Collector() : head(NULL), size(0){}
    Node* head;
    int size;

};
