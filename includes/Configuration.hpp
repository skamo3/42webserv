#ifndef CONFIGURATION_HPP
#define CONFIGURATION_HPP

#include "base.hpp"
#include "Server.hpp"

class Configuration
{
	private:
		std::map<std::string, std::string>	option;
		std::vector<Server>			server;
		void    saveOption(std::string line);
	
	public:
		Configuration();
		Configuration(const Configuration &other);
		Configuration &operator=(const Configuration &other);
		~Configuration();

		void	saveConfig(std::ifstream &fin);

		std::vector<Server>		getServerVec();
		std::string 			getOption(std::string const &key);





};

#endif