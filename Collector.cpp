#include <bits/stdc++.h>
#include <iostream>
#include "Node.cpp" 
/* It creates a linked list that stores integers */
class Collector
{


/* Creating a constructor for the class. */
public:
    /**
     * This function is a constructor for the Collector class
     */
    static Collector* instance()
    {  
        static Collector* instance= new Collector();
        return instance;
    };

    /**
     * It returns true if the size of the list is 0, otherwise it returns false.
     * 
     * @return A boolean value.
     */
    bool isEmpty()
    {
        return this->size == 0;
    };

    /**
     * It returns the size of the array.
     * 
     * @return The size of the array.
     */
    int Size()
    {
        return this->size;
    };

    /**
     * It inserts a new node at the beginning of the list.
     * 
     * @param data The data that you want to insert into the linked list.
     */
    void insertFirst(Node *newNode)
    {
        newNode->setNext(this->head);
        this->head = newNode;
        this->size++;
    };

    /**
     * It deletes the first node in the linked list.
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
     * It prints the list.
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
    Collector() : head(NULL), size(0){}
    Node* head;
    int size;

};

/*int main()
{
    Collector *Prueba;
    Prueba = new Collector();
    Prueba->insertFirst(1);
    Prueba->insertFirst(2);
    Prueba->insertFirst(3);
    Prueba->insertFirst(4);
    Prueba->insertFirst(5);
    Prueba->displayList();

    return 0;
};*/