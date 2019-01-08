#include"Venom.h"

int main(int argc, char* argv[])
{
	Venom* load = new Venom;

	load->windowcreate();

	SDL_Event e;

	bool quit = false;

	load->loadBG();
	load->loadvenom();

	while (!quit)
	{
		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_QUIT)
				quit = true;
			load->handleMain(e);
		}
		load->movepos();

		load->renderBG();
		load->rendervenom();

		load->updatewindow();
		load->renderclear();
	}
	

	load->closewindow();

	return 0;
}