///
/// @file
/// @details This scene is the gameplay scene for the RacingBrains project.
///
/// <!-- Copyright (c) 2017 Tim Beaudet - All Rights Reserved -->
///-----------------------------------------------------------------------------------------------------------------///

#include "racing_scene.h"
#include "scene_manager.h"

//--------------------------------------------------------------------------------------------------------------------//

RacingScene::RacingScene(void)
{
}

//--------------------------------------------------------------------------------------------------------------------//

RacingScene::~RacingScene(void)
{
}

//--------------------------------------------------------------------------------------------------------------------//

void RacingScene::OnSimulate(void)
{
	tbGame::GameScene::OnSimulate();
}

//--------------------------------------------------------------------------------------------------------------------//

void RacingScene::OnUpdate(const float deltaTime)
{
	tbGame::GameScene::OnUpdate(deltaTime);

	if (true == tbApplication::Input::IsKeyReleased(tbApplication::tbKeyEscape))
	{	//This should be the very last check to happen as game ends immediately.
		RacingBrains::theSceneManager->QuitGame();
	}
}

//--------------------------------------------------------------------------------------------------------------------//

void RacingScene::OnRender(void) const
{
	tbGame::GameScene::OnRender();
}

//--------------------------------------------------------------------------------------------------------------------//

void RacingScene::OnOpen(void)
{
	tbGame::GameScene::OnOpen();
}

//--------------------------------------------------------------------------------------------------------------------//

void RacingScene::OnClose(void)
{
	tbGame::GameScene::OnClose();
}

//--------------------------------------------------------------------------------------------------------------------//