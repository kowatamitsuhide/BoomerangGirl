#include"FieldManager.h"

FieldManager::FieldManager()
{
	_model = nullptr;
}

FieldManager::~FieldManager()
{

}

bool FieldManager::Initialize()
{
	_model = GraphicsDevice.CreateModelFromFile(_T("MODEL/Floor/floor_0526.X"));

	_model->SetScale(1.0);
	_model->SetPosition(0.0f, 0.0f, 0.0f);
	_model->SetRotation(0.0f, 0.0f, 0.0f);

	if (_model == nullptr)
		return false;

	Material material;
	material.Diffuse = Color(1.0f, 1.0f, 1.0f);
	material.Ambient = Color(1.0f, 1.0f, 1.0f);
	material.Specular = Color(1.0f, 1.0f, 1.0f);
	material.Power = 1.0f;
	_model->SetMaterial(material);

	return true;
}

void FieldManager::Draw()
{
	_model->Draw();
}

Vector3 FieldManager::Position()
{
	return _model->GetPosition();
}