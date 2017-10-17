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
#include "BreadthFirstAlgorithm.h"

#define GRID_HEIGHT 25
#define GRID_WIDTH 25



int main(int argc, char *argv[])
{
	BreadthFirst Algor;
	std::shared_ptr<Surface> image;
	//makes a surface called image

	std::shared_ptr<Surface> screen;
	//makes a surface called screen

	SDL_Init(SDL_INIT_EVERYTHING);
	//initialise SDL

	screen = Surface::setVideoMode();

	image = Surface::loadBmp("notvisitednode.bmp");
	int imageHeight = 50;
	int imageWidth = 50;

	int Grid_Width = 1280 / imageWidth;
	int Grid_Height = 720 / imageHeight;
	//numbers control the number of nodes we'll make so that they don't go beyond the screens borders

	//Generate the grid
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

	//Adds the function to the grid to know of its neighbours
	//Nested loop traverses the grid adding neighnours to the top, bottom, left and right
	//Neighbours are added by adding and subtracting 1 from the grid width and height as this represents the position of the neighbouting nodes
	/*Add diagonals
		Try not to cry, cry a lot and then kill yours self because its too much for my tiny stupid brain to understand but
		its too essencial then ask someone how knows how to do this stuff*/
	/*Move to class????*/

	size_t i = 0;

	for (size_t y = 0; y < Grid_Height; y++)
	{
		for (size_t x = 0; x < Grid_Width; x++)
		{
			Node* curr = &nodes.at(i);

			if (x == 0)
			{
				curr->addNeighbour(curr + 1);
			}
			else if (x == GRID_WIDTH - 1)
			{
				curr->addNeighbour(curr - 1);
			}
			else
			{
				curr->addNeighbour(curr - 1);
				curr->addNeighbour(curr + 1);
			}

			if (y == 0)
			{
				curr->addNeighbour(curr + 1);
			}
			else if (y == GRID_HEIGHT - 1)
			{
				curr->addNeighbour(curr - 1);
			}
			else
			{
				curr->addNeighbour(curr - 1);
				curr->addNeighbour(curr + 1);
			}

			i++;
		}
	}

	Algor.BreadthFirstSearch(&nodes.at(10), &nodes.at(15));

	//Draws the grid to the scren
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
