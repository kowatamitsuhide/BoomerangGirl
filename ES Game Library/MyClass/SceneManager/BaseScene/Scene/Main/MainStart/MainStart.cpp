#include"MainStart.h"
#include"../MainGame/MainGame.h"
#include "../../../../../TimeManager/TimeManager.h"
MainStart::MainStart()
{
	playermanager = new PlayerManager;
	fieldmanager = new FieldManager;
}

MainStart::~MainStart()
{
	delete playermanager;
	delete fieldmanager;
}

bool MainStart::Initialize()
{
	playermanager->Initialize();
	fieldmanager->Initialize();
	ui.Initialize();
	TimeManager::Instance().Initialize();
	player = playermanager->GetModel();

	Light light;
	light.Type = Light_Directional;
	light.Direction = Vector3(1.0f, 1.0f, 1.0f);
	light.Ambient = Color(1.0f, 1.0f, 1.0f);
	light.Diffuse = Color(1.0f, 1.0f, 1.0f);
	light.Specular = Color(1.0f, 1.0f, 1.0f);
	GraphicsDevice.SetLight(light);

	camera->SetView(Vector3(0, 0, -650), Vector3(0, 0, 0));
	camera->SetPerspectiveFieldOfView(45.0f, 16.0f / 9.0f, 1.0f, 10000.0f);
	camera->SetLookAt(player->GetPosition() + Vector3_Backward * 5 + Vector3(0.0f, 7.0f, 0.0f), player->GetPosition() + player->GetUpVector(), Vector3_Up);
	GraphicsDevice.SetCamera(camera);
	return true;
}

int MainStart::Update()
{
	//! ゲーム開始時のUIの点滅が終わった場合、次のシーンに遷移
	if (ui.Update() == 1)
		return Scene::NEXT;
	TimeManager::Instance().Update();
	ui.Update();
	return Scene::NOW;
}

void MainStart::Draw2D()
{
	ui.Draw();
}