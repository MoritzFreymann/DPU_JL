// ********************************************************
// ************** Cooperation_and_Interface ***************
// ********************************************************

DPUCooperation_and_Interface Cooperation_and_Interface
{
	Computer = {TRF};
	Index = 10;
	
	DecisionTime = 7;
	AutomationActive_In = 0;		#
	
	// 0: default action is reject, 1: default action is accept, 2: automation gets disabled
	DefaultAction = 2;
	
	TargetSpeed_In = 33.33;		#120 km/h
	BrakeSpeed_In = 25.00;		#90 km/h			27.67;		#100 km/h
	x_end = 300.00;				
	
	# delay distances
	delay_distance_1 = 150;
	delay_distance_2 = 0;
	delay_distance_3 = 0;
	delay_distance_4 = 0;
	delay_distance_5 = 0;
	delay_distance_6 = 0;
	delay_distance_7 = 0;
	delay_distance_8 = 0;
	delay_distance_9 = 0;
	
};


// *********************************************************
// *************** Hedgehogs für Situation *****************
// *********************************************************
# GameCase
DPUSCNXHedgehogKiller CaseTrigger
{
	Computer = {TRF};
	Index = 60;
	Family = "Situation";
	Name1 = "ID";
	// identifier for each situation
	Default1 = 0;
	// TYPE = '1': slow down, TYPE = '2' : lane change
	Name2 = "TYPE";
	Default2 = 0;
	OutMode1 = (MonoFlop, 7500);
};
		
	DPUBooleanGate ~OR_Accept
		{
			Computer = {MOCKUP};
			Index = 5;
			Channels = 2;
			Gate = OR;
		};		
		
	DPUBooleanGate ~OR_Reject
		{
			Computer = {MOCKUP};
			Index = 5;
			Channels = 2;
			Gate = OR;
		};		
		
		
Connections = {

	VDyn.v -> Cooperation_and_Interface.Speed_In,
	VDyn.X -> Cooperation_and_Interface.position_x,
	# Cooperation_and_Interface.velocity_Out -> VDyn.v,								# schau ma mal
	CaseTrigger.Out1 ->  Cooperation_and_Interface.RequestID_In,		
	CaseTrigger.Out2 ->  Cooperation_and_Interface.RequestType_In,
	#~ZBECAN.wheelDOWN -> Cooperation_and_Interface.AcceptButtonPressed_In,			#Tastenbelegung Accept
	#~ZBECAN.paddleRIGHTPUSH -> Cooperation_and_Interface.AcceptButtonPressed_In,
	#~ZBECAN.wheelMINUS -> Cooperation_and_Interface.RejectButtonPressed_In,		#Tastenbelegung Reject
	#~ZBECAN.paddleLEFTPUSH -> Cooperation_and_Interface.RejectButtonPressed_In,
	Keyboard.Return -> Cooperation_and_Interface.AcceptButtonPressed_In,
	Keyboard.Back  -> Cooperation_and_Interface.RejectButtonPressed_In,
  
	Cooperation_and_Interface.Accepted1_Out -> TRFX.ExternTrigger01,
	Cooperation_and_Interface.Rejected1_Out -> TRFX.ExternTrigger11,
	Cooperation_and_Interface.Accepted2_Out -> TRFX.ExternTrigger02,
	Cooperation_and_Interface.Rejected2_Out -> TRFX.ExternTrigger12,
	Cooperation_and_Interface.Accepted3_Out -> TRFX.ExternTrigger03,
	Cooperation_and_Interface.Rejected3_Out -> TRFX.ExternTrigger13,
	Cooperation_and_Interface.Accepted4_Out -> TRFX.ExternTrigger04,
	Cooperation_and_Interface.Rejected4_Out -> TRFX.ExternTrigger14,
	Cooperation_and_Interface.Accepted5_Out -> TRFX.ExternTrigger05,
	Cooperation_and_Interface.Rejected5_Out -> TRFX.ExternTrigger15,
	Cooperation_and_Interface.Accepted6_Out -> TRFX.ExternTrigger06,
	Cooperation_and_Interface.Rejected6_Out -> TRFX.ExternTrigger16,
  

  
  # Background Reject Request-Interface
  Cooperation_and_Interface.ObjBaselayerCircleLeftVisible_Out -> ObjBaselayerCircleLeft.Show,
  Cooperation_and_Interface.ObjBaselayerCircleLeftOpacity_Out -> ObjBaselayerCircleLeft.ColA,
  Cooperation_and_Interface.ObjBaselayerCircleLeftColorRed_Out -> ObjBaselayerCircleLeft.ColR,
  Cooperation_and_Interface.ObjBaselayerCircleLeftColorGreen_Out -> ObjBaselayerCircleLeft.ColG,
  Cooperation_and_Interface.ObjBaselayerCircleLeftColorBlue_Out -> ObjBaselayerCircleLeft.ColB,
 
  # Background Accept Request-Interface
  Cooperation_and_Interface.ObjBaselayerCircleRightVisible_Out -> ObjBaselayerCircleRight.Show,
  Cooperation_and_Interface.ObjBaselayerCircleRightOpacity_Out -> ObjBaselayerCircleRight.ColA,
  Cooperation_and_Interface.ObjBaselayerCircleRightColorRed_Out -> ObjBaselayerCircleRight.ColR,
  Cooperation_and_Interface.ObjBaselayerCircleRightColorGreen_Out -> ObjBaselayerCircleRight.ColG,
  Cooperation_and_Interface.ObjBaselayerCircleRightColorBlue_Out -> ObjBaselayerCircleRight.ColB,
  
  # Reject-Icon Request-Interface
  Cooperation_and_Interface.ObjIconRejectVisible_Out -> ObjIconReject.Show,
  Cooperation_and_Interface.ObjIconRejectOpacity_Out -> ObjIconReject.ColA,
  
  # Accept-Icon Request-Interface
  Cooperation_and_Interface.ObjIconAcceptVisible_Out -> ObjIconAccept.Show,
  Cooperation_and_Interface.ObjIconAcceptOpacity_Out -> ObjIconAccept.ColA,
  
  # Background Request-Interface
  Cooperation_and_Interface.ObjBaselayerCircleBigVisible_Out -> ObjBaselayerCircleBig.Show,
  Cooperation_and_Interface.ObjBaselayerCircleBigOpacity_Out -> ObjBaselayerCircleBig.ColA,
  
  # Arrow-Down-Icon Request-Interface
  Cooperation_and_Interface.ObjArrowDownVisible_Out -> ObjArrowDown.Show,
  Cooperation_and_Interface.ObjArrowDownOpacity_Out -> ObjArrowDown.ColA,
  
  # Street-Icon Request-Interface
  Cooperation_and_Interface.ObjStreetVisible_Out -> ObjStreet.Show,
  Cooperation_and_Interface.ObjStreetOpacity_Out -> ObjStreet.ColA,
  
  # Arrow-Left-Icon Request-Interface
  Cooperation_and_Interface.ObjArrowLeftVisible_Out -> ObjArrowLeft.Show,
  Cooperation_and_Interface.ObjArrowLeftOpacity_Out -> ObjArrowLeft.ColA,
  
  # Timer Request-Interface
  Cooperation_and_Interface.ObjTimerVisible_Out -> ObjTimer.Show,
  Cooperation_and_Interface.ObjTimerOpacity_Out -> ObjTimer.ColA,
  Cooperation_and_Interface.ObjTimerValue_Out -> ObjTimer.Param1.W,
  
   # TOR-Icon
  Cooperation_and_Interface.ObjhandsOnBigVisible_Out -> ObjhandsOnBig.Show,
  Cooperation_and_Interface.ObjhandsOnBigOpacity_Out -> ObjhandsOnBig.ColA,
  
  ###
  Cooperation_and_Interface.ObjBaselayerCircleLeftMiddleVisible_Out -> ObjBaselayerCircleLeftMiddle.Show,
  Cooperation_and_Interface.ObjBaselayerCircleLeftMiddleOpacity_Out -> ObjBaselayerCircleLeftMiddle.ColA,
  
  Cooperation_and_Interface.ObjIconRejectMiddleVisible_Out -> ObjIconRejectMiddle.Show,
  Cooperation_and_Interface.ObjIconRejectMiddleOpacity_Out -> ObjIconRejectMiddle.ColA,
  
  Cooperation_and_Interface.ObjBaselayerCircleRightMiddleVisible_Out -> ObjBaselayerCircleRightMiddle.Show,
  Cooperation_and_Interface.ObjBaselayerCircleRightMiddleOpacity_Out -> ObjBaselayerCircleRightMiddle.ColA,
  
  Cooperation_and_Interface.ObjIconAcceptMiddleVisible_Out -> ObjIconAcceptMiddle.Show,
  Cooperation_and_Interface.ObjIconAcceptMiddleOpacity_Out -> ObjIconAcceptMiddle.ColA,
  
  Cooperation_and_Interface.ObjDefault0_Visible_Out -> ObjDefault0.Show,
  Cooperation_and_Interface.ObjDefault0_Opacity_Out -> ObjDefault0.ColA,
  
  Cooperation_and_Interface.ObjDefault1_Visible_Out -> ObjDefault1.Show,
  Cooperation_and_Interface.ObjDefault1_Opacity_Out -> ObjDefault1.ColA,
  
  Cooperation_and_Interface.ObjDefault2_Visible_Out -> ObjDefault2.Show,
  Cooperation_and_Interface.ObjDefault2_Opacity_Out -> ObjDefault2.ColA,
  

  
  
// *******************************************************
// ********************** Sounds *************************
// *******************************************************
  
  Cooperation_and_Interface.PlaySoundRequest_Out	<-> MediaSoundRequest.Start,	#Request Sound
  
  Cooperation_and_Interface.PlaySoundAccept_Out	<-> ~OR_Accept.In1,					#Accept Sound
  Cooperation_and_Interface.AcceptSound_Out 				<-> ~OR_Accept.In2,
  ~OR_Accept.Out 							<-> MediaSoundAccept.Start,
 
  Cooperation_and_Interface.PlaySoundReject_Out 	<-> ~OR_Reject.In1,				#Reject Sound
  Cooperation_and_Interface.RejectSound_Out 				<-> ~OR_Reject.In2,
  ~OR_Reject.Out 							<-> MediaSoundReject.Start,
  
  Cooperation_and_Interface.DefaultSound_Out				<->	Warnungen.Start		#TOR Sound
};