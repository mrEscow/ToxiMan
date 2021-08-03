#include "ObjectManager.h"

uint  ObjectManager::ObjectID{ 0 };
//const char* ObjectManager::name;

void ObjectManager::CreateStaticBox64() 
{
	m_name = "object_" + ObjectID;
	ObjectID++;
	m_shape = System::CreateShape(System::cur_p, v2f(64, 64), -3, Color::Black, Color::Blue);
	m_body = World::CreateBodyBox(m_shape, m_name);
	
}

uint ObjectManager::GetObjectID()
{
	return ObjectID;
}

void ObjectManager::Update()
{
	m_shape.setPosition(m_body->GetPosition().x * SCALE, m_body->GetPosition().y * SCALE);
	m_shape.setRotation(m_body->GetAngle() * DEG);
}

void ObjectManager::Draw()
{
	System::wnd.draw(m_shape);
}

