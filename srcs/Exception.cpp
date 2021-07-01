#include "Exception.hpp"

const char *FileCannotOpenException::what() const throw()
{
    return "Error : File cannot open";
}

const char *WrongInputArgumentException::what() const throw()
{
    return "Error : Wrong input program argument";
}

const char *WrongFileFormatException::what() const throw()
{
    return "Error : Wrong input program argument";
}

