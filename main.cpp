#include <iostream>
#include <vector>
#include <string>
#include "producer.h"
#include "consumer.h"
#include "facade.h"
#include <random>

const uint32_t NUMBER_OF_PRODUCERS = 1;
const uint32_t NUMBER_OF_CONSUMERS = 2;
const uint32_t NUMBER_OF_INTEGERS = 10;
int main()
{
Facade facade(NUMBER_OF_PRODUCERS,NUMBER_OF_CONSUMERS,NUMBER_OF_INTEGERS);
}
