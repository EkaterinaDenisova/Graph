// ConsoleApplication_Graph.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "LinkedList.h"
#include "Graph.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
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


    cout << l.searchNodeInd(2) <<"\n";

    try {
        cout << l.dataByInd(1);
    }
    catch (invalid_argument const& ex) {
        cout << ex.what();
    }

    cout << "\n" << l.ListSize();

    LinkedList<int> l1;
    cout << "\n" << l1.ListSize();

    l.removeNode(5);
    cout << "\n";
    // цикл с использованием итераторов
    for (LinkedList<int>::LinkedListIterator<int> it1 = l.begin(); it1 != l.end(); ++it1) {
        cout << *it1 << " ";
    }
    cout << "\n" << l.ListSize();

    cout << "\n\nТестирование класса Граф\n";

    try {

        Graph<int> g(5);
        //cout << g.NumberOfVertices();
        //cout << g.GetMaxSize();

        g.InsertVertex(2);
        g.InsertVertex(4);

        g.InsertEdge(2, 4, 100);
        vector<int> v1;
        v1 = g.GetNeighbors(2);

        //cout << v1.at(0);

        g.InsertVertex(10);
        g.InsertEdge(2, 10, 50);
        g.InsertEdge(10, 4, 70);
        
        cout << "\n" << g.GetWeight(10, 4);
        cout << "\n" << g.GetWeight(2, 4);

        cout << "\n\n";
        //g.DeleteVertex(2);
        //v1 = g.GetNeighbors(10); 
        //cout << "\n" << v1.at(0);
        vector<int> v2 = g.DepthFirstSearch(2);

        for (int item : v2) {
            cout << item << " ";
        }

        cout << "\n\n";
        v2 = g.BreadthFirstSearch(2);
        for (int item : v2) {
            cout << item << " ";
        }

    }
    catch (invalid_argument const& ex) {
        cout << ex.what();
    }
}
