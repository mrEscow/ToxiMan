#pragma once

#include "Architect.h"
#include "Level.h"

class LevelEditor
{
	std::map<UINT32, Level> Levels;
	unique_ptr<Architect> m_Architect;
public:
	LevelEditor();

	void Update();
	void Draw();
	void Action();

	~LevelEditor();
};

