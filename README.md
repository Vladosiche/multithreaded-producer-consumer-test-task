# multithreaded-producer-consumer-test-task
# Основні концептуальні рішення
## - Використання атомарних функцій замість м'ютексов
### Використовуючи атомарну змінну зміннюва її значення для зробивши з неї прапор за яким і виконувалося регулювання доступу приклад з коду:
```
  while(set_lock.exchange(1) == 0) //atomic access control for write
    {
    shared_queue.push(integer);
    }
    set_lock.store(0);
``` 
## - Використання фабрик для створення виробника(Producer) та споживачів (Consumer)
### Аби не закодовувати жорстко кількість потоків створив фабрики які отримують значення рівне кількості необхідних потоків та створюють відповідну кількість інстанцій.

## - Використання посередника для комунікації між виробником та споживачами
### Вся робота з чергою як на ввід та на вивід відбувається за комунікації та роботи посередника за допомогою функцій get() та set()
## - Використання патерну "Фасад"
### Аби не "Запихувати" виклик усіх необхідних функцій в мейн створив фасад в якому це все. Фрагмент коду:
```
Facade::Facade(uint32_t count_produce, uint32_t count_consume) : prfactory(count_produce,&mediator), cmfactory(count_consume,&mediator)   {
        prfactory.createInstance();
        cmfactory.createInstance();
        prfactory.launchInstance();
        cmfactory.launchInstance();
        prfactory.join_treads();
        cmfactory.join_treads();}
```
# Дякую за увагу!

# Main conceptual decisions
## - Using atomic functions instead of mutexes
### Using an atomic variable, changing its value to make it a flag, which was used to control access. Example from the code:
```
  while(set_lock.exchange(1) == 0) //atomic access control for write
    {
    shared_queue.push(integer);
    }
    set_lock.store(0);
``` 
## - Using factories to create producers and consumers
### In order to avoid hard-coding the number of streams, I created factories that receive a value equal to the number of streams required and create the corresponding number of instances.

## - Using a mediator for communication between producers and consumers
### All work with the queue, both input and output, is done through communication and the work of the intermediary using the get() and set() functions.
## - Using the “Facade” pattern
### In order not to “cram” all the necessary functions into the main, I created a facade that contains everything. Code snippet:
```
Facade::Facade(uint32_t count_produce, uint32_t count_consume) : prfactory(count_produce,&mediator), cmfactory(count_consume,&mediator)   {
        prfactory.createInstance();
        cmfactory.createInstance();
        prfactory.launchInstance();
        cmfactory.launchInstance();
        prfactory.join_treads();
        cmfactory.join_treads();}
```
# Thank you for your attention!