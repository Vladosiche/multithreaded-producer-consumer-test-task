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
    std::vector<std::thread> consume_threads;
public:
    ConsumerFactory(uint32_t number, Mediator *ref_mediator) : inst_number(number), mediator(ref_mediator){};
    void createInstance();
    void launchInstance();
    void join_treads();
};

class Consumer
{
private:
    Mediator* mediator;
public:
   int id;
   Consumer(Mediator  *ref_mediator , int create_id) : mediator(ref_mediator), id(create_id){};
   void consume();

};
