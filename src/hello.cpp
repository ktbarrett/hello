#include "hello/hello.hpp"
#include <string>


namespace hello {


std::string hello(char const * name)
{
    return std::string("Hello, ") + name + "!";
}

int return_answer_to_life()
{
    return 42;
}


}
