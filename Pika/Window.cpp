#include "Window.h"

Window::Window()
{
	wWidth = WSIZE;
	wHeight = HSIZE;
}

void Window::windowcreate()
{
	SDL_Init(SDL_INIT_VIDEO);

	window = SDL_CreateWindow("Pika Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, wWidth, wHeight, SDL_WINDOW_SHOWN);

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}

void Window::closewindow()
{
	SDL_DestroyRenderer(renderer);
	renderer = NULL;
	SDL_DestroyWindow(window);
	window = NULL;

	IMG_Quit();
	SDL_Quit();
}

void Window::updatewindow()
{
	SDL_RenderPresent(renderer);
}

void Window::renderclear()
{
	SDL_RenderClear(renderer);
}

void Window::loadfile(std::string path)
{
	SDL_Surface* loadPNG = IMG_Load(path.c_str());

	bTexture = SDL_CreateTextureFromSurface(renderer, loadPNG);

	SDL_FreeSurface(loadPNG);

}


void Window::renderbackground(SDL_Rect* clip)
{
	SDL_RenderCopy(renderer, bTexture, clip, NULL);
}

void Window::renderfile(int x,int y,SDL_Texture* alpha, double angle, SDL_RendererFlip flip, SDL_Rect* clip)
{
	SDL_Rect renderQuad;
	
	renderQuad.x = x;
	renderQuad.y = y;
	
	if (clip != NULL)
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}
	
	SDL_RenderCopyEx(renderer, alpha, clip, &renderQuad, angle, NULL, flip);
}

Window::~Window()
{
	if (bTexture != 0)
	{
		SDL_DestroyTexture(bTexture);
		bTexture = NULL;
	}
}
