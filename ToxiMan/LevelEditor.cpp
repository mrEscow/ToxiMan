#include "LevelEditor.h"

LevelEditor::LevelEditor()
{
	for (UINT32 i = 0; i <= GameSettings::GetGemeLevels(); i++)
	{
		JsonSaveMenager TJSM;
		Level tLevel;
		tLevel.m_Map = TJSM.LoadMap("", i);
		Levels.insert(pair<uint32, Level>(i, tLevel));
	}

	m_Architect = make_unique<Architect>(Levels);
}

void LevelEditor::Update()
{
	m_Architect->Update();
}

void LevelEditor::Draw()
{
	m_Architect->Draw();
}

void LevelEditor::Action()
{
	m_Architect->Action();
}

LevelEditor::~LevelEditor()
{
}
