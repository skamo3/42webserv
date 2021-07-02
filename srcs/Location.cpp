#include "Location.hpp"

Location::Location()
{}

Location::Location(const Location &other)
{}

Location &Location::operator=(const Location &other)
{
    if (this != &other)
	{
		
	}
	return *this;
}

Location::~Location()
{}


bool	Location::checkSpaceLine(std::string line)
{
	int i = 0;
	bool res = true;
	while (line[i])
	{
		if (!isspace(static_cast<int>(line[i])))
		{
			res = false;
		}
		i++;
	}
	return res;
}

void	Location::saveOption(std::string line)
{

}


// TODO : location 컨피그 작성하기
// 기본으로 들어갈 것 path, option받아올 때 1개 이상이면 여러개로 나눠주는 함수
// getOption 자체를 2개로 만들어서 하나는 list형태로 받게 하면 리턴값만 보고 판단 가능할까??
void    Location::saveLocationConfig(std::list<std::string> &lines)
{
	std::list<std::string>::iterator it = lines.begin();
	this->path = 
	for ( ; it != lines.end(); it++)
	{
		if (it->find("location") != std::string::npos)
			saveOption(*it);
		else
			saveOption(*it);
	}
}


