#pragma once
#include <queue>
#include <atomic>

class Mediator
{
   private: 
   std::atomic<int> get_lock;
   std::atomic<int> set_lock;
   std::queue<int> shared_queue;
   bool end =0;
   public:
   Mediator()
   {
    set_lock.store(0);
    get_lock.store(0);
   };
   void set(int integer);
   std::queue<int> get();
   bool is_empty();
   bool is_end();
   void set_end();
};