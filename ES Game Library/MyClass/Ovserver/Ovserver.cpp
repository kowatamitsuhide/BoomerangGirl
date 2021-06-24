#include"Ovserver.h"
#include"../SceneManager/SceneManager.h"
Ovserver::Ovserver()
{
}

Ovserver::~Ovserver()
{
}

int Ovserver::Update(PlayerManager* playerdata, EnemyManager* enemydata)
{
	ColisionDetection(playerdata, enemydata);
	return 0;
}

void Ovserver::ColisionDetection(PlayerManager* playerdata, EnemyManager* enemydata)
{

	if (playerdata->GetShootState())
	{
		auto a = playerdata->GetBoomerang().GetCollision();

		auto a_pos = a->GetPosition();
		auto a_scale = a->GetScale();
		for (auto enemy : enemydata->GetEnemy())
		{
			auto b = enemy->GetCollision();
			auto b_pos = b->GetPosition();
			auto b_scale = b->GetScale() / 2;
			//! aとbのボックスの当たり判定
			if (a_pos.x - a_scale.x < b_pos.x + b_scale.x &&
				a_pos.x + a_scale.x > b_pos.x - b_scale.x &&
				a_pos.y - a_scale.y < b_pos.y + b_scale.y &&
				a_pos.y + a_scale.y > b_pos.y - b_scale.y &&
				a_pos.z - a_scale.z < b_pos.z + b_scale.z &&
				a_pos.z + a_scale.z > b_pos.z - b_scale.z)
			{
				enemydata->OnCollisionEnter(enemy);
				SceneManager::Instance().AddCombo();
			}
		}
	}

	if (playerdata->GetAnimState() != playerdata->DAMAGE)
	{
		auto a_pos = playerdata->GetCollision()->GetPosition();
		auto a_scale = playerdata->GetCollision()->GetScale();
		for (auto enemy : enemydata->GetEnemy())
		{
			auto b = enemy->GetCollision();
			auto b_pos = b->GetPosition();
			auto b_scale = b->GetScale() / 2;
			//! aとbのボックスの当たり判定
			if (a_pos.x - a_scale.x < b_pos.x + b_scale.x &&
				a_pos.x + a_scale.x > b_pos.x - b_scale.x &&
				a_pos.y - a_scale.y < b_pos.y + b_scale.y &&
				a_pos.y + a_scale.y > b_pos.y - b_scale.y &&
				a_pos.z - a_scale.z < b_pos.z + b_scale.z &&
				a_pos.z + a_scale.z > b_pos.z - b_scale.z)
			{
				playerdata->OnCollisionEnter();
				break;
			}
		}
	}
}
