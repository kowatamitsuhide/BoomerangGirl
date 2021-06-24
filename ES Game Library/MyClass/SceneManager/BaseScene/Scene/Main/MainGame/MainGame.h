#include"../../../BaseScene.h"
#include "../../../../../PlayerManager/PlayerManeger.h"
#include "../../../../../EnemyManager/EnemyManeger.h"
#include "../../../../../Ovserver/Ovserver.h"
#include "../../../../../Field/FieldManager.h"
#include "../../../../../UI/UI.h"
class MainGame :public BaseScene
{
public:
	MainGame();
	~MainGame();
	bool Initialize() override;
	int Update()override;
	void Draw2D() override;
	void Draw3D() override;
private:
	FONT DefaultFont;
	PlayerManager* playermanager;
	EnemyManager* enemymanager;
	Ovserver* ovserver;
	FieldManager* fieldmanager;

	CAMERA camera;
	ANIMATIONMODEL player;
	MUSIC main;
	UI ui;

	const float time_over = 0.9f;
};