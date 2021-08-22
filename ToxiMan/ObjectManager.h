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
	bool is_delete;

public:

	static uint ObjectBeckID;
	static uint ObjectZeroID;
	static uint ObjectFrontID;

	void CreateStaticBox(Shape& shape);
	void CreateStaticBox(Json& json);

	void CreateTextureBoxBack(Shape& shape);
	void CreateTextureBoxBack(Json& json);

	void CreateTextureBoxFront(Shape& shape);
	void CreateTextureBoxFront(Json& json);

	const char* GetName();

	Shape& GetShape();
	b2Body* GetBoby();

	uint GetObjectID();

	v2f GetObjectPosition();
	v2f GetObjectSize();

	void DeleteObject();
	bool Check_is_delete();

	void Update(string vecName);
	void Draw();
};

