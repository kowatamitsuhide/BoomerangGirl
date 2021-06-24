#include"SceneManager.h"
#include"BaseScene/Scene/Tittle/TitleManager.h"
#include"BaseScene/Scene/Main/MainManager.h"
#include"BaseScene/Scene/Result/ResultManager.h"
#include"../Data/WordsTable.h"

SceneManager::SceneManager()
{
	_scene = nullptr;
	this->SetCombo(0);
	this->SetDeathEnemy(0);
}

SceneManager::SceneManager(int combo)
{
	this->SetCombo(combo);
	this->SetDeathEnemy(combo);
}

SceneManager::~SceneManager()
{
}
void SceneManager::ChangeScene(string scene)
{
	_scene.reset();

	if (scene == SceneNumber::TITLE)		_scene = std::make_unique<TitleManager>();
	else if (scene == SceneNumber::MAIN)	_scene = std::make_unique<MainManager>();
	else if (scene == SceneNumber::RESULT)	_scene = std::make_unique<ResultManager>();

	assert(_scene && "ŠY“–scene‚È‚µ");
	_scene->Initialize();
}
bool SceneManager::Initialize(string scene)
{
	Effekseer.Attach(GraphicsDevice, 8192);
	ChangeScene(scene);
	return 0;
}

int SceneManager::Update()
{
	Effekseer.Update();
	if (_scene->Update() == _scene->NEXT)
	{
		ChangeScene(_scene->GetNextScene());
	}

	_combo_reset_time += GameTimer.GetElapsedSecond();

	if (_combo_reset_time >= 3.0f)
	{
		_combo = 0;
		_combo_reset_time  = 0.0f;
	}

	return 0;
}

void SceneManager::Draw()
{
	GraphicsDevice.Clear(Color_CornflowerBlue);
	GraphicsDevice.BeginScene();

	_scene->Draw3D();

	SpriteBatch.Begin();

	_scene->Draw2D();

	SpriteBatch.End();

	GraphicsDevice.EndScene();
}

void SceneManager::AddCombo()
{
	_combo_reset_time = 0.0f;
	_combo += 1;
	MaximumCombo();
}

void SceneManager::SetCombo(int combo)
{
	if (combo < 0) return;
	this->_combo = combo;
}

int SceneManager::GetCombo()
{
	return this->_combo;
}

int SceneManager::MaximumCombo()
{
	if (_combo >= _max_combo)
		_max_combo = _combo;

	return _max_combo;
}

void SceneManager::AddDeathEnemy() {
	_count ++;
}

void SceneManager::SetDeathEnemy(int count) {
	if (count < 0) return;
	this->_count = count;
}

int SceneManager::GetDeathEnemy() {
	return _count;
}
