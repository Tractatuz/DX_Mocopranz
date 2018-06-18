#include "stdafx.h"
#include "ObjectFactory.h"

#include "Engine_Define_Check.h"

#include "Object.h"
#include "../Object/TestObject.h"
#include "CameraDynamic.h"

IMPLEMENT_SINGLETON(ObjectFactory)


ObjectFactory::ObjectFactory()
{
}


ObjectFactory::~ObjectFactory()
{

}

Engine::Object* ObjectFactory::CreateObject(const EObjectID & _eObjectID)
{
	Engine::Object* pTargetCreated	= nullptr;

	switch (_eObjectID)
	{
	case EObjectID::OBJECT_ID_TEST :
		pTargetCreated = new TestObject();
		pTargetCreated->Init();
		break;

	case EObjectID::OBJECT_ID_CAMERA_DYNAMIC :
		pTargetCreated = new Engine::CameraDynamic();
		pTargetCreated->Init();
		break;

	default :
		break;
	}

	return pTargetCreated;
}

template<class T>
T* ObjectFactory::CreateObject()
{
	T* pTargetCreated = new T();
	pTargetCreated->Init();
	return pTargetCreated;
}