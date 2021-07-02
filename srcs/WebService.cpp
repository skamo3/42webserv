#include "WebService.hpp"
#include "Exception.hpp"

WebService *WebService::instance;

WebService::WebService()
{}

WebService::WebService(const WebService &other)
{}

WebService &WebService::operator=(const WebService &other)
{
	if (this != &other)
	{
		
	}
	return *this;
}

WebService::~WebService()
{}

WebService  *WebService::getInstance()
{
	if (instance == NULL)
		instance = new WebService();
	return instance;
}

void    WebService::initConfig(int argc, char **argv)
{

	if (argc != 2)
		throw WrongInputArgumentException();

	std::ifstream fin;

	fin.open(argv[1], std::ifstream::in);

	if (!fin.is_open())
		throw FileCannotOpenException();

	this->config.saveConfig(fin);

}


void	WebService::initServer()
{
	std::cout << "run server" << std::endl;

	this->config.getServerVec();


}