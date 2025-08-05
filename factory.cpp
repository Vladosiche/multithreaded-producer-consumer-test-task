#include "factory.h"

Factory::Factory(uint32_t count_produce, uint32_t count_consume) : prfactory(count_produce,&mediator), cmfactory(count_consume,&mediator)   {
        prfactory.createInstance();
        cmfactory.createInstance();
        prfactory.launchInstance();
        cmfactory.launchInstance();
    }