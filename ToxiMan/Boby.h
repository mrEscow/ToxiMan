#pragma once
#include "System.h"
class BodyBox
{
private:
public:
	b2PolygonShape m_polygonShape{};
	//b2CircleShape b_circle;
	b2BodyDef m_bodyDef{};
	b2Body* m_body{};

	BodyBox() {

	}

	float GetPositionX() {
		return m_body->GetPosition().x * SCALE;
	}
	float GetPositionY() {
		return m_body->GetPosition().y * SCALE;
	}
	float GetAngel() {
		return m_body->GetAngle() * DEG;
	}

};


