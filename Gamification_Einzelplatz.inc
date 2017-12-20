// *******************************************************
// ********************** Gamification Interface **********************
// *******************************************************

DPUGamificationSandra Gamification
{
	Computer = {TRF};
	Index = 60;
};

DPUScreenPosition Pos
{
	Computer = {TRF};
	Index = 65;
	OffsetX_In = 70;
	OffsetY_In = -40;
	Param_In = 2;
	MaxY_In = 350;
};

DPUSGEObject ObjKarma0 {
	Index = 40;
	Computer = {VIS};
	Object = "models.karma0";
	X = 1000;
	Y = 770;

	sX = 2.0;
	sY = 2.0;
	Show = 0;
};

DPUSGEObject ObjKarma1 {
	Index = 40;
	Computer = {VIS};
	Object = "models.karma1";
	X = 1000;
	Y = 770;

	sX = 2.0;
	sY = 2.0;
	Show = 0;
};


DPUSGEObject ObjKarma2 {
	Index = 40;
	Computer = {VIS};
	Object = "models.karma2";
	X = 1000;
	Y = 770;

	sX = 2.0;
	sY = 2.0;
	Show = 0;
};

DPUSGEObject ObjKarma3 {
	Index = 40;
	Computer = {VIS};
	Object = "models.karma3";
	X = 1000;
	Y = 770;

	sX = 2.0;
	sY = 2.0;
	Show = 0;
};

DPUSGEObject ObjKarma4 {
	Index = 40;
	Computer = {VIS};
	Object = "models.karma4";
	X = 1000;
	Y = 770;

	sX = 2.0;
	sY = 2.0;
	Show = 0;
};

DPUSGEObject ObjKarma5 {
	Index = 40;
	Computer = {VIS};
	Object = "models.karma5";
	X = 1000;
	Y = 770;

	sX = 2.0;
	sY = 2.0;
	Show = 0;
};

DPUSGEObject ObjKarma6 {
	Index = 40;
	Computer = {VIS};
	Object = "models.karma6";
	X = 1000;
	Y = 770;

	sX = 2.0;
	sY = 2.0;
	Show = 0;
};

DPUSGEObject ObjNarrative {
	Index = 40;
	Computer = {VIS};
	Object = "models.narrative";
	X = 700;
	Y = 600;

	sX = 2;
	sY = 2;
	
	Show = 0;
};

DPUSGEObject ObjFeedback1 {
	Index = 40;
	Computer = {VIS};
	Object = "models.feedback1";
	X = 700;
	Y = 600;

	sX = 2;
	sY = 2;
	
	Show = 0;
};

DPUSGEObject ObjFeedback2 {
	Index = 40;
	Computer = {VIS};
	Object = "models.feedback2";
	X = 700;
	Y = 600;

	sX = 2;
	sY = 2;
	
	Show = 0;
};

DPUSGEObject ObjFeedback3 {
	Index = 40;
	Computer = {VIS};
	Object = "models.feedback3";
	X = 700;
	Y = 600;

	sX = 2;
	sY = 2;
	
	Show = 0;
};

DPUSGEObject ObjFeedback4 {
	Index = 40;
	Computer = {VIS};
	Object = "models.feedback4";
	X = 700;
	Y = 600;

	sX = 2;
	sY = 2;
	
	Show = 0;
};

DPUSGEObject ObjFeedback5 {
	Index = 40;
	Computer = {VIS};
	Object = "models.feedback5";
	X = 700;
	Y = 600;

	sX = 2;
	sY = 2;
	
	Show = 0;
};

DPUSGEObject ObjFeedback6 {
	Index = 40;
	Computer = {VIS};
	Object = "models.feedback6";
	X = 700;
	Y = 600;

	sX = 2;
	sY = 2;
	
	Show = 0;
};

DPUSGEProjection Proj {
	Computer = {VIS}; 
	Index = 12; 
};


DPUSGEObject ObjName1 {
	Index = 100;
	Computer = {VIS};
	Object = "models.name1";
	sX = 0.8;
	sY = 0.8;
};

DPUSGEObject ObjName2 {
	Index = 100;
	Computer = {VIS};
	Object = "models.name2";
	sX = 0.8;
	sY = 0.8;
};

DPUSGEObject ObjName3 {
	Index = 100;
	Computer = {VIS};
	Object = "models.name3";
	sX = 0.8;
	sY = 0.8;
};

DPUSGEObject ObjName4 {
	Index = 100;
	Computer = {VIS};
	Object = "models.name4";
	sX = 0.8;
	sY = 0.8;
};

DPUSGEObject ObjName5 {
	Index = 100;
	Computer = {VIS};
	Object = "models.name5";
	sX = 0.8;
	sY = 0.8;
};

DPUSGEObject ObjName6 {
	Index = 100;
	Computer = {VIS};
	Object = "models.name6";
	sX = 0.8;
	sY = 0.8;
};

DPUTRFDataSingle PartnerInfo {
	Index = 100;
	Computer = {TRF};
	UserID1 = 1;
	UserID2 = 2;
	UserID3 = 3;
	UserID4 = 4;
	UserID5 = 5;
	UserID6 = 6;
};

DPUMediaPlayer MediaSoundWin {
  Computer = {MOCKUP};
  Index = 100;
  Volume = 1.0; 
  MediaFile = "sounds/win.wav";
};


Connections = {

  CaseTrigger.Out1 ->  Gamification.User_ID_In,

  PartnerInfo.X1 -> Proj.Coord1.X,
  PartnerInfo.Y1 -> Proj.Coord1.Y,
  PartnerInfo.Z1 -> Proj.Coord1.Z,
  
  PartnerInfo.X2 -> Proj.Coord2.X,
  PartnerInfo.Y2 -> Proj.Coord2.Y,
  PartnerInfo.Z2 -> Proj.Coord2.Z,
  
  PartnerInfo.X3 -> Proj.Coord3.X,
  PartnerInfo.Y3 -> Proj.Coord3.Y,
  PartnerInfo.Z3 -> Proj.Coord3.Z,
  
  PartnerInfo.X4 -> Proj.Coord4.X,
  PartnerInfo.Y4 -> Proj.Coord4.Y,
  PartnerInfo.Z4 -> Proj.Coord4.Z,
  
  PartnerInfo.X5 -> Proj.Coord5.X,
  PartnerInfo.Y5 -> Proj.Coord5.Y,
  PartnerInfo.Z5 -> Proj.Coord5.Z,
  
  PartnerInfo.X6 -> Proj.Coord6.X,
  PartnerInfo.Y6 -> Proj.Coord6.Y,
  PartnerInfo.Z6 -> Proj.Coord6.Z,
  
  Proj.Coord1.WindowX <-> Pos.Coord1X_In,
  Pos.Coord1X_Out <-> ObjName1.X,
  Proj.Coord1.WindowY <->  Pos.Coord1Y_In,
  Pos.Coord1Y_Out <-> ObjName1.Y,
  
  Proj.Coord2.WindowX <-> Pos.Coord2X_In,
  Pos.Coord2X_Out <-> ObjName2.X,
  Proj.Coord2.WindowY <->  Pos.Coord2Y_In,
  Pos.Coord2Y_Out <-> ObjName2.Y,
  
  Proj.Coord3.WindowX <-> Pos.Coord3X_In,
  Pos.Coord3X_Out <-> ObjName3.X,
  Proj.Coord3.WindowY <->  Pos.Coord3Y_In,
  Pos.Coord3Y_Out <-> ObjName3.Y,
  
  Proj.Coord4.WindowX <-> Pos.Coord4X_In,
  Pos.Coord4X_Out <-> ObjName4.X,
  Proj.Coord4.WindowY <->  Pos.Coord4Y_In,
  Pos.Coord4Y_Out <-> ObjName4.Y,
  
  Proj.Coord5.WindowX <-> Pos.Coord5X_In,
  Pos.Coord5X_Out <-> ObjName5.X,
  Proj.Coord5.WindowY <->  Pos.Coord5Y_In,
  Pos.Coord5Y_Out <-> ObjName5.Y,
  
  Proj.Coord6.WindowX <-> Pos.Coord6X_In,
  Pos.Coord6X_Out <-> ObjName6.X,
  Proj.Coord6.WindowY <->  Pos.Coord6Y_In,
  Pos.Coord6Y_Out <-> ObjName6.Y,

  Cooperation_and_Interface.CooperationState_Out ->  Gamification.State_In,
  Cooperation_and_Interface.Accepted_Out ->  Gamification.Accepted_In,
 #  Cooperation.CooperationState_Out ->  Gamification.State_In,
 #  Cooperation.Accepted_Out ->  Gamification.Accepted_In,
  
  Gamification.ObjNarrative_Visible_Out -> ObjNarrative.Show,
  Gamification.ObjNarrative_Opacity_Out -> ObjNarrative.ColA,
  
  Gamification.ObjKarma0_Visible_Out -> ObjKarma0.Show,
  Gamification.ObjKarma0_Opacity_Out -> ObjKarma0.ColA,
  Gamification.ObjKarma1_Visible_Out -> ObjKarma1.Show,
  Gamification.ObjKarma1_Opacity_Out -> ObjKarma1.ColA,
  Gamification.ObjKarma2_Visible_Out -> ObjKarma2.Show,
  Gamification.ObjKarma2_Opacity_Out -> ObjKarma3.ColA,
  Gamification.ObjKarma3_Visible_Out -> ObjKarma3.Show,
  Gamification.ObjKarma3_Opacity_Out -> ObjKarma3.ColA,
  Gamification.ObjKarma4_Visible_Out -> ObjKarma4.Show,
  Gamification.ObjKarma4_Opacity_Out -> ObjKarma4.ColA,
  Gamification.ObjKarma5_Visible_Out -> ObjKarma5.Show,
  Gamification.ObjKarma5_Opacity_Out -> ObjKarma5.ColA,
  Gamification.ObjKarma6_Visible_Out -> ObjKarma6.Show,
  Gamification.ObjKarma6_Opacity_Out -> ObjKarma6.ColA,
  
  Gamification.ObjFeedback1_Visible_Out -> ObjFeedback1.Show,
  Gamification.ObjFeedback1_Opacity_Out -> ObjFeedback1.ColA,
  Gamification.ObjFeedback2_Visible_Out -> ObjFeedback2.Show,
  Gamification.ObjFeedback2_Opacity_Out -> ObjFeedback3.ColA,
  Gamification.ObjFeedback3_Visible_Out -> ObjFeedback3.Show,
  Gamification.ObjFeedback3_Opacity_Out -> ObjFeedback3.ColA,
  Gamification.ObjFeedback4_Visible_Out -> ObjFeedback4.Show,
  Gamification.ObjFeedback4_Opacity_Out -> ObjFeedback4.ColA,
  Gamification.ObjFeedback5_Visible_Out -> ObjFeedback5.Show,
  Gamification.ObjFeedback5_Opacity_Out -> ObjFeedback5.ColA,
  Gamification.ObjFeedback6_Visible_Out -> ObjFeedback6.Show,
  Gamification.ObjFeedback6_Opacity_Out -> ObjFeedback6.ColA,
  
  Gamification.ObjName1_Visible_Out -> ObjName1.Show,
  Gamification.ObjName1_Opacity_Out -> ObjName1.ColA,
  
  Gamification.ObjName2_Visible_Out -> ObjName2.Show,
  Gamification.ObjName2_Opacity_Out -> ObjName2.ColA,
  
  Gamification.ObjName3_Visible_Out -> ObjName3.Show,
  Gamification.ObjName3_Opacity_Out -> ObjName3.ColA,
  
  Gamification.ObjName4_Visible_Out -> ObjName4.Show,
  Gamification.ObjName4_Opacity_Out -> ObjName4.ColA,
  
  Gamification.ObjName5_Visible_Out -> ObjName5.Show,
  Gamification.ObjName5_Opacity_Out -> ObjName5.ColA,
  
  Gamification.ObjName6_Visible_Out -> ObjName6.Show,
  Gamification.ObjName6_Opacity_Out -> ObjName6.ColA,
  
  
  Gamification.PlayWinSound_Out -> MediaSoundWin.Start
  
};