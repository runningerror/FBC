#ifndef WINDOW_CRE_INFO_HXX_
#define WINDOW_CRE_INFO_HXX_

#include <SDL.h>
#include <string>

class WindowCreInfo final
{
private:
  std::string _title;
  int _xpos;
  int _ypos;
  int _width;
  int _height;
  Uint32 _flags;

protected:
public:
  /*
   *  Constructors
   */
  explicit WindowCreInfo(   std::string title
                          , int xpos
                          , int ypos
                          , int width
                          , int height
                          , Uint32 flags
                        ) noexcept;

  /*
   *  Move Constructor
   */
  WindowCreInfo(WindowCreInfo&& src) noexcept;

  /*
   *  Automatically generate destructor
   */
  ~WindowCreInfo() = default;
  /*
   *  Avoid generation of implicit copy constructor and copy assignment operator
   */
  WindowCreInfo(const WindowCreInfo&) = delete;
  WindowCreInfo& operator=(const WindowCreInfo&) = delete;

  /*
   *  Move assignment operator
   */
   WindowCreInfo& operator=(WindowCreInfo&& src) noexcept;

   /*
    * Returns a std::string that represents the title of the window.
    *
    * @return: std::string - the window title
    */
   std::string getTitle() const noexcept;

   /*
    * Returns the horizontal position of the window.
    *
    * @return: int - the horizontal position
    */
   int getXPosition() const noexcept;

   /*
    * Returns the vertical position of the window.
    *
    * @return: int - the vertical position
    */
   int getYPosition() const noexcept;

   /*
    * Returns the width of the window.
    *
    * @return: int - the window width
    */
   int getWidth() const noexcept;

   /*
    * Returns the height of the window.
    *
    * @return: int - the window height
    */
   int getHeight() const noexcept;

   /*
    * Returns the SDL_WindowFlags that should be set.
    *
    * @return: Uint32 - all SDL_WindowFlags or'ed together
    */
   Uint32 getFlags() const noexcept;
};

#endif
