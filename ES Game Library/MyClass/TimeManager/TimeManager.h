#pragma once
#include "../../ESGLib.h"

class TimeManager
{
private:
	TimeManager(const TimeManager&) = delete;
	void operator=(const TimeManager&) = delete;



public:
	TimeManager();
    ~TimeManager();

	static TimeManager& Instance() {
		static TimeManager instance;
		return instance;
	};

	void Initialize();
	void Update();
	
	//何秒立ったかの取得
	inline float GetTime()		const { return time; }
	//残り時間の取得
	inline float GetTimeLeft()  const { return limitTime - time; }
	bool StartFlag();
	void AddTime(float count) { limitTime += count; }
private:
	inline float GetLimitTime() const { return limitTime; }
	int GetTimeMinutes();
	int GetTimeSeconds();
	int GetTimeOnesPlace();
	int GetTimeTensPlace();
	int Countdown();
	float GetStartTime();
	float GetTransitionTimer() const { return transition_time; }
	//! 制限時間
	float limitTime;
	float time;

	//! 終了後のタイマー
	float transition_time;
	bool game_end;

	//! カウントダウン
	float startTime;
	int countTime;

	bool startFlag;
	
	};