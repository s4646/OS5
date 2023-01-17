#include "reactor.hpp"
#include "signal.h"


Reactor *r;

void sigint(int sig)
{
    delete r;
    std::cout << std::endl;
}

int main(int argc, char *argv[])
{
    if (argc !=2)
    {
        std::cout << "Usage: ./main <number>\n";
        return 0;
    }
    if (atoi(argv[1]) < 1 || atoi(argv[1]) > 10)
    {
        std::cout << "Number of clients must be between 1-10!\n";
        return 0;
    }

    signal(SIGINT, sigint);
    r = new Reactor();
    r->initReactor(atoi(argv[1]));
    r->startReactor();

    return 0;
}