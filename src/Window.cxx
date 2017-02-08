#include <Window.hxx>
#include <CreationFailedException.hxx>
#include <NotInitializedException.hxx>

#include <sstream>
#include <string>
#include <utility>

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

void Window::createWindow(WindowCreInfo&& creInfo)
{
  _window = SDL_CreateWindow( creInfo.getTitle().c_str()
                              , creInfo.getXPosition()
                              , creInfo.getYPosition()
                              , creInfo.getWidth()
                              , creInfo.getHeight()
                              , creInfo.getFlags()
                            );
  if(_window == NULL)
  {
    std::string message("Unable to create window: ");
    message.append(SDL_GetError());
    throw CreationFailedException(message.c_str());
  }
}

bool Window::isVideoInitialized()
{
  return (SDL_WasInit(SDL_INIT_VIDEO) != 0);
}

void Window::setGLVersionMajor(int ver)
{
  SET_ATTRIBUTE(SDL_GL_CONTEXT_MAJOR_VERSION, ver);
}

void Window::setGLVersionMinor(int ver)
{
  SET_ATTRIBUTE(SDL_GL_CONTEXT_MINOR_VERSION, ver);
}

Window::Window(WindowCreInfo&& creInfo)
  : _window(nullptr)
{
  if(!isVideoInitialized())
    throw NotInitializedException("The SDL Video Module is not initialized.");

  createWindow(std::move(creInfo));
}

Window::~Window() noexcept
{
  if(_window != nullptr && _window != NULL)
  {
    SDL_DestroyWindow(_window);
  }
}
