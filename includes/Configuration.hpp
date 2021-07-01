#ifndef CONFIGURATION_HPP
#define CONFIGURATION_HPP

#include "base.hpp"
#include "ServerConfig.hpp"

class Configuration
{
	private:
		std::map<std::string, std::string>	option;
		std::vector<ServerConfig>			serverConfig;

	
	public:
		Configuration();
		Configuration(const Configuration &other);
		Configuration &operator=(const Configuration &other);
		~Configuration();

		void saveConfig(int fd);

		bool    checkSpaceLine(std::string line);

		void    saveOption(std::string line);





};

#endif