#include <stdio.h> 
#include <iostream>
#include "Node.cpp"
#include "Collector.cpp"
#include "List.cpp"

void prueba() {
    List *list;
    list->operator new(sizeof(int), 7);

    list->displayList();

}

int main() {

    prueba();
    
    return 0;

}