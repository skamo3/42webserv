#ifndef SERVERCONFIG_HPP
#define SERVERCONFIG_HPP

#include "base.hpp"
#include "Location.hpp"

class Server
{
	private:
		std::map<std::string, std::string>	option;
		std::vector<Location>				location;

		void	saveOption(std::string line);


	public:
		Server();
		Server(const Server &other);
		Server &operator=(const Server &other);
		~Server();

		void	saveServerConfig(std::list<std::string> &lines);


		std::vector<Location>	getLocationVec();
		std::string			getOption(std::string const &key);

	
};

#endif
