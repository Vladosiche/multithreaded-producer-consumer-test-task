#include "consumer.h"

void Consumer::consume()
{
    while (!(integers.empty()))
    {
       std::cout<<integers.front();
       integers.pop();
    }
}

 std::queue<std::unique_ptr<Consumer>>ConsumerFactory::createFactory()
 {
     for(size_t i = 0 ; i<inst_number ; ++i)
        {
            instance.push(std::make_unique<Consumer>());
        }
        return std::move(instance);
 }
