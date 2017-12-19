// DPUCooperation_and_Interface
// Created: 16.10.2017 (SILABDPUWizard)
// Author: Freymann, Moritz

#ifndef __DPU_DPUCooperation_and_Interface_H__
#define __DPU_DPUCooperation_and_Interface_H__

// The following definitions are required for inserting the DPU into the SILAB system
// and should not be modified.
#ifdef WINDOWS_SYSTEM
#	ifdef DPUCooperation_and_Interface_EXPORTS
#		define SPUCooperation_and_Interface_API __declspec(dllexport)
#	else
#		define SPUCooperation_and_Interface_API __declspec(dllimport)
#	endif
#else
#	define SPUCooperation_and_Interface_API __attribute__ ((visibility("default")))
#endif

#include "SYS/DEV/DEV.h"
// additional include files
#include "Linear.h"
#include "Config.h"
#include "ColorRGBA.h"
#include "VisualObject.h"

SPU_Decl(Cooperation_and_Interface, SPUCooperation_and_Interface_API);

// ------------------------------------------------------------------
// sSPUCooperation_and_Interface
// ------------------------------------------------------------------

// The data structure sSPUCooperation_and_Interface contains the variables that define the interface of the SPU.
// It should only contain members of type cVar.
struct SPUCooperation_and_Interface_API sSPUCooperation_and_Interface
{
	// Input variables of the SPU
		
	cVar md_DecisionTime;
	cVar mi_DefaultAction;
	
	cVar mi_AutomationActive_In;
	cVar mi_RequestType_In;
	cVar mi_RequestID_In;
	cVar mb_AcceptButtonPressed_In;
	cVar mb_RejectButtonPressed_In;

	cVar md_Speed_In;
	cVar md_TargetSpeed_In;
	cVar md_BrakeSpeed_In;

	cVar md_position_x;		// aktuelle x-Position des EGO-Car
	cVar md_x_end;			// x-Position in Area2, an der die Kooperation abgeschlossen sein muss.

	cVar mi_delay_distance_1;
	cVar mi_delay_distance_2;
	cVar mi_delay_distance_3;
	cVar mi_delay_distance_4;
	cVar mi_delay_distance_5;
	cVar mi_delay_distance_6;
	cVar mi_delay_distance_7;
	cVar mi_delay_distance_8;
	cVar mi_delay_distance_9;

	// Output variables of the SPU

	// ==========================================================================================
	// Cooperation
	// ==========================================================================================

	cVar md_velocity_Out;
	cVar mi_CooperationState_Out;
	cVar md_DecisionTime_Out;
	cVar mb_Accepted_Out;
	cVar mi_LaneChange_Out;
	cVar md_TargetSpeed_Out;
	cVar mb_BlinkerStartLinks_Out;
	cVar mb_BlinkerOnLinks_Out;
	cVar mb_AutomationEnabled_Out;

	cVar mb_Accepted1_Out;
	cVar mb_Rejected1_Out;
	cVar mb_Accepted2_Out;
	cVar mb_Rejected2_Out;
	cVar mb_Accepted3_Out;
	cVar mb_Rejected3_Out;
	cVar mb_Accepted4_Out;
	cVar mb_Rejected4_Out;
	cVar mb_Accepted5_Out;
	cVar mb_Rejected5_Out;
	cVar mb_Accepted6_Out;
	cVar mb_Rejected6_Out;
	cVar mb_Accepted7_Out;
	cVar mb_Rejected7_Out;
	cVar mb_Accepted8_Out;
	cVar mb_Rejected8_Out;
	cVar mb_Accepted9_Out;
	cVar mb_Rejected9_Out;

	cVar mb_ObjBaselayerDefaultAVisible_Out;
	cVar mb_ObjBaselayerDefaultAOpacity_Out;
	cVar mb_ObjBaselayerDefaultBVisible_Out;
	cVar mb_ObjBaselayerDefaultBOpacity_Out;
	cVar mb_ObjBaselayerDefaultCVisible_Out;
	cVar mb_ObjBaselayerDefaultCOpacity_Out;

	// cookie
	cVar md_x_position;

	// ==========================================================================================
	// Interface
	// ==========================================================================================

	cVar mb_ObjBaselayerCircleBigVisible_Out;
	cVar md_ObjBaselayerCircleBigOpacity_Out;

	cVar mb_ObjBaselayerCircleLeftVisible_Out;
	cVar md_ObjBaselayerCircleLeftOpacity_Out;
	cVar md_ObjBaselayerCircleLeftColorRed_Out;
	cVar md_ObjBaselayerCircleLeftColorGreen_Out;
	cVar md_ObjBaselayerCircleLeftColorBlue_Out;

	cVar mb_ObjBaselayerCircleRightVisible_Out;
	cVar md_ObjBaselayerCircleRightOpacity_Out;
	cVar md_ObjBaselayerCircleRightColorRed_Out;
	cVar md_ObjBaselayerCircleRightColorGreen_Out;
	cVar md_ObjBaselayerCircleRightColorBlue_Out;

	cVar mb_ObjBaselayerCircleLeftMiddleVisible_Out;
	cVar md_ObjBaselayerCircleLeftMiddleOpacity_Out;

	cVar mb_ObjBaselayerCircleRightMiddleVisible_Out;
	cVar md_ObjBaselayerCircleRightMiddleOpacity_Out;

	cVar mb_ObjBaselayerCircleDefaultLeftMiddleVisible_Out;
	cVar md_ObjBaselayerCircleDefaultLeftMiddleOpacity_Out;

	cVar mb_ObjBaselayerCircleDefaultRightMiddleVisible_Out;
	cVar md_ObjBaselayerCircleDefaultRightMiddleOpacity_Out;

	cVar mb_ObjhandsOnBigVisible_Out;
	cVar md_ObjhandsOnBigOpacity_Out;

	cVar mb_ObjBaselayerCircleDefaultVisible_Out;
	cVar md_ObjBaselayerCircleDefaultOpacity_Out;

	cVar mb_ObjIconRejectVisible_Out;
	cVar md_ObjIconRejectOpacity_Out;

	cVar mb_ObjIconAcceptVisible_Out;
	cVar md_ObjIconAcceptOpacity_Out;

	cVar mb_ObjIconRejectMiddleVisible_Out;
	cVar md_ObjIconRejectMiddleOpacity_Out;

	cVar mb_ObjIconAcceptMiddleVisible_Out;
	cVar md_ObjIconAcceptMiddleOpacity_Out;

	cVar mb_ObjArrowDownVisible_Out;
	cVar md_ObjArrowDownOpacity_Out;

	cVar mb_ObjStreetVisible_Out;
	cVar md_ObjStreetOpacity_Out;

	cVar mb_ObjArrowLeftVisible_Out;
	cVar md_ObjArrowLeftOpacity_Out;

	cVar mb_ObjTimerVisible_Out;
	cVar md_ObjTimerOpacity_Out;
	cVar md_ObjTimerValue_Out;

	cVar mb_ObjDefault0_Visible_Out;
	cVar md_ObjDefault0_Opacity_Out;

	cVar mb_ObjDefault1_Visible_Out;
	cVar md_ObjDefault1_Opacity_Out;

	cVar mb_ObjDefault2_Visible_Out;
	cVar md_ObjDefault2_Opacity_Out;

	// Sounds
	cVar mb_PlaySoundRequest_Out;
	cVar mb_PlaySoundAccept_Out;
	cVar mb_PlaySoundReject_Out;

	cVar mb_DefaultSound_Out;
	cVar mb_AcceptSound_Out;
	cVar mb_RejectSound_Out;

	sSPUCooperation_and_Interface ();

	void sSPUCooperation_and_InterfaceInit()
	{
		// Each variable contained in the interface structure must be made known to the system
		// using a VARInitXX macro. The macros define type, valid numeric range and the function
		// (in-/output) of the variable.
		// The method s[SPUName]Init() must be called in the constructor of the interface
		// structure.

		// Input variables of the SPU
		VARInitI(mi_RequestType_In);
		VARInitI(mi_DefaultAction);
		VARInitI(mi_RequestID_In);
		VARInitI(md_DecisionTime);
		VARInitI(mi_AutomationActive_In);

		VARInitI(md_Speed_In);
		VARInitI(md_TargetSpeed_In);
		VARInitI(md_BrakeSpeed_In);

		VARInitI(mb_AcceptButtonPressed_In);
		VARInitI(mb_RejectButtonPressed_In);

		VARInitI(md_position_x);
		VARInitI(md_x_end);

		// delay-distances
		VARInitI(mi_delay_distance_1);
		VARInitI(mi_delay_distance_2);
		VARInitI(mi_delay_distance_3);
		VARInitI(mi_delay_distance_4);
		VARInitI(mi_delay_distance_5);
		VARInitI(mi_delay_distance_6);
		VARInitI(mi_delay_distance_7);
		VARInitI(mi_delay_distance_8);
		VARInitI(mi_delay_distance_9);

		// Output variables of the SPU

		// ==========================================================================================
		// Cooperation
		// ==========================================================================================	
		VARInitO(md_velocity_Out);
		VARInitO(mi_CooperationState_Out);
		VARInitO(md_DecisionTime_Out);
		VARInitO(mb_Accepted_Out);

		VARInitO(mi_LaneChange_Out);
		VARInitO(md_TargetSpeed_Out);

		VARInitO(mb_BlinkerStartLinks_Out);
		VARInitO(mb_BlinkerOnLinks_Out);
		VARInitO(mb_AutomationEnabled_Out);

		VARInitO(mb_Accepted1_Out);
		VARInitO(mb_Rejected1_Out);
		VARInitO(mb_Accepted2_Out);
		VARInitO(mb_Rejected2_Out);
		VARInitO(mb_Accepted3_Out);
		VARInitO(mb_Rejected3_Out);
		VARInitO(mb_Accepted4_Out);
		VARInitO(mb_Rejected4_Out);
		VARInitO(mb_Accepted5_Out);
		VARInitO(mb_Rejected5_Out);
		VARInitO(mb_Accepted6_Out);
		VARInitO(mb_Rejected6_Out);
		VARInitO(mb_Accepted7_Out);
		VARInitO(mb_Rejected7_Out);
		VARInitO(mb_Accepted8_Out);
		VARInitO(mb_Rejected8_Out);
		VARInitO(mb_Accepted9_Out);
		VARInitO(mb_Rejected9_Out);

		VARInitO(mb_ObjBaselayerDefaultAVisible_Out);
		VARInitO(mb_ObjBaselayerDefaultAOpacity_Out);
		VARInitO(mb_ObjBaselayerDefaultBVisible_Out);
		VARInitO(mb_ObjBaselayerDefaultBOpacity_Out);
		VARInitO(mb_ObjBaselayerDefaultCVisible_Out);
		VARInitO(mb_ObjBaselayerDefaultCOpacity_Out);

		// cookie
		VARInitO(md_x_position);

		// ==========================================================================================
		// Interface
		// ==========================================================================================

		//background circles
		VARInitO(mb_ObjBaselayerCircleBigVisible_Out);
		VARInitO(md_ObjBaselayerCircleBigOpacity_Out);

		// left circle
		VARInitO(mb_ObjBaselayerCircleLeftVisible_Out);
		VARInitO(md_ObjBaselayerCircleLeftOpacity_Out);
		VARInitO(md_ObjBaselayerCircleLeftColorRed_Out);
		VARInitO(md_ObjBaselayerCircleLeftColorGreen_Out);
		VARInitO(md_ObjBaselayerCircleLeftColorBlue_Out);

		// right circle
		VARInitO(mb_ObjBaselayerCircleRightVisible_Out);
		VARInitO(md_ObjBaselayerCircleRightOpacity_Out);
		VARInitO(md_ObjBaselayerCircleRightColorRed_Out);
		VARInitO(md_ObjBaselayerCircleRightColorGreen_Out);
		VARInitO(md_ObjBaselayerCircleRightColorBlue_Out);

		VARInitO(mb_ObjBaselayerCircleLeftMiddleVisible_Out);
		VARInitO(md_ObjBaselayerCircleLeftMiddleOpacity_Out);

		VARInitO(mb_ObjBaselayerCircleRightMiddleVisible_Out);
		VARInitO(md_ObjBaselayerCircleRightMiddleOpacity_Out);

		VARInitO(mb_ObjBaselayerCircleDefaultLeftMiddleVisible_Out);
		VARInitO(md_ObjBaselayerCircleDefaultLeftMiddleOpacity_Out);

		VARInitO(mb_ObjBaselayerCircleDefaultRightMiddleVisible_Out);
		VARInitO(md_ObjBaselayerCircleDefaultRightMiddleOpacity_Out);

		VARInitO(mb_ObjhandsOnBigVisible_Out);
		VARInitO(md_ObjhandsOnBigOpacity_Out);

		VARInitO(mb_ObjBaselayerCircleDefaultVisible_Out);
		VARInitO(md_ObjBaselayerCircleDefaultOpacity_Out);

		// icons
		VARInitO(mb_ObjIconRejectVisible_Out);
		VARInitO(md_ObjIconRejectOpacity_Out);

		VARInitO(mb_ObjIconAcceptVisible_Out);
		VARInitO(md_ObjIconAcceptOpacity_Out);

		VARInitO(mb_ObjIconRejectMiddleVisible_Out);
		VARInitO(md_ObjIconRejectMiddleOpacity_Out);

		VARInitO(mb_ObjIconAcceptMiddleVisible_Out);
		VARInitO(md_ObjIconAcceptMiddleOpacity_Out);

		VARInitO(mb_ObjArrowDownVisible_Out);
		VARInitO(md_ObjArrowDownOpacity_Out);

		VARInitO(mb_ObjStreetVisible_Out);
		VARInitO(md_ObjStreetOpacity_Out);

		VARInitO(mb_ObjArrowLeftVisible_Out);
		VARInitO(md_ObjArrowLeftOpacity_Out);

		VARInitO(mb_ObjTimerVisible_Out);
		VARInitO(md_ObjTimerOpacity_Out);
		VARInitO(md_ObjTimerValue_Out);

		VARInitO(mb_ObjDefault0_Visible_Out);
		VARInitO(md_ObjDefault0_Opacity_Out);

		VARInitO(mb_ObjDefault1_Visible_Out);
		VARInitO(md_ObjDefault1_Opacity_Out);

		VARInitO(mb_ObjDefault2_Visible_Out);
		VARInitO(md_ObjDefault2_Opacity_Out);


		VARInitO(mb_PlaySoundRequest_Out);
		VARInitO(mb_PlaySoundAccept_Out);
		VARInitO(mb_PlaySoundReject_Out);

		VARInitO(mb_DefaultSound_Out);
		VARInitO(mb_AcceptSound_Out);
		VARInitO(mb_RejectSound_Out);
	}
};

// ------------------------------------------------------------------
// cSPUCooperation_and_Interface
// ------------------------------------------------------------------

// The class cSPUCooperation_and_Interface is the main class of the SPU.
// Its methods are called by SILAB during the simulation.
class SPUCooperation_and_Interface_API cSPUCooperation_and_Interface : public cSPU
{
public:
	// This macro creates some methods that every SPU must override.
	// The project name is passed as an argument so that the macro can
	// expand the class name correctly.
	SPU_Init(Cooperation_and_Interface);
	~cSPUCooperation_and_Interface();

protected:

	// The interface structure is instantiated here. The contained variables
	// are used to connect to other DPUs.
	sSPUCooperation_and_Interface m_Data;

	// *** SPU Control Flow *** //
	// The following methods of the SPU class are called by SILAB at certain points in time
	// during the simulation. A detailed description is found in the class cSPU.
	// The methods are declared in the order in which they are usually called during a simulation.

	// Generic initialization of the SPU. Is executed when the SPU is loaded.
	void cSPUCooperation_and_InterfaceInit()
	{
	}
	// Is called once when a configuration is loaded in SILAB.
	// Task: Preparation steps that might take a long time, such as reading configuration
	//       files, precomputing tables, etc.
	// Return: true  -> Preparation succeeded.
	// 		   false -> An error occurred during the preparation.
	virtual bool Prepare();
	// Called periodically while the simulation is running.
	// Task: Implement the SPU's functionality during the simulation.
	// Each call shouldn't take more than 1 ms to complete.
	///
	virtual void Trigger(double d_TimeMS, double d_TimeErrorMS);
	// Generic cleanup of the SPU.
	// The method will be called when the simulation is shut down,
	// no matter if the shutdown is regular or using the 'emergency stop' (x)
	// button.
	// Warning: Cleanup() may be called more than once.
	//          Cleanup() may be called in any state of the simulation, because
	//          it is always possible to shut down the simulation.
	// Task: Release all resources held by the SPU.
	virtual void Cleanup();

	// own functions
	void mapOutput();	// sets all the DPU's outputs to the current value

	void handleRequest(double d_TimeMS);

	void exitREQUEST();

	void handleRejection();

	void handleAcception();

	void doCooperation();

	void gotoIDLE();

	void disableAutomation();

	void entryCooperation_TOR();

	void exitIDLE();

	double SlowDown();

	void showInterface(bool show, double speed);

	void showDefaultAction(bool show, double speed);

	Linear * LinearTimer;

	double decisionTime;

	private:

	// ==========================================================================================
	// Cooperation
	// ==========================================================================================
	double x_position;	// current x_position of EGO-Car
	int pos;			// current number of request
	int state;			// current state
	int type;			// current type of request
	int defaultAction;
	int laneChange;
	double targetSpeed;

	bool decisionTime_over;
	bool decisionDefault;
	bool cooperation_finished;

	// SlowDown
	double x_start;	// point, where slowdown begins
	double x_end;	// point, where slowdown ends
	double d;		// distance to the point, where EGO-Car has v_end (x_start - x_end)
	double v_start;	// velocity befor slowdown
	double v_end;	// velocity after slowdown
	double delta_v;	// v_end - v_start (delta_v < 0)
	double v;		// new velocity, which is given to

	bool playDefaultSound;

	bool blinkerStart;
	bool blinkerOn;
	bool automationEnabled;

	int *accepted_arr;
	int *rejected_arr;
	int *delay_distance_arr;

	bool accepted;
	bool rejected;

	VisualObject * BaselayerDefaultA;
	VisualObject * BaselayerDefaultB;
	VisualObject * BaselayerDefaultC;

	// ==========================================================================================
	// Interface
	// ==========================================================================================
	VisualObject * BaselayerCircleBig;
	VisualObject * BaselayerCircleLeft;
	VisualObject * BaselayerCircleRight;
	VisualObject * BaselayerCircleLeftMiddle;
	VisualObject * BaselayerCircleRightMiddle;
	VisualObject * BaselayerCircleDefaultLeftMiddle;
	VisualObject * BaselayerCircleDefaultRightMiddle;
	VisualObject * handsOnBig;
	VisualObject * BaselayerCircleDefault;
	VisualObject * IconReject;
	VisualObject * IconAccept;
	VisualObject * IconRejectMiddle;
	VisualObject * IconAcceptMiddle;
	VisualObject * ArrowDown;
	VisualObject * ArrowLeft;
	VisualObject * Street;
	VisualObject * Timer;

	VisualObject * Default0;
	VisualObject * Default1;
	VisualObject * Default2;

	bool playRequestSound;
	bool playAcceptSound;
	bool playRejectSound;
};

#endif
