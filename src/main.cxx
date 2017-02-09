#include <Window.hxx>
#include <Exception.hxx>

#include <iostream>
#include <utility>

int main(int argc, char* argv[])
{
	if(SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		std::cerr << "Unable to initialize SDL: " << SDL_GetError() << std::endl;
		return 1;
	}

	try
	{
		WindowCreInfo info("FBC", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, 0);
		Window win(std::move(info));
	}
	catch(const Exception& e)
	{
		std::cerr << e.what_str() << std::endl;
	}

	SDL_Quit();

	return 0;
}
