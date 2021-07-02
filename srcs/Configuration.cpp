#include "Configuration.hpp"
#include "Exception.hpp"

Configuration::Configuration()
{}

Configuration::Configuration(const Configuration &other)
: option(other.option), server(other.server)
{}

Configuration &Configuration::operator=(const Configuration &other)
{
	if (this != &other)
	{
		this->option = other.option;
		this->server = other.server;
	}
	return *this;
}

Configuration::~Configuration()
{}

void    Configuration::saveOption(std::string line)
{
	line = line.substr(0, line.find('#')).substr(0, line.find(';'));
	if (line.empty())
		return;
	if (Location::checkSpaceLine(line))
		return ;
	char *cLine = strtok((char *)line.c_str(), " \t");
	std::string key = std::string(cLine);
	cLine = strtok(NULL, " \t");
	line.clear();
	while (cLine != 0)
	{
		line.append(cLine);
		cLine = strtok(NULL, " \t");
		if (cLine != 0)
			line.append(" ");
	}
	if (line.empty() || key.empty())
		return ;
	option[key] = line;
}

void	Configuration::saveConfig(std::ifstream &fin)
{
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
				Server newServer;
				newServer.saveServerConfig(save);
				this->server.push_back(newServer);
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

std::vector<Server> Configuration::getServerVec()
{
	return this->server;
}

std::string Configuration::getOption(std::string const &key)
{
	if (this->option.count(key) == 0)
		return "";
	return this->option[key];
}

