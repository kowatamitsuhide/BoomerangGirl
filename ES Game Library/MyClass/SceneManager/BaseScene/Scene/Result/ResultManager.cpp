#include"ResultManager.h"
#include"ResultScene/ResultScene.h"
#include"../../../../Data/WordsTable.h"
ResultManager::ResultManager()
{
	_next_scene = SceneNumber::TITLE;
}

ResultManager::~ResultManager()
{
}

bool ResultManager::Initialize()
{
	_child_scene.push_back(std::make_unique<ResultScene>());
	for (auto&& childscene : _child_scene)
	{
		childscene->Initialize();
	}
	return true;
}

void ResultManager::Draw2D()
{
	for (auto&& childscene : _child_scene)
	{
		childscene->Draw2D();
	}
}