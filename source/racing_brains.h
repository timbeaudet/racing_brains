///
/// @file
/// @details Entry point of the RacingBrains project.
///
/// <!-- Copyright (c) 2017 Tim Beaudet - All Rights Reserved -->
///-----------------------------------------------------------------------------------------------------------------///

#ifndef _RacingBrains_RacingBrains_h_
#define _RacingBrains_RacingBrains_h_

#include "tb_application_kit.h"
#include "tb_audio_kit.h"
#include "tb_core_kit.h"
#include "tb_debug_kit.h"
#include "tb_game_kit.h"
#include "tb_graphics_kit.h"
#include "tb_math_kit.h"

#include <stdint.h>

namespace RacingBrains
{

	typedef uint32_t MillisecondTimer;

	static const MillisecondTimer kFixedTimeMS(10);
	static const float kFixedTime(0.01f);

}; /* namespace RacingBrains */

#endif /* _RacingBrains_RacingBrains_h_ */
