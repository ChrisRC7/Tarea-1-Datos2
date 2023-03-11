#include <iostream>
#include "Node.cpp"
#include "Collector.cpp"

class List
{
private: 
    Node *head;
    int size;
    Collector *collector;

public: 
    List()
    {
        this->head = NULL;
        this->size = 0;
        this->collector = new Collector();
    };

public:
    void insertFirst(int data)
    {
        if (collector->isEmpty()) {
            
        } else { 

        }
        Node *newNode = NULL;
        newNode = new Node(data);
        newNode->setNext(this->head);
        this->head = newNode;
        this->size++;
    };

public: 
    int getFirst() {
        if (this->head != NULL) {
            return this->head->getData();
        } else {
            return NULL;
        }
    }

public: 
    void modifyFirst(int data) {
        this->head->setData(data);
    }


};
