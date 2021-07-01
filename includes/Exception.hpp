#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

#include <exception>

class FileCannotOpenException : public std::exception
{
    const char *what() const throw();
};

class WrongInputArgumentException : public std::exception
{
    const char *what() const throw();
};

class WrongFileFormatException : public std::exception
{
    const char *what() const throw();
};


#endif
