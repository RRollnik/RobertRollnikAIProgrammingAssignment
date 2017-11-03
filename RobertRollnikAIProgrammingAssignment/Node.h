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
	Node* GetParent() { return parent; }

	void SetY(int Yv2) { y = Yv2; }
	void SetX(int Xv2) { x = Xv2; }
	void SetImage(std::shared_ptr <Surface> image) { thenodessurface = image; }
	void SetParent(Node* newparent) { parent = newparent; }


	void Draw(std::shared_ptr<Surface> screen);

	void addNeighbour(Node* neighbour);



	std::vector<Node *> neighbours;

private:
	//position, scope, draw node or put on screen, etc
	int y;
	int x;


	int column;
	int row;

	Node* parent;
	std::shared_ptr <Surface> thenodessurface;

};

#endif