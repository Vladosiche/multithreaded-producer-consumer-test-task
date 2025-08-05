#include <iostream>
#include <vector>
#include <string>
#include "producer.h"
#include "consumer.h"
#include <random>

int main()
{
//ProducerFactory Factory(1); //це краще перенести до криейт факторі та перейменувати функцію на криейтпродюс
//std::queue<std::unique_ptr<Producer>> instance = Factory.createFactory();
//std::cout<<"\n"<<"instance size:"<<instance.size()<<"\n";
//instance.front()->produce();
ConsumerFactory Factory(1);
std::queue<std::unique_ptr<Consumer>> instance = Factory.createFactory();
instance.front()->consume();
}
