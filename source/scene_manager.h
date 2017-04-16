///
/// @file
/// @details Contains all of the scenes in the RacingBrains project from splash, menus, options, 
///   to gameplay to provide an  easy way for the scenes to be managed and changed between.
///   (Although TurtleBrains supplies a way to change between GameScene's it doesn't provide a great way to manage their memory.)
///
/// <!-- Copyright (c) 2017 Tim Beaudet - All Rights Reserved -->
///-----------------------------------------------------------------------------------------------------------------///

#ifndef _RacingBrains_SceneManager_h_
#define _RacingBrains_SceneManager_h_

#include "racing_brains.h"
#include <vector>

enum SceneId
{
	kSplashScene,
	kRacingScene,
	kSceneCount,
};

class SceneManager : public tbCore::Noncopyable
{
public:
	///
	/// @details Creates the SceneManager instance for theSceneManager which is accessed as a global singleton object.
	///   Each scene of the game APRIL is then added it to the SceneManager so it can be changed to the active scene
	///   with ChangeToScene().
	///
	static void CreateSceneManager(void);

	///
	/// @details Destroys the SceneManager instance for theSceneManager and sets it to nullptr, destroying all scenes
	///   in the process.
	///
	static void DestroySceneManager(void);

	///
	/// @details Returns a reference to the game scene object that corresponds with the sceneIdentifier supplied. An
	///   error condition will be triggered if the SceneManager has not been created with CreateSceneManager or if the
	///   sceneIdentifier is out of range.
	///
	static tbGame::GameScene& GetScene(const SceneId& sceneIdentifier);

	///
	/// @details Changes the TurtleBrains Scene to the desired scene which will then be the active scene.  An error
	///   condition will be triggered if the SceneManager has not been created with CreateSceneManager() or if the
	///   sceneIdentifier is out of range.
	///
	static void ChangeToScene(const SceneId& sceneIdentifier);

	///
	/// @details Signals TurtleBrains to close the game.
	///
	static void QuitGame(void);

private:
	SceneManager(void);
	~SceneManager(void);

	std::vector<tbGame::GameScene*> mScenes;
};


namespace RacingBrains
{
	extern SceneManager* theSceneManager;
}; /* namespace RacingBrains */

#endif /* _RacingBrains_SceneManager_h_ */
