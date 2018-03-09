#pragma once

#include "Component.h"

BEGIN(Engine)


class ENGINE_DLL Object abstract
{
public:
	enum class EState
	{
		STATE_NONE,

		STATE_IDLE,
		STATE_ALIVE,
		STATE_DIE
	};

protected:
	explicit Object(void);
public:
	virtual ~Object(void) PURE;

public:
	const Component*	GetComponent(const std::wstring& _wstrComponentKey);
	EState				GetObjState() { return m_eObjState; }
protected:
	void				SetObjState(const EState _eState) { m_eObjState = _eState; }

protected:
	virtual HRESULT			Init()			PURE;
	virtual Object::EState	Update()		PURE;
	virtual void			Render()		PURE;
	virtual void			Release()		PURE;


private:
	void	AddDefaultComponent();
protected:
	void	Update_Component();
protected:
	void	Release_Component();


protected:
	typedef std::map<std::wstring, Component*>	MAPCOMPONENT;
	MAPCOMPONENT		m_mapComponent;
	EState				m_eObjState;

protected:
	class Transform*			m_pTransform;

	friend class Layer;
};


END