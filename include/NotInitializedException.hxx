#ifndef NOT_INITIALIZED_EXCEPTION_HXX_
#define NOT_INITIALIZED_EXCEPTION_HXX_

#include <Exception.hxx>

class NotInitializedException : public Exception
{
private:
protected:
public:
  NotInitializedException(const char* message) noexcept;
  virtual ~NotInitializedException() noexcept;
  virtual const char* what() const noexcept override;
  virtual std::string what_str() const noexcept override;
};

#endif
