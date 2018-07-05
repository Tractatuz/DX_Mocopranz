#pragma once

#include "VIBuffer.h"

BEGIN(Engine)


class Camera;
class Layer;
class ENGINE_DLL Terrain : public VIBuffer
{
public:
	static Terrain* Create
	(
		const int _iCntX
		, const int _iCntY
		, const char* _Path = nullptr
	);
private:
	explicit Terrain();
public:
	virtual ~Terrain();


public :
	//GET(int, IndexNum, m_iIndexNum);

public:
	virtual HRESULT	Init(const int _iCntX, const int _iCntZ, const char* _Path = nullptr);
	virtual void	Update();
	virtual void	Render();
protected:
	virtual void	CreateRasterizerState();
protected:
	virtual void	Release();

protected :
	HRESULT LoadHeightMap(const char* _Path);
	void	NormalizeHeightMap();

	HRESULT	Init_Buffer(const int _iCntX, const int _iCntY);

protected:
	struct HeightMapType
	{
		float x, y, z;
	};

protected:
	int		m_iWidth;
	int		m_iHeight;

	HeightMapType* m_pHeightMapTypeInfoArray;
};


END