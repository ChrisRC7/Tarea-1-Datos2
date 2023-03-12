#include "Collector.cpp"

class List {
private:
    Node *head;
    Node *tail;
    int size;
    Collector *collector;

public:
    List()
    {
        this->head = NULL;
        this->tail = NULL;
        this->size = 0;
        this->collector = new Collector();
    };

public:
    void neW(int newData) {
        if (collector->isEmpty()) { //Collector vacio, MALLOC
            Node *newNode = (Node*)malloc(sizeof(Node));
            newNode->setData(newData);

            if (head == NULL) {
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
        } else {
            Node *newNode = collector->deleteFirst();
            *newNode = newData;

            if (head == NULL) {
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
    }

public:
    void deletE(int deleteData) {
        Node *current = head;
        Node *temp = head;

        while(current != NULL) {
            if (current->getData() == deleteData) {
                temp = current->getNext();
                current->getPrevious()->setNext(temp);
                temp->setPrevious(current->getPrevious());
                collector->insertFirst(current);
                size--;
                break;
            } else {
                temp = current;
                current = current->getNext();
            }
        }

        if (current == NULL) {
            printf("El valor %i a eliminar no se encuentra en al lista\n", deleteData);
        } else {
            printf("Se ha eliminado %i de la lista\n\n", deleteData);
        }
    }
public:
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