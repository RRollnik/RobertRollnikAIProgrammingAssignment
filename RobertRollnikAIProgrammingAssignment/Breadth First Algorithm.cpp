//Class to add the function of the Breadth First Search Algorithm to the program for actors to find a path to the desired goal

#include "Breadth First Algorithm.h"

void BreadthFirst::BreadthFirstSearch(std::vector<Node> search, Node* start, Node* goal)
{

	//Pushes the start/first node into the Open vector so that the program knows with whitch node to start
	Open.push_back(start);

	//Pushes the start/first node into the closed vector for the program to know it has been visited and does not need to be reffered to again
	Close.push_back(start);

	while (!Open.empty() || goalnode)
	{
		Node* currentNode = Open.front();
		/*Add that the function should check if the node is in closed of not*/
		for (std::vector<Node>::iterator count = search.begin(); count != search.end(); count++)
		{
			if (currentNode == goal)
			{
				goalnode = true;
				break;
			}

			else
			{
				Path.push_back(currentNode);
			}

			Close.push_back(currentNode);
		}


	}
}