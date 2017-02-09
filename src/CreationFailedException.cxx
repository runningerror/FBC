#include <CreationFailedException.hxx>

CreationFailedException::CreationFailedException(const char* message) noexcept
  : Exception(message)
{
}

CreationFailedException::~CreationFailedException() noexcept
{
}

const char* CreationFailedException::what() const noexcept
{
  std::string message("An error occured while creating an object:\n");
  message.append(Exception::what());

  return message.c_str();
}

std::string CreationFailedException::what_str() const noexcept
{
  std::string message("An error occured while creating an object:\n");
  message.append(Exception::what_str());

  return message;
}
