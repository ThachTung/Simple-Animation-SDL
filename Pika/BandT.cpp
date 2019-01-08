#include "BandT.h"



BandT::BandT()
{
}

void BandT::loadBG()
{
	int bNumber = 0;

	loadfile("background.jpg");

	for (int i = 0; i < 8; i++)
	{
		spriteBackground[i].x = 0;
		spriteBackground[i].y = bNumber;
		spriteBackground[i].w = 800;
		spriteBackground[i].h = 336;

		bNumber += 336;
	}

}

void BandT::renderBG()
{
	static int fBackground = 0;
	
	currentBackground = &spriteBackground[(fBackground / 3) % 8];

	renderbackground(currentBackground);

	++fBackground;
	if ((fBackground / 3) >= 8)
	{
		fBackground = 0;
	}
}

void BandT::loadJuggernault()
{
	if (jTexture != 0)
	{
		SDL_DestroyTexture(jTexture);
		jTexture = NULL;
	}
	SDL_Surface* loadJUGGER = IMG_Load("juggernault.png");

	jTexture = SDL_CreateTextureFromSurface(renderer, loadJUGGER);

	SDL_FreeSurface(loadJUGGER);
	int jNumber = 0;
	for (int i = 0; i < 9; i++)
	{
		spriteJuggernault[i].x = 0;
		spriteJuggernault[i].y = jNumber;
		spriteJuggernault[i].w = 600;
		spriteJuggernault[i].h = 700;

		jNumber += 700;
	}
}

void BandT::renderJuggernault()
{
	renderBG();

	static int frameJ = 0;

	currentJuggernault = &spriteJuggernault[(frameJ / 6) % 9];

	renderfile(1000, 100,jTexture, NULL, SDL_FLIP_HORIZONTAL, currentJuggernault);

	++frameJ;
	if ((frameJ / 6) >= 9)
	{
		frameJ = 0;
	}
}

BandT::~BandT()
{
	if (jTexture != 0)
	{
		SDL_DestroyTexture(jTexture);
		jTexture = NULL;
	}
}
