///
/// @file
/// @details Contains all of the scenes in the RacingBrains project from splash, menus, options, 
///   to gameplay to provide an  easy way for the scenes to be managed and changed between.
///   (Although TurtleBrains supplies a way to change between GameScene's it doesn't provide a great way to manage their memory.)
///
/// <!-- Copyright (c) 2017 Tim Beaudet - All Rights Reserved -->
///-----------------------------------------------------------------------------------------------------------------///

#include "scene_manager.h"
#include "splash_scene.h"
#include "racing_scene.h"

SceneManager* RacingBrains::theSceneManager(nullptr);

//--------------------------------------------------------------------------------------------------------------------//

SceneManager::SceneManager(void) :
	mScenes()
{
	mScenes.resize(kSceneCount, nullptr);
	mScenes[SceneId::kSplashScene] = new SplashScene();
	mScenes[SceneId::kRacingScene] = new RacingScene();
}

//--------------------------------------------------------------------------------------------------------------------//

SceneManager::~SceneManager(void)
{
	while (false == mScenes.empty())
	{
		delete mScenes.back();
		mScenes.pop_back();
	}
}

//--------------------------------------------------------------------------------------------------------------------//

void SceneManager::CreateSceneManager(void)
{
	tb_error_if(nullptr != RacingBrains::theSceneManager, "Expected theSceneManager to be null when calling create, seems create has been called twice.");
	RacingBrains::theSceneManager = new SceneManager();
}

//--------------------------------------------------------------------------------------------------------------------//

void SceneManager::DestroySceneManager(void)
{
	tb_error_if(nullptr == RacingBrains::theSceneManager, "Expected theSceneManager to be a valid pointer when calling destroy, seems destroy has been called twice, or without create.");
	delete RacingBrains::theSceneManager;
	RacingBrains::theSceneManager = nullptr;
}

//--------------------------------------------------------------------------------------------------------------------//

tbGame::GameScene& SceneManager::GetScene(const SceneId& sceneIdentifier)
{
	tb_error_if(nullptr == RacingBrains::theSceneManager, "Expected theSceneManager to be created and valid before ChangeToScene is called.");
	tb_error_if(sceneIdentifier < 0, "Expected a valid sceneIdentifier, below zero is out of range.");
	tb_error_if(static_cast<size_t>(sceneIdentifier) >= RacingBrains::theSceneManager->mScenes.size(), "Expected a valid sceneIdentifier, out of range.  Was the scene added to manager?");
	return *RacingBrains::theSceneManager->mScenes[sceneIdentifier];
}

//--------------------------------------------------------------------------------------------------------------------//

void SceneManager::ChangeToScene(const SceneId& sceneIdentifier)
{
	tbGame::GameScene::ChangeToScene(SceneManager::GetScene(sceneIdentifier));
}

//--------------------------------------------------------------------------------------------------------------------//

void SceneManager::QuitGame(void)
{
	tb_error_if(nullptr == RacingBrains::theSceneManager, "Expected theSceneManager to be created and valid before ChangeToScene is called.");
	tbGame::GameApplication::MarkForClose();
}

//--------------------------------------------------------------------------------------------------------------------//
