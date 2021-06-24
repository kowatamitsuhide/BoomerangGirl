#include"EnemyBase.h"
#include "../../EnemyManeger.h"
#include "../../../Data/MyAlgorithm.h"
EnemyBase::EnemyBase()
{
}

EnemyBase::~EnemyBase()
{
}
bool EnemyBase::Initialize(string _model_name,Vector3 position, Vector3 speed, int hp) {

	_model = GraphicsDevice.CreateAnimationModelFromFile(ConvertStringFileName(_model_name));
	SimpleShape shape;
	shape.Type = Shape_Box;

	shape.Width = 1;
	shape.Height = 1;
	shape.Length = 1;

	Material mtrl;
	mtrl.Diffuse  = Color(Vector3_One);
	mtrl.Ambient  = Color(Vector3_One);
	mtrl.Specular = Color(Vector3_One);

	Material _enemy_mtrl;
	_enemy_mtrl.Diffuse  = Color(Vector3_One);
	_enemy_mtrl.Ambient  = Color(Vector3_One / half);
	_enemy_mtrl.Specular = Color(Vector3_One);
	_enemy_mtrl.Power = 1.0f;

	_collision = GraphicsDevice.CreateModelFromSimpleShape(shape);
	_collision->SetScale(0.8);
	_collision->SetMaterial(mtrl);

	_position = position;
	_model->SetPosition(_position);
	_model->SetMaterial(_enemy_mtrl);
	_model->SetRotation(Vector3_Zero);

	_hp = hp;
	_hp += PlusHp();
	_speed.z = speed.z;

	player_pos = Vector3_Zero;
	return true;
}

int EnemyBase::Update(PlayerManager* playermanager) {
	IsDamage();
	return 0;
}
void EnemyBase::Draw() {
	_model->Draw();
}

int EnemyBase::PlusHp() {
	if (SceneManager::Instance().GetDeathEnemy() % DIST_ENEMY_NUM == REMAINDER)
		_hp++;

	return _hp;
}

void EnemyBase::Damage() {

	_combo = SceneManager::Instance().GetCombo();
	if (_combo >= 0 && _combo < _100COMBO)
		_add_damage = FIRST;

	else if (_combo >= _100COMBO && _combo < _200COMBO)
		_add_damage = SECOND;

	else if (_combo >= _200COMBO && _combo < _300COMBO)
		_add_damage = THIRD;

	else if (_combo >= _300COMBO)
 		_add_damage = FOURTH;

	_hp -= FIRST * _add_damage;
	damage_flag = true;
}

bool EnemyBase::IsDamage() {
	if (damage_flag && damage_frame < DAMAGE_STOP_FRAME) {
		damage_frame++;
		return true;
	}
	else {
		damage_flag = false;
		return false;
	}
}

int EnemyBase::AutoDead()
{
	//!自動削除時間フラグから返ってきた値によって値を返す
	if (!IsDead()) {
		_destroy_time++;
	}
	else {
		return DESTROY;
	}
	return LIVING;
}

bool EnemyBase::IsDead()
{
	if (_destroy_time > AUTODEADTIME)return true;
	return false;
}