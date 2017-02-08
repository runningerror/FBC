#include <Window.hxx>
#include <Exception.hxx>

#include <sstream>

#define SET_ATTRIBUTE(A, V) { \
  if(SDL_GL_SetAttribute(A, V) != 0) \
  { \
    std::stringstream sstream;\
    sstream << "Unable to set Attribute " << #A << " to value " << V << ".\n"; \
    sstream << "Message: " << SDL_GetError(); \
    \
    throw Exception(sstream.str().c_str()); \
  } \
}

void Window::setGLVersionMajor(int ver)
{
  SET_ATTRIBUTE(SDL_GL_CONTEXT_MAJOR_VERSION, ver);
}

void Window::setGLVersionMinor(int ver)
{
  SET_ATTRIBUTE(SDL_GL_CONTEXT_MINOR_VERSION, ver);
}

Window::Window()
{

}

Window::~Window() noexcept
{

}
