#ifndef WEBSERVICE_HPP
#define WEBSERVICE_HPP

#include "base.hpp"
#include "Configuration.hpp"

class WebService
{
	private:
		Configuration config;

		static WebService *instance;

	public:
		WebService();
		WebService(const WebService &other);
		WebService &operator=(const WebService &other);
		~WebService();

		static WebService *getInstance();

		void    initConfig(int argc, char **argv);

		void	initServer();


		

};


#endif

