#pragma once

#include "Common.h"
#include "BuildOrder.h"
#include "BuildingManager.h"
#include "BuildOrderQueue.h"

class CCBot;

class ProductionManager
{
    CCBot &       m_bot;

    BuildingManager m_buildingManager;
    BuildOrderQueue m_queue;

    Unit    getClosestUnitToPosition(const std::vector<Unit> & units, CCPosition closestTo);
    bool    meetsReservedResources(const MetaType & type);
    bool    canMakeNow(const Unit & producer, const MetaType & type);
    bool    detectBuildOrderDeadlock();
    void    setBuildOrder(const BuildOrder & buildOrder);
    void    addToBuildOrder(const BuildOrder & buildOrder);  //Chris Kelly
    void    create(const Unit & producer, BuildOrderItem & item);
    void    manageBuildOrderQueue();
    int     getFreeMinerals();
    int     getFreeGas();

    void    fixBuildOrderDeadlock();

public:

    ProductionManager(CCBot & bot);

    void    onStart();
    void    onFrame();
    void    changeStrat(std::string strat); //Chris Kelly
    void    addToStrat(std::string strat); //Chris Kelly
    void    onUnitDestroy(const Unit & unit);
    void    drawProductionInformation();

    Unit getProducer(const MetaType & type, CCPosition closestTo = CCPosition(0, 0));
};
