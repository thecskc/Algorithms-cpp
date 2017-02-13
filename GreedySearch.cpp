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

//Source Node - 0, Goal Node - 7
struct VertexInfo
{
	int distance; //distance from source node to a particular node
	int previous_node; //previous node to a particular node in a solution path



};

int heuristic(int nodeNumber) //straight line distance from that particular node to node 7 (Bucharest)
{
	switch (nodeNumber)
	{
	case 0:
	{
		return 374;
	}
	case 1:
	{
		return 380;
	}
	case 2:
	{
		return 366;
	}
	case 3:
	{
		return 253;
	}
	case 4:
	{
		return 176;
	}
	case 5:
	{
		return 193;
	}
	case 6:
	{
		return 98;
	}
	case 7:
	{
		return 0; //Bucharest - goal
	}
	default:
	{
		return -1;
	}
		
	}


}




int main()
{
	Graph g(8); //8 Nodes in total.
	g[0].push_front(1);
	g[0].push_front(2);
	g[1].push_front(3);
	g[1].push_front(0);
	g[2].push_front(3);
	g[2].push_front(0);
	g[3].push_front(4);
	g[3].push_front(5);
	g[3].push_front(1);
	g[3].push_front(2);
	g[4].push_front(7);
	g[4].push_front(3);
	g[5].push_front(6);
	g[5].push_front(3);
	g[6].push_front(7);
	g[6].push_front(5);



}