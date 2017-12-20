// *******************************************************
// ********************** BaseLayer **********************
// *******************************************************

// background circle for timer and arrow
DPUSGEObject ObjBaselayerCircleBig {
	Index = 40;
	Computer = {VIS};
	Object = "models.BaselayerCircle";
	X = 530;
	Y = 600;
	
	// grey background color
	ColR = 0.6;
	ColG = 0.6;
	ColB = 0.6;
	ColA = 0.8;
	
	Show = 1;
};

// background circle for reject icon
DPUSGEObject ObjBaselayerCircleLeft {
	Index = 40;
	Computer = {VIS};
	Object = "models.BaselayerCircle";
	X = 420;
	Y = 620;
	
	// red background color
	ColR = 0.96;
	ColG = 0.33;
	ColB = 0.26;
	ColA = 0.9;
	
	sX = 0.5;
	sY = 0.5;
	
	Show = 1;
};

// background circle for accept icon
DPUSGEObject ObjBaselayerCircleRight {
	Index = 40;
	Computer = {VIS};
	Object = "models.BaselayerCircle";
	X = 610;
	Y = 620;
	
	// green background color
	ColR = 0.18;
	ColG = 0.8;
	ColB = 0.44;
	ColA = 0.9;
  
	sX = 0.5;
	sY = 0.5;
	
	Show = 1;
};

// reject icon
DPUSGEObject ObjIconReject {
  Index = 50;
  Computer = {VIS};
  Object = "models.Reject";
  X = 406;
  Y = 636;
  
  sX = 0.18;
  sY = 0.18;
  
  ColR = 1;
  ColG = 1;
  ColB = 1;
  
  Show = 1;

};

// accept icon
DPUSGEObject ObjIconAccept {
  Index = 50;
  Computer = {VIS};
  Object = "models.Check";
  X = 594;
  Y = 636;
  
  sX = 0.18;
  sY = 0.18;
  
  ColR = 1;
  ColG = 1;
  ColB = 1;
  
  Show = 1;
};

// background circle for reject icon
DPUSGEObject ObjBaselayerCircleLeftMiddle {
	Index = 40;
	Computer = {VIS};
	Object = "models.BaselayerCircle";
	X = 2130;
	Y = 1230;
	
	// red background color
	ColR = 0.96;
	ColG = 0.33;
	ColB = 0.26;
	ColA = 0.9;
	
	sX = 0.7;
	sY = 0.7;
	
	Show = 1;
};

// background circle for accept icon
DPUSGEObject ObjBaselayerCircleRightMiddle {
	Index = 40;
	Computer = {VIS};
	Object = "models.BaselayerCircle";
	//X = 2130;
	//Y = 1230;
	X = 610;
	Y = 620;
	
	// green background color
	ColR = 0.18;
	ColG = 0.8;
	ColB = 0.44;
	ColA = 0.9;
  
	sX = 0.7;
	sY = 0.7;
	
	Show = 1;
};

// reject icon
DPUSGEObject ObjIconRejectMiddle {
  Index = 50;
  Computer = {VIS};
  Object = "models.Reject";
  X = 2112;
  Y = 1253;
	
  sX = 0.28;
  sY = 0.28;
  
  ColR = 1;
  ColG = 1;
  ColB = 1;
  
  Show = 1;

};

// accept icon
DPUSGEObject ObjIconAcceptMiddle {
  Index = 50;
  Computer = {VIS};
  Object = "models.Check";
  X = 2111;
  Y = 1253;
  
  sX = 0.28;
  sY = 0.28;
  
  ColR = 1;
  ColG = 1;
  ColB = 1;
  
  Show = 1;
};

// Street background for arrow
DPUSGEObject ObjStreet {
  Index = 50;
  Computer = {VIS};
  Object = "models.street";
  
  X = 503;
  Y = 627;
  
  sX = 0.39;
  sY = 0.39;
 
  ColR = 1;
  ColG = 1;
  ColB = 1;
  
  Show = 1;
};

// Arrow slow down
DPUSGEObject ObjArrowDown {
  Index = 50;
  Computer = {VIS};
  Object = "models.ArrowDown";
  
  X = 500;
  Y = 628;
  
  sX = 0.5;
  sY = 0.5;
 
  ColR = 1;
  ColG = 1;
  ColB = 1;
  
  Show = 0;
};

// Arrow lanechange
DPUSGEObject ObjArrowLeft {
  Index = 50;
  Computer = {VIS};
  Object = "models.ArrowLeft";
  
  X = 501;
  Y = 632;
  
  sX = 0.5;
  sY = 0.5;
  
  ColR = 1;
  ColG = 1;
  ColB = 1;
  
  Show = 1;
};

// Default symbol for reject
DPUSGEObject ObjDefault0 {
  Index = 50;
  Computer = {VIS};
  Object = "models.RejectDefault";
  
  X = 501;
  Y = 630;
  
  sX = 0.5;
  sY = 0.5;
  
  ColR = 1;
  ColG = 1;
  ColB = 1;
  
  Show = 0;
};

// Default symbol for accept
DPUSGEObject ObjDefault1 {
  Index = 50;
  Computer = {VIS};
  Object = "models.AcceptDefault";
  
  X = 501;
  Y = 630;
  
  sX = 0.5;
  sY = 0.5;
  
  ColR = 1;
  ColG = 1;
  ColB = 1;
  
  Show = 1;
};

// TOR symbol 
DPUSGEObject ObjhandsOnBig {
  Index = 50;
  Computer = {VIS};
  Object = "models.handsOnBig";
  
	X = 530;
	Y = 600;
  
  sX = 0.5;
  sY = 0.5;
  
  ColR = 1;
  ColG = 1;
  ColB = 1;
  
  Show = 1;
};

// Timer visualization
DPUSGEObject ObjTimer {
  Index = 60;
  Computer = {VIS};
  Object = "models.Timer";
  X = 501.5;
  Y = 631.5;
  
  NMaxParams = 1;
  
  Param1.X = 4.35; // Radius Inner
  Param1.Y = 4.65; // Radius Outer
  Param1.Z = 1.0; // Nothing
  Param1.W = 0.75; // Circle Percentage
  
  rX = 90;
   
  ColR = 0.16;
  ColG = 0.5;
  ColB = 0.73;
  ColA = 0.8;
  
  Show = 1;
};

// *******************************************************
// ********************** Sounds *********************
// *******************************************************


DPUMediaPlayer MediaSoundRequest {
  Computer = {MOCKUP};
  Index = 100;
  Volume = 1.0; 
  MediaFile = "sounds/request.wav";
};

DPUMediaPlayer MediaSoundAccept {
  Computer = {MOCKUP};
  Index = 100;
  Volume = 1.0; 
  MediaFile = "sounds/yes.mp3";
};

DPUMediaPlayer MediaSoundReject {
  Computer = {MOCKUP};
  Index = 100;
  Volume = 1.0; 
  MediaFile = "sounds/no.wav";
};










