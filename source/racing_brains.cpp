///
/// @file
/// @details Entry point of the RacingBrains project.
///
/// <!-- Copyright (c) 2017 Tim Beaudet - All Rights Reserved -->
///-----------------------------------------------------------------------------------------------------------------///

#include "racing_brains.h"
#include "scene_manager.h"

//--------------------------------------------------------------------------------------------------------------------//

int real_main(int argumentCount, const char* argumentValues[])
{
	tb_unused(argumentCount);
	tb_unused(argumentValues);

	tbGame::GameApplication gameApplication;
	gameApplication.SetWindowTitle(tb_string("Racing Brains"));

	tbGraphics::theSpriteManager.LoadSpriteSheetFromFile("concept_art", "data/concept_kit/concept_art_sheet.json");
	tbAudio::theAudioManager.LoadEventTable("concept_audio", "data/concept_kit/concept_audio_events.json");
	tbAudio::theAudioManager.LoadEventTable("audio_events", "data/audio/audio_events.json");

	SceneManager::CreateSceneManager();

#if defined(tb_release_build)
	gameApplication.RunGame(SceneManager::GetScene(SceneId::kSplashScene));
#else
	gameApplication.RunGame(SceneManager::GetScene(SceneId::kRacingScene));
#endif

	SceneManager::DestroySceneManager();

	return 0;
}

//--------------------------------------------------------------------------------------------------------------------//

int main(const int argumentCount, const char* argumentValues[])
{
	tb_log_open("debug_log.txt", true);
	tb_log("Started: RacingBrains\n");

	int returnCode = tb_debug_project_entry_point_with(real_main, argumentCount, argumentValues);

	tb_log("Clean shutdown.\n");
	tb_log_close();
	return returnCode;
}

//--------------------------------------------------------------------------------------------------------------------//
