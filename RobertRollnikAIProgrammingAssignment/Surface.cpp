#include "Surface.h"

Surface::Surface()
{
}

Surface::~Surface()
{
}

std::shared_ptr<Surface> Surface::setVideoMode()
{
	std::shared_ptr<Surface> rtn;

	rtn.reset(new Surface());
	rtn->surface.reset(SDL_SetVideoMode(1280, 720, 32, SDL_SWSURFACE), screenDeleter);

	return rtn;
}

std::shared_ptr<Surface> Surface::loadBmp(std::string path)
{
	std::shared_ptr<Surface> rtn;

	rtn.reset(new Surface());
	rtn->surface.reset(SDL_LoadBMP(path.c_str()), surfaceDeleter);

	return rtn;
}

void Surface::blit(std::weak_ptr<Surface> dest, int x, int y)
{
	SDL_Rect rect = { 0 };

	rect.x = x;
	rect.y = y;

	SDL_BlitSurface(surface.get(), NULL, dest.lock()->surface.get(), &rect);
}

void Surface::flip()
{
	SDL_Flip(surface.get());
}

void Surface::screenDeleter(SDL_Surface *surface)
{
	std::cout << "SDL_Quit" << std::endl;
	SDL_Quit();
}

void Surface::surfaceDeleter(SDL_Surface *surface)
{
	std::cout << "SDL_FreeSurface" << std::endl;
	SDL_FreeSurface(surface);
}