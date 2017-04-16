///
/// @file
/// @details This scene is the gameplay scene for the RacingBrains project.
///
/// <!-- Copyright (c) 2017 Tim Beaudet - All Rights Reserved -->
///-----------------------------------------------------------------------------------------------------------------///

#ifndef _RacingBrains_RacingScene_h_
#define _RacingBrains_RacingScene_h_

#include "racing_brains.h"

class RacingScene : public tbGame::GameScene
{
public:
	RacingScene(void);
	virtual ~RacingScene(void);

	virtual void OnSimulate(void) override;
	virtual void OnUpdate(const float deltaTime) override;
	virtual void OnRender(void) const override;
	virtual void OnOpen(void) override;
	virtual void OnClose(void) override;

protected:

private:
};

#endif /* _RacingBrains_RacingScene_h_ */
