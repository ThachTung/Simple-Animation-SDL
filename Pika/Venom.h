#pragma once
#include"BandT.h"

#define VEC 10
#define COL 20
#define ROW 4

class Venom :public BandT
{
public:
	Venom();
	~Venom();

	void loadvenom();
	void framevenom(int rowSprite, int colSprite, double angle = 0.0);

	void handleInside(SDL_Event& e);
	void handleOutside(SDL_Event& e);

	void handleMain(SDL_Event& e);
	void movepos();

	void rendervenom();

	void freetexture();

private:
	SDL_Texture* vTexture = NULL;

	SDL_Rect* currentVenom = NULL;
	SDL_Rect spriteVenom[ROW][COL];

	int vPosx, vPosy;
	int vVecx, vVecy;

	int spriteNumber = 0;

	SDL_RendererFlip flipwalk = SDL_FLIP_NONE;

	double angle = 0.0;

};