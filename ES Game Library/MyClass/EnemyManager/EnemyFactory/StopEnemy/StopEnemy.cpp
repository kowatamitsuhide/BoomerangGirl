#include"StopEnemy.h"
StopEnemy::StopEnemy()
{
}

StopEnemy::~StopEnemy()
{
}

int StopEnemy::Update(PlayerManager* player_manager)
{
	if (_hp <= 0)
		return EnemyBase::DEATH;

	_collision->SetPosition(_model->GetPosition());
	_position = _model->GetPosition();

	return EnemyBase::LIVING;
}
