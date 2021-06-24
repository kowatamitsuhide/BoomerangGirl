#pragma once

/**
 * @file   EnemyManager.h
 * @brief  敵を監視するクラス
 * @author Mitsuhide Kowata
 * @date 　2021/03/31
 */

#include "EnemyFactory/EnemyFactory.h"

class EnemyManager {
public:
    EnemyManager::EnemyManager();
    EnemyManager::~EnemyManager();
    bool Initialize();
    int  Update(PlayerManager* playermanager);
    void Draw();
    void OnCollisionEnter(EnemyBase*);
    std::list<EnemyBase*> GetEnemy() {return _enemy; }

private:
    void Generate(PlayerManager* player_manager);
    void LoadCSV();

    std::list<EnemyBase*> _enemy;
    float _frame = 0.0f;
    float _time  = 0.0f;

    /**
　　* @enum EnemyState
　　* 敵の状態変化用
　　*/
    enum EnemyState { LIVING,DESTROY, DEATH };

    /**
　　* @enum LoadFile
　　* ファイル読み込み用
　　*/
    enum LoadFile{ DUMMYLINENUM = 3,ENEMY_NUM = 250 };

    /**
　　* @enum Frame
　　* 敵の出現時間計測用
　　*/
    enum Frame{ GAME_FRAME = 60 };
   
    int count = 0;                   //!敵の累計出現数カウント 
    string  tag[ENEMY_NUM];          //!敵の種類         
    Vector3 appear_pos[ENEMY_NUM];   //!敵の出現座標  
    float   appear_time[ENEMY_NUM];  //!敵の出現時間
    bool    appear_flag[ENEMY_NUM];  //!敵の出現フラグ 
    SOUND explode;

    PlayerManager* _playermanager;
};