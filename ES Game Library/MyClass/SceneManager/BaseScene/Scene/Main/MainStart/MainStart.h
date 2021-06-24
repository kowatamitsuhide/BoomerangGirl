#pragma once

/**
 * @file   MainStart.h
 * @brief  ゲーム開始時のUI・フィールド・プレイヤー表示をしているクラス
 * @author Mitsuhide Kowata
 * @date   2021/05/20
 */

#include"../../../BaseScene.h"
#include "../../../../../Field/FieldManager.h"
#include "../../../../../PlayerManager/PlayerManeger.h"
#include "../../../../../UI/UI.h"
class MainStart :public BaseScene
{
public:
	MainStart();
	virtual ~MainStart();
	bool Initialize() override;
	int Update() override;
	void Draw2D() override;
private:
	FieldManager* fieldmanager;
	PlayerManager* playermanager;

	CAMERA camera;
	ANIMATIONMODEL player;
	UI ui;
};