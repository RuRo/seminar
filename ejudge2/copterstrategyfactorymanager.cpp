#include "copterstrategy.h"

copter::CopterStrategyFactoryManager&
copter::CopterStrategyFactoryManager::instance()
{
    static CopterStrategyFactoryManager inst{};
    return inst;
}
