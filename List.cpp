#include "Collector.cpp"

/* It's a circular doubly linked list with a collector */
class List {
/* It's declaring the variables that will be used in the class. */
private:
    Node *head;
    Node *tail;
    int size;
    Collector *collector;

/* It's the constructor of the class. */
public:
    List()
    {
        this->head = NULL;
        this->tail = NULL;
        this->size = 0;
        this->collector = new Collector();
    };

/* It's adding a new node to the list. */
public:
    /**
     * If the collector is empty, allocate a new node and add it to the list.
     *
     * If the collector is not empty, get a node from the collector and add it to the list.
     *
     * @param newData The data that will be stored in the new node.
     */
    void neW(int newData) {
        if (collector->isEmpty()) { //Collector vacio, MALLOC
            Node *newNode = (Node*)malloc(sizeof(Node));
            newNode->setData(newData);

            if (head == NULL)
            {
                head = newNode;
                tail = newNode;

                head->setNext(tail);
                head->setPrevious(tail);

                tail->setNext(head);
                tail->setPrevious(head);
            }
            else
            {
                newNode->setNext(head);
                newNode->setPrevious(tail);

                tail->setNext(newNode);
                head->setPrevious(newNode);

                head = newNode;
            }
            size++;
        }
        else
        {
            Node *newNode = collector->deleteFirst();
            *newNode = newData;

            if (head == NULL)
            {
                head = newNode;
                tail = newNode;

                head->setNext(tail);
                head->setPrevious(tail);

                tail->setNext(head);
                tail->setPrevious(head);
            }
            else
            {
                newNode->setNext(head);
                newNode->setPrevious(tail);

                tail->setNext(newNode);
                head->setPrevious(newNode);

                head = newNode;
            }
            size++;
        }
    }

/* It's deleting a node from the list and inserting it into the collector list. */
public:
    /**
     * It deletes a node from the list and inserts it into the collector list
     *
     * @param deleteData The data to be deleted from the list.
     */
    void deletE(int deleteData) {
        Node *current = head;
        Node *temp = head;

        while (current != NULL)
        {
            if (current->getData() == deleteData)
            {
                temp = current->getNext();
                current->getPrevious()->setNext(temp);
                temp->setPrevious(current->getPrevious());
                collector->insertFirst(current);
                size--;
                break;
            }
            else
            {
                temp = current;
                current = current->getNext();
            }
        }

        if (current == NULL)
        {
            printf("El valor %i a eliminar no se encuentra en al lista\n", deleteData);
        }
        else
        {
            printf("Se ha eliminado %i de la lista\n\n", deleteData);
        }
    }

public:
    void printFirst()
    {
        printf("El valor al inicio de esta lista es: %i\n", head->getData());
    }

public:
    void changeFirst(int setData)
    {
        head->setData(setData);
    }

public:
    void setFirst(int setData)
    {
        if (!(head->getData() == setData))
        {
            Node *current = head;
            Node *temp = head;

            while (current != NULL)
            {
                if (tail->getData() == setData)
                {
                    tail = tail->getPrevious();
                    head = tail->getNext();

                    break;
                }
                else
                {
                    if (current->getData() == setData)
                    {
                        temp->setNext(current->getNext());
                        current->getNext()->setPrevious(temp);

                        current->setNext(head);
                        current->setPrevious(tail);
                        head = current;

                        break;
                    }
                    else
                    {
                        temp = current;
                        current = current->getNext();
                    }
                }
            }

            if (current == NULL)
            {
                printf("El valor %i a asignar como primero NO se encuentra en la lista \n", setData);
            }
            else
            {
                printf("Se actualizo el primer valor de la lista\n");
            }
        }
        else
        {
            printf("El valor es el mismo al actual\n");
        }
    }

/* It's displaying the list. */
public:
    /**
     * It prints the list
     */
    void displayList()
    {
        printf(" ------ Displaying LIST con %i de elementos ------\n", size);
        Node *current = head;

        while (current != tail)
        {
            printf("%d \tPosicion de memoria: %p\n", current->getData(), current);
            current = current->getNext();
        }

        printf("%d \tPosicion de memoria: %p\n\n", current->getData(), current);


        collector->displayList();

        printf("\n\n\n");

    };
};