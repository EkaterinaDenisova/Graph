#pragma once
//author: Денисова Екатерина

#include <stdexcept> // для исключений
#include <iostream>
#include <cstring>

#include "LinkedList.h"

using namespace std;

// класс Графа
template <typename T>
class Graph
{
private:
	// основные данные включают список вершин, матрицу смежности
	//и текущий размер (число вершин) графа
	LinkedList<T> vertexList; // список вершин
	T** edge;  // матрица смежности
	int graphsize; // число вершин в графе
	int maxGraphSize; // максимальное число вершин в графе

	// методы для поиска вершины и указания ее позиции в списке
	int FindVertex(LinkedList<T>& L1, const T& vertex1);
	int GetVertexPos(const T& vertex1);

public:
	// конструктор
	Graph(int maxsize);

	// деструктор
	~Graph();

	// методы проверки графа
	bool GraphEmpty() const; // true, если граф пуст

	// методы обработки данных

	// количество вершин
	//int NumberOfVertices() const;

	// количество рёбер
	//int NumberOfEdges(void) const;

	// получение веса ребра
	int GetWeight(const T& vertex1, const T& vertex2);

	// получение списка из соседних вершин
	LinkedList<T>& GetNeighbors(const T& vertex);

	// методы модификации графа

	// dвставка вершины
	void InsertVertex(const T& vertex);

	// вставка ребра
	void InsertEdge(const T& vertexl, const T& vertex2, int weight);

	// удаление вершины
	void DeleteVertex(const T& vertex);

	// удаление ребра
	void DeleteEdge(const T& vertexl, const T& vertex2);

	// утилиты
	//void ReadGraph(char* filename);
	//int MinimumPath(const T& sVertex, const T& sVertex);

	// обход в глубину
	LinkedList<T>& DepthFirstSearch(const T& beginVertex);

	// обход в ширину
	LinkedList<T>& BreadthFirstSearch(const T& beginVertex);

	// итератор для обхода вершин
	//friend class VertexIterator<T>;
};

// конструктор, обнуляет матрицу смежности и переменную graphsize
// выделяет память под матрицу смежности
template <typename T>
Graph<T>::Graph(int maxsize)
{
	edge = nullptr;

	// вместо cout выбрасывать исключения
	if (maxsize <= 0) {
		throw invalid_argument("Неправильное максимальное количество вершин");
		//std::cout << "Неправильная размерность массива";
	}
	maxGraphSize = maxsize;

	// выделение памяти под матрицу
	edge = new T * [maxGraphSize];

	for (int i = 0; i < maxGraphSize; i++) {
		edge[i] = new T [maxGraphSize];
	}

	// заполнение матрицы смежности нулями
	for (int i = 0; i < maxGraphSize; i++)
		for (int j = 0; j < maxGraphSize; j++)
			edge[i][j] = 0;

	// фактическое количество вершин в графе = 0
	graphsize = 0;

}

// деструктор
template <typename T>
Graph<T>::~Graph() {
	// освободить память, выделенную под матрицу
	// если эта память была выделенна
	if (edge != nullptr) {

		for (int i = 0; i < maxGraphSize; i++) {
			delete[] edge[i];
		}

		delete[] edge;
	}

}

// метод проверки графа на отсутствие вершин, true, если граф пуст
template <typename T>
bool Graph<T>::GraphEmpty() const {
	if (graphsize == 0) {
		return true;
	}
	else return false;
}

// количество вершин
/*template <typename T>
int  Graph<T>::NumberOfVertices() const {
	return 1;
}*/

// получение индекса вершины в списке
// если вершины нет, то возвращает -1
template <typename T>
int Graph<T>::GetVertexPos(const T& vertex1) {

	return vertexList.searchNodeInd(vertex1);

	/*
	LinkedList<T>::LinkedListIterator<T> it1;
	bool vertex_found = false;
	int pos = 0;
	for (it1 = vertexList.begin(); it1 != vertexList.end(); ++it1) {
		if (*it1 == vertex1) {
			vertex_found = true;
			break;
		}
		else {
			pos++;
		}
		
	}
	LinkedList<T>::LinkedListIterator<T> liter = vertexList.begin();
	int pos = 0;
	while (!liter.EndOfList() && (*liter != vertex1))
	{
		pos++;
		liter.Next();
	}

	if (vertex_found) {
		return pos;
	}
	else return -1;*/
}

// получение веса ребра
template <typename T>
int Graph<T>::GetWeight(const T& vertex1, const T& vertex2) {
	//return 1;
}