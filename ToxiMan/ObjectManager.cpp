#include "ObjectManager.h"

uint  ObjectManager::ObjectBeckID{ 0 };
uint  ObjectManager::ObjectZeroID{ 0 };
uint  ObjectManager::ObjectFrontID{ 0 };


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

void ObjectManager::CreateStaticBox(Shape& shape) 
{
	m_name = "object_" + ObjectZeroID;
	m_ID = ObjectZeroID;
	ObjectZeroID++;
	m_shape = System::CreateShape(System::cur_p, shape.getSize(), -3, Color::Black, Color::Blue);
	m_body = World::CreateBodyBox(m_shape, m_name);
	//cout << "Object " << m_ID << "  POS:  " << m_shape.getPosition().x << "  " << m_shape.getPosition().y << endl;
}

void ObjectManager::DeleteObject()
{
}

void ObjectManager::Action()
{
}



void ObjectManager::Update(string vecName)
{
	if (vecName == "objectListBeck") {

	}
	if (vecName == "objectListZero") {
		m_shape.setPosition(m_body->GetPosition().x * SCALE, m_body->GetPosition().y * SCALE);
		m_shape.setRotation(m_body->GetAngle() * DEG);
	}
	if (vecName == "objectListFront") {

	}

}

void ObjectManager::Draw()
{
	System::wnd.draw(m_shape);
}

void ObjectManager::CreateTextureBoxBeck(Shape& shape)
{
	m_name = "object_" + ObjectBeckID;
	m_ID = ObjectBeckID;
	ObjectBeckID++;
	m_shape = System::CreateShape(System::cur_p, shape.getSize(), -3, Color::Yellow, Color::Blue);
	//m_body = World::CreateBodyBox(m_shape, m_name);
}

void ObjectManager::CreateTextureBoxFront(Shape& shape)
{
	m_name = "object_" + ObjectFrontID;
	m_ID = ObjectFrontID;
	ObjectFrontID++;
	m_shape = System::CreateShape(System::cur_p, shape.getSize(), -3, Color::Green, Color::Blue);
	//m_body = World::CreateBodyBox(m_shape, m_name);
}

