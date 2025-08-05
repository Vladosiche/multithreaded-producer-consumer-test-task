#include <iostream>
#include <vector>
#include <string>
#include "producer.h"
#include <random>

int main()
{
ProducerFactory Factory(1); //це краще перенести до криейт факторі та перейменувати функцію на криейтпродюс
std::queue<std::unique_ptr<Producer>> instance = Factory.createFactory();
std::cout<<"\n"<<"instance size:"<<instance.size();
instance.front()->produce();
instance.front()->show();
}
