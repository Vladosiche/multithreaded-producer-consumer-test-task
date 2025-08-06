#include "consumer.h"
#include <iostream>
#include <syncstream>
//================================================================================
// Method: consume()
// Description: Makes a request to the mediator in order to obtain a queue block and
//              further output to the console
//================================================================================
void Consumer::consume()
{  
        while(!(mediator->is_end()) || !(mediator->is_empty()))
        {
            
            std::queue<int> value = mediator->get(id);
            for(size_t i = value.size(); i>0; i--)
            {
            std::osyncstream(std::cout)<<value.front()<<"\n";
            value.pop();
            }
        }
}
//================================================================================
// Method: createInstance()
// Description: The function of creating instances of consumers
//================================================================================
 void ConsumerFactory::createInstance()
 {
     for(size_t i = 0 ; i<inst_number ; ++i)
        {
            instance.push(std::make_unique<Consumer>(mediator,i));
        }
 }

//================================================================================
// Method: launchInstance()
// Description: The function of creating and splitting into streams and 
//              calling the consume() method for each of them
//================================================================================
 void ConsumerFactory::launchInstance()
 {
    while (!(instance.empty()))
    {
        auto item = std::move(instance.front());
        instance.pop();
        consume_threads.emplace_back([item = std::move(item)]() mutable {
            item->consume();
        });
    }
 }

//================================================================================
// Method: join_treads()
// Description: Tread waiting function
//================================================================================
void ConsumerFactory::join_treads()
{
    for (auto& t : consume_threads) {
    t.join();
    }
}