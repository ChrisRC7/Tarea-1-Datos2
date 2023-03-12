#include <iostream>
//#include "Node.cpp"
//#include "Collector.cpp"
#include "List.cpp"

int main() {
    size_t t;
    void* v;
    List* list= (List*)malloc(sizeof(List));
    

    list->operator new(t, 5, list);
    list->operator new(t, 8, list);
    list->displayList();
    list->operator new(t, 14, list);
    list->operator new(t, 15, list);
    list->operator new(t, 16, list);
    list->operator new(t, 17, list);
    list->operator new(t, 80, list);
    list->displayList();
    list->operator delete(v, 14, list);

    
    list->changeFirst(20);
    list->operator new(t, 69, list);
    list->setFirst(5);
    list->displayList();

    return 0;
}
