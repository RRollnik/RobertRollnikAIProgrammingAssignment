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
#include <time.h> 

#include "Surface.h"
#include "Node.h"
#include "BreadthFirstAlgorithm.h"

#include "State.h"
#include "IdleState.h"

#include "StateManager.h"
#include "AttackState.h"

#define GRID_HEIGHT 25
#define GRID_WIDTH 25



int main(int argc, char *argv[])
{
	BreadthFirst searchpath;

	std::shared_ptr<Surface> notvisitednde;
	std::shared_ptr<Surface> goalnode;
	std::shared_ptr<Surface> startnode;
	std::shared_ptr<Surface> pathnode;
	std::shared_ptr<Surface> blockednode;
	//makes a surface called image

	std::shared_ptr<Surface> screen;
	//makes a surface called screen

	SDL_Init(SDL_INIT_EVERYTHING);
	//initialise SDL

	screen = Surface::setVideoMode();

	notvisitednde = Surface::loadBmp("notvisitednode.bmp");
	pathnode = Surface::loadBmp("path.bmp");
	goalnode = Surface::loadBmp("goalnode.bmp");
	startnode = Surface::loadBmp("startnode.bmp");
	blockednode = Surface::loadBmp("blockade.bmp");

	int imageHeight = 50;
	int imageWidth = 50;

	int Grid_Width = 1280 / imageWidth;
	int Grid_Height = 720 / imageHeight;
	//numbers control the number of nodes we'll make so that they don't go beyond the screens borders

	//Generate the grid
	std::vector<Node> nodes;
	//generate a vector of our Node class

	int randGoal;
	int randStart;
	Node* goal;
	Node* start;
	std::vector<Node*> path;
	std::vector<Node*> blockades;
	
	StateManager enemie1;
	enemie1.setState(new AttackState(&enemie1));

	StateManager enemie2;
	enemie2.setState(new AttackState(&enemie2));

	for (size_t y = 0; y < Grid_Height; y++)
	{
		for (size_t x = 0; x < Grid_Width; x++)
		{
			Node node(notvisitednde, (y + 1), (x + 1));
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
				curr->addNeighbour(curr + GRID_WIDTH);
			}
			else if (y == GRID_HEIGHT - 1)
			{
				curr->addNeighbour(curr - GRID_WIDTH);
			}
			else
			{
				curr->addNeighbour(curr - GRID_WIDTH);
				curr->addNeighbour(curr + GRID_WIDTH);
			}

			// Middle
			if (x != 0 && y != 0 && x != GRID_WIDTH - 1 && y != GRID_HEIGHT - 1)
			{
				curr->addNeighbour(curr - GRID_WIDTH - 1);
				curr->addNeighbour((curr - GRID_WIDTH) + 1);
				curr->addNeighbour(curr + GRID_WIDTH - 1);
				curr->addNeighbour((curr + GRID_WIDTH) + 1);
			}// Top Left
			else if (x == 0 && y == 0)
			{
				curr->addNeighbour((curr + GRID_WIDTH) + 1);
			}// Top Right
			else if (x == GRID_WIDTH - 1 && y == 0)
			{
				curr->addNeighbour((curr + GRID_WIDTH) - 1);
			}// Bottom Left
			else if (x == 0 && y == GRID_HEIGHT - 1)
			{
				curr->addNeighbour((curr - GRID_WIDTH) + 1);
			}// Bottom Right
			else if (x == GRID_WIDTH - 1 && y == GRID_HEIGHT - 1)
			{
				curr->addNeighbour((curr - GRID_WIDTH) - 1);
			}// Left
			else if (x == 0)
			{
				curr->addNeighbour((curr + GRID_WIDTH) + 1);
				curr->addNeighbour((curr - GRID_WIDTH) + 1);
			}// Right
			else if (x == GRID_WIDTH - 1)
			{
				curr->addNeighbour((curr + GRID_WIDTH) - 1);
				curr->addNeighbour((curr - GRID_WIDTH) - 1);
			}// Top
			else if (y == 0)
			{
				curr->addNeighbour((curr + GRID_WIDTH) - 1);
				curr->addNeighbour((curr + GRID_WIDTH) + 1);
			}// Bottom
			else if (y == GRID_HEIGHT - 1)
			{
				curr->addNeighbour((curr - GRID_WIDTH) - 1);
				curr->addNeighbour((curr - GRID_WIDTH) + 1);
			}
			i++;
		}
	}


	
	
	srand(time(NULL));
	randStart = rand() % 349 + 0;

	
	start = &nodes.at(randStart);
	goal = &nodes.at(SDL_BUTTON_LEFT);

	searchpath.BreadthFirstSearch(start, goal);

	Node* curr = goal;

	while (curr->GetParent())
	{
		std::cout << curr->GetX() << " " << curr->GetY() << std::endl;
		path.push_back(curr);
		curr = curr->GetParent();
	}


	for (size_t i = 0; i < path.size(); i++)
	{
		path.at(i)->SetImage(pathnode);
	}

	start->SetImage(pathnode);

	//Draws the grid to the scren
	for (size_t i = 0; i < nodes.size(); i++)
	{
		nodes.at(i).Draw(screen);
	}
	
	screen->flip();


	for(int i = 0; i < 1100; i++)
	{
		enemie1.update();
		enemie2.update();
	}


#ifdef _MSC_VER
	Sleep(3000);
#else
	sleep(3);
#endif

	return 0;
}
