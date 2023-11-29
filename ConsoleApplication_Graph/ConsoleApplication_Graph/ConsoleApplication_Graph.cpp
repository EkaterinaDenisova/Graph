// ConsoleApplication_Graph.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "LinkedList.h"

using namespace std;

int main()
{
    std::cout << "Hello World!\n";
    LinkedList<int> l;
    l.addNode(5);
    l.addNode(10);
    l.printList();
    std::cout << "\n";

    // цикл с использованием итераторов
    for (LinkedList<int>::LinkedListIterator<int> it1 = l.begin(); it1 != l.end(); ++it1) {
        cout << *it1 << " ";
    }

    std::cout << "\n";

    // Автоматически создаётся 2 итератора на начало и конец
    // совпадает с циклом выше, но реализация короче
    for (auto it2 : l) {
        cout << it2 << " ";
    }


    cout << l.searchNodeInd(2);
}
