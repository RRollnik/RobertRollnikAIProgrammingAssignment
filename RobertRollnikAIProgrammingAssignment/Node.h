#pragma once

#ifndef NODE_H
#define NODE_H

#include <vector>
#include "Surface.h"

class Node
{
public:
	Node(std::shared_ptr <Surface> thenodessurface, int column, int row);
	~Node();

	int GetY() { return y; }
	int GetX() { return x; }

	void SetY(int Yv2) { y = Yv2; }
	void SetX(int Xv2) { x = Xv2; }

	void Draw(std::shared_ptr<Surface> screen);

	void addNeighbour(Node* neighbour);

private:
	//position, scope, draw node or put on screen, etc
	int y;
	int x;

	int column;
	int row;

	std::shared_ptr <Surface> thenodessurface;

public:
	std::vector<Node *> neighbours;
};

#endif