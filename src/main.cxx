#include <Window.hxx>
#include <Exception.hxx>

#include <iostream>

int main(int argc, char* argv[])
{
	try
	{
		Window::setGLVersionMajor(-10);
	}
	catch(Exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
