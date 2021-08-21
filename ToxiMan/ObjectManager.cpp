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
	this->m_ID--;
}

v2f ObjectManager::GetObjectPosition()
{
	return m_shape.getPosition();
}

v2f ObjectManager::GetObjectSize() 
{
	return m_shape.getSize();
}

void ObjectManager::CreateStaticBox(Shape& shape) 
{
	is_delete = false;
	m_name = "static_object";// +ObjectZeroID;
	m_ID = ObjectZeroID;
	ObjectZeroID++;
	m_shape = System::CreateShape(
		shape.getPosition(), 
		shape.getSize(), 
		-8, Color::Black, 
		Color::Blue
	);
	m_body = World::CreateBodyBox(m_shape, m_name);
	//cout << "Create Object S " << m_ID << endl;
	//cout << "Object " << m_ID << "  POS:  " << m_shape.getPosition().x << "  " << m_shape.getPosition().y << endl;
}

bool ObjectManager::Check_is_delete()
{
	return is_delete;
}

void ObjectManager::CreateStaticBox(Json& json)
{
	is_delete = false;
	m_name = "static_object";// +ObjectZeroID;
	m_ID = json["ID"].get<uint>();
	ObjectZeroID++;
	m_shape = System::CreateShape(
		v2f(json["PosX"].get<float>(), json["PosY"].get<float>()),
		v2f(json["SizeX"].get<float>(), json["SizeY"].get<float>()),
		-8,
		Color::Black,
		Color::Blue
	);
	m_body = World::CreateBodyBox(m_shape, m_name);
	//cout << "Create Object J " << m_ID  << endl;
	//cout << "Object " << m_ID << "  POS:  " << m_shape.getPosition().x << "  " << m_shape.getPosition().y << endl;
}

void ObjectManager::DeleteObject()
{
	is_delete = true;
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

Shape ObjectManager::GetShape()
{
	return m_shape;
}

//b2Body* ObjectManager::GetName()
//{
//	return m_body;
//}

void ObjectManager::CreateTextureBoxBeck(Shape& shape)
{
	is_delete = false;
	m_name = "beck_object";// + ObjectBeckID;
	m_ID = ObjectBeckID;
	ObjectBeckID++;
	m_shape = System::CreateShape(/*System::cur_p*/shape.getPosition(), shape.getSize(), -3, Color::Yellow, Color::Blue);
	//m_body = nullptr;
	cout << "Create Object S " << m_ID << endl;
	cout << "Object " << m_ID << "  POS:  " << m_shape.getPosition().x << "  " << m_shape.getPosition().y << endl;
}

void ObjectManager::CreateTextureBoxBeck(Json& json)
{
	is_delete = false;
	m_name = "beck_object";//json["Name"].get<string>();
	m_ID = json["ID"].get<uint>();
	ObjectBeckID++;
	m_shape = System::CreateShape(
		v2f(json["PosX"].get<float>(), json["PosY"].get<float>()),
		v2f(json["SizeX"].get<float>(), json["SizeX"].get<float>()),
		-3, 
		Color::Yellow, 
		Color::Blue
	);
	//m_body = nullptr;
	//cout << "Create Object S " << m_ID << endl;
	//cout << "Object " << m_ID << "  POS:  " << m_shape.getPosition().x << "  " << m_shape.getPosition().y << endl;
}

void ObjectManager::CreateTextureBoxFront(Shape& shape)
{
	is_delete = false;
	m_name = "front_object";// +ObjectFrontID;
	m_ID = ObjectFrontID;
	ObjectFrontID++;
	m_shape = System::CreateShape(/*System::cur_p*/shape.getPosition(), shape.getSize(), -3, Color::Green, Color::Blue);
	//m_body = nullptr;
	//cout << "Create Object S " << m_ID << endl;
	//cout << "Object " << m_ID << "  POS:  " << m_shape.getPosition().x << "  " << m_shape.getPosition().y << endl;
}

void ObjectManager::CreateTextureBoxFront(Json& json)
{
	is_delete = false;
	m_name = "front_object";//json["Name"].get<string>();
	m_ID = json["ID"].get<uint>();
	ObjectBeckID++;
	m_shape = System::CreateShape(
		v2f(json["PosX"].get<float>(), json["PosY"].get<float>()),
		v2f(json["SizeX"].get<float>(), json["SizeX"].get<float>()),
		-3,
		Color::Green,
		Color::Blue
	);
	//m_body = nullptr;
	//cout << "Create Object S " << m_ID << endl;
	//cout << "Object " << m_ID << "  POS:  " << m_shape.getPosition().x << "  " << m_shape.getPosition().y << endl;
}

