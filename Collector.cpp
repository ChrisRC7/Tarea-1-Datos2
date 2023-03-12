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
    void insertFirst(Node *newNode)
    {
        //printf("\nEntro al insertFirst de Collector\n");
        //printf("%d \tPosicion de memoria: %p\n", newNode->getData(), *newNode);
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
        printf(" ------ Displaying COLLECTOR con %i de elementos ------\n", size);
        Node *current = this->head;
        while (current != NULL)
        {
            printf("%d \tPosicion de memoria: %p\n", current->getData(), current);
            current = current->getNext();
        }
    };
};
