// ▼
#pragma once
#include "World.h"

// Выносим статические поля в глобальную область видимости

float 		World::wind;
float		World::gravity;
b2Vec2		World::worldParam;
b2World*	World::world;
int			World::id;