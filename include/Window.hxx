#ifndef WINDOW_HXX_
#define WINDOW_HXX_

#include <WindowCreInfo.hxx>

class Window
{
private:
	SDL_Window* _window;

	void createWindow(WindowCreInfo&& creInfo);
	bool isVideoInitialized();
protected:
public:
	static void setGLVersionMajor(int ver);
	static void setGLVersionMinor(int ver);

	explicit Window(WindowCreInfo&& creInfo);
	virtual ~Window() noexcept;
};

#endif
