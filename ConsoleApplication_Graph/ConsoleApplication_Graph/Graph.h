#pragma once
//author: �������� ���������

#include <stdexcept> // ��� ����������
#include <iostream>
#include <cstring>

#include "LinkedList.h"

using namespace std;

// ����� �����
template <typename T>
class Graph
{
private:
	// �������� ������ �������� ������ ������, ������� ���������
	//� ������� ������ (����� ������) �����
	LinkedList<T> vertexList; // ������ ������
	T** edge;  // ������� ���������
	int graphsize; // ����� ������ � �����
	int maxGraphSize; // ������������ ����� ������ � �����

	// ������ ��� ������ ������� � �������� �� ������� � ������
	int FindVertex(LinkedList<T>& L1, const T& vertex1);
	int GetVertexPos(const T& vertex1);

public:
	// �����������
	Graph(int maxsize);

	// ����������
	~Graph();

	// ������ �������� �����
	bool GraphEmpty() const; // true, ���� ���� ����

	// ������ ��������� ������

	// ���������� ������
	//int NumberOfVertices() const;

	// ���������� ����
	//int NumberOfEdges(void) const;

	// ��������� ���� �����
	int GetWeight(const T& vertex1, const T& vertex2);

	// ��������� ������ �� �������� ������
	LinkedList<T>& GetNeighbors(const T& vertex);

	// ������ ����������� �����

	// d������� �������
	void InsertVertex(const T& vertex);

	// ������� �����
	void InsertEdge(const T& vertexl, const T& vertex2, int weight);

	// �������� �������
	void DeleteVertex(const T& vertex);

	// �������� �����
	void DeleteEdge(const T& vertexl, const T& vertex2);

	// �������
	//void ReadGraph(char* filename);
	//int MinimumPath(const T& sVertex, const T& sVertex);

	// ����� � �������
	LinkedList<T>& DepthFirstSearch(const T& beginVertex);

	// ����� � ������
	LinkedList<T>& BreadthFirstSearch(const T& beginVertex);

	// �������� ��� ������ ������
	//friend class VertexIterator<T>;
};

// �����������, �������� ������� ��������� � ���������� graphsize
// �������� ������ ��� ������� ���������
template <typename T>
Graph<T>::Graph(int maxsize)
{
	edge = nullptr;

	// ������ cout ����������� ����������
	if (maxsize <= 0) {
		throw invalid_argument("������������ ������������ ���������� ������");
		//std::cout << "������������ ����������� �������";
	}
	maxGraphSize = maxsize;

	// ��������� ������ ��� �������
	edge = new T * [maxGraphSize];

	for (int i = 0; i < maxGraphSize; i++) {
		edge[i] = new T [maxGraphSize];
	}

	// ���������� ������� ��������� ������
	for (int i = 0; i < maxGraphSize; i++)
		for (int j = 0; j < maxGraphSize; j++)
			edge[i][j] = 0;

	// ����������� ���������� ������ � ����� = 0
	graphsize = 0;

}

// ����������
template <typename T>
Graph<T>::~Graph() {
	// ���������� ������, ���������� ��� �������
	// ���� ��� ������ ���� ���������
	if (edge != nullptr) {

		for (int i = 0; i < maxGraphSize; i++) {
			delete[] edge[i];
		}

		delete[] edge;
	}

}

// ����� �������� ����� �� ���������� ������, true, ���� ���� ����
template <typename T>
bool Graph<T>::GraphEmpty() const {
	if (graphsize == 0) {
		return true;
	}
	else return false;
}

// ���������� ������
/*template <typename T>
int  Graph<T>::NumberOfVertices() const {
	return 1;
}*/

// ��������� ������� ������� � ������
// ���� ������� ���, �� ���������� -1
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

// ��������� ���� �����
template <typename T>
int Graph<T>::GetWeight(const T& vertex1, const T& vertex2) {
	//return 1;
}