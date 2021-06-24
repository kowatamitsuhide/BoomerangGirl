#include"MainManager.h"
#include"MainStart/MainStart.h"
#include"MainGame/MainGame.h"
#include"MainEnd/MainEnd.h"
#include"../../../../Data/WordsTable.h"
MainManager::MainManager()
{
	_next_scene = SceneNumber::RESULT;
}

MainManager::~MainManager()
{
}

bool MainManager::Initialize()
{
	_child_scene.push_back(std::make_unique<MainStart>());
	_child_scene.push_back(std::make_unique<MainGame>());
	_child_scene.push_back(std::make_unique<MainEnd>());
	for (auto&& childscene : _child_scene)
	{
		childscene->Initialize();
	}
	return true;
}

void MainManager::Draw2D()
{
	for (auto&& childscene : _child_scene)
	{
		childscene->Draw2D();
	}
}
void MainManager::Draw3D()
{
	for (auto&& childscene : _child_scene)
	{
		childscene->Draw3D();
	}
}