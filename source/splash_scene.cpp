///
/// @file
/// @details Provide a simple title scene for the RacingBrains project that will fade into the title scene.
///
/// <!-- Copyright (c) 2017 Tim Beaudet - All Rights Reserved -->
///-----------------------------------------------------------------------------------------------------------------///

#include "splash_scene.h"
#include "scene_manager.h"

const tbGame::GameTimer kFinishFadeInTime(1000);
const tbGame::GameTimer kStartFadeOutTime(3500);
const tbGame::GameTimer kMaximumSplashTime(4000);

//--------------------------------------------------------------------------------------------------------------------//

SplashScene::SplashScene(void) :
	mBlackbirdLogo("data/blackbird_logo_512.png"),
	mSceneTimer(0),
	mJumpToGameAction()
{
	mJumpToGameAction.AddBinding(tbApplication::tbKeyEscape);
	mJumpToGameAction.AddBinding(tbApplication::tbKeySpace);
	mJumpToGameAction.AddBinding(tbApplication::tbMouseLeft);

	mBlackbirdLogo.SetScale(0.5f);
	mBlackbirdLogo.SetOrigin(tbGraphics::kAnchorCenter);
	mBlackbirdLogo.SetPosition(tbGraphics::ScreenCenter());
	AddGraphic(mBlackbirdLogo);
}

//--------------------------------------------------------------------------------------------------------------------//

SplashScene::~SplashScene(void)
{
}

//--------------------------------------------------------------------------------------------------------------------//

void SplashScene::OnSimulate(void)
{
	tbGame::GameScene::OnSimulate();

	if (true == mJumpToGameAction.IsReleased() && mSceneTimer < kStartFadeOutTime)
	{
		mSceneTimer = kStartFadeOutTime;
	}

	if (mSceneTimer.IncrementStep(kMaximumSplashTime))
	{
		RacingBrains::theSceneManager->ChangeToScene(SceneId::kRacingScene);
	}

	if (mSceneTimer.GetElapsedTime() < kFinishFadeInTime.GetElapsedTime())
	{	//Fade the logo in.
		float percentage = mSceneTimer.GetPercentageOf(kFinishFadeInTime);
		tbGraphics::Color fadingColor;
		fadingColor.SetColor(percentage, tbGraphics::Color::kAlphaNone, tbGraphics::Color::kAlphaFull);
		SetColor(fadingColor);
	}
	else if (mSceneTimer.GetElapsedTime() < kStartFadeOutTime.GetElapsedTime())
	{
		SetColor(tbGraphics::Color::kWhite);
	}
	else
	{	//Fade the logo out.
		SetColor(tbGraphics::Color::kAlphaNone);

		const float currentTiming = static_cast<float>(mSceneTimer.GetElapsedTime() - kStartFadeOutTime.GetElapsedTime());
		const float timingRange = static_cast<float>(kMaximumSplashTime.GetElapsedTime() - kStartFadeOutTime.GetElapsedTime());
		const float percentage = (currentTiming / timingRange);

		tbGraphics::Color fadingColor;
		fadingColor.SetColor(percentage, tbGraphics::Color::kAlphaFull, tbGraphics::Color::kAlphaNone);
		SetColor(fadingColor);
	}
}

//--------------------------------------------------------------------------------------------------------------------//

void SplashScene::OnUpdate(const float deltaTime)
{
	tbGame::GameScene::OnUpdate(deltaTime);
}

//--------------------------------------------------------------------------------------------------------------------//

void SplashScene::OnRender(void) const
{
	tbGame::GameScene::OnRender();
}

//--------------------------------------------------------------------------------------------------------------------//

void SplashScene::OnOpen(void)
{
	tbGame::GameScene::OnOpen();

	SetColor(tbGraphics::Color::kAlphaNone);
	mSceneTimer = tbGame::GameTimer::Zero();
}

//--------------------------------------------------------------------------------------------------------------------//

void SplashScene::OnClose(void)
{
	tbGame::GameScene::OnClose();
}

//--------------------------------------------------------------------------------------------------------------------//

