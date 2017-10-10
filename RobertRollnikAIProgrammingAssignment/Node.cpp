#include "Node.h"

Node::Node(std::shared_ptr <Surface> thenodessurface, int column, int row)
{
	this->thenodessurface = thenodessurface;
	this->column = column;
	this->row = row;
}

Node::~Node()
{
}

void Node::Draw(std::shared_ptr<Surface> screen)
{
	thenodessurface->blit(screen, x, y);
}

void Node::addNeighbour(Node* neighbour)
{
	neighbours.push_back(neighbour);
}