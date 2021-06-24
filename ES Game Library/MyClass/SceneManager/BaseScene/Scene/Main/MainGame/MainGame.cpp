#include"MainGame.h"
#include "../../../../../EffectManager/EffectManager.h"
#include "../../../../../TimeManager/TimeManager.h"
#include"../../../../SceneManager.h"
#include"../../../../../ResouceManager/ResouceManager.h"
MainGame::MainGame():DefaultFont(GraphicsDevice.CreateDefaultFont())
{
	playermanager = new PlayerManager;
	enemymanager = new EnemyManager;
	ovserver = new Ovserver;
	fieldmanager = new FieldManager;
}

MainGame::~MainGame()
{
	delete ovserver;
	delete enemymanager;
	delete playermanager;
	delete fieldmanager;
}

bool MainGame::Initialize()
{
	main = ResouceManager::Instance().LoadMusicFile(_T("Audio/Bgm/main.wav"));
	main->Play();

	playermanager->Initialize();
	enemymanager->Initialize();
	fieldmanager->Initialize();
	ui.Initialize();
	EffectManager::Instance().Initialize();
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
	GraphicsDevice.SetCamera(camera);
	return true;
}

int MainGame::Update()
{
	if (TimeManager::Instance().GetTimeLeft() < time_over)
	{	
		main->Stop();
		return Scene::NEXT;
	}
	playermanager->Update();
	enemymanager->Update(playermanager);
	ovserver->Update(playermanager, enemymanager);
	EffectManager::Instance().Update();
	TimeManager::Instance().Update();
	ui.Update();
	return 0;
}

void MainGame::Draw2D()
{
	ui.Draw();
}

void MainGame::Draw3D()
{
	camera->SetLookAt(player->GetPosition() + Vector3_Backward * 5 + Vector3(0.0f, 7.0f, 0.0f), player->GetPosition() + player->GetUpVector(), Vector3_Up);
	GraphicsDevice.SetCamera(camera);
	playermanager->Draw();
	enemymanager->Draw();
	fieldmanager->Draw();
	EffectManager::Instance().Draw();

	GraphicsDevice.SetRenderState(DepthBuffer_Disable);
	GraphicsDevice.SetRenderState(DepthBufferFunction_Always);
	Effekseer.SetCamera(camera);
	Effekseer.Draw();
	GraphicsDevice.SetRenderState(DepthBufferFunction_Less);
	GraphicsDevice.SetRenderState(DepthBuffer_Enable);
}

//void MainGame::MusicPlay() {
//
//}
