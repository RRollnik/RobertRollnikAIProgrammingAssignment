//Class to add the function of the Breadth First Search Algorithm to the program for actors to find a path to the desired goal

#include "BreadthFirstAlgorithm.h"

void BreadthFirst::BreadthFirstSearch(/*std::vector<Node> search,*/ Node* start, Node* goal)
{

	//Pushes the start/first node into the Open vector so that the program knows with whitch node to start
	Open.push_back(start);

	//Pushes the start/first node into the closed vector for the program to know it has been visited and does not need to be reffered to again
	//Close.push_back(start);

	while (!Open.empty() || goalnode)
	{
		Node* currentNode = Open.front();

		for (size_t i = 0; i < currentNode->neighbours.size(); i++)
		{
			bool found = false;
			Node* N = currentNode->neighbours.at(i);
			for (std::vector<Node*>::iterator count = Open.begin(); count != Open.end(); count++)
			{
				if (*count == N)
				{
					found = true;
					break;
				}
			}

			for (std::vector<Node*>::iterator count = Close.begin(); count != Close.end(); count++)
			{
				if (*count == N)
				{
					found = true;
					break;
				}
			}

			if (found == false)
			{
				N->parent = currentNode;
				Open.push_back(N);
			}
		}

		if (currentNode == goal)
		{
			goalnode = true;
			std::cout << "Goal has been reached" << std::endl;
			break;
		}

		else
		{
			Path.push_back(currentNode);
			std::cout << "Goal has not been reached" << std::endl;
		}

		Close.push_back(currentNode);
		Open.erase(Open.begin());
	}
}