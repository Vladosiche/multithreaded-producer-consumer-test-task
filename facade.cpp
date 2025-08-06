#include "facade.h"
//================================================================================
// Constructor: Facade()
// Description: Hides and composes function calls
//================================================================================
Facade::Facade(uint32_t count_produce, uint32_t count_consume,uint32_t numberOfIntegers) : prfactory(count_produce,&mediator), cmfactory(count_consume,&mediator)   {
        prfactory.createInstance(numberOfIntegers);
        cmfactory.createInstance();
        prfactory.launchInstance();
        cmfactory.launchInstance();
        prfactory.join_treads();
        cmfactory.join_treads();
    }