#ifndef CREATION_FAILED_EXCEPTION_HXX_
#define CREATION_FAILED_EXCEPTION_HXX_

#include <Exception.hxx>

class CreationFailedException : public Exception
{
private:
protected:
public:
  CreationFailedException(const char* message) noexcept;
  virtual ~CreationFailedException() noexcept;

  virtual const char* what() const noexcept override;
  virtual std::string what_str() const noexcept override;
};

#endif
