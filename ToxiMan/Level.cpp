#include "Level.h"

//void Level::NextLevel()
//{
//	m_ptr_GS->NextGameLevel();
//	m_GameLevel = m_ptr_GS->GetGameLevel();
//
//	//clear
//	m_objectListBack.clear();
//	m_objectListZero.clear();
//	m_objectListFront.clear();
//
//	LoadLevel(m_GameLevel);
//}
//
//void Level::LoadLevel(UINT32 GameLevel)
//{
//	
//	cout << "GameLevel: " << GameLevel << endl;
//
//
//	// map
//	//*m_map_ptr = m_jsonSM.LoadMap("Save/MAP.json", GameLevel);
//
//	//m_size_map = static_cast<v2f> (m_map_ptr->GetMapSize());
//
//	//m_StartPos = m_map_ptr->GetStartPos();
//	//m_FinishPos = m_map_ptr->GetFinalPos();
//
//
//	// objects
//	m_objectListBack = m_jsonSM.LoadVecObject("Save/file_back.json", GameLevel);
//	m_objectListZero = m_jsonSM.LoadVecObject("Save/file_zero.json", GameLevel);
//	m_objectListFront = m_jsonSM.LoadVecObject("Save/file_front.json", GameLevel);
//
//
//	m_jsonSM.DeleteJsonFile("file_back.json", GameLevel);
//	m_jsonSM.DeleteJsonFile("file_zero.json", GameLevel);
//	m_jsonSM.DeleteJsonFile("file_front.json", GameLevel);
//
//	// backgraund
//}
////----------------------------------------------------------------------
//Level::Level(GameStates& GS, GameSettings& game_settings)
//{
//	
//	for (uint32_t i = 0; i <= GameSettings::GetGemeLevels(); i++)
//	{
//		std::pair <uint32_t, Map> temp;
//		temp.first = i;
//		temp.second = m_jsonSM.LoadMap("", i);
//		Maps.insert(temp);
//	}
//
//	//for (auto map : Maps) {
//	//	if (GS.GetGameLevel() == map.first)
//	//	{
//	//		map.second.GetFinalPos();
//	//		map.second.GetMapSize();
//	//		map.second.GetName();
//	//		map.second.GetStartPos();
//	//	}
//	//}
//	
//	//m_map_ptr = &Maps[0];
//
//	is_Next_Level = false;
//	m_ptr_GS = &GS;
//	m_GameLevel = GS.GetGameLevel();
//
//	System::resources.texture.LoadForArhitect();
//	System::resources.texture.LoadLevel_0();
//
//	//m_map_ptr = new Map;
//
//	//LoadLevel(m_GameLevel);
//
//
//	//m_ptr_player = new Player(*m_map_ptr, m_StartPos, m_size_map);
//
//
//	cout << "TEST MAP: " << Maps[0].GetName() << endl;
//	cout << "MAPS SIZE: " << Maps.size() << endl;
//	m_ptr_arhitevt = new Architect(Maps, m_objectListBack, m_objectListZero, m_objectListFront, m_size_map, game_settings);
//
//	//m_ptr_Li = new AlgoritmLi(m_ptr_arhitevt, m_ptr_player);
//
//	is_from_arhitetc = false;
//	is_reset = false;
//
//	shaderBg5_a.loadFromMemory
//	(
//		"uniform vec2 offset;"
//
//		"void main() {"
//		"    gl_Position = gl_ProjectionMatrix * gl_ModelViewMatrix * gl_Vertex;"
//		"    gl_TexCoord[0] = gl_TextureMatrix[0] * gl_MultiTexCoord0;"
//		"    gl_TexCoord[0].x = gl_TexCoord[0].x + offset.x;"
//		"    gl_TexCoord[0].y = gl_TexCoord[0].y + offset.y;"
//		"    gl_FrontColor = gl_Color;"
//		"}"
//		, sf::Shader::Vertex
//	);
//	shaderBg5_b.loadFromMemory
//	(
//		"uniform vec2 offset;"
//
//		"void main() {"
//		"    gl_Position = gl_ProjectionMatrix * gl_ModelViewMatrix * gl_Vertex;"
//		"    gl_TexCoord[0] = gl_TextureMatrix[0] * gl_MultiTexCoord0;"
//		"    gl_TexCoord[0].x = gl_TexCoord[0].x + offset.x;"
//		"    gl_TexCoord[0].y = gl_TexCoord[0].y + offset.y;"
//		"    gl_FrontColor = gl_Color;"
//		"}"
//		, sf::Shader::Vertex
//	);
//	shaderBg5_c.loadFromMemory
//	(
//		"uniform vec2 offset;"
//
//		"void main() {"
//		"    gl_Position = gl_ProjectionMatrix * gl_ModelViewMatrix * gl_Vertex;"
//		"    gl_TexCoord[0] = gl_TextureMatrix[0] * gl_MultiTexCoord0;"
//		"    gl_TexCoord[0].x = gl_TexCoord[0].x + offset.x;"
//		"    gl_TexCoord[0].y = gl_TexCoord[0].y + offset.y;"
//		"    gl_FrontColor = gl_Color;"
//		"}"
//		, sf::Shader::Vertex
//	);
//	shaderBg5_d.loadFromMemory
//	(
//		"uniform vec2 offset;"
//
//		"void main() {"
//		"    gl_Position = gl_ProjectionMatrix * gl_ModelViewMatrix * gl_Vertex;"
//		"    gl_TexCoord[0] = gl_TextureMatrix[0] * gl_MultiTexCoord0;"
//		"    gl_TexCoord[0].x = gl_TexCoord[0].x + offset.x;"
//		"    gl_TexCoord[0].y = gl_TexCoord[0].y + offset.y;"
//		"    gl_FrontColor = gl_Color;"
//		"}"
//		, sf::Shader::Vertex
//	);
//	shaderBg5_e.loadFromMemory
//	(
//		"uniform vec2 offset;"
//
//		"void main() {"
//		"    gl_Position = gl_ProjectionMatrix * gl_ModelViewMatrix * gl_Vertex;"
//		"    gl_TexCoord[0] = gl_TextureMatrix[0] * gl_MultiTexCoord0;"
//		"    gl_TexCoord[0].x = gl_TexCoord[0].x + offset.x;"
//		"    gl_TexCoord[0].y = gl_TexCoord[0].y + offset.y;"
//		"    gl_FrontColor = gl_Color;"
//		"}"
//		, sf::Shader::Vertex
//	);
//
//	offsetBg5_a = v2f(0, 0);;
//	offsetBg5_b = v2f(0, 0);;
//	offsetBg5_c = v2f(0, 0);;
//	offsetBg5_d = v2f(0, 0);;
//	offsetBg5_e = v2f(0, 0);;
//
//	m_bg5_a = System::CreateShape(v2f(((64 * m_size_map.x) / 2) - 32, ((64 * m_size_map.y) / 2) - 32), v2f(64 * m_size_map.x + 500, 64 * m_size_map.y), System::resources.texture.bg5_a);
//	m_bg5_b = System::CreateShape(v2f(((64 * m_size_map.x) / 2) - 32, ((64 * m_size_map.y) / 2) - 32), v2f(64 * m_size_map.x + 500, 64 * m_size_map.y), System::resources.texture.bg5_b);
//	m_bg5_c = System::CreateShape(v2f(((64 * m_size_map.x) / 2) - 32, ((64 * m_size_map.y) / 2) - 32), v2f(64 * m_size_map.x + 500, 64 * m_size_map.y), System::resources.texture.bg5_c);
//	m_bg5_d = System::CreateShape(v2f(((64 * m_size_map.x) / 2) - 32, ((64 * m_size_map.y) / 2) - 32), v2f(64 * m_size_map.x + 500, 64 * m_size_map.y), System::resources.texture.bg5_d);
//	m_bg5_e = System::CreateShape(v2f(((64 * m_size_map.x) / 2) - 32, ((64 * m_size_map.y) / 2) - 32), v2f(64 * m_size_map.x + 500, 64 * m_size_map.y), System::resources.texture.bg5_e);
//
//	m_bg5_g = System::CreateShape(v2f(((64 * m_size_map.x) / 2) - 32, ((64 * m_size_map.y) / 2) - 32), v2f(64 * m_size_map.x + 500, 64 * m_size_map.y), System::resources.texture.bg5_g);
//
//
//	// points
//	//m_s_start = System::CreateShape(m_map_ptr->GetStartPos(), v2f(500, 500), Color(0, 0, 0, 255));
//	//m_s_final = System::CreateShape(m_map_ptr->GetFinalPos(), v2f(64, 64), Color(255, 255, 255, 255));
//	m_shader_start.loadFromFile("vertex_shader.vert", "inet2.frag");
//	m_shader_stop.loadFromFile("vertex_shader.vert", "inet2.frag");
//
//	m_ptr_thread = new sf::Thread(&Level::LI, this);
//
//	//m_ptr_thread->launch();
//}
//
//void Level::LI()
//{
//	while (System::wnd.isOpen()) {
//		if (m_ptr_Li->CreateRoad()) // Потом нужно будет сделать CreateRoad(NPC)
//			m_Li_go = m_ptr_Li->GetRoad();
//	}
//}
//
//void Level::Action(StateGame& state_game, StateGame& previous_state, UINT32 GameLevel)
//{
//	if (is_Next_Level) {
//		NextLevel();
//		is_Next_Level = false;
//	}
//
//	switch (state_game)
//	{
//	case StateGame::ON_MAIN_MENU:
//		break;
//	case StateGame::ON_GAME:
//		//m_ptr_player->Action(state_game);
//		break;
//	case StateGame::ON_ARCITECT:
//		m_ptr_arhitevt->Action(state_game, previous_state, is_from_arhitetc, m_jsonSM, GameLevel, is_Next_Level);
//		break;
//	default:
//		break;
//	}
//}
//
//void Level::Update(StateGame& state_game, UINT32 GameLevel)
//{
//	if (!is_Next_Level) {
//		//m_s_final.setPosition(m_map_ptr->GetFinalPos());
//
//		if (is_reset) {
//			cout << "DEAD" << endl;
//			offsetBg5_a = v2f(0, 0);
//			offsetBg5_b = v2f(0, 0);
//			offsetBg5_c = v2f(0, 0);
//			offsetBg5_d = v2f(0, 0);
//			offsetBg5_e = v2f(0, 0);
//			is_reset = false;
//		}
//
//		float value = 100000;
//
//		//if (System::cam.getCenter().x > System::scr_w / 2 && System::cam.getCenter().x < 64 * m_size_map.x - 32 - (System::scr_w / 2))
//		//	offsetBg5_a.x += m_ptr_player->GetBody()->GetLinearVelocity().x / (5 * value);
//		//if (System::cam.getCenter().y < 64 * m_size_map.y - 32 - (System::scr_h / 2) && System::cam.getCenter().y > System::scr_h / 2)
//		//	offsetBg5_a.y += m_ptr_player->GetBody()->GetLinearVelocity().y / (5 * value);
//		//shaderBg5_a.setUniform("offset", offsetBg5_a);
//
//		//if (System::cam.getCenter().x > System::scr_w / 2 && System::cam.getCenter().x < 64 * m_size_map.x - 32 - (System::scr_w / 2))
//		//	offsetBg5_b.x += m_ptr_player->GetBody()->GetLinearVelocity().x / (4 * value);
//		//if (System::cam.getCenter().y < 64 * m_size_map.y - 32 - (System::scr_h / 2) && System::cam.getCenter().y > System::scr_h / 2)
//		//	offsetBg5_b.y += m_ptr_player->GetBody()->GetLinearVelocity().y / (4 * value);
//		//shaderBg5_b.setUniform("offset", offsetBg5_b);
//
//		//if (System::cam.getCenter().x > System::scr_w / 2 && System::cam.getCenter().x < 64 * m_size_map.x - 32 - (System::scr_w / 2))
//		//	offsetBg5_c.x += m_ptr_player->GetBody()->GetLinearVelocity().x / (3 * value);
//		//if (System::cam.getCenter().y < 64 * m_size_map.y - 32 - (System::scr_h / 2) && System::cam.getCenter().y > System::scr_h / 2)
//		//	offsetBg5_c.y += m_ptr_player->GetBody()->GetLinearVelocity().y / (3 * value);
//		//shaderBg5_c.setUniform("offset", offsetBg5_c);
//
//		//if (System::cam.getCenter().x > System::scr_w / 2 && System::cam.getCenter().x < 64 * m_size_map.x - 32 - (System::scr_w / 2))
//		//	offsetBg5_d.x += m_ptr_player->GetBody()->GetLinearVelocity().x / (2 * value);
//		//if (System::cam.getCenter().y < 64 * m_size_map.y - 32 - (System::scr_h / 2) && System::cam.getCenter().y > System::scr_h / 2)
//		//	offsetBg5_d.y += m_ptr_player->GetBody()->GetLinearVelocity().y / (2 * value);
//		//shaderBg5_d.setUniform("offset", offsetBg5_d);
//
//		//if (System::cam.getCenter().x > System::scr_w / 2 && System::cam.getCenter().x < 64 * m_size_map.x - 32 - (System::scr_w / 2))
//		//	offsetBg5_e.x += m_ptr_player->GetBody()->GetLinearVelocity().x / (1 * value);
//		//if (System::cam.getCenter().y < 64 * m_size_map.y - 32 - (System::scr_h / 2) && System::cam.getCenter().y > System::scr_h / 2)
//		//	offsetBg5_e.y += m_ptr_player->GetBody()->GetLinearVelocity().y / (1 * value);
//		//shaderBg5_e.setUniform("offset", offsetBg5_e);
//
//		if (is_from_arhitetc) {
//
//			m_objectListBack = m_jsonSM.LoadVecObject("file_back.json", GameLevel);
//			m_objectListZero = m_jsonSM.LoadVecObject("file_zero.json", GameLevel);
//			m_objectListFront = m_jsonSM.LoadVecObject("file_front.json", GameLevel);
//
//			m_jsonSM.DeleteJsonFile("file_back.json", GameLevel);
//			m_jsonSM.DeleteJsonFile("file_zero.json", GameLevel);
//			m_jsonSM.DeleteJsonFile("file_front.json", GameLevel);
//
//			System::cam.reset(sf::FloatRect(
//				0,
//				0,
//				static_cast<float>(System::scr_w),
//				static_cast<float>(System::scr_h)
//			));
//			//System::cam.move(m_ptr_player->GetPosCam());
//			//System::cam.setCenter(m_ptr_player->GetPosCam());
//			System::wnd.setView(System::cam);
//			System::zoom /= System::zoom;
//			System::zoom = 1;
//
//			is_from_arhitetc = false;
//		}
//
//		for (auto& object : m_objectListBack)
//			object.Update("objectListBack");
//		for (auto& object : m_objectListZero)
//			object.Update("objectListZero");
//
//		switch (state_game)
//		{
//		case StateGame::ON_MAIN_MENU:
//			break;
//		case StateGame::ON_GAME:
//
//			//m_ptr_player->Update(is_reset);
//			break;
//		case StateGame::ON_ARCITECT:
//			m_ptr_arhitevt->Update();
//			break;
//		default:
//			break;
//		}
//
//		for (auto& object : m_objectListFront)
//			object.Update("objectListFront");
//	}
//}
//
//void Level::Draw(StateGame& state_game, UINT32 GameLevel)
//{
//	if (!is_Next_Level) {
//		System::wnd.draw(m_bg5_g);
//
//		System::wnd.draw(m_bg5_a, &shaderBg5_a);
//		System::wnd.draw(m_bg5_b, &shaderBg5_b);
//		System::wnd.draw(m_bg5_c, &shaderBg5_c);
//		System::wnd.draw(m_bg5_d, &shaderBg5_d);
//		System::wnd.draw(m_bg5_e, &shaderBg5_e);
//
//		// for shaders
//		v2f center = System::wnd.getView().getCenter();
//		v2f size = System::wnd.getView().getSize();
//
//		switch (state_game)
//		{
//		case StateGame::ON_MAIN_MENU:
//			break;
//		case StateGame::ON_GAME:
//			for (auto& object : m_objectListBack)
//				if (System::IsShapeInCamera(object.GetShape()))
//					object.Draw();
//			for (auto& object : m_objectListZero)
//				if (System::IsShapeInCamera(object.GetShape()))
//					object.Draw();
//
//
//
//			m_time = m_time + System::time / 1000;
//
//			m_shader_start.setUniform("time", m_time);
//			m_shader_start.setUniform("pos", System::GetPosForShader(m_s_start));
//			m_shader_start.setUniform("size", m_s_start.getSize());
//			System::wnd.draw(m_s_start, &m_shader_start);
//
//			m_shader_stop.setUniform("time", m_time);
//			m_shader_stop.setUniform("pos", System::GetPosForShader(m_s_final));
//			m_shader_stop.setUniform("size", m_s_final.getSize());
//			System::wnd.draw(m_s_final, &m_shader_stop);
//
//			//m_ptr_player->Draw();
//			for (auto& object : m_objectListFront)
//				if (System::IsShapeInCamera(object.GetShape()))
//					object.Draw();
//			break;
//		case StateGame::ON_ARCITECT:
//			for (auto& object : m_objectListBack)
//				object.Draw();
//			for (auto& object : m_objectListZero)
//				object.Draw();
//			for (auto& object : m_objectListFront)
//				object.Draw();
//			m_ptr_arhitevt->Draw(state_game);
//			break;
//		default:
//			break;
//		}
//	}
//
//}
//
//v2f Level::GetPositionPlayer()
//{
//	return v2f(0, 0); //m_ptr_player->GetPosition();
//}
//
//
//
//bool Level::check_lvl()
//{
//	return false;
//}
//
//Level::~Level()
//{
//	for (auto &obj : m_objectListBack) 
//		m_jsonSM.SaveObject(obj, "file_back.json", m_GameLevel);
//	
//	for (auto &obj : m_objectListZero) 
//		m_jsonSM.SaveObject(obj, "file_zero.json", m_GameLevel);
//	
//	for (auto &obj : m_objectListFront) 
//		m_jsonSM.SaveObject(obj, "file_front.json", m_GameLevel);
//	
//	m_jsonSM.DeleteJsonFile("Save/file_back.json", m_GameLevel);
//	m_jsonSM.DeleteJsonFile("Save/file_zero.json", m_GameLevel);
//	m_jsonSM.DeleteJsonFile("Save/file_front.json", m_GameLevel);
//
//	for (auto& obj : m_objectListBack) 
//		m_jsonSM.SaveObject(obj, "Save/file_back.json", m_GameLevel);
//	
//	for (auto& obj : m_objectListZero) 
//		m_jsonSM.SaveObject(obj, "Save/file_zero.json", m_GameLevel);
//	
//	for (auto& obj : m_objectListFront) 
//		m_jsonSM.SaveObject(obj, "Save/file_front.json", m_GameLevel);
//	
//	//delete m_ptr_player;
//	delete m_ptr_arhitevt;
//	//delete m_map_ptr;
//
//	delete m_ptr_thread;
//}
