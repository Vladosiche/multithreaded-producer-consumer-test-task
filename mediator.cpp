#include "mediator.h"
#include <iostream>

void Mediator::set(int integer)
{
    while(set_lock.exchange(1)==0)
    {
    shared_queue.push(integer);
    }
    set_lock.store(0);
}

std::queue<int> Mediator::get()
{
    while(get_lock.exchange(1)!=0)
    {
            while (!(is_empty()))  //поміняти на визначення кінця запису
            {
            std::queue<int> return_value = shared_queue;
            for(int i = return_value.size(); i!=0;--i)
            {
            shared_queue.pop();
            }
            get_lock.store(0);
            return return_value;
            }   
    }   
    return std::queue<int>();
}
bool Mediator::is_empty()
{
    return shared_queue.empty();
}

bool Mediator::is_end()
{
    return end;
}

void Mediator::set_end()
{
    end=1; //треба допрацювати
}