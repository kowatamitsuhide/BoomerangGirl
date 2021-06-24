#pragma once

#include "../../ESGLib.h"
static const float ENEMYADDTIME = 0.5f;
static const float MAXTIME = 60.0f;
namespace EffectTag {
	static const std::string HIT = "hit";
	static const std::string SAMLL = "small_";
	static const std::string EXPLOSION = "explosion";
	static const std::string SMALLEXPLOSION = "explosion";
}
namespace SceneNumber {
	static const std::string TITLE  = "title";
	static const std::string MAIN   = "main";
	static const std::string RESULT = "result";
}
enum SaveData
{
	EnemyCount,
	Combo,
	ALLCOUNT
};