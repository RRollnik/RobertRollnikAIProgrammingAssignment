#include <SDL/SDL.h>
#undef main

#ifdef _MSC_VER
#include <windows.h>
#else
#include <unistd.h>
#endif

#include <iostream>
#include <string>
#include <memory>
#include <vector>

#include "Surface.h"
#include "Node.h"

#define GRID_HEIGHT 25
#define GRID_WIDTH 25

void BreadthFirstSearch(std::vector<Node> search, Node start, Node goal)
{
	std::vector<Node*> Path;
	std::vector<Node> Open;
	std::vector<Node> Close;

	Open.push_back(start);
	Close.push_back(start);

	bool goalnode = false;

	while (!(Open.empty) || goalnode)
	{
		Node currentNode = Open.front();

		for (std::vector<Node>::iterator count = search.begin(); count != search.end(); count++)
		{
			if (currentNode.GetX, currentNode.GetY == goal)
			{
				goalnode = true;
				break;
			}

			else
			{

			}
		}
	}
	//return *Path;
}

int main(int argc, char *argv[])
{
	std::shared_ptr<Surface> image;
	//makes a surface called image

	std::shared_ptr<Surface> screen;
	//makes a surface called screen

	SDL_Init(SDL_INIT_EVERYTHING);
	//initialise SDL

	screen = Surface::setVideoMode();

	image = Surface::loadBmp("node.bmp");
	int imageHeight = 50;
	int imageWidth = 50;

	int Grid_Width = 1280 / imageWidth;
	int Grid_Height = 720 / imageHeight;
	//numbers control the number of nodes we'll make so that they don't go beyond the screens borders

	std::vector<Node> nodes;
	//generate a vector of our Node class

	for (size_t y = 0; y < Grid_Height; y++)
	{
		for (size_t x = 0; x < Grid_Width; x++)
		{
			Node node(image, (y + 1), (x + 1));
			//makes a node, passes in 'image' which is the nodes texture representation, also the x and y, which we'll use as the column and row, hence why we add 1 to each, so that 0 becomes 1 etc

			node.SetX(x * 50);
			node.SetY(y * 50);
			//x and y being effectively the grid points of our node, we times that by 50 (which is the size of the image) to determine the x and y coordinate position to draw our image

			nodes.push_back(node);
			//pushes our newly defined class into the vector
		}
	}

	std::vector<Node*> grid;

	size_t i = 0;

	for (size_t y = 0; y < Grid_Height; y++)
	{
		for (size_t x = 0; x < Grid_Width; x++)
		{
			Node* curr = grid.at(i);
		}
	}

	for (size_t i = 0; i < nodes.size(); i++)
	{
		nodes.at(i).Draw(screen);
	}

	screen->flip();

#ifdef _MSC_VER
	Sleep(3000);
#else
	sleep(3);
#endif

	return 0;
}
