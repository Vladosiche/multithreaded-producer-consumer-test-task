#include <iostream>
#include "mediator.h"
#include "consumer.h"
#include "producer.h"
#include <cstdint>

class Factory
{
    private:
    uint32_t produce;
    uint32_t consume;
    Mediator mediator;
    ProducerFactory prfactory;
    ConsumerFactory cmfactory;
    public:
    Factory(uint32_t count_produce, uint32_t count_consume);
};