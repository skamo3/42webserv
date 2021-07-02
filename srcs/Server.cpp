#include "Server.hpp"
#include "Exception.hpp"

Server::Server()
{}

Server::Server(const Server &other)
: option(other.option), location(other.location)
{}

Server &Server::operator=(const Server &other)
{
	if (this != &other)
	{
		this->option = other.option;
		this->location = other.location;
	}
	return *this;
}

Server::~Server()
{}

void	Server::saveOption(std::string line)
{
	line = line.substr(0, line.find('#')).substr(0, line.find(';'));
	if (line.empty())
		return ;
	if (Location::checkSpaceLine(line))
		return ;
	char *cLine = std::strtok((char *)line.c_str(), " \t");
	std::string key = std::string(cLine);
	if (key.compare(0, 7, "server\0") == 0)
		return ;
	cLine = std::strtok(NULL, " \t");
	line.clear();
	while (cLine != 0)
	{
		line.append(cLine);
		cLine = std::strtok(NULL, " \t");
		if (cLine != 0)
			line.append(" ");
	}
	if (line.empty() || key.empty())
		return ;
	option[key] = line;
}

void    Server::saveServerConfig(std::list<std::string> &lines)
{
	int	parenthesis = 0;
	std::list<std::string> save;

	for (std::list<std::string>::iterator it = lines.begin(); it != lines.end(); it++)
	{
		if (it->find('{') != std::string::npos && it->find("server") == std::string::npos)
		{
			save.push_back(*it);
			parenthesis++;
		}
		else if (it->find('}') != std::string::npos)
		{
			save.push_back(*it);
			parenthesis--;
			if (parenthesis == 0 && it != --lines.end())
			{
				Location newLocation;
				newLocation.saveLocationConfig(save);
				this->location.push_back(newLocation);
				save.clear();
			}
		}
		else if (parenthesis > 0)
			save.push_back(*it);
		else
			saveOption(*it);
	}
	// ip, server_name, port 를 넣는다
	// parenthesis = parenthesis != -1 ? parenthesis : sliceOptions();
	// parenFlag != -1 -> error
	if (parenthesis != -1)
		throw WrongFileFormatException();
}

std::vector<Location>	Server::getLocationVec()
{
	return this->location;
}

std::string Server::getOption(std::string const &key)
{
	if (this->option.count(key) == 0)
		return "";
	return this->option[key];
}
