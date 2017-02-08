#ifndef EXCEPTION_HXX_
#define EXCEPTION_HXX_

#include <exception>
#include <string>

class Exception: public std::exception
{
private:
  std::string _message;

protected:
public:
  Exception(const char* message) noexcept;
  virtual ~Exception() noexcept;

  virtual const char* what() const noexcept override;
};

#endif
