#pragma once
#include <memory> 
#include <queue>
#include <random>
#include <iostream>
#include "mediator.h"

class Consumer; 

class ConsumerFactory
{
private:
    uint32_t inst_number;
    std::queue<std::unique_ptr<Consumer>> instance;
    Mediator* mediator;
public:
    ConsumerFactory(uint32_t number, Mediator *ref_mediator) : inst_number(number), mediator(ref_mediator){};
    void createInstance();
    void launchInstance();
};

class Consumer
{
private:
    Mediator* mediator;
public:
   Consumer(Mediator  *ref_mediator) : mediator(ref_mediator){};
   void consume();

};
