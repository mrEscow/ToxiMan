#include "Level.h"


void Level::LoadLevel(LevelNumber& number)
{
	System::resources.texture.LoadLevel_0();
	System::resources.texture.LoadForArhitect();
	m_firstPos = v2f(500, 1750);
	m_size_map = v2f(80, 30);
	m_objectListBeck = m_jsonSM.LoadVecObject("Save/file_beck.json", number);
	m_objectListZero = m_jsonSM.LoadVecObject("Save/file_zero.json", number);
	m_objectListFront = m_jsonSM.LoadVecObject("Save/file_front.json", number);

	m_jsonSM.DeleteJsonFile("file_beck.json", number);
	m_jsonSM.DeleteJsonFile("file_zero.json", number);
	m_jsonSM.DeleteJsonFile("file_front.json", number);
}
//----------------------------------------------------------------------
Level::Level(LevelNumber& number)
{
	m_ptr_number = &number;
	LoadLevel(number);
	
	m_ptr_player = new Player(m_firstPos, m_size_map);
	m_ptr_arhitevt = new Architect(m_objectListBeck, m_objectListZero, m_objectListFront, m_size_map);

	is_from_arhitetc = false;
	

	
	// Shader
	//shaderOne.loadFromMemory
	//(
	//	"uniform vec2 offset;"

	//	"void main() {"
	//	"    gl_Position = gl_ProjectionMatrix * gl_ModelViewMatrix * gl_Vertex;"
	//	"    gl_TexCoord[0] = gl_TextureMatrix[0] * gl_MultiTexCoord0;"
	//	"    gl_TexCoord[0].x = gl_TexCoord[0].x + offset.x;"
	//	"    gl_FrontColor = gl_Color;"
	//	"}"
	//	, sf::Shader::Vertex
	//);
	//shaderTwo.loadFromMemory
	//(
	//	"uniform vec2 offset;"

	//	"void main() {"
	//	"    gl_Position = gl_ProjectionMatrix * gl_ModelViewMatrix * gl_Vertex;"
	//	"    gl_TexCoord[0] = gl_TextureMatrix[0] * gl_MultiTexCoord0;"
	//	"    gl_TexCoord[0].x = gl_TexCoord[0].x + offset.x;"
	//	"    gl_TexCoord[0].y = gl_TexCoord[0].y + offset.y;"
	//	"    gl_FrontColor = gl_Color;"
	//	"}"
	//	, sf::Shader::Vertex
	//);
	//shaderTree.loadFromMemory
	//(
	//	"uniform vec2 offset;"

	//	"void main() {"
	//	"    gl_Position = gl_ProjectionMatrix * gl_ModelViewMatrix * gl_Vertex;"
	//	"    gl_TexCoord[0] = gl_TextureMatrix[0] * gl_MultiTexCoord0;"
	//	"    gl_TexCoord[0].x = gl_TexCoord[0].x + offset.x;"
	//	"    gl_TexCoord[0].y = gl_TexCoord[0].y + offset.y;"
	//	"    gl_FrontColor = gl_Color;"
	//	"}"
	//	, sf::Shader::Vertex
	//);

	//offsetOne = v2f(0, 0);
	//offsetTwo = v2f(0, 0);
	//offsetTree = v2f(0, 0);

	// Shader2
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

	// beckground
	//m_beckground = System::CreateShape(v2f(0,0), v2f(640,360), System::resources.texture.background);
	//
	//m_backOne = System::CreateShape(v2f(((64 * m_size_map.x) / 2) - 32, ((64 * m_size_map.y) / 2) - 32), v2f(64 * m_size_map.x, 64 * m_size_map.y), System::resources.texture.backOne);
	//m_backTwo = System::CreateShape(v2f(((64 * m_size_map.x) / 2) - 32, ((64 * m_size_map.y) / 2) - 32), v2f(64 * m_size_map.x, 64 * m_size_map.y), System::resources.texture.backTwo);
	//m_backTree = System::CreateShape(v2f(((64 * m_size_map.x) / 2) - 32, ((64 * m_size_map.y) / 2) - 32), v2f(64 * m_size_map.x, 64 * m_size_map.y), System::resources.texture.backTree);

	// beckground 2

	m_bg5_a = System::CreateShape(v2f(((64 * m_size_map.x) / 2) - 32, ((64 * m_size_map.y ) / 2 ) - 32), v2f(64 * m_size_map.x, 64 * m_size_map.y), System::resources.texture.bg5_a);
	m_bg5_b = System::CreateShape(v2f(((64 * m_size_map.x) / 2) - 32, ((64 * m_size_map.y ) / 2 ) - 32), v2f(64 * m_size_map.x, 64 * m_size_map.y), System::resources.texture.bg5_b);
	m_bg5_c = System::CreateShape(v2f(((64 * m_size_map.x) / 2) - 32, ((64 * m_size_map.y ) / 2 ) - 32), v2f(64 * m_size_map.x, 64 * m_size_map.y), System::resources.texture.bg5_c);
	m_bg5_d = System::CreateShape(v2f(((64 * m_size_map.x) / 2) - 32, ((64 * m_size_map.y ) / 2 ) - 32), v2f(64 * m_size_map.x, 64 * m_size_map.y), System::resources.texture.bg5_d);
	m_bg5_e = System::CreateShape(v2f(((64 * m_size_map.x) / 2) - 32, ((64 * m_size_map.y ) / 2 ) - 32), v2f(64 * m_size_map.x, 64 * m_size_map.y), System::resources.texture.bg5_e);

	m_bg5_g = System::CreateShape(v2f(((64 * m_size_map.x) / 2) - 32, ((64 * m_size_map.y ) / 2 ) - 32), v2f(64 * m_size_map.x, 64 * m_size_map.y), System::resources.texture.bg5_g);
}

void Level::Action(StateGame& state_game, LevelNumber& number)
{
	switch (state_game)
	{
	case StateGame::ON_MAIN_MENU:
		break;
	case StateGame::ON_GAME:
		m_ptr_player->Action(state_game);
		break;
	case StateGame::ON_ARCITECT:
		m_ptr_arhitevt->Action(state_game, is_from_arhitetc, m_jsonSM, number);
		break;
	default:
		break;
	}


}

void Level::Update(StateGame& state_game, LevelNumber& number)
{

	//m_beckground.setPosition(System::cam.getCenter().x + 480, System::cam.getCenter().y - 270);
	//// Shader 
	//offsetOne.x += System::time / 10000;
	//shaderOne.setUniform("offset", offsetOne);


	//offsetTwo.x += m_ptr_player->GetBody()->GetLinearVelocity().x / 200000;
	//offsetTwo.y += m_ptr_player->GetBody()->GetLinearVelocity().y / 200000;
	//shaderTwo.setUniform("offset", offsetTwo);


	//offsetTree.x += m_ptr_player->GetBody()->GetLinearVelocity().x / 100000;
	//offsetTree.y += m_ptr_player->GetBody()->GetLinearVelocity().y / 100000;
	//shaderTree.setUniform("offset", offsetTree);

	// Shader 2

	int test = 5;

	if (System::cam.getCenter().x > System::scr_w / 2 && System::cam.getCenter().x < 64 * m_size_map.x - 32 - (System::scr_w / 2)) 
		offsetBg5_a.x += m_ptr_player->GetBody()->GetLinearVelocity().x / (30000 * test);
	if (System::cam.getCenter().y < 64 * m_size_map.y - 32 - (System::scr_h / 2) && System::cam.getCenter().y > System::scr_h / 2)
		offsetBg5_a.y += m_ptr_player->GetBody()->GetLinearVelocity().y / (30000 * test);
	shaderBg5_a.setUniform("offset", offsetBg5_a);

	if (System::cam.getCenter().x > System::scr_w / 2 && System::cam.getCenter().x < 64 * m_size_map.x - 32 - (System::scr_w / 2))
		offsetBg5_b.x += m_ptr_player->GetBody()->GetLinearVelocity().x / (25000 * test);
	if (System::cam.getCenter().y < 64 * m_size_map.y - 32 - (System::scr_h / 2) && System::cam.getCenter().y > System::scr_h / 2)
		offsetBg5_b.y += m_ptr_player->GetBody()->GetLinearVelocity().y / (25000 * test);
	shaderBg5_b.setUniform("offset", offsetBg5_b);

	if (System::cam.getCenter().x > System::scr_w / 2 && System::cam.getCenter().x < 64 * m_size_map.x - 32 - (System::scr_w / 2))
		offsetBg5_c.x += m_ptr_player->GetBody()->GetLinearVelocity().x / (20000 * test);
	if (System::cam.getCenter().y < 64 * m_size_map.y - 32 - (System::scr_h / 2) && System::cam.getCenter().y > System::scr_h / 2)
		offsetBg5_c.y += m_ptr_player->GetBody()->GetLinearVelocity().y / (20000 * test);
	shaderBg5_c.setUniform("offset", offsetBg5_c);

	if (System::cam.getCenter().x > System::scr_w / 2 && System::cam.getCenter().x < 64 * m_size_map.x - 32 - (System::scr_w / 2))
		offsetBg5_d.x += m_ptr_player->GetBody()->GetLinearVelocity().x / (15000 * test);
	if (System::cam.getCenter().y < 64 * m_size_map.y - 32 - (System::scr_h / 2) && System::cam.getCenter().y > System::scr_h / 2)
		offsetBg5_d.y += m_ptr_player->GetBody()->GetLinearVelocity().y / (15000 * test);
	shaderBg5_d.setUniform("offset", offsetBg5_d);

	if (System::cam.getCenter().x > System::scr_w / 2 && System::cam.getCenter().x < 64 * m_size_map.x - 32 - (System::scr_w / 2))
		offsetBg5_e.x += m_ptr_player->GetBody()->GetLinearVelocity().x / (10000 * test);
	if (System::cam.getCenter().y < 64 * m_size_map.y - 32 - (System::scr_h / 2) && System::cam.getCenter().y > System::scr_h / 2)
		offsetBg5_e.y += m_ptr_player->GetBody()->GetLinearVelocity().y / (10000 * test);
	shaderBg5_e.setUniform("offset", offsetBg5_e);


	// Save objecks
	if (is_from_arhitetc) {

		m_objectListBeck = m_jsonSM.LoadVecObject("file_beck.json", number);
		m_objectListZero = m_jsonSM.LoadVecObject("file_zero.json", number);
		m_objectListFront = m_jsonSM.LoadVecObject("file_front.json", number);






		m_jsonSM.DeleteJsonFile("file_beck.json", number);
		m_jsonSM.DeleteJsonFile("file_zero.json", number);
		m_jsonSM.DeleteJsonFile("file_front.json", number);

		is_from_arhitetc = false;
	}

	for (auto& object : m_objectListBeck)
		object.Update("objectListBeck");
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
		m_ptr_player->Update();
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
	// background
	//System::wnd.draw(m_beckground,&shaderOne);


	//System::wnd.draw(m_backOne, &shaderOne);
	//System::wnd.draw(m_backTwo, &shaderTwo);
	//System::wnd.draw(m_backTree, &shaderTree);

	// background 2
	System::wnd.draw(m_bg5_g);

	System::wnd.draw(m_bg5_a, &shaderBg5_a);
	System::wnd.draw(m_bg5_b, &shaderBg5_b);
	System::wnd.draw(m_bg5_c, &shaderBg5_c);
	System::wnd.draw(m_bg5_d, &shaderBg5_d);
	System::wnd.draw(m_bg5_e, &shaderBg5_e);



	for (auto &object : m_objectListBeck) {
		if (System::IsShapeInCamera(object.m_shape))
			object.Draw();
	}

	for (auto &object : m_objectListZero) {
		if(System::IsShapeInCamera(object.m_shape))
			object.Draw();
	}



	switch (state_game)
	{
	case StateGame::ON_MAIN_MENU:
		break;
	case StateGame::ON_GAME:
		m_ptr_player->Draw();
		break;
	case StateGame::ON_ARCITECT:
		m_ptr_player->Draw();
		m_ptr_arhitevt->Draw(state_game, m_ptr_player);
		break;
	default:
		break;
	}

	for (auto &object : m_objectListFront) {
		if (System::IsShapeInCamera(object.m_shape))
			object.Draw();
	}	
}

v2f Level::GetPositionPlayer()
{
	return m_ptr_player->GetPosition();
}

Level::~Level()
{
	for (auto &obj : m_objectListBeck) {
		m_jsonSM.SaveObject(obj, "file_beck.json", *m_ptr_number);
	}
	for (auto &obj : m_objectListZero) {
		m_jsonSM.SaveObject(obj, "file_zero.json", *m_ptr_number);
	}
	for (auto &obj : m_objectListFront) {
		m_jsonSM.SaveObject(obj, "file_front.json", *m_ptr_number);
	}


	m_jsonSM.DeleteJsonFile("Save/file_beck.json", *m_ptr_number);
	m_jsonSM.DeleteJsonFile("Save/file_zero.json", *m_ptr_number);
	m_jsonSM.DeleteJsonFile("Save/file_front.json", *m_ptr_number);

	for (auto& obj : m_objectListBeck) {
		m_jsonSM.SaveObject(obj, "Save/file_beck.json", *m_ptr_number);
	}
	for (auto& obj : m_objectListZero) {
		m_jsonSM.SaveObject(obj, "Save/file_zero.json", *m_ptr_number);
	}
	for (auto& obj : m_objectListFront) {
		m_jsonSM.SaveObject(obj, "Save/file_front.json", *m_ptr_number);
	}

	delete m_ptr_player;
	delete m_ptr_arhitevt;
	//delete m_ptr_number;
	//delete m_ptr_jsonSM;
}
