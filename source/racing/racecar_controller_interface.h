///
/// @file
/// @details The RacecarControllerInterface allows the driver to control any race cars using the same interface of
///   a steering wheel, throttle, brakes, clutch and other car controls.
///-----------------------------------------------------------------------------------------------------------------///

#ifndef _RacingBrains_RacecarControllerInterface_h_
#define _RacingBrains_RacecarControllerInterface_h_

namespace Racing
{

	class RacecarControllerInterface
	{
	public:
		enum class ShifterPosition
		{
			Neutral,
			First,
			Second,
			Third,
			Fourth,
			Fifth,
			Sixth,
			Reverse,
		};

		RacecarControllerInterface(void);
		virtual ~RacecarControllerInterface(void);

		void ApplyControls(void) const;

		//Analog Controls
		float GetSteeringPosition(void) const { return mSteering; }
		float GetThrottlePosition(void) const { return mThrottle; }
		float GetBrakePosition(void) const { return mBrake; }
		float GetClutchPosition(void) const { return mClutch; }

		//Button Controls
		inline bool GetShiftUpButton(void) const { return mShiftUp; }
		inline bool GetShiftDownButton(void) const { return mShiftDown; }

		//Shifter Controls
		inline const ShifterPosition& GetShifterPosition(void) const { return mShifterPosition; }

	protected:
		///
		/// @details This shall be overridden by a concrete class to set the various controls of the car.
		///
		virtual void OnApplyControls(void) const = 0;

		//Analog Controls
		void SetSteeringPosition(float steering);
		void SetThrottlePosition(float throttle);
		void SetBrakePosition(float brake);
		void SetClutchPosition(float clutch);

		//Button Controls
		void SetShiftUpButton(bool buttonPressed);
		void SetShiftDownButton(bool buttonPressed);

		//Shifter Controls
		void SetShifterPosition(const ShifterPosition& shifterPosition);

	private:
		//Disabled copy constructor, assignment operator
		RacecarControllerInterface(const RacecarControllerInterface& other);
		RacecarControllerInterface& operator=(const RacecarControllerInterface& other);

		//Analog Controls
		float mSteering;
		float mThrottle;
		float mBrake;
		float mClutch;

		//Button Controls
		bool mShiftUp;
		bool mShiftDown;

		//Shifter Controls
		ShifterPosition mShifterPosition;
	};

};	//namespace Racing

#endif /* _RacingBrains_RacecarControllerInterface_h_ */
