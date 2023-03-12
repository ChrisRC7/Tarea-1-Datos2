#include <iostream>
//#include "Node.cpp"
//#include "Collector.cpp"
#include "List.cpp"

int main() {
    List* list= (List*)malloc(sizeof(List));
    list->operator new(NULL, 5, list);
    list->operator new(NULL, 8, list);
    list->displayList(list);
    list->operator new(NULL, 14, list);
    list->operator new(NULL, 15, list);
    list->operator new(NULL, 16, list);
    list->operator new(NULL, 17, list);
    list->operator new(NULL, 80, list);
    list->displayList(list);
    list->operator delete(NULL, 14, list);

    
    list->changeFirst(20);
    list->operator new(NULL, 69, list);
    list->displayList(list);

    return 0;
}
