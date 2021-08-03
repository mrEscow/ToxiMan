#include "ObjectManager.h"

uint  ObjectManager::ObjectID{ 0 };

void ObjectManager::CreateStaticBox64() {
	m_name = "object_" + ObjectID++;
	m_shape = System::CreateShape(System::cur_p_wnd, v2f(64, 64), -3, Color::Black, Color::Blue);
	m_body = World::CreateBodyBox(m_shape,m_name);
}