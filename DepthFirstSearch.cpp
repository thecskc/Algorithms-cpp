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

//Goal node is 7 and source node is 0

struct VertexInfo
{
	int distance; //distance from source node to a particular node
	int previous_node; //previous node to a particular node in a solution path



};

void printpath(int current, vector<VertexInfo>& vertices)
{
	stack<int> path;
	int j = current;
	while (j != -1)
	{
		path.push(j);
		j = vertices[j].previous_node;


	}

	while (!path.empty())
	{
		cout << path.top() << ": ";
		path.pop();


	}




}



void DFS(Graph& graph, int source)
{
	stack<int> graphStack;
	vector<VertexInfo> vertices(graph.size());
	for (int counter=0;counter<vertices.size();counter++)
	{
		vertices[counter].distance = -1;
		vertices[counter].previous_node = -1;

		cout << vertices[counter].distance << " : " << vertices[counter].previous_node << endl;

	}
	vertices[source].distance = 0;

	
	graphStack.push(source);
	while (!graphStack.empty())
	{

		int current = graphStack.top();
		
		graphStack.pop();
		for (list<int>::iterator itr = graph[current].begin();itr != graph[current].end();itr++)
		{	
			cout << *itr << endl;
			cout << vertices[*itr].distance << endl;
			if (vertices[*itr].distance == -1)
			{
				
				vertices[*itr].distance = vertices[current].distance + 1;
				vertices[*itr].previous_node = current;
				graphStack.push(*itr);
			}

		}


	}




	printpath(7, vertices);




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
