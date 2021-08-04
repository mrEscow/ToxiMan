#pragma once
#include"System.h"
#include"World.h"
#include "GameStates.h"
class ObjectManager
{
private:

	uint m_ID;
	const char* m_name;
	Shape m_shape;
	b2Body *m_body;

public:

	static uint ObjectBeckID;
	static uint ObjectZeroID;
	static uint ObjectFrontID;

	uint GetObjectID();
	void SetNewID();
	v2f GetObjectPosition();
	v2f GetObjectSize();
	void CreateStaticBox(Shape& shape);
	void CreateTextureBoxBeck(Shape& shape);
	void CreateTextureBoxFront(Shape& shape);
	void DeleteObject();
	void Action();
	void Update(string vecName);
	void Draw();
	//~Architect();
};

