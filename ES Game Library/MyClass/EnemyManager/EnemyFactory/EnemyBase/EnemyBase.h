#pragma once

/**
 * @file   EnemyBase.h
 * @brief  敵の元になるクラス
 * @author Mitsuhide Kowata
 * @date 　2021/03/31
 */

#include "../../../../ESGLib.h"
#include"../../../PlayerManager/PlayerManeger.h"
#include "../../../TimeManager/TimeManager.h"
#include "../../../SceneManager/SceneManager.h"

class EnemyBase {
public:
    EnemyBase::EnemyBase();
    EnemyBase::~EnemyBase();
    virtual bool Initialize(string _model_name, Vector3 position, Vector3 speed, int hp);
    virtual int  Update(PlayerManager* playermanager);
    void Draw();
    MODEL GetCollision() { return _collision; }
    Vector3 GetPosition() { return _position; }
    void Damage();
    virtual int AutoDead();
protected:
    bool IsDamage();
    Vector3 _position;
    Vector3 _angle;
    Vector3 _speed;
    Vector3 player_pos;
    int     _hp;
    MODEL   _collision;
    ANIMATIONMODEL   _model;

    float   _rotation = 0.0f;
    const float  _homing_area = 8.5f;

   /**
    * @enum EnemyState
    * 敵の状態
    */
    enum EnemyState{ LIVING,DESTROY, DEATH };

private:
    /**
     * @enum Frame
     * 敵に関係する時間計測用
     */
    enum Frame { 
        //!ダメージを受けた敵が止まる時間
        DAMAGE_STOP_FRAME = 30, 
        //!敵が自動削除される時間
        AUTODEADTIME = 900 
    };

    /**
     * @enum Dist_Enemy
     * 敵を倒した数でHPを増やす
     */
    enum Dist_Enemy {
        //!割った数の余り
        REMAINDER = 0,
        //!割る数
        DIST_ENEMY_NUM = 10
    };

    /**
    * @enum Combo
    * コンボ数
    */
    enum Combo {
        _100COMBO = 100,
        _200COMBO = 200,
        _300COMBO = 300
    };

    /**
　　* @enum Power
　　* ダメージ加算用
　　*/
    enum Power {
        FIRST  = 1,
        SECOND = 2,
        THIRD  = 3,
        FOURTH = 4
    };

    int  PlusHp();
    bool IsDead();

    const int half = 2;

    int _destroy_time = 0;
    int _add_damage = 0;
    int _combo = 0;

    bool  damage_flag = false;

    const float time_over      = 0.9f;
    const float collision_size = 0.8f;

    float damage_frame = 0.0f;
};