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

bool	WebService::checkSpaceLine(std::string line)
{
	int i = 0;
	bool res = true;
	while (line[i])
	{
		if (isspace(line[i]))
			res = false;
		i++;
	}
	return res;
}

void    WebService::saveOption(std::string line)
{
	std::cout << "in save option " << std::endl;
	if (checkSpaceLine(line))
		return ;
	line = line.substr(0, line.find('#')).substr(0, line.find(';'));
	if (line.empty())
		return;
	std::cout << "in save : {" << line << "}" << std::endl;
	char *cLine = std::strtok((char *)line.c_str(), " \t");
	
	std::pair<std::string, std::string> res;

	std::string key = std::string(cLine);
	cLine = std::strtok(NULL, " \t");
	line.clear();
	while (cLine != 0)
	{
		line.append(cLine);
		cLine = std::strtok(NULL, " \t");
		if (cLine != 0)
			line.append(" ");
	}
	std::cout << "key : {" << key << "} | value : {" << line << "}" << std::endl;
	if (line.empty() || key.empty())
		return ;
	option[key] = line;
}

void    WebService::initConfig(int argc, char **argv)
{

	if (argc != 2)
		throw WrongInputArgumentException();

	std::ifstream fin;

	fin.open(argv[1], std::ifstream::in);

	if (!fin.is_open())
		throw FileCannotOpenException();



	std::string line;
	std::list<std::string>  save;
	int                     parenthesis = 0;

	while (std::getline(fin, line))
	{
		if (line.find('{') != std::string::npos)
		{
			save.push_back(line);
			parenthesis++;
		}
		else if (line.find('}') != std::string::npos)
		{
			save.push_back(line);
			parenthesis--;
			if (parenthesis == 0)
			{
				// 서버 하나 추가
				save.clear();
			}
		}
		else if (parenthesis > 0)
			save.push_back(line);
		else
			saveOption(line);

	}
	fin.close();
	if (parenthesis != 0)
		throw WrongFileFormatException();

}

