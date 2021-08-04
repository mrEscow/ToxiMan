#pragma once
#include"System.h"
#include"World.h"
class ObjectManager
{
private:

	uint m_ID;
	const char* m_name;
	Shape m_shape;
	b2Body *m_body;

public:

	static uint ObjectID;

	uint GetObjectID();
	void SetNewID();
	v2f GetObjectPosition();
	v2f GetObjectSize();
	void CreateStaticBox(Shape& shape);
	void DeleteObject();
	void Action();
	void Update();
	void Draw();
	//~Architect();
};

