#pragma once
#include"../../../ESGLib.h"

class BaseScene
{
public:
	BaseScene() {};
	virtual ~BaseScene();

	virtual bool Initialize() = 0;
	int BeginScene(std::list<std::unique_ptr<BaseScene>>& scene);
	virtual int Update();
	virtual void Draw2D() {};
	virtual void Draw3D() {};
	string GetNextScene() { return _next_scene;}
	enum Scene { NOW, NEXT };
protected:
	std::list<std::unique_ptr<BaseScene>> _child_scene;
	string _next_scene;
private:
};