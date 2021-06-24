#include"../../../BaseScene.h"
#include"../../../../SceneManager.h"
class TitleScene:public BaseScene
{
public:
	TitleScene();
	virtual ~TitleScene();
	bool Initialize() override;
	int Update() override;
	void Draw2D() override;
private:
	FONT   font;
	SPRITE bg,logo;
	MUSIC  title;
};