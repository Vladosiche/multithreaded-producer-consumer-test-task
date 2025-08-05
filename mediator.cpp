#include "mediator.h"
#include <iostream>

void Mediator::set(int integer)
{
    shared_queue.push(integer);
}

int Mediator::get()
{
    int return_value = shared_queue.front();
    shared_queue.pop();
    return return_value;
}
bool Mediator::is_empty()
{
    return shared_queue.empty();
}