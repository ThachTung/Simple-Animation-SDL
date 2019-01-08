#include "Venom.h"



Venom::Venom()
{
	vPosx = 0;
	vPosy = 417;

	vVecx = 0;
	vVecy = 0;

}

void Venom::loadvenom()
{
	SDL_Surface* loadVENOM = IMG_Load("venom.png");

	vTexture = SDL_CreateTextureFromSurface(renderer, loadVENOM);

	int nStand = 0;
	for (int i = 0; i < 13; i++)
	{
		spriteVenom[0][i].x = 600;
		spriteVenom[0][i].y = nStand;
		spriteVenom[0][i].w = 500;
		spriteVenom[0][i].h = 383;

		nStand += 383;
	}

	int nWalk = 0;
	for (int j = 0; j < 10; j++)
	{
		spriteVenom[1][j].x = 1100;
		spriteVenom[1][j].y = nWalk;
		spriteVenom[1][j].w = 500;
		spriteVenom[1][j].h = 370;

		nWalk += 370;
	}

	int nAskill = 0;
	for (int k = 0; k < 7; k++)
	{
		spriteVenom[2][k].x = 0;
		spriteVenom[2][k].y = nAskill;
		spriteVenom[2][k].w = 600;
		spriteVenom[2][k].h = 400;

		nAskill += 400;
	}

	int nWallwalk = 0;
	for (int l = 0; l < 10; l++)
	{
		spriteVenom[3][l].x = 1600;
		spriteVenom[3][l].y = nWallwalk;
		spriteVenom[3][l].w = 500;
		spriteVenom[3][l].h = 670;

		nWallwalk += 670;
	}

	SDL_FreeSurface(loadVENOM);
}

void Venom::framevenom(int rowSprite, int colSprite, double angle)
{
	
	static int framevenom = 0;

	currentVenom = &spriteVenom[rowSprite][(framevenom / 5) % colSprite];

	renderfile(vPosx, vPosy, vTexture, angle, flipwalk, currentVenom);
	
	++framevenom;
	if ((framevenom / 5) >= colSprite)
	{
		framevenom = 0;
	}

}


void Venom::handleInside(SDL_Event& e)
{
	if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
	{
		switch (e.key.keysym.sym)
		{
		case SDLK_RIGHT:
			spriteNumber = 1;
			vVecx += VEC;
			flipwalk = SDL_FLIP_NONE;
			break;
		case SDLK_LEFT:
			spriteNumber = 1;
			vVecx -= VEC;
			flipwalk = SDL_FLIP_HORIZONTAL;
			break;
		case SDLK_UP:
			vVecy -= VEC;
			break;
		case SDLK_DOWN:
			vVecy += VEC;
			break;
		case SDLK_a:
			spriteNumber = 2;
			break;

		}
	}

	if (e.type == SDL_KEYUP && e.key.repeat == 0)
	{
		switch (e.key.keysym.sym)
		{
		case SDLK_RIGHT:
			spriteNumber = 0;
			vVecx -= VEC;
			break;
		case SDLK_LEFT:
			spriteNumber = 0;
			vVecx += VEC;
			break;
		case SDLK_UP:
			vVecy += VEC;
			break;
		case SDLK_DOWN:
			vVecy -= VEC;
			break;
		case SDLK_a:
			spriteNumber = 0;
			break;
		}
	}
}

void Venom::handleOutside(SDL_Event& e)
{
	if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
	{
		switch (e.key.keysym.sym)
		{
		case SDLK_UP:
			vVecy -= VEC;
			break;
		case SDLK_DOWN:
			vVecy += VEC;
			break;
		case SDLK_RIGHT:
			vVecx += VEC;
			break;
		case SDLK_LEFT:
			vVecx -= VEC;
			break;
		}
	}

	if (e.type == SDL_KEYUP && e.key.repeat == 0)
	{
		switch (e.key.keysym.sym)
		{
		case SDLK_UP:
			vVecy += VEC;
			break;
		case SDLK_DOWN:
			vVecy -= VEC;
			break;
		case SDLK_RIGHT:
			vVecx -= VEC;
			break;
		case SDLK_LEFT:
			vVecx += VEC;
			break;
		}
	}
}

void Venom::handleMain(SDL_Event& e)
{
	if (vPosx < 0 || vPosx >= 1101 || vPosy < 0)
	{
		handleOutside(e);
	}
	else
	{
		handleInside(e);
	}
	
}
void Venom::movepos()
{
	vPosx += vVecx;
	vPosy += vVecy;

	if (flipwalk == SDL_FLIP_HORIZONTAL)
	{
		if (vPosx < 0)
		{
			vPosx = -1;
			spriteNumber = 3;
		}

		if (vPosy < 0 && vPosx >= -1 && vPosx <1101)
		{
			vPosy = -100;
			spriteNumber = 3;
			angle = 90;
		}

		if (vPosx >=1101)
		{
			vPosx = 1102;
			spriteNumber = 3;
			angle = 180;
		}

	}
	else
	{
		if (vPosx >= 1101)
		{
			vPosx = 1102;
			spriteNumber = 3;
		}
		if (vPosy < 0 && vPosx <=1102 && vPosx >= 0)
		{
			vPosy = -100;
			spriteNumber = 3;
			angle = -90;
		}

		if (vPosx < 0)
		{	
			vPosx = -1;
			spriteNumber = 3;
			angle = -180;
		}
	}
	
}

void Venom::rendervenom()
{
	switch (spriteNumber)
	{
	case 1:
		framevenom(1, 10,angle);
		break;
	case 2:
		framevenom(2, 7,angle);
		break;
	case 3:
		framevenom(3, 10,angle);
		break;
	default:
		framevenom(0, 13,angle);
		break;
	}
}

void Venom::freetexture()
{
	if (vTexture != 0)
	{
		SDL_DestroyTexture(vTexture);
		vTexture = NULL;
	}
}

Venom::~Venom()
{
	freetexture();
}
