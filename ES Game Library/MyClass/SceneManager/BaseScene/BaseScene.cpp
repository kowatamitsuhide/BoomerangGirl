#include"BaseScene.h"
BaseScene::~BaseScene()
{
}
int BaseScene::BeginScene(std::list<std::unique_ptr<BaseScene>>& scene)
{
	int next = Scene::NEXT;
	for (auto&& childscene : scene)
	{
		if (childscene->Update() == childscene->NOW)
		{
			next = Scene::NOW;
			break;
		}
	}
	return next;
}
int BaseScene::Update()
{
	return BeginScene(_child_scene);
}