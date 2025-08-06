#include "producer.h"
#include <iostream>
#include <thread>
//================================================================================
// Method: createInstance()
// Description: The function of creating instances of producers
//================================================================================
void ProducerFactory::createInstance(uint32_t numberOfIntegers)
{
        for(size_t i = 0 ; i<inst_number ; ++i)
        {
            instance.push(std::make_unique<Producer>(numberOfIntegers,mediator));
        }
}
//================================================================================
// Method: launchInstance()
// Description: The function of creating and splitting into streams and 
//              calling the produce() method for each of them
//================================================================================
void ProducerFactory::launchInstance()
{
    while (!(instance.empty()))
    {
        auto item = std::move(instance.front());
        instance.pop();
        produce_threads.emplace_back([item = std::move(item)]() mutable {
        item->produce();
        });
    }
    
}
//================================================================================
// Method: join_treads()
// Description: Tread waiting function
//================================================================================
void ProducerFactory::join_treads()
{
    for (auto& t : produce_threads) {
    t.join();
}
}
//================================================================================
// Method: produce()
// Description: generation and sending of values to the mediator
//================================================================================
void Producer::produce()
{
        for(size_t i = 0 ; i<iteration;++i)
        {
            mediator->set(dist(gen));
        }
        mediator->set_end();
}
//================================================================================
// Constructor: Producer
// Description: determining the randomization method and 
//              range of generated numbers
//================================================================================
Producer::Producer(uint32_t number_repetitions, Mediator *ref_mediator) : iteration(number_repetitions), mediator(ref_mediator)
{
    gen.seed(rd());
    dist = std::uniform_int_distribution<int>(1, 100); // generates values from 1 to 100
};