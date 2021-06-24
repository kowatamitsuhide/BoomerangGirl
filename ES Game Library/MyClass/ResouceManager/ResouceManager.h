//! @file   ResouceManager.h
//! @brief  ファイル読み込みを管理しているクラス
//! @author Souta_Miura
//! @date   2020/11/26
#pragma once

#include "../../ESGLib.h"

class ResouceManager
{
public:
	ResouceManager() {};
	~ResouceManager() {};

	static ResouceManager& Instance() {
		static ResouceManager instance;
		return instance;
	};

	SPRITE		   LoadSpriteFile(tstring sprite_file_name);
	MODEL		   LoadModelFile(tstring model_file_name);
	ANIMATIONMODEL LoadAnimationModelFile(tstring animation_model_name);
	FONT		   LoadFontFile(tstring font_file_name, float size);
	EFFECT		   LoadEffectFile(tstring effect_file_name);
	SOUND		   LoadSoundFile(tstring sound_file_name);
	MUSIC		   LoadMusicFile(tstring music_file_name);
	MEDIA		   LoadMediaFile(tstring media_file_name);
	EFFEKSEER	   LoadEffekseerFile(tstring effekseer_file_name);

	void ResoucesEffekseerClear();
private:
	ResouceManager(const ResouceManager&) = delete;
	void operator=(const ResouceManager&) = delete;

	std::map<tstring, SPRITE>			_resouces_sprite;
	std::map<tstring, MODEL>			_resouces_model;
	std::map<tstring, ANIMATIONMODEL>   _resouces_animation_model;
	std::map<tstring, FONT>				_resouces_font;
	std::map<tstring, EFFECT>			_resouces_effect;
	std::map<tstring, SOUND>			_resouces_sound;
	std::map<tstring, MUSIC>			_resouces_music;
	std::map<tstring, MEDIA>			_resouces_media;
	std::map<tstring, EFFEKSEER>		_resouces_effekseer;
};
