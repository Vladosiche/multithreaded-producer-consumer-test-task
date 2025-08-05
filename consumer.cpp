#include "consumer.h"
#include <iostream>

void Consumer::consume()
{  
        while(!(mediator->is_end()) || !(mediator->is_empty()))
        {
            std::queue<int> value = mediator->get();
            for(size_t i = value.size(); i>0; i--)
            {
            std::cout<<value.front()<<"\n";
            value.pop();
            }
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