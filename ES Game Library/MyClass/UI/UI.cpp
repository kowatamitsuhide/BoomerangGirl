#include "UI.h"
#include"../SceneManager/SceneManager.h"
#include "../Data/WordsTable.h"
#include "../ResouceManager/ResouceManager.h"
UI::UI() {

}

UI::~UI() {

}

bool UI::Initialize() {
	start_finish   = ResouceManager::Instance().LoadSpriteFile(_T("ui/START、ＦＩＮＩＳＨ.png"));
	combo          = ResouceManager::Instance().LoadSpriteFile(_T("ui/ＣＯＭＢＯ.png"));
	time           = ResouceManager::Instance().LoadSpriteFile(_T("ui/TIME_2.png"));
	start          = ResouceManager::Instance().LoadSoundFile(_T("Audio/SoundEffect/Item/powerup.wav"));
	end            = ResouceManager::Instance().LoadSoundFile(_T("Audio/SoundEffect/whistle.wav"));
	time_over_font = GraphicsDevice.CreateSpriteFont(_T("UD デジタル 教科書体 N-B"), 50);
	time_font      = GraphicsDevice.CreateSpriteFont(_T("UD デジタル 教科書体 N-B"), 80);

	start->SetVolume(0.95f);
	end->SetVolume(0.8f);
	return true;
}

int UI::Update() {
	SpriteAlpha();
	Sound();

	if (SceneFlag()) {
		return 1;
	}

	return 0;
}

/**
 * @fn     ゲーム開始と終了時のSE
 * @brief  ゲーム開始・終了時にsound_stateとauto型の変数を元にSEを鳴らす
 * @return なし
 */

void UI::Sound() {
	//!ゲーム開始SE
	auto start_se = !TimeManager::Instance().StartFlag();
	//!ゲーム終了SE
	auto end_se   = TimeManager::Instance().GetTimeLeft() < time_over && sprite_alpha < MAX_ALPHA && count < MAX_COUNT;

	if (start_se && sound_state == SE_START) {
		start->Play();
		sound_state = SE_END;
	}
	if (end_se && sound_state == SE_END) {
		end->Play();
		sound_state = NUM;
	}
}

/**
 * @fn 　  シーン遷移用のフラグ
 * @brief  auto型の変数の条件式を元にゲーム開始・終了時にシーン遷移用フラグを返す
 * @return シーン遷移用フラグ
 */

bool UI::SceneFlag() {
	//!スタートしていて時間が 制限時間 より大きい場合　または 制限時間で終了時処理が終わった時
	auto flag = TimeManager::Instance().StartFlag() && TimeManager::Instance().GetTimeLeft() > time_over ||
			    TimeManager::Instance().GetTimeLeft() < time_over && sprite_alpha < MAX_ALPHA&& count >= MAX_COUNT;

	if (flag)return true;

	return false;
}

/**
 * @fn 　  画像の点滅
 * @brief  auto型の変数の条件式を元にゲーム開始・終了時に画像を点滅させる
 * @return 画像のalpha値
 */

int  UI::SpriteAlpha() {
	//!ゲーム開始前処理 または ゲーム終了時処理
	auto start_sprite_alpha = !TimeManager::Instance().StartFlag()                && sprite_alpha < MAX_ALPHA && count < MAX_COUNT ||
		                       TimeManager::Instance().GetTimeLeft() < time_over  && sprite_alpha < MAX_ALPHA && count < MAX_COUNT;

	//!ゲーム中の場合
	auto between_game       = TimeManager::Instance().StartFlag() && TimeManager::Instance().GetTimeLeft() > time_over;

	int  over_sprite_alpha  = sprite_alpha >= MAX_ALPHA;

	if (start_sprite_alpha)
		sprite_alpha += ALPHA_NUM;
	else if (over_sprite_alpha) {
		sprite_alpha = MIN_ALPHA;
		count++;
	}
	else if (between_game) {
		count = MIN_COUNT;
		sprite_alpha = MIN_ALPHA;
	}

	return sprite_alpha;
}

Color UI::TimeColor() {
  switch ((int)TimeManager::Instance().GetTimeLeft()) {
    case START:
    	color = Color_White;
    	break;
    case HARF:
    	color = Color_Orange;
    	break;
    case END:
    	color = Color_Red;
    	break;
  }
	return color;
}

void UI::Draw() {
	//!ゲーム開始
	if(!TimeManager::Instance().StartFlag())
	SpriteBatch.Draw(*start_finish, Vector3(450,320,1),RectWH(0,0,300,64),Color(255,255, 255, SpriteAlpha()));

	SpriteBatch.Draw(*time, Vector3(0,0, 1));
	SpriteBatch.Draw(*combo, Vector3(250, 100, 1));
	SpriteBatch.DrawString(time_font, Vector2(130, 97), Color_White, _T("%d"), SceneManager::Instance().GetCombo());

		if (TimeManager::Instance().GetTimeLeft() > time_over)
			SpriteBatch.DrawString(time_font, Vector2(240, 12), TimeColor(), _T("%.3f"), TimeManager::Instance().GetTimeLeft());
		else {
			SpriteBatch.DrawString(time_over_font, Vector2(250, 25), Color_Red, _T("TIME OVER"));
			//!ゲーム終了
			SpriteBatch.Draw(*start_finish, Vector3(450, 320, 1), RectWH(400, 0, 750, 64), Color(255, 255, 255, SpriteAlpha()));
		}
	
}