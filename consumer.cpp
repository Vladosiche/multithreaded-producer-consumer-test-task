#include "consumer.h"
#include <iostream>

void Consumer::consume()
{
    while (!(mediator->is_empty()))
    {
       std::cout<<mediator->get()<<"\n";
    }
}

 void ConsumerFactory::createInstance()
 {
     for(size_t i = 0 ; i<inst_number ; ++i)
        {
            instance.push(std::make_unique<Consumer>(mediator));
        }
 }

 void ConsumerFactory::launchInstance()
 {
     while (!(instance.empty()))
    {
        instance.front()->consume();
        instance.pop();
    }
 }