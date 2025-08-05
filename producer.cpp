#include "producer.h"
#include <iostream>

void ProducerFactory::createInstance()
{
        for(size_t i = 0 ; i<inst_number ; ++i)
        {
            instance.push(std::make_unique<Producer>(7,mediator));
        }
}

void ProducerFactory::launchInstance()
{
    while (!(instance.empty()))
    {
        instance.front()->produce();
        instance.pop();
    }
    
}

void Producer::produce()
{
        for(size_t i = 0 ; i<iteration;++i)
        {
            mediator->set(dist(gen));
        }
        mediator->set_end();
}
Producer::Producer(uint32_t number_repetitions, Mediator *ref_mediator) : iteration(number_repetitions), mediator(ref_mediator)
{
    gen.seed(rd());
    dist = std::uniform_int_distribution<int>(1, 100);
};