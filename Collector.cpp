#include <bits/stdc++.h>
#include <iostream>
#include "Node.cpp"
class Collector
{
private:
    Node *head;

private:
    int size;

public:
    Collector()
    {
        this->head = NULL;
        this->size = 0;
    };

public:
    bool isEmpty()
    {
        return this->size == 0;
    };

public:
    int Size()
    {
        return this->size;
    };

public:
    void insertFirst(int data)
    {
        Node *newNode = NULL;
        newNode = new Node(data);
        newNode->setNext(this->head);
        this->head = newNode;
        this->size++;
    };

public:
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

public:
    void displayList()
    {
        Node *current = this->head;
        while (current != NULL)
        {
            printf("%d", current->getData());
            current = current->getNext();
        }
    };
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