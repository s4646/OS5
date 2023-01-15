#pragma once

#include "activeObject.hpp"
#include <vector>

class Pipeline
{
    private:
        std::vector<ActiveObject*> line;
        std::vector<void*(*)(void*)> tasks;
    
    public:
        Pipeline();
        ~Pipeline();
        void addToPipeline(void* (*f)(void*));
        void removeFromPipeline();
        void getInput(void *vp);
        void startLine();
        void stopLine();
        void killLine();
};