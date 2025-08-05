#pragma once
#include <queue>

class Mediator
{
   private: 
   std::queue<int> shared_queue;
   public:
  //Mediator(std::queue<int> init_queue) : shared_queue(init_queue){};
   void set(int integer);
   int get();
   bool is_empty();
};