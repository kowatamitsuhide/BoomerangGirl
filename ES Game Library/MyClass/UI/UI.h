#pragma once

/**
 * @file   UI.h
 * @brief  ゲーム内の文字・画像描画、MainGame内のシーン遷移を行っているクラス
 * @author Mitsuhide Kowata
 * @date   2021/05/20
 */

#include "../../ESGLib.h"
#include "../../StdAfx.h"
#include "../TimeManager/TimeManager.h"
#include "../PlayerManager/Boomerang/Boomerang.h"
#include"../EnemyManager/EnemyManeger.h"

class UI {
public:
	UI::UI();
	UI::~UI();
	bool Initialize();
	int  Update();
	void Draw();
private:
	int  SpriteAlpha();
	bool SceneFlag();
	void Sound();

	Color TimeColor();
	Color color;
	SPRITE start_finish,combo,time;
	FONT time_font,time_over_font;
	SOUND start,end;

	const float time_over = 0.9f;
	bool  time_over_flag = false;
	bool  test_flag = false;
	bool  next_scene_flag = false;
	int   sprite_alpha = MIN_ALPHA;
	int   count        = MIN_COUNT;
	int   sound_state  = SE_START;

	/**
    * @enum Sound
    * SEの状態変化用
    */
	enum Sound { SE_START,SE_END,NUM };

	/**
    * @enum Alpha
    * 画像のアルファ値変更用
    */
	enum Alpha { MIN_ALPHA  =  0, ALPHA_NUM  =   2, MAX_ALPHA = 255 };

	/**
    * @enum Time
    * 時間を指定し処理を行う
    */
	enum Time  { START      = 60, HARF       =  30, END       = 10  };

	/**
    * @enum Count
    * 画像点滅の点滅回数カウント
    */
	enum Count { MIN_COUNT  =  0, MAX_COUNT  =   3 };
protected:
};