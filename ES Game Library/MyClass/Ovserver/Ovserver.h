#pragma once

#include"../../ESGLib.h"
#include"../PlayerManager/PlayerManeger.h"
#include"../EnemyManager/EnemyManeger.h";
class Ovserver {
public:
    Ovserver::Ovserver();
    Ovserver::~Ovserver();
    int     Update(PlayerManager*, EnemyManager*);
    void    ColisionDetection(PlayerManager* playerdata, EnemyManager* enemydata);
};