#ifndef WINDOW_HXX_
#define WINDOW_HXX_

#include <SDL.h>

class Window
{
private:
protected:
public:
	static void setGLVersionMajor(int ver);
	static void setGLVersionMinor(int ver);

	explicit Window();
	virtual ~Window() noexcept;
};

#endif
