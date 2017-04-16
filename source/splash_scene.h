///
/// @file
/// @details Provide a simple title scene for the RacingBrains project that will fade into the title scene.
///
/// <!-- Copyright (c) 2017 Tim Beaudet - All Rights Reserved -->
///-----------------------------------------------------------------------------------------------------------------///

#ifndef _RacingBrains_SplashScene_h_
#define _RacingBrains_SplashScene_h_

#include "racing_brains.h"

class SplashScene : public tbGame::GameScene
{
public:
	SplashScene(void);
	virtual ~SplashScene(void);

	virtual void OnSimulate(void) override;
	virtual void OnUpdate(const float deltaTime) override;
	virtual void OnRender(void) const override;
	virtual void OnOpen(void) override;
	virtual void OnClose(void) override;

protected:

private:
	tbGraphics::Sprite mBlackbirdLogo;

	tbGame::GameTimer mSceneTimer;
	tbGame::InputAction mJumpToGameAction;
};

#endif /* _RacingBrains_SplashScene_h_ */
