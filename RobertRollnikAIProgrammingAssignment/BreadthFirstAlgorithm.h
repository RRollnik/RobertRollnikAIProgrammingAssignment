#pragma once

#ifndef BREADTHFIRST_H
#define BREADTHFIRST_H

#include <vector>
#include "Node.h"

class BreadthFirst
{
public:
	void BreadthFirstSearch(/*std::vector<Node> search,*/ Node* start, Node* goal);

private:
	//Vectors for storing the nodes to make the path, nodes visited and nodes not visited 
	std::vector<Node*> Path;
	std::vector<Node*> Open;
	std::vector<Node*> Close;
	std::vector<Node*> Blockade;

	//Boolean variable to check if the goal node has been reached or not
	bool goalnode = false;

};

#endif