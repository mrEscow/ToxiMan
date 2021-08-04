#include "ObjectManager.h"

uint  ObjectManager::ObjectID{ 0 };
//const char* ObjectManager::name;

uint ObjectManager::GetObjectID()
{
	return m_ID;
}

void ObjectManager::SetNewID()
{
	m_ID-=1;
}

v2f ObjectManager::GetObjectPosition()
{
	return m_shape.getPosition();
}

v2f ObjectManager::GetObjectSize() {
	return m_shape.getSize();
}

void ObjectManager::CreateStaticBox64() 
{
	m_name = "object_" + ObjectID;
	m_ID = ObjectID;
	ObjectID++;
	m_shape = System::CreateShape(System::cur_p, v2f(64, 64), -3, Color::Black, Color::Blue);
	m_body = World::CreateBodyBox(m_shape, m_name);
	cout << "Object " << m_ID << "  POS:  " << m_shape.getPosition().x << "  " << m_shape.getPosition().y << endl;
}

void ObjectManager::DeleteObject()
{
}

void ObjectManager::Action()
{
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

