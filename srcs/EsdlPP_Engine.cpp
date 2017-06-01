#include <EsdlPP_Engine.h>

EsdlPP_Engine::EsdlPP_Engine(std::string engineName, int rx, int ry):
	EngineName(engineName),
	Rx(rx),
	Ry(ry)
{

}

EsdlPP_Engine::EsdlPP_Engine():
	EngineName("Engine"),
	Rx(640),
	Ry(480)
{

}

EsdlPP_Engine::~EsdlPP_Engine()
{
	Quit();
	std::cout << "Exiting " << EngineName << std::endl;
}

bool
EsdlPP_Engine::Init()
{
	if (!Init_SDL())
		return (false);

	std::cout << EngineName << " Initialized" << std::endl;
	return (true);
}

void
EsdlPP_Engine::Quit()
{
	Quit_SDL();
}

bool
EsdlPP_Engine::Init_SDL()
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		std::cerr << SDL_GetError() << std::endl;
		return (false);
	}

	Win = SDL_CreateWindow(
			EngineName.c_str(),
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			Rx,
			Ry,
			SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE
			);
	if (!Win)
	{
		std::cerr << SDL_GetError() << std::endl;
		Quit_SDL();
		return (false);
	}

	Ren = SDL_CreateRenderer(
		Win,
		-1,
		SDL_RENDERER_ACCELERATED
		);
	if (!Ren)
	{
		std::cerr << SDL_GetError() << std::endl;
		Quit_SDL();
		return (false);
	}

	return (true);
}

void
EsdlPP_Engine::Quit_SDL()
{
	if (Ren)
	{
		SDL_DestroyRenderer(Ren);
	}

	if (Win)
	{
		SDL_DestroyWindow(Win);
	}

	SDL_Quit();
}