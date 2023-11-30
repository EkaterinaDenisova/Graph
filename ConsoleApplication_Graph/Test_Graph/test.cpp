#include "pch.h"
#include "../ConsoleApplication_Graph/Graph.h"

using namespace std;
// ������������ ������� ������
TEST(TestGraph, TestInsertVertex) {

	Graph<int> g1(2);
	EXPECT_EQ(g1.NumberOfVertices(),0);
	EXPECT_EQ(g1.GetMaxSize(), 2);

	g1.InsertVertex(1);
	g1.InsertVertex(5);

	EXPECT_EQ(g1.NumberOfVertices(), 2);
	EXPECT_EQ(g1.GetMaxSize(), 2);

	g1.InsertVertex(8);
	EXPECT_EQ(g1.NumberOfVertices(), 3);
	EXPECT_EQ(g1.GetMaxSize(), 4);

	// ��������� ������ ������
	vector<int> v1 = {1, 5, 8};
	vector<int> v2 = g1.GetVertexList();
	EXPECT_EQ(v1, v2);
  
}

// ������������ ������� ���� � ��������� ����
TEST(TestGraph, TestInsertEdge) {

	Graph<int> g1(2);
	

	g1.InsertVertex(1); g1.InsertVertex(5); g1.InsertVertex(8);
	
	g1.InsertEdge(1, 5, 20);
	g1.InsertEdge(5, 8, 45);
	g1.InsertEdge(5, 1, 12);

	// ��������� ��� ����
	EXPECT_EQ(20, g1.GetWeight(1,5));
	EXPECT_EQ(12, g1.GetWeight(5, 1));
	EXPECT_EQ(45, g1.GetWeight(5, 8));
	EXPECT_EQ(0, g1.GetWeight(1, 8)); // 0 ��������,  ��� ����� ���, �� ��� ������� ����������

	// �������� ���� ����� �������������� �������
	try {
		g1.GetWeight(5, 9);
	}
	catch (invalid_argument const& ex) {
		string s = ex.what();
		EXPECT_EQ(s, "����������� ��������� �������");
	}
}

// 
TEST(TestGraph, TestDelete) {
	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);
}

// �������� �������
TEST(TestGraph, TestNeighbors) {
	Graph<int> g1(2);


	g1.InsertVertex(1); g1.InsertVertex(5); g1.InsertVertex(8);
	g1.InsertVertex(2); g1.InsertVertex(13); 

	g1.InsertEdge(1, 5, 20);
	g1.InsertEdge(5, 8, 45);
	g1.InsertEdge(5, 1, 12);
	g1.InsertEdge(8, 13, 99);
	g1.InsertEdge(2, 13, 125);
	g1.InsertEdge(2, 5, 54);
	g1.InsertEdge(13, 1, 49);

	// �������� ������� ��� ������� 1
	vector<int> v1 = {5, 13};
	vector<int> v2 = {5};
	EXPECT_EQ(v1, g1.GetNeighbors(1));
	EXPECT_EQ(v2, g1.GetFolowers(1));

	// ��� ������� 5
	v1 = { 1, 8, 2 }; v2 = { 1, 8 };
	EXPECT_EQ(v1, g1.GetNeighbors(5));
	EXPECT_EQ(v2, g1.GetFolowers(5));

	// ��� ������� 8
	v1 = { 1, 8, 2 }; v2 = { 1, 8 };
	EXPECT_EQ(v1, g1.GetNeighbors(8));
	EXPECT_EQ(v2, g1.GetFolowers(8));

	
}

// ������������ ������� � ������� � ������
TEST(TestGraph, TestSearch) {
	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);
}