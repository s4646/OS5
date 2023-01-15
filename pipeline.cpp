#include "pipeline.hpp"

Pipeline::Pipeline() {}
Pipeline::~Pipeline() {}

void Pipeline::addToPipeline(void* (*f)(void*))
{
    line.push_back(new ActiveObject(f));
    tasks.push_back(f);
    
    if (line.size() > 1)
    {
        line.at(line.size()-2)->setNext(line.at(line.size()-1));
    }
}

void Pipeline::removeFromPipeline()
{
    line.pop_back();
    tasks.pop_back();
}

void Pipeline::startLine()
{
    for (auto element : line)
    {
        element->activate();
    }
}

void Pipeline::stopLine()
{
    for (auto element : line)
    {
        element->deactivate();
    }
}

void Pipeline::killLine()
{
    stopLine();
    ActiveObject *ao;
    while (line.size() > 0 && tasks.size() > 0)
    {
        ao = *(line.end()-1);
        line.pop_back();
        tasks.pop_back();
        delete ao;
    }
}

void Pipeline::getInput(void *vp)
{
    Item *i = new Item(vp);
    line.at(0)->doTask(i);
}