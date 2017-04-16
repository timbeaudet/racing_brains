///
/// @file
/// @details The RacecarControllerInterface allows the driver to control any race cars using the same interface of
///   a steering wheel, throttle, brakes, clutch and other car controls. 
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

void Racing::RacecarControllerInterface::SetSteeringPosition(float steering)
{
	mSteering = (steering < 0.0f) ? 0.0f : (steering > 1.0f) ? 1.0f : steering;
}

//-------------------------------------------------------------------------------------------------------------------//

void Racing::RacecarControllerInterface::SetThrottlePosition(float throttle)
{
	mThrottle = (throttle < 0.0f) ? 0.0f : (throttle > 1.0f) ? 1.0f : throttle;
}

//-------------------------------------------------------------------------------------------------------------------//

void Racing::RacecarControllerInterface::SetBrakePosition(float brake)
{
	mBrake = (brake < 0.0f) ? 0.0f : (brake > 1.0f) ? 1.0f : brake;
}

//-------------------------------------------------------------------------------------------------------------------//

void Racing::RacecarControllerInterface::SetClutchPosition(float clutch)
{
	mClutch = (clutch < 0.0f) ? 0.0f : (clutch > 1.0f) ? 1.0f : clutch;
}

//-------------------------------------------------------------------------------------------------------------------//

void Racing::RacecarControllerInterface::SetShiftUpButton(bool buttonPressed)
{
	mShiftUp = buttonPressed;
}

//-------------------------------------------------------------------------------------------------------------------//

void Racing::RacecarControllerInterface::SetShiftDownButton(bool buttonPressed)
{
	mShiftDown = buttonPressed;
}

//-------------------------------------------------------------------------------------------------------------------//

void Racing::RacecarControllerInterface::SetShifterPosition(const ShifterPosition& shifterPosition)
{
	mShifterPosition = shifterPosition;
}

//-------------------------------------------------------------------------------------------------------------------//
