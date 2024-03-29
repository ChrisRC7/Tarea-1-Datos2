#include "Collector.cpp"

/* It's a circular doubly linked list with a collector */
class List {
/* It's declaring the variables that will be used in the class. */
private:
    Node *head;
    Node *tail;
    int size;
  

/* It's the constructor of the class. */
public:
    List(){ 
        head= NULL;
        tail= NULL;
        size=0;
}

    /**
     * @brief If the collector is empty, then we use malloc to create a new node, otherwise we use the
     * collector to get a node
     * 
     * @param sizet The size of the memory block, in bytes.
     * @param newData The data that will be stored in the node.
     * @param list The list where the new node will be added.
     * 
     * @return A pointer to the new allocated memory.
     */
    void* operator new(size_t sizet,int newData, List* list) {
       
        if (Collector::instance()->isEmpty()) { //Collector vacio, MALLOC
            Node *newNode = (Node*)malloc(sizeof(Node));
            newNode->setData(newData);

            if (list->head == NULL)
            {
                list->head = newNode;
                list->tail = newNode;

                list->head->setNext(list->tail);
                list->head->setPrevious(list->tail);

                list->tail->setNext(list->head);
                list->tail->setPrevious(list->head);
            }
            else
            {
                newNode->setNext(list->head);
                newNode->setPrevious(list->tail);

                list->tail->setNext(newNode);
                list->head->setPrevious(newNode);

                list->head = newNode;
            }
            list->size++;
        }
        else
        {
            Node *newNode = Collector::instance()->deleteFirst();
            *newNode = newData;

            if (list->head == NULL)
            {
                list->head = newNode;
                list->tail = newNode;

                list->head->setNext(list->tail);
                list->head->setPrevious(list->tail);

                list->tail->setNext(list->head);
                list->tail->setPrevious(list->head);
            }
            else
            {
                newNode->setNext(list->head);
                newNode->setPrevious(list->tail);

                list->tail->setNext(newNode);
                list->head->setPrevious(newNode);

                list->head = newNode;
            }
            list->size++;
        }
        void* ptr= malloc(sizet);
        return ptr;
    }

    /**
     * @brief This function deletes a node from the list
     * 
     * @param Void This is the pointer to the memory that is being deleted.
     * @param deleteData The data to be deleted from the list
     * @param list The list that the node is being deleted from.
     */
    void operator delete(void* Void, int deleteData, List* list) {
        Node *current = list->head;
        Node *temp = list->head;

        while (current != NULL)
        {
            if (current->getData() == deleteData)
            {
                temp = current->getNext();
                current->getPrevious()->setNext(temp);
                temp->setPrevious(current->getPrevious());
                Collector::instance()->insertFirst(current);
                list->size--;
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


    /**
     * It prints the value of the first node in the list
     */
    void printFirst()
    {
        List* list= static_cast<List*>(NULL);
        printf("El valor al inicio de esta lista es: %i\n", list->head->getData());
    }


    /**
     * This function changes the data of the first node in the linked list
     * 
     * @param setData The data you want to set the first node to.
     */
    void changeFirst(int setData)
    {
        head->setData(setData);
    }


    
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


        Collector::instance()->displayList();

        printf("\n\n\n");

    };
};