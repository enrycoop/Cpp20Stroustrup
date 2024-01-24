//
// Created by enrico on 1/9/24.
//
#include <iostream>
#include "container_custom.h"

int main ()
{
	stdlibfac::Vector x{1,2,3}, y{4,5,6}, z{7,8,9};
	stdlibfac::Vector r = x + y + z;
    r.print();
}