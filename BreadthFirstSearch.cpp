#include<iostream>
#include<fstream>
#include<vector>
#include<list>
#include<queue>
#include<stack>
using namespace std;


typedef vector<list<int>> Graph;

struct vertexInfo
{
	int distance;
	int previous_node;
};


void printpath(int current, vector<vertexInfo>& vertices)
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


//Vertex representations are in adjacency lists.
void shortestPath(Graph& graph, int source)
{
	queue<int> graphQueue;

	vector<vertexInfo> vertices(graph.size());
	for (auto i : vertices)
	{
		i.distance = -1;i.previous_node = -1;
	}
	vertices[source].distance = 0;

	graphQueue.push(source);

	while (!graphQueue.empty())
	{
		int current = graphQueue.front();
		graphQueue.pop();
		for (list<int>::iterator itr = graph[current].begin(); itr != graph[current].end();itr++)
		{
			if (vertices[*itr].distance == -1)
			{
				vertices[*itr].distance = vertices[current].distance + 1;
				vertices[*itr].previous_node = current;
				graphQueue.push(*itr);
				
			}


		}


	}

	for (int counter = 0;counter < vertices.size();counter++)
	{
		cout << "Vertex: " << counter << endl;
		cout << "Distance: " << vertices[counter].distance << endl;
		cout << "Shortest Path: ";
		printpath(counter, vertices);
		cout << endl << endl;


	}




}


void main()
{
	Graph g(
		6);
	g[
		0].push_back
		(
			2);
		g[
			1].push_back
			(
				3);
			g[
				1].push_back
				(
					2);
				g[
					2].push_back
					(
						3);
					g[
						2].push_back
						(
							5);
						g[
							2].push_back
							(
								1);
							g[
								2].push_back
								(
									0);
								g[
									3].push_back
									(
										1);
									g[
										3].push_back
										(
											2);
										g[
											3].push_back
											(
												4);
											g[
												5].push_back
												(
													4);
												g[
													4].push_back
													(
														5);
													g[
														4].push_back
														(
															3);
														g[
															5].push_back
															(
																2);



															shortestPath(g, 0);



}
