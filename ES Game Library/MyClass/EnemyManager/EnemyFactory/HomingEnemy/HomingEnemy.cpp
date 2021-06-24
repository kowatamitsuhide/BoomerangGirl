#include"HomingEnemy.h"

HomingEnemy::HomingEnemy()
{
}

HomingEnemy::~HomingEnemy()
{
}
int HomingEnemy::Update(PlayerManager* player_manager)
{
	//!ホーミング用X座標
	float floor_area_x = _position.x >  _homing_area || _position.x < -_homing_area;
	//!ホーミング用Z座標
	float floor_area_z = _position.z < -_homing_area;

	player_pos = player_manager->PlayerGetPosition();

	if (!EnemyBase::IsDamage()) {
		Move();
		Rotate();
	}

	if (_hp <= 0)
		return EnemyBase::DEATH;

	if (floor_area_x || floor_area_z)
		return EnemyBase::DESTROY;

	_collision->SetPosition(_model->GetPosition());
	_position  = _model->GetPosition();

	return EnemyBase::LIVING;
}

void HomingEnemy::Move() {
	Vector3 delta  = Vector3_Normalize(Vector3(_position - player_pos));
	float speed_index = 0.015f;
	float move_speed = delta.z * speed_index;

	if (_position.z > player_pos.z)
		_model->Move(0, 0, - move_speed);
	else
		_model->Move(0, 0,   move_speed);

}

void HomingEnemy::Rotate() {
	_rotation = MathHelper_Atan2((player_pos.z - _position.z), -(player_pos.x - _position.x)) + 90.0f;
	_model->SetRotation(0.0f, _rotation, 0.0f);
}