#ifndef		ESDLPP_ENGINE_H
# define	ESDLPP_ENGINE_H

#include <iostream>
#include <string>

#include <SDL.h>

#include <EsdlPP_Draw.h>
#include <EsdlPP_Surface.h>
#include <EsdlPP_Color.h>

class EsdlPP_Engine
{

public:

	EsdlPP_Engine();
	EsdlPP_Engine(std::string engineName, int rx, int ry);
	~EsdlPP_Engine();

	bool Init();
	void Quit();

	bool Init_SDL();
	void Quit_SDL();

public:

	std::string		EngineName;
	int				Rx;
	int				Ry;

	SDL_Window		*Win;
	SDL_Renderer	*Ren;

	void			*GameData;
};

#endif