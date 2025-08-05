#pragma once
#include <memory> 
#include <queue>
#include <random>
#include <iostream>

class Consumer; 

class ConsumerFactory
{
private:
    uint32_t inst_number;
    std::queue<std::unique_ptr<Consumer>> instance;
public:
    ConsumerFactory(uint32_t number) : inst_number(number){};
    std::queue<std::unique_ptr<Consumer>> createFactory();
   
};

class Consumer
{
private:
    std::queue<int> integers;
public:
   Consumer ()
   {
    integers.push(2);
    integers.push(4);
    integers.push(6);
    integers.push(7);
    integers.push(9);
    integers.push(11);
   }
   void consume();

};
