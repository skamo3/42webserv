#include "Configuration.hpp"

Configuration::Configuration()
{}

Configuration::Configuration(const Configuration &other)
: option(other.option), serverConfig(other.serverConfig)
{}

Configuration &Configuration::operator=(const Configuration &other)
{
	if (this != &other)
	{
		this->option = other.option;
		this->serverConfig = other.serverConfig;
	}
	return *this;
}

Configuration::~Configuration()
{}

void	Configuration::saveConfig(int fd)
{
	
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