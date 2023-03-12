#include <iostream>
//#include "Node.cpp"
//#include "Collector.cpp"
#include "List.cpp"

int main() {
    size_t t;
    void* v;
    List* list= (List*)malloc(sizeof(List));
    

    //Add the firsts values to the list
    printf("------ ADDING VALUES ------ \n");
    list->operator new(t, 5, list);
    list->operator new(t, 8, list);
    list->displayList();

    //keep adding values
    printf("------ KEEP ADDING VALUES ------ \n");
    list->operator new(t, 14, list);
    list->operator new(t, 15, list);
    list->operator new(t, 16, list);
    list->operator new(t, 17, list);
    list->operator new(t, 80, list);
    list->displayList();
    
    //delete the 14 of the list
    printf("------ DELETING 14 ------ \n");
    list->operator delete(v, 14, list);
    list->displayList();

    
    // Change the first Value
    printf("------ CHANGING FIRST VALUE ------ \n");
    list->changeFirst(20);
    list->displayList();
    
    //Add 69 to the list
    printf("------ ADDING VALUE ------ \n");
    list->operator new(t, 69, list);
    list->displayList();
    
    //set 5 as the first 
    printf("------ SETTING 5 AS THE FIRST VALUE ------ \n");
    list->setFirst(5);
    list->displayList();

    return 0;
}
