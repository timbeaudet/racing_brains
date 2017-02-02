///
/// @file
/// @details The RacecarControllerInterface allows the driver to control any race cars using the same interface of
///   a steering wheel, throttle, brakes, clutch and other car controls.
///
/// <!-- Copyright (c) Tim Beaudet 2016 - All Rights Reserved --> 
///-----------------------------------------------------------------------------------------------------------------///

#include "racecar_controller_interface.h"

//-------------------------------------------------------------------------------------------------------------------//

Racing::RacecarControllerInterface::RacecarControllerInterface(void) :
	mSteering(0.0f),
	mThrottle(0.0f),
	mBrake(0.0f),
	mClutch(0.0f),
	mShiftUp(false),
	mShiftDown(false),
	mShifterPosition(ShifterPosition::Neutral)
{
}

//-------------------------------------------------------------------------------------------------------------------//

Racing::RacecarControllerInterface::~RacecarControllerInterface(void)
{
}

//-------------------------------------------------------------------------------------------------------------------//

void Racing::RacecarControllerInterface::ApplyControls(void) const
{
	OnApplyControls();
}

//-------------------------------------------------------------------------------------------------------------------//
