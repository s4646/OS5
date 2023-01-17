#include "reactor.hpp"
#include "signal.h"


Reactor *r;

void sigint(int sig)
{
    delete r;
    std::cout << std::endl;
}

int main()
{
    signal(SIGINT, sigint);
    r = new Reactor();
    r->initReactor(2);
    r->startReactor();
    std::cout << "start\n";

    return 0;
}