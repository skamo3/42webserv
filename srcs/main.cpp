#include "base.hpp"
#include "WebService.hpp"

int main(int argc, char **argv)
{
	// webservice에서 쓰일 config 저장
	try
	{
		WebService::getInstance()->initConfig(argc, argv);

		WebService::getInstance()->initServer();

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	



	return 0;
}
