#include <iostream>
#include "Node.cpp"
#include "Collector.cpp"

class List
{
private:
    static Node *head;
    static Node *tail;
    static int size;
    static Collector *collector;

public:
    List()
    {
        this->head = NULL;
        this->tail = NULL;
        this->size = 0;
        this->collector = new Collector();
    };

public:
    Node search(int searchData)
    {
        Node *current = this->head;
        while (current->getData() != NULL)
        {
            if (current->getData() == searchData) {
                return *current;
            } else {
                current = current->getNext();
            }
        }

        return NULL;
    }

public:
    void *operator new(size_t prueba, int data)
    {
        if (collector->isEmpty())
        { // crear espacio con malloc ya que el Collector no tiene espacios disponibles
            static Node *newNode = (Node *)malloc(sizeof(Node));
            newNode->setData(data);

            if (head == NULL) { // Si la lista esta vacia, el head y tail son los mismos
                head = newNode;
                tail = newNode;

                head->setNext(tail);
                head->setPrevious(tail);

                tail->setNext(head);
                tail->setPrevious(head);
            } else {
                newNode->setNext(head);
                newNode->setPrevious(tail);

                tail->setNext(newNode);
                head->setPrevious(newNode);

                head = newNode;
            }
            size++;
        }
        else
        { // reutiliza espacio de memoria, por lo que llamamos al Collector
            Node *newNode = collector->deleteFirst();
            newNode->setData(data);

            if (head == NULL) { // Si la lista esta vacia, el head y tail son los mismos
                head = newNode;
                tail = newNode;

                head->setNext(tail);
                head->setPrevious(tail);

                tail->setNext(head);
                tail->setPrevious(head);
            } else {
                newNode->setNext(head);
                newNode->setPrevious(tail);

                tail->setNext(newNode);
                head->setPrevious(newNode);

                head = newNode;
            }
            size++;
        }
    };

public: 
    void deletE(int deleteData) {
        Node *current = this->head;
        Node *temp= this->head;

        while (current != NULL)
        {
            if (current->getData() == deleteData) {
                //Proceso de eliminar
                temp = current->getNext();
                current->getPrevious()->setNext(temp);
                temp->setPrevious(current->getPrevious());
                size--;
                break;
            } else {
                temp = current;
                current = current->getNext();
            }
        }
        
        printf("El valor %i a eliminar no se encuentra en al lista", deleteData);
    }

/*public:
    int getFirst()
    {
        if (this->head != NULL)
        {
            return this->head->getData();
        }
        else
        {
            return NULL;
        }
    }*/

public:
    void modifyFirst(int data)
    {
        this->head->setData(data);
    }

public: 
    void displayList()
    {
        Node *current = head;
        printf("%d", current->getData());
        while (current != tail)
        {
            printf("%d", current->getData());
            current = current->getNext();
        }
    };

};
