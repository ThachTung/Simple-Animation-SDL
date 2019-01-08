#pragma once
#include"Window.h"

class BandT: public Window
{
public:
	BandT();
	~BandT();

	void loadBG();
	void renderBG();
	
	void loadJuggernault();
	void renderJuggernault();
private:

	SDL_Rect* currentBackground = NULL;
	SDL_Rect spriteBackground[8];

	SDL_Texture* jTexture = NULL;

	SDL_Rect* currentJuggernault = NULL;
	SDL_Rect spriteJuggernault[9];
};

