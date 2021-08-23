#include "Level.h"


void Level::LoadLevel(LevelNumber& number)
{
	System::resources.texture.LoadForArhitect();

	System::resources.texture.LoadLevel_0();

	m_firstPos = v2f(500, 1750);
	m_size_map = v2f(80, 30);

	m_objectListBack = m_jsonSM.LoadVecObject("Save/file_back.json", number);
	m_objectListZero = m_jsonSM.LoadVecObject("Save/file_zero.json", number);
	m_objectListFront = m_jsonSM.LoadVecObject("Save/file_front.json", number);

	m_jsonSM.DeleteJsonFile("file_back.json", number);
	m_jsonSM.DeleteJsonFile("file_zero.json", number);
	m_jsonSM.DeleteJsonFile("file_front.json", number);
}
//----------------------------------------------------------------------
Level::Level(LevelNumber& number, GameSettings& game_settings)
{



	m_ptr_number = &number;
	m_map_ptr = new Map(number);

	LoadLevel(number);


	
	m_ptr_player = new Player(m_firstPos, m_size_map);
	m_ptr_arhitevt = new Architect(*m_map_ptr,m_objectListBack, m_objectListZero, m_objectListFront, m_size_map, game_settings);

	is_from_arhitetc = false;
	is_reset = false;
	
	shaderBg5_a.loadFromMemory
	(
		"uniform vec2 offset;"

		"void main() {"
		"    gl_Position = gl_ProjectionMatrix * gl_ModelViewMatrix * gl_Vertex;"
		"    gl_TexCoord[0] = gl_TextureMatrix[0] * gl_MultiTexCoord0;"
		"    gl_TexCoord[0].x = gl_TexCoord[0].x + offset.x;"
		"    gl_TexCoord[0].y = gl_TexCoord[0].y + offset.y;"
		"    gl_FrontColor = gl_Color;"
		"}"
		, sf::Shader::Vertex
	);
	shaderBg5_b.loadFromMemory
	(
		"uniform vec2 offset;"

		"void main() {"
		"    gl_Position = gl_ProjectionMatrix * gl_ModelViewMatrix * gl_Vertex;"
		"    gl_TexCoord[0] = gl_TextureMatrix[0] * gl_MultiTexCoord0;"
		"    gl_TexCoord[0].x = gl_TexCoord[0].x + offset.x;"
		"    gl_TexCoord[0].y = gl_TexCoord[0].y + offset.y;"
		"    gl_FrontColor = gl_Color;"
		"}"
		, sf::Shader::Vertex
	);
	shaderBg5_c.loadFromMemory
	(
		"uniform vec2 offset;"

		"void main() {"
		"    gl_Position = gl_ProjectionMatrix * gl_ModelViewMatrix * gl_Vertex;"
		"    gl_TexCoord[0] = gl_TextureMatrix[0] * gl_MultiTexCoord0;"
		"    gl_TexCoord[0].x = gl_TexCoord[0].x + offset.x;"
		"    gl_TexCoord[0].y = gl_TexCoord[0].y + offset.y;"
		"    gl_FrontColor = gl_Color;"
		"}"
		, sf::Shader::Vertex
	);
	shaderBg5_d.loadFromMemory
	(
		"uniform vec2 offset;"

		"void main() {"
		"    gl_Position = gl_ProjectionMatrix * gl_ModelViewMatrix * gl_Vertex;"
		"    gl_TexCoord[0] = gl_TextureMatrix[0] * gl_MultiTexCoord0;"
		"    gl_TexCoord[0].x = gl_TexCoord[0].x + offset.x;"
		"    gl_TexCoord[0].y = gl_TexCoord[0].y + offset.y;"
		"    gl_FrontColor = gl_Color;"
		"}"
		, sf::Shader::Vertex
	);
	shaderBg5_e.loadFromMemory
	(
		"uniform vec2 offset;"

		"void main() {"
		"    gl_Position = gl_ProjectionMatrix * gl_ModelViewMatrix * gl_Vertex;"
		"    gl_TexCoord[0] = gl_TextureMatrix[0] * gl_MultiTexCoord0;"
		"    gl_TexCoord[0].x = gl_TexCoord[0].x + offset.x;"
		"    gl_TexCoord[0].y = gl_TexCoord[0].y + offset.y;"
		"    gl_FrontColor = gl_Color;"
		"}"
		, sf::Shader::Vertex
	);

	offsetBg5_a = v2f(0, 0);;
	offsetBg5_b = v2f(0, 0);;
	offsetBg5_c = v2f(0, 0);;
	offsetBg5_d = v2f(0, 0);;
	offsetBg5_e = v2f(0, 0);;

	m_bg5_a = System::CreateShape(v2f(((64 * m_size_map.x) / 2) - 32, ((64 * m_size_map.y ) / 2 ) - 32), v2f(64 * m_size_map.x + 500, 64 * m_size_map.y), System::resources.texture.bg5_a);
	m_bg5_b = System::CreateShape(v2f(((64 * m_size_map.x) / 2) - 32, ((64 * m_size_map.y ) / 2 ) - 32), v2f(64 * m_size_map.x + 500, 64 * m_size_map.y), System::resources.texture.bg5_b);
	m_bg5_c = System::CreateShape(v2f(((64 * m_size_map.x) / 2) - 32, ((64 * m_size_map.y ) / 2 ) - 32), v2f(64 * m_size_map.x + 500, 64 * m_size_map.y), System::resources.texture.bg5_c);
	m_bg5_d = System::CreateShape(v2f(((64 * m_size_map.x) / 2) - 32, ((64 * m_size_map.y ) / 2 ) - 32), v2f(64 * m_size_map.x + 500, 64 * m_size_map.y), System::resources.texture.bg5_d);
	m_bg5_e = System::CreateShape(v2f(((64 * m_size_map.x) / 2) - 32, ((64 * m_size_map.y ) / 2 ) - 32), v2f(64 * m_size_map.x + 500, 64 * m_size_map.y), System::resources.texture.bg5_e);

	m_bg5_g = System::CreateShape(v2f(((64 * m_size_map.x) / 2) - 32, ((64 * m_size_map.y ) / 2 ) - 32), v2f(64 * m_size_map.x + 500, 64 * m_size_map.y), System::resources.texture.bg5_g);
}

void Level::Action(StateGame& state_game, StateGame& previous_state, LevelNumber& number)
{
	switch (state_game)
	{
	case StateGame::ON_MAIN_MENU:
		break;
	case StateGame::ON_GAME:
		m_ptr_player->Action(state_game);
		break;
	case StateGame::ON_ARCITECT:
		m_ptr_arhitevt->Action(state_game, previous_state, is_from_arhitetc, m_jsonSM, number);
		break;
	default:
		break;
	}
}

void Level::Update(StateGame& state_game, LevelNumber& number)
{
	if (is_reset) {
		cout << "DEAD" << endl;
		offsetBg5_a = v2f(0, 0);
		offsetBg5_b = v2f(0, 0);
		offsetBg5_c = v2f(0, 0);
		offsetBg5_d = v2f(0, 0);
		offsetBg5_e = v2f(0, 0);
		is_reset = false;
	}

	float value = 100000;

	if (System::cam.getCenter().x > System::scr_w / 2 && System::cam.getCenter().x < 64 * m_size_map.x - 32 - (System::scr_w / 2)) 
		offsetBg5_a.x += m_ptr_player->GetBody()->GetLinearVelocity().x / (5 * value);
	if (System::cam.getCenter().y < 64 * m_size_map.y - 32 - (System::scr_h / 2) && System::cam.getCenter().y > System::scr_h / 2)
		offsetBg5_a.y += m_ptr_player->GetBody()->GetLinearVelocity().y / (5 * value);
	shaderBg5_a.setUniform("offset", offsetBg5_a);

	if (System::cam.getCenter().x > System::scr_w / 2 && System::cam.getCenter().x < 64 * m_size_map.x - 32 - (System::scr_w / 2))
		offsetBg5_b.x += m_ptr_player->GetBody()->GetLinearVelocity().x / (4 * value);
	if (System::cam.getCenter().y < 64 * m_size_map.y - 32 - (System::scr_h / 2) && System::cam.getCenter().y > System::scr_h / 2)
		offsetBg5_b.y += m_ptr_player->GetBody()->GetLinearVelocity().y / (4 * value);
	shaderBg5_b.setUniform("offset", offsetBg5_b);

	if (System::cam.getCenter().x > System::scr_w / 2 && System::cam.getCenter().x < 64 * m_size_map.x - 32 - (System::scr_w / 2))
		offsetBg5_c.x += m_ptr_player->GetBody()->GetLinearVelocity().x / (3 * value);
	if (System::cam.getCenter().y < 64 * m_size_map.y - 32 - (System::scr_h / 2) && System::cam.getCenter().y > System::scr_h / 2)
		offsetBg5_c.y += m_ptr_player->GetBody()->GetLinearVelocity().y / (3 * value);
	shaderBg5_c.setUniform("offset", offsetBg5_c);

	if (System::cam.getCenter().x > System::scr_w / 2 && System::cam.getCenter().x < 64 * m_size_map.x - 32 - (System::scr_w / 2))
		offsetBg5_d.x += m_ptr_player->GetBody()->GetLinearVelocity().x / (2 * value);
	if (System::cam.getCenter().y < 64 * m_size_map.y - 32 - (System::scr_h / 2) && System::cam.getCenter().y > System::scr_h / 2)
		offsetBg5_d.y += m_ptr_player->GetBody()->GetLinearVelocity().y / (2 * value);
	shaderBg5_d.setUniform("offset", offsetBg5_d);

	if (System::cam.getCenter().x > System::scr_w / 2 && System::cam.getCenter().x < 64 * m_size_map.x - 32 - (System::scr_w / 2))
		offsetBg5_e.x += m_ptr_player->GetBody()->GetLinearVelocity().x / (1 * value);
	if (System::cam.getCenter().y < 64 * m_size_map.y - 32 - (System::scr_h / 2) && System::cam.getCenter().y > System::scr_h / 2)
		offsetBg5_e.y += m_ptr_player->GetBody()->GetLinearVelocity().y / (1 * value);
	shaderBg5_e.setUniform("offset", offsetBg5_e);

	if (is_from_arhitetc) {

		m_objectListBack = m_jsonSM.LoadVecObject("file_back.json", number);
		m_objectListZero = m_jsonSM.LoadVecObject("file_zero.json", number);
		m_objectListFront = m_jsonSM.LoadVecObject("file_front.json", number);

		m_jsonSM.DeleteJsonFile("file_back.json", number);
		m_jsonSM.DeleteJsonFile("file_zero.json", number);
		m_jsonSM.DeleteJsonFile("file_front.json", number);

		is_from_arhitetc = false;
	}

	for (auto& object : m_objectListBack)
		object.Update("objectListBack");
	for (auto& object : m_objectListZero)
		object.Update("objectListZero");

	switch (state_game)
	{
	case StateGame::ON_MAIN_MENU:
		break;
	case StateGame::ON_GAME:
		System::cam.reset(sf::FloatRect(0, 0, System::scr_w, System::scr_h));
		System::cam.setCenter(m_ptr_player->GetPosCam());
		System::wnd.setView(System::cam);
		System::zoom /= System::zoom;
		System::zoom = 1;
		m_ptr_player->Update(is_reset);
		break;
	case StateGame::ON_ARCITECT:
		m_ptr_arhitevt->Update();
		break;
	default:
		break;
	}

	for (auto& object : m_objectListFront)
		object.Update("objectListFront");
}

void Level::Draw(StateGame& state_game,LevelNumber& number)
{
	System::wnd.draw(m_bg5_g);

	System::wnd.draw(m_bg5_a, &shaderBg5_a);
	System::wnd.draw(m_bg5_b, &shaderBg5_b);
	System::wnd.draw(m_bg5_c, &shaderBg5_c);
	System::wnd.draw(m_bg5_d, &shaderBg5_d);
	System::wnd.draw(m_bg5_e, &shaderBg5_e);
	
	switch (state_game)
	{
	case StateGame::ON_MAIN_MENU:
		break;
	case StateGame::ON_GAME:
		for (auto& object : m_objectListBack)
			if (System::IsShapeInCamera(object.GetShape()))
				object.Draw();
		for (auto& object : m_objectListZero)
			if (System::IsShapeInCamera(object.GetShape()))
				object.Draw();
		m_ptr_player->Draw();
		for (auto& object : m_objectListFront)
			if (System::IsShapeInCamera(object.GetShape()))
				object.Draw();
		break;
	case StateGame::ON_ARCITECT:
		for (auto& object : m_objectListBack)
				object.Draw();
		for (auto& object : m_objectListZero)
				object.Draw();
		for (auto& object : m_objectListFront)
				object.Draw();
		m_ptr_arhitevt->Draw(state_game, m_ptr_player);
		break;
	default:
		break;
	}		
}

v2f Level::GetPositionPlayer()
{
	return m_ptr_player->GetPosition();
}

Level::~Level()
{
	for (auto &obj : m_objectListBack) 
		m_jsonSM.SaveObject(obj, "file_back.json", *m_ptr_number);
	
	for (auto &obj : m_objectListZero) 
		m_jsonSM.SaveObject(obj, "file_zero.json", *m_ptr_number);
	
	for (auto &obj : m_objectListFront) 
		m_jsonSM.SaveObject(obj, "file_front.json", *m_ptr_number);
	
	m_jsonSM.DeleteJsonFile("Save/file_back.json", *m_ptr_number);
	m_jsonSM.DeleteJsonFile("Save/file_zero.json", *m_ptr_number);
	m_jsonSM.DeleteJsonFile("Save/file_front.json", *m_ptr_number);

	for (auto& obj : m_objectListBack) 
		m_jsonSM.SaveObject(obj, "Save/file_back.json", *m_ptr_number);
	
	for (auto& obj : m_objectListZero) 
		m_jsonSM.SaveObject(obj, "Save/file_zero.json", *m_ptr_number);
	
	for (auto& obj : m_objectListFront) 
		m_jsonSM.SaveObject(obj, "Save/file_front.json", *m_ptr_number);
	
	delete m_ptr_player;
	delete m_ptr_arhitevt;
	delete m_map_ptr;

	
}
