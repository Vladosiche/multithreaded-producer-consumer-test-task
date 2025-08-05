#pragma once
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
public:
    ProducerFactory(uint32_t number) : inst_number(number){};
    std::queue<std::unique_ptr<Producer>> createFactory();
   
};


class Producer
{
private:
    std::queue<int> integers;
    uint32_t iteration;
    std::random_device rd; 
    std::mt19937 gen;
    std::uniform_int_distribution<int> dist;
public:
   Producer(uint32_t number_repetitions);
   void produce();
    /*
    void show()
    {
        while(!(integers.empty()))
        {
            std::cout<<integers.front()<<" ";
            integers.pop();
        }
    }
        */
};

//producer::producer(args)
//{
//}

//producer::~producer()
//{
//}
