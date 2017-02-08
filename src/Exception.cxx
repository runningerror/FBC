#include <Exception.hxx>
#include <iostream>

Exception::Exception(const char* message) noexcept
  : std::exception(),
    _message(std::string(message))
{
}

Exception::~Exception() noexcept
{

}

const char* Exception::what() const noexcept
{
  return _message.c_str();
}
