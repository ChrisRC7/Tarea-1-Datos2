#include <iostream>
//#include "Node.cpp"
//#include "Collector.cpp"
#include "List.cpp"

int main() {

    List *list = new List();
    list->neW(9);
    list->neW(14);
    list->neW(15);
    list->neW(16);
    list->neW(17);
    list->displayList();

    list->changeFirst(16);
    list->displayList();

    return 0;
}
