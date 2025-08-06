#include <iostream>
#include "mediator.h"
#include "consumer.h"
#include "producer.h"
#include <cstdint>

class Facade
{
    private:
    uint32_t produce;
    uint32_t consume;
    Mediator mediator;
    ProducerFactory prfactory;
    ConsumerFactory cmfactory;
    public:
    Facade(uint32_t count_produce, uint32_t count_consume);
};