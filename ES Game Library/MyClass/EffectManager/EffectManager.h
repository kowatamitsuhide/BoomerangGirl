#pragma once


#include"../../ESGLib.h"
#include"../ParticleSystem/Particle.h"
class EffectManager{
public:
    EffectManager::EffectManager();
    EffectManager::~EffectManager();
    bool   Initialize();
    int    Update();
    void   Draw();
    void Create(string tag, Vector3 pos);
    //! シングルトンオブジェクトを他で呼び出す時の記述
    static EffectManager& Instance() {
        static EffectManager instance;
        return instance;
    };
private:
    std::map<string, ParticleSystem*> _effect;
    ParticleSystem* SetEffectInit(string filename,float speed,float scale);
};