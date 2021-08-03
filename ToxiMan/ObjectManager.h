#pragma once
#include"System.h"
#include"World.h"
class ObjectManager
{
private:
	static uint ObjectID;
	const char* m_name;
	Shape m_shape;
	b2Body *m_body;

public:
	
	static uint GetObjectID();
	void CreateStaticBox64();
	void Action();
	void Update();
	void Draw();
	//~Architect();
};

