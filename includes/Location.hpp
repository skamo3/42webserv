#ifndef LOCATION_HPP
#define LOCATION_HPP

#include "base.hpp"

class Location
{
	private:
		std::map<std::string, std::string>	option;
		std::string							path;

		void	saveOption(std::string line);

	public:
		Location();
		Location(const Location &other);
		Location &operator=(const Location &other);
		~Location();

		static bool    checkSpaceLine(std::string line);

		void    saveLocationConfig(std::list<std::string> &lines);

};

#endif

// void Location::configParse(std::string line)
// {
// 	line = line.substr(0, line.find('#')).substr(0, line.find(';'));
// 	char *cLine = std::strtok((char *)line.c_str(), " \t");
// 	if (cLine == NULL)
// 		return ;
// 	std::pair<std::string, std::string> res;
// 	res.first = std::string(cLine);
// 	cLine = std::strtok(NULL, " \t");
// 	line.clear();
// 	while (cLine != 0)
// 	{
// 		line.append(cLine);
// 		cLine = std::strtok(NULL, " \t");
// 		if (cLine != 0)
// 			line.append(" ");
// 	}
// 	res.second = line;
// 	if (res.second.empty() || res.first.empty())
// 		return ;
// 	option[res.first] = res.second;
// }

// /*
// 	location 뒤로 붙은 path를 저장해주는 함수
// 	location /path { 의 형태로 들어오고 여기서 "/path" 만 저장
// 	@param -> std::string line -> 파싱에 쓰일 문자열
// */
// void Location::saveLocation(std::string line)
// {
// 	line = line.substr(0, line.find('{'));
// 	char *cLine = std::strtok((char *)line.c_str(), " \t");
// 	if (cLine == NULL)
// 		return ;
// 	cLine = std::strtok(NULL, " \t");
// 	line.clear();
// 	while (cLine != 0)
// 	{
// 		line.append(cLine);
// 		cLine = std::strtok(NULL, " \t");
// 		if (cLine != 0)
// 			line.append(" ");
// 	}
// 	path = std::string(line);
// }




// Location::Location(std::list<std::string> &line)
// {
// 	for (std::list<std::string>::iterator it = line.begin(); it != line.end(); it++)
// 	{
// 		if (it->find("location") != std::string::npos)
// 			saveLocation(*it);
// 		else
// 			configParse(*it);
// 	}
// 	cgi_extension = splitSpaces(option["cgi_extension"]);
// 	allow_method = splitSpaces(option["allow_method"]);
// 	index = splitSpaces(option["index"]);
// }

