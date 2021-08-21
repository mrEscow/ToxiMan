#pragma once
#include"System.h"
#include"World.h"
#include "GameStates.h"
class ObjectManager
{
private:
public:
	uint m_ID;
	const char* m_name;

	Shape m_shape;
	b2Body *m_body;

	static uint ObjectBeckID;
	static uint ObjectZeroID;
	static uint ObjectFrontID;

	bool is_delete;

	uint GetObjectID();
	Shape GetShape();	
	//b2Body* GetBoby();
	void SetNewID();

	v2f GetObjectPosition();
	v2f GetObjectSize();

	bool Check_is_delete();

	void CreateStaticBox(Shape& shape);
	void CreateStaticBox(Json& json);

	void CreateTextureBoxBeck(Shape& shape);
	void CreateTextureBoxBeck(Json& json);

	void CreateTextureBoxFront(Shape& shape);
	void CreateTextureBoxFront(Json& json);

	void DeleteObject();
	void Action();
	void Update(string vecName);
	void Draw();

};

