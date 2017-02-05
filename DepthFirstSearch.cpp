#include<iostream>
#include<fstream>
#include<list>
#include<string>
#include<vector>
#include<stack>
#include<queue>

using namespace std;

typedef vector<list<int>> Graph;

//Vertex representations are in adjacency lists.

//Goal node is 8 and source node is 

struct VertexInfo
{
	int distance; //distance from source node to a particular node
	int previous_node; //previous node to a particular node in a solution path



};


void DFS(Graph& adjacencyList, int source)
{




}






int main()
{
	Graph adjacencyList(8);
	adjacencyList[0].push_back(1);
	adjacencyList[0].push_back(2);
	adjacencyList[1].push_back(3);
	adjacencyList[1].push_back(4);
	adjacencyList[2].push_back(4);
	adjacencyList[2].push_back(5);
	adjacencyList[3].push_back(6);
	adjacencyList[4].push_back(7);
	adjacencyList[5].push_back(7);
	adjacencyList[6].push_back(7);

	DFS(adjacencyList, 0);




}
