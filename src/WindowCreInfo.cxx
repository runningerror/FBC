#include <WindowCreInfo.hxx>
#include <utility>


WindowCreInfo::WindowCreInfo(   std::string title
                              , int xpos
                              , int ypos
                              , int width
                              , int height
                              , Uint32 flags
                            ) noexcept
  : _title(title)
  , _xpos(xpos)
  , _ypos(ypos)
  , _width(width)
  , _height(height)
  , _flags(flags)
{

}

WindowCreInfo::WindowCreInfo(WindowCreInfo&& src) noexcept
  : _title(std::move(src._title))
  , _xpos(std::move(src._xpos))
  , _ypos(std::move(src._ypos))
  , _width(std::move(src._width))
  , _height(std::move(src._height))
  , _flags(std::move(src._flags))
{

}

WindowCreInfo& WindowCreInfo::operator=(WindowCreInfo&& src) noexcept
{
  _title = std::move(src._title);
  _xpos = std::move(src._xpos);
  _ypos = std::move(src._ypos);
  _width = std::move(src._width);
  _height = std::move(src._height);
  _flags = std::move(src._flags);

  return *this;
}

std::string WindowCreInfo::getTitle() const noexcept
{
  return _title;
}

int WindowCreInfo::getXPosition() const noexcept
{
  return _xpos;
}

int WindowCreInfo::getYPosition() const noexcept
{
  return _ypos;
}

int WindowCreInfo::getWidth() const noexcept
{
  return _width;
}

int WindowCreInfo::getHeight() const noexcept
{
  return _height;
}

Uint32 WindowCreInfo::getFlags() const noexcept
{
  return _flags;
}
