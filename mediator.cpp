#include "mediator.h"
#include <iostream>
//================================================================================
// Method: set()
// Description: Adding new values to the queue
//================================================================================
void Mediator::set(int integer)
{
    while(set_lock.exchange(1) == 0) //atomic access control for write
    {
    shared_queue.push(integer);
    }
    set_lock.store(0);
}

//================================================================================
// Method: get()
// Description: Getting a queue block
//================================================================================
std::queue<int> Mediator::get(int id)
{
    while(get_lock.exchange(1) == 0) //atomic access control for read
    {
            while (!(is_empty())) 
            {
            std::queue<int> return_value;  // block queue
                while(set_lock.exchange(1) == 0)
                {
                return_value = shared_queue;
                }
            set_lock.store(0);
            for(int i = return_value.size(); i!=0;--i)
            {
                while(set_lock.exchange(1) == 0)
                {
                if(!shared_queue.empty())
                shared_queue.pop();
                }
                set_lock.store(0);
            }
            get_lock.store(0);
            return return_value;
            }   
            get_lock.store(0);
    }   
    return std::queue<int>();
}
//================================================================================
// Method: is_empty()
// Description: Queue emptiness check
//================================================================================
bool Mediator::is_empty()
{
    return shared_queue.empty();
}
//================================================================================
// Method: is_end()
// Description: Check end of input
// TODO: To increase the number of produce treads, it is necessary 
// to refine the check for completion of input.
//================================================================================
bool Mediator::is_end()
{
    return end;
}
//================================================================================
// Method: set_end()
// Description: Set end of input
// TODO: To increase the number of produce treads, it is necessary 
// to refine the check for completion of input.
//================================================================================
void Mediator::set_end()
{
    end=1;
}