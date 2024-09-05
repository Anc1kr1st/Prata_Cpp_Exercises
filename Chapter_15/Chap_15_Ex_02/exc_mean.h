// exc_mean.h -- trídy výjimek pro hmean(), gmean()
#ifndef EXC_MEAN_H_
#define EXC_MEAN_H_

#include <iostream>
#include <stdexcept>

class hmeanexcp : public std::logic_error
{

public:
    hmeanexcp()
        : std::logic_error("hmean() chybne argumenty: a = -b\n")
    {

    }


};

class gmeanexcp : public std::logic_error
{
public:
    gmeanexcp()
        : std::logic_error("argumenty gmean() musi byt >= 0\n")
    {

    }
};

#endif