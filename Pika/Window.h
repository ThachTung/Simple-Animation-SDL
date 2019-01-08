#pragma once
#include"SDL.h"
#include"SDL_image.h"

#include<iostream>

#define WSIZE 1600
#define HSIZE 800
class Window
{
public:
	Window();
	~Window();

	void windowcreate();
	void closewindow();

	void updatewindow();
	void renderclear();

	void loadfile(std::string path);
	void renderbackground(SDL_Rect* clip=NULL);
	void renderfile(int x, int y,SDL_Texture* alpha =NULL, double angle =0.0, SDL_RendererFlip flip =SDL_FLIP_NONE, SDL_Rect* clip=NULL);

private:
	int wWidth, wHeight;

	SDL_Window* window = NULL;
	SDL_Texture* bTexture = NULL;
protected:
	SDL_Renderer* renderer = NULL;
};

