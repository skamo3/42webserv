#ifndef SERVERCONFIG_HPP
#define SERVERCONFIG_HPP

#include "base.hpp"
#include "Location.hpp"

class ServerConfig
{
	private:
		std::map<std::string, std::string>	option;
		std::vector<Location>				Location;

	public:
		ServerConfig();
		ServerConfig(const ServerConfig &other);
		ServerConfig &operator=(const ServerConfig &other);
		~ServerConfig();
	
};

#endif

