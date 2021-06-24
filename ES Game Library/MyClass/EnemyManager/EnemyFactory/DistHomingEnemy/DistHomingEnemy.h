#pragma once

/**
 * @file   DistHomingEnemy.h
 * @brief  一定距離でホーミングする敵クラス
 * @author Mitsuhide Kowata
 * @date 　2021/03/31
 */

#include "../EnemyBase/EnemyBase.h"

class DistHomingEnemy : public EnemyBase{
public:
    DistHomingEnemy::DistHomingEnemy();
    DistHomingEnemy::~DistHomingEnemy();
    int    Update(PlayerManager* player_manager) override;
private:
    void    Move();
    void    Rotate();

    Vector3 player_pos;
    bool homing_flag = false;

    /**
    * @enum Pos
    * ホーミング開始距離
    */
    enum Pos { DIST_POS = 3 };
};