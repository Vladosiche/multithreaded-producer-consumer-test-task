#include "producer.h"

std::queue<std::unique_ptr<Producer>> ProducerFactory::createFactory()
{
        for(size_t i = 0 ; i<inst_number ; ++i)
        {
            instance.push(std::make_unique<Producer>(100));
        }
        return std::move(instance);
}

void Producer::produce()
{
        for(size_t i = 0 ; i<iteration;++i)
        {
            integers.push(dist(gen));
        }
}
Producer::Producer(uint32_t number_repetitions) : iteration(number_repetitions)
{
    gen.seed(rd());
    dist = std::uniform_int_distribution<int>(1, 100);
};