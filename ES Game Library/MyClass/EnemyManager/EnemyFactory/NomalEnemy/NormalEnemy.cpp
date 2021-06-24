#include"NormalEnemy.h"

NormalEnemy::NormalEnemy() {

}
NormalEnemy::~NormalEnemy() {

}

int NormalEnemy::Update(PlayerManager* player_manager)
{
	if (!EnemyBase::IsDamage())
		Move();

	if (_hp <= 0)
		return EnemyBase::DEATH;

	if (_position.z <= enemy_living_area_z)
		return EnemyBase::DESTROY;

	_collision->SetPosition(_model->GetPosition());
	_position  = _model->GetPosition();

	return EnemyBase::LIVING;
}

void NormalEnemy::Move() {
	_model->Move(0, 0, -_speed.z);
}