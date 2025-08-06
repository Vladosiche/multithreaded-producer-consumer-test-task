#pragma once
#include "mediator.h"
#include <memory> 
#include <queue>
#include <random>
#include <iostream>

class Producer; 

class ProducerFactory
{
private:
    uint32_t inst_number;
    std::queue<std::unique_ptr<Producer>> instance;
    Mediator* mediator;
    std::vector<std::thread> produce_threads;
public:
    ProducerFactory(uint32_t number, Mediator *ref_mediator) : inst_number(number), mediator(ref_mediator){};
    void createInstance(uint32_t numberOfIntegers);
    void launchInstance();
    void join_treads();
   
};


class Producer
{
private:
    Mediator* mediator; 
    //std::queue<int> integers;
    uint32_t iteration;
    std::random_device rd; 
    std::mt19937 gen;
    std::uniform_int_distribution<int> dist;
public:
   Producer(uint32_t number_repetitions, Mediator *ref_mediator);
   void produce();

};
