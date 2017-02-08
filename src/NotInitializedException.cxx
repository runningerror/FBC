#include <NotInitializedException.hxx>
#include <iostream>

NotInitializedException::NotInitializedException(const char* message) noexcept
  : Exception(message)
{
}

NotInitializedException::~NotInitializedException() noexcept
{
}

const char* NotInitializedException::what() const noexcept
{
  std::string message("Unable to initialize object/system:\n");
  message.append(Exception::what_str());
  return message.c_str();
}

std::string NotInitializedException::what_str() const noexcept
{
  std::string message("Unable to initialize object/system:\n");
  message.append(Exception::what_str());
  return message;
}
