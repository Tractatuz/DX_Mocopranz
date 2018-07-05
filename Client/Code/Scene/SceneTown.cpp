#include "stdafx.h"
#include "SceneTown.h"

// for Test (����)
#include "ResourceMgr.h"
#include "ObjectMgr.h"
#include "Export_Function_Mgr.h"
#include "VIBufferCube.h"
#include "ShaderColor.h"
#include "Terrain.h"

#include "Object.h"

#include "../Mgr/ObjectFactory.h"

SceneTown::SceneTown()
{
}

SceneTown::~SceneTown()
{
}

HRESULT SceneTown::Init()
{
	Engine::Scene::Init();


	// for Test (����)
	Engine::ShaderColor* pShader = Engine::ShaderColor::Create();
	Engine::GetResourceMgr()->AddResource(
		Engine::ResourceMgr::RESOURCE_ATTRI_STATIC
		, Engine::ResourceMgr::RESOURCE_TYPE_SHADER
		, L"Test_Shader_Color"
		, pShader);

	Engine::VIBufferCube* pVIBufferCube = Engine::VIBufferCube::Create();
	Engine::GetResourceMgr()->AddResource(
		Engine::ResourceMgr::RESOURCE_ATTRI_STATIC
		, Engine::ResourceMgr::RESOURCE_TYPE_BUFFER
		, L"Test_Buffer_Cube"
		, pVIBufferCube);

	Engine::Terrain* pTerrain = Engine::Terrain::Create(30, 30);
	Engine::GetResourceMgr()->AddResource(
		Engine::ResourceMgr::RESOURCE_ATTRI_STATIC
		, Engine::ResourceMgr::RESOURCE_TYPE_BUFFER
		, L"Test_Buffer_Terrain"
		, pTerrain);
	

	// TestObject
	Engine::Object* pCreatedObj
		= ObjectFactory::GetInstance()->CreateObject(ObjectFactory::EObjectID::OBJECT_ID_TEST);
	pCreatedObj->SetWorldMatrix(D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	Engine::GetObjectMgr()->AddObj(
		Engine::Scene::ELayerType::LAYER_TYPE_GAMELOGIC
		, pCreatedObj);

	pCreatedObj
		= ObjectFactory::GetInstance()->CreateObject(ObjectFactory::EObjectID::OBJECT_ID_TEST);
	pCreatedObj->SetWorldMatrix(D3DXVECTOR3(10.0f, 0.0f, 0.0f));
	Engine::GetObjectMgr()->AddObj(
		Engine::Scene::ELayerType::LAYER_TYPE_GAMELOGIC
		, pCreatedObj);

	pCreatedObj
		= ObjectFactory::GetInstance()->CreateObject(ObjectFactory::EObjectID::OBJECT_ID_TEST);
	pCreatedObj->SetWorldMatrix(D3DXVECTOR3(0.0f, 0.0f, 10.0f));
	Engine::GetObjectMgr()->AddObj(
		Engine::Scene::ELayerType::LAYER_TYPE_GAMELOGIC
		, pCreatedObj);

	pCreatedObj
		= ObjectFactory::GetInstance()->CreateObject(ObjectFactory::EObjectID::OBJECT_ID_TEST);
	pCreatedObj->SetWorldMatrix(D3DXVECTOR3(0.0f, 10.0f, 0.0f));
	Engine::GetObjectMgr()->AddObj(
		Engine::Scene::ELayerType::LAYER_TYPE_GAMELOGIC
		, pCreatedObj);

	// Terrain
	pCreatedObj
		= ObjectFactory::GetInstance()->CreateObject(ObjectFactory::EObjectID::OBJECT_ID_TERRAIN);
	Engine::GetObjectMgr()->AddObj(
		Engine::Scene::ELayerType::LAYER_TYPE_BACK
		, pCreatedObj);

	// Camera
	Engine::GetObjectMgr()->AddObj(
		Engine::Scene::ELayerType::LAYER_TYPE_GAMELOGIC
		, ObjectFactory::GetInstance()->CreateObject(ObjectFactory::EObjectID::OBJECT_ID_CAMERA_DYNAMIC));
	

	return S_OK;
}

void SceneTown::Update()
{
	Engine::Scene::Update();
}

void SceneTown::Render()
{
	Engine::Scene::Render();
}

void SceneTown::Release()
{
	Engine::Scene::Release();
}