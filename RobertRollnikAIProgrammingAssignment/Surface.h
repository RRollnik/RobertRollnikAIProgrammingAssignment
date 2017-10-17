#pragma once

#ifndef SURFACE_H
#define SURFACE_H

#include <memory>
#include <string>
#include <SDL/SDL.h>
#include <iostream>

#undef main

class Surface
{
public:

	Surface();

	~Surface();

	static std::shared_ptr<Surface> setVideoMode();

	static std::shared_ptr<Surface> loadBmp(std::string path);

	void blit(std::weak_ptr<Surface> dest, int x, int y);

	void flip();

private:

	std::shared_ptr<SDL_Surface> surface;

	static void screenDeleter(SDL_Surface *surface);

	static void surfaceDeleter(SDL_Surface *surface);
};

#endif // !SURFACE_H