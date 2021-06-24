#include "ResultScene.h"
#include "../../../../SceneManager.h"
#include"../../../../../ResouceManager/ResouceManager.h"
#include"../../../../../Data/MyAlgorithm.h"
#include <fstream>
ResultScene::ResultScene() {

}

ResultScene::~ResultScene() {
}

bool ResultScene::Initialize() {

	SaveScore();
	font     = ResouceManager::Instance().LoadFontFile(_T("UD デジタル 教科書体 N-B"), 120);
	result   = ResouceManager::Instance().LoadSpriteFile(_T("Result/result_background.png"));
	record   = ResouceManager::Instance().LoadSpriteFile(_T("Result/result.png"));
	dramroll = ResouceManager::Instance().LoadSoundFile(_T("Audio/SoundEffect/dramroll.wav"));
	dramroll->Play();

	bgm = ResouceManager::Instance().LoadMusicFile(_T("Audio/Bgm/result.wav"));
	bgm->Play();

	InputDevice.CreateGamePad(1);
	return true;
}

int ResultScene::Update() {

	if (count < MAX_COUNT)
		count++;
	else
		appear_flag = true;


	KeyboardBuffer key = Keyboard->GetBuffer();
	GamePadBuffer pad = GamePad(0)->GetBuffer();
	if (key.IsPressed(Keys_Space) || pad.IsPressed(GamePad_Button4))
	{	
		bgm->Stop();
		return Scene::NEXT;
	}

	return Scene::NOW;
}

void ResultScene::Draw2D() {
	SpriteBatch.Draw(*result, Vector3(0,0,2));
	SpriteBatch.Draw(*record, Vector3(130,100,1));
	if (appear_flag) {
		//!倒した敵の数
		SpriteBatch.DrawString(font, Vector2(530, 260), Color_Black, _T("%d"), SceneManager::Instance().GetDeathEnemy());
		//!最大コンボ数
		SpriteBatch.DrawString(font, Vector2(270, 460), Color_Black, _T("最大 %d"), SceneManager::Instance().MaximumCombo());
	}
}

void ResultScene::SaveScore()
{
	auto data = GetSaveData();

	if (SceneManager::Instance().GetDeathEnemy() > data[EnemyCount])
		data[EnemyCount] = SceneManager::Instance().GetDeathEnemy();
	if (SceneManager::Instance().MaximumCombo() > data[Combo])
		data[Combo] = SceneManager::Instance().MaximumCombo();

	std::ofstream outputfile("Score/Score.txt");
	outputfile << data[EnemyCount] << ' ' << data[Combo];
	outputfile.close();
}
