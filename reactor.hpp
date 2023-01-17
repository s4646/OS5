#pragma once
#include <stdio.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>

#include "pipeline.hpp"
#include "tasks.hpp"

#define PORT "7777"

class Reactor
{
    private:

        Pipeline *pipeline;

        fd_set master;    // master file descriptor list
        fd_set read_fds;  // temp file descriptor list for select()
        int fdmax;        // maximum file descriptor number

        int listener;     // listening socket descriptor
        int newfd;        // newly accept()ed socket descriptor
        struct sockaddr_storage remoteaddr; // client address
        socklen_t addrlen;

        char buf[256];    // buffer for client data
        int nbytes;

        int yes = 1;        // for setsockopt() SO_REUSEADDR, below
        int i, j, rv;
        int save_in = dup(STDOUT_FILENO); // copy of STDOUT

        struct addrinfo hints, *ai, *p;

    public:
        Reactor();
        ~Reactor();
        void initReactor(int maxClients);
        void startReactor();

};