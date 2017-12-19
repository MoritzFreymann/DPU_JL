#include "DPUCooperation_and_Interface.h"

// The following definitions are required to integrate the SPU into the SILAB system.
SPU_Impl(Cooperation_and_Interface, SPUCooperation_and_Interface_API, 1.0, "")

// ------------------------------------------------------------------
// sSPUCooperation_and_Interface (Implementation)
// ------------------------------------------------------------------

sSPUCooperation_and_Interface::sSPUCooperation_and_Interface()
{
	sSPUCooperation_and_InterfaceInit();
}

// ------------------------------------------------------------------
// cSPUCooperation_and_Interface (Implementation)
// ------------------------------------------------------------------

cSPUCooperation_and_Interface::~cSPUCooperation_and_Interface()
{
	Cleanup();
}

bool cSPUCooperation_and_Interface::Prepare()
{
	// ==========================================================================================
	// Cooperation
	// ==========================================================================================

	// Conection to the Input-Variables of the DPU
	this->targetSpeed = m_Data.md_TargetSpeed_In;
	this->decisionTime = m_Data.md_DecisionTime;	// time the driver to make the decision 'reject' or 'accept'

	// Setting values
	this->pos = -1;
	this->state = IDLE;
	this->decisionTime_over		= false;
	this->cooperation_finished	= false;
	this->decisionDefault		= false;
	this->accepted = false;
	this->rejected = false;

	// SlowDown
	double x_start = 0;				// point, where slowdown begins
	double x_end = m_Data.md_x_end;	// point, where slowdown ends
	double d = 0;					// distance to the point, where EGO-Car has v_end (x_start - x_end)
	double v_start = 0;				// velocity befor slowdown
	double v_end = 0;				// velocity after slowdown
	double delta_v = 0;				// v_end - v_start (delta_v < 0)
	double v = 0;					// new velocity, which is given to

	this->accepted_arr = new int[9];
	this->accepted_arr[0] = 0;
	this->accepted_arr[1] = 0;
	this->accepted_arr[2] = 0;
	this->accepted_arr[3] = 0;
	this->accepted_arr[4] = 0;
	this->accepted_arr[5] = 0;
	this->accepted_arr[6] = 0;
	this->accepted_arr[7] = 0;
	this->accepted_arr[8] = 0;
	this->rejected_arr = new int[9];
	this->rejected_arr[0] = 0;
	this->rejected_arr[1] = 0;
	this->rejected_arr[2] = 0;
	this->rejected_arr[3] = 0;
	this->rejected_arr[4] = 0;
	this->rejected_arr[5] = 0;
	this->rejected_arr[6] = 0;
	this->rejected_arr[7] = 0;
	this->rejected_arr[8] = 0;;

	// delay distance
	this->delay_distance_arr = new int[9];
	this->delay_distance_arr[0] = m_Data.mi_delay_distance_1;
	this->delay_distance_arr[1] = m_Data.mi_delay_distance_2;
	this->delay_distance_arr[2] = m_Data.mi_delay_distance_3;
	this->delay_distance_arr[3] = m_Data.mi_delay_distance_4;
	this->delay_distance_arr[4] = m_Data.mi_delay_distance_5;
	this->delay_distance_arr[5] = m_Data.mi_delay_distance_6;
	this->delay_distance_arr[6] = m_Data.mi_delay_distance_7;
	this->delay_distance_arr[7] = m_Data.mi_delay_distance_8;
	this->delay_distance_arr[8] = m_Data.mi_delay_distance_9;

	// current position
	this->x_position = m_Data.md_x_position;

	this->laneChange = 0;		// no lane-change
	this->blinkerStart = 0;		//
	this->blinkerOn = 0;		// blinker off
	this->automationEnabled = m_Data.mi_AutomationActive_In;

	// sounds
	this->playDefaultSound = 0;
	this->playRequestSound = 0;
	this->playAcceptSound = 0;
	this->playRejectSound = 0;

	this->BaselayerDefaultC = new VisualObject(0, 0, 0, new ColorRGBA(0, 0, 0, 1), 0, false);
	this->BaselayerDefaultA = new VisualObject(0, 0, 0, new ColorRGBA(0.96, 0.33, 0.26, 0.9), 0, false);
	this->BaselayerDefaultB = new VisualObject(0, 0, 0, new ColorRGBA(0.18, 0.8, 0.44, 0.9), 0, false);

	// timer
	this->LinearTimer = new Linear();

	// ==========================================================================================
	// Interface
	// ==========================================================================================
	// Generate Visual Objects
	this->BaselayerCircleBig = new VisualObject(0, 0, 0, new ColorRGBA(0.6, 0.6, 0.6, 0.8), 0, false);					// Hintergrung fuer Timer und Pfeile
	this->BaselayerCircleLeft = new VisualObject(0, 0, 0, new ColorRGBA(0.96, 0.33, 0.26, 0.9), 0, false);			// Hintergrund fuer Reject-Icon
	this->BaselayerCircleRight = new VisualObject(0, 0, 0, new ColorRGBA(0.18, 0.8, 0.44, 0.9), 0, false);			// Hintergrund fuer Accept_Icon
	this->BaselayerCircleLeftMiddle = new VisualObject(0, 0, 0, new ColorRGBA(0.96, 0.33, 0.26, 0.9), 0, false);	// Hintergrund fuer Reject-Icon
	this->BaselayerCircleRightMiddle = new VisualObject(0, 0, 0, new ColorRGBA(0.18, 0.8, 0.44, 0.9), 0, false);	// Hintergrund fuer Accept_Icon

	this->IconReject = new VisualObject(0, 0, 0, new ColorRGBA(0.04,0.59,0.27,0.9), 0, false);			// Reject-Icon
	this->IconAccept = new VisualObject(0, 0, 0, new ColorRGBA(0.04,0.59,0.27,0.9), 0, false);			// Accept_Icon
	this->IconRejectMiddle = new VisualObject(0, 0, 0, new ColorRGBA(0.04,0.59,0.27,0.9), 0, false);	// Reject-Icon
	this->IconAcceptMiddle = new VisualObject(0, 0, 0, new ColorRGBA(0.04,0.59,0.27,0.9), 0, false);	// Accept_Icon
	this->ArrowDown = new VisualObject(0, 0, 0, new ColorRGBA(1, 1, 1, 0.9), 0, false);			// Pfeil fuer Request Slow-Down
	this->ArrowLeft = new VisualObject(0, 0, 0, new ColorRGBA(1, 1, 1, 0.9), 0, false);			// Pfeil fuer Request Lane-Change
	this->Street = new VisualObject(0, 0, 0, new ColorRGBA(1, 1, 1, 0.9), 0, false);				// Strasse
	this->Timer = new VisualObject(0, 0, 0, new ColorRGBA(0.16, 0.5, 0.73, 0.8), 0, false);						// Timer

	this->Default0 = new VisualObject(0, 0, 0, new ColorRGBA(1, 1, 1, 0.8), 0, false);
	this->Default1 = new VisualObject(0, 0, 0, new ColorRGBA(1, 1, 1, 0.8), 0, false);
	this->Default2 = new VisualObject(0, 0, 0, new ColorRGBA(1, 1, 1, 0.8), 0, false);

	return true;
}

void cSPUCooperation_and_Interface::Trigger(double d_TimeMS, double d_TimeErrorMS)
{
	// ==========================================================================================
	// there is a switch-case-structure to switch between the different states
	// in each state different functions are excecuted
	// in the end all the variables are output
	// ==========================================================================================
	
	this->defaultAction = m_Data.mi_DefaultAction +3;	// 0->REJECT, 1->ACCEPT, 2->STOP_AUTOMATION

	switch (this->state)
	{
	// IDLE
	case IDLE:
	
		// transition
		if ( (int)m_Data.mi_RequestID_In > (this->pos + 1) )	// checking, if there is a new request 
		{
			// there is a new request
			this->state = DELAY;

			// exit
			this->exitIDLE();
		}

		break;	// exit switch, so trigger can go on

	// DELAY
	case DELAY:

		//transition
		if ( ( (double)m_Data.md_position_x - this->x_position ) >= this->delay_distance_arr[this->pos] )	//checking, if the distance since hedgehog is bigger than delay-distance
		{
			this->state = REQUEST;
		}
		break;	// exit switch, so trigger can go on

	// REQUEST
	case REQUEST:
		// do
		this->handleRequest(d_TimeMS);	// handle request

		// transition
		if (this->decisionTime_over)
		{
			this->state = this->defaultAction;	// go to the default state (REJECT, ACCEPT or DIASABLE_AUTOMATION)
			g_LogSys << "DPUCooperativeMotorwayMerge: DEFAULT " << endl;
		}
		else if(m_Data.mb_AcceptButtonPressed_In)
		{
			g_LogSys << "DPUCooperativeMotorwayMerge: ACCEPT COOPERATION" << endl;
			this->state = ACCEPT;	// go to state ACCEPT
		}
		else if (m_Data.mb_RejectButtonPressed_In)
		{
			g_LogSys << "DPUCooperativeMotorwayMerge: REJECT COOPERATION" << endl;
			this->state = REJECT;	// go to state REJECT
		}
		// exit
		if (this->decisionTime_over || m_Data.mb_AcceptButtonPressed_In || m_Data.mb_RejectButtonPressed_In )
		{
			// exit-function
			this->exitREQUEST();
		}
		break;	// exit switch, so trigger can go on

	// REJECT
	case REJECT:
		// entry
		this->handleRejection();

		//transition
		if(m_Data.mi_AutomationActive_In == 1)
		{
			this->state = COOPERATION;
		}
		else
		{
			this->state = TOR;
		}
		break;	// exit switch, so trigger can go on

	// ACCEPT
	case ACCEPT:
		// entry
		this->handleAcception();
		//transition
		if(m_Data.mi_AutomationActive_In == 1)
		{
			this->state = COOPERATION;
		}
		else
		{
			this->state = TOR;
		}
		break;	// exit switch, so trigger can go on

	// STOP_AUTOMATION
	case STOP_AUTOMATION:
		//entry
		this->disableAutomation();
		//transition
		this->state = TOR;
		break;	// exit switch, so trigger can go on

	// COOPERATION
	case COOPERATION:
		// do
		this->doCooperation();
		// transition
		if ((double)m_Data.mi_RequestID_In < 0 || this->cooperation_finished)	// no request or cooperation finished
		{
			this->state = IDLE;
			// exit
			this->gotoIDLE();
		}
		break;	// exit switch, so trigger can go on
	// TOR
	case TOR:
		// transition
		if ( (double)m_Data.mi_RequestID_In < 0 )	// no request
		{
			this->state = IDLE;
			// exit
			this->gotoIDLE();
		}
		break;	// exit switch, so trigger can go on

	default:
		break;	// exit switch, so trigger can go on
		
	}

	// set output variables
	this->mapOutput();
}

void cSPUCooperation_and_Interface::exitIDLE()
{
	// ==========================================================================================
	// exit-function of state IDLE
	// gets the type and number of request
	// also the curent x_position for delay
	// ==========================================================================================

	this->type = (int)m_Data.mi_RequestType_In;		// type is either 1 (REQUEST_SLOWDOWN) or 2 (REQUEST_CHANGELANE)
	this->pos = (int)m_Data.mi_RequestID_In - 1;	// currrent number of request (1-6)

	this->x_position = m_Data.md_position_x;		// get current position for delay
}

void cSPUCooperation_and_Interface::handleRequest(double d_TimeMS)
{
	// ==========================================================================================
	// do-function of state REQUEST
	// starts the timer for the transition time and sets objects visibilty to 'true'
	// checks, if the transtion condition 'decisionTime_over' is true
	// ==========================================================================================

	// Set Objects Visibility to true	
	this->showInterface(true, 0.5);
	this->showDefaultAction(true, 0.5);

	// Show arrow
	if (type == REQUEST_SLOWDOWN)
	{
		this->ArrowDown->setVisibility(true, 0.5);
	}
	else if (type == REQUEST_LANECHANGE)
	{
		this->ArrowLeft->setVisibility(true, 0.5);
	}

	// Timer for decision time 
	if(!this->LinearTimer->isRunning() && !this->LinearTimer->isTriggered())	
	{
		// start timer

		// Initialize Timer
		this->LinearTimer->start(d_TimeMS, d_TimeMS + (double)m_Data.md_DecisionTime * 1000);
		
		this->playRequestSound = true;	// play sound

	} 
	else if(this->LinearTimer->isRunning() && LinearTimer->isTriggered())	
	{		
		// timer is running

		double time = this->LinearTimer->run(d_TimeMS);	// get time
		this->Timer->setValue(1-time);	// set remaining time
	}
	// condition 'time over'
	else if(!this->LinearTimer->isRunning() && LinearTimer->isTriggered())	
	{
		// time over
		this->decisionTime_over = true;
		this->decisionDefault = true;

		// reset trigger
		this->LinearTimer->resetTrigger();
	}
}

void cSPUCooperation_and_Interface::exitREQUEST()
{
	// ==========================================================================================
	// exit-function of state REQUEST
	// resets timer and hides objects
	// ==========================================================================================

	this->LinearTimer->stop();
	this->LinearTimer->resetTrigger();
	this->playRequestSound = false;

	// Hide objects
	this->showInterface(false, 20);
	this->Timer->setVisibility(false, 20);
	this->ArrowDown->setVisibility(false, 20);
	this->ArrowLeft->setVisibility(false, 20);
	this->IconRejectMiddle->setVisibility(false, 20);
	this->IconAcceptMiddle->setVisibility(false, 20);
	this->BaselayerCircleLeftMiddle->setVisibility(false, 20);
	this->BaselayerCircleRightMiddle->setVisibility(false, 20);
}

void cSPUCooperation_and_Interface::handleRejection()
{
	// ==========================================================================================
	// entry-function of state REJECTION
	// sets the variable 'rejected' true
	// sets at the current position of rejected_arr to '1' to remeber the request was rejected
	// informs driver, that request was rejeted
	// ==========================================================================================

	this->rejected = true;
	//g_LogSys << "DPUCooperativeMotorwayMerge: Cooperation rejected " << endl;
	g_LogSys << "DPUCooperativeMotorwayMerge: VR slow down " << endl;
	this->rejected_arr[this->pos] = 1;

	// show state to driver
	this->IconRejectMiddle->setVisibility(true, 20);			// speed = 20, damit in einem Zeitschritt das Interface gezeigt werden kann
	this->BaselayerCircleLeftMiddle->setVisibility(true, 20);	// speed = 20, damit in einem Zeitschritt das Interface gezeigt werden kann

	if (this->decisionDefault)
	{
		// default
		this->BaselayerDefaultB->setVisibility(true, 20);	// speed = 20, damit in einem Zeitschritt das Interface gezeigt werden kann
	}

	// hide all the other objects
	this->BaselayerCircleLeft->setVisibility(false, 20);
	this->BaselayerCircleRight->setVisibility(false, 20);
	this->IconReject->setVisibility(false, 20);
	this->IconAccept->setVisibility(false, 20);
	this->showDefaultAction(false, 20);
	this->Default2->setVisibility(false, 20);
	// play sound
	this->playRejectSound = true;

}

void cSPUCooperation_and_Interface::handleAcception()
{
	// ==========================================================================================
	// entry-function of state ACCEPT
	// sets the variable 'accepted' true
	// sets at the current position of accepted_arr to '1' to remeber the request was accepted
	// gets all needed values for the function 'Slowdown'
	// informs driver, that request was accepted
	// ==========================================================================================

	this->x_start = m_Data.md_position_x;					// get current position;
	this->x_end = m_Data.md_position_x + m_Data.md_x_end;	// get x_end
	this->v = m_Data.md_Speed_In;							// get current velocity;
	this->v_start = this->v;								// set start-velocity to current velocity;
	this->v_end = m_Data.md_BrakeSpeed_In;					// get brake-velocity;
	this->d = this->x_end - this->x_start;					// compute distance of slowdown
	this->delta_v = this->v_end - this->v_start;			// compute delta_v

	this->accepted = true;
	g_LogSys << "DPUCooperativeMotorwayMerge: Cooperation is started " << endl;
	this->accepted_arr[this->pos] = 1;

	//// show state to driver
	//this->IconAcceptMiddle->setVisibility(true, 20);			// speed = 20, damit in einem Zeitschritt das Interface gezeigt werden kann
	//this->BaselayerCircleRightMiddle->setVisibility(true, 20);	// speed = 20, damit in einem Zeitschritt das Interface gezeigt werden kann

	if (this->decisionDefault)
	{
		// default
		this->BaselayerDefaultA->setVisibility(true, 20);
	}

	// hide all the other objects
	this->BaselayerCircleLeft->setVisibility(false, 20);
	this->BaselayerCircleRight->setVisibility(false, 20);
	this->IconReject->setVisibility(false, 20);
	this->IconAccept->setVisibility(false, 20);
	this->showDefaultAction(false, 20);
	this->Default2->setVisibility(false, 20);
	// play sound
	this->playAcceptSound = true;


}

void cSPUCooperation_and_Interface::disableAutomation()
{	
	// ==========================================================================================
	// entry-function of state STOP_AUTOMATION
	// sets the variable 'playDefaultSound' to '1' to signalize driver TOR
	// sets at the current position of rejected_arr to '1' to remeber the request was rejected
	// sets the variable 'playDefaultSound' to '1' to
	// ==========================================================================================

	this->BaselayerDefaultC->setVisibility(true, 0.5);	// show TOR-Icon in HUD
	this->playDefaultSound = 1;							// play TOR-Sound
	// hide objects
	this->BaselayerCircleLeft->setVisibility(false, 20);
	this->BaselayerCircleRight->setVisibility(false, 20);
	this->IconReject->setVisibility(false, 20);
	this->IconAccept->setVisibility(false, 20);
	this->showDefaultAction(false, 20);
	this->Default2->setVisibility(false, 20);
	g_LogSys << "DPUCooperativeMotorwayMerge: Automation gets disabled " << endl;
	this->rejected_arr[this->pos] = 1;
	this->automationEnabled = 0;	//disable Automation

}

void cSPUCooperation_and_Interface::entryCooperation_TOR()
{
	// ==========================================================================================
	// entry-function of state COOPERATION and TOR
	// turns off sounds and hides objects
	// ==========================================================================================

	// turning off sound 
	this->playRequestSound = false;
	this->playRejectSound = false;
	this->playAcceptSound = false;

}

void cSPUCooperation_and_Interface::doCooperation()
{
	// ==========================================================================================
	// do-function of state COOPERATION
	// does a LANECHANGE or a SLOWDOWN depending on the type of request
	// ==========================================================================================

	// show state to driver
	this->IconAcceptMiddle->setVisibility(true, 20);			// speed = 20, damit in einem Zeitschritt das Interface gezeigt werden kann
	this->BaselayerCircleRightMiddle->setVisibility(true, 20);	// speed = 20, damit in einem Zeitschritt das Interface gezeigt werden kann

	if (this->type == REQUEST_LANECHANGE) 
	{
		this->laneChange = -1;	// start lanechange to left lane
		this->blinkerStart = 1;
		this->blinkerOn = 1;
	}

	else if (this->type == REQUEST_SLOWDOWN) 
	{
		this->targetSpeed = SlowDown();
	}
}

void cSPUCooperation_and_Interface::gotoIDLE()
{
	// ==========================================================================================
	// exit-function of state COOPERATION and state TOR
	// sets the variables to the IDLE-values
	// hides objects of Action
	// ==========================================================================================
	g_LogSys << "DPUCooperativeMotorwayMerge: IDLE" << endl;

	this->BaselayerCircleLeft->setColor(new ColorRGBA(0.96, 0.33, 0.26, 0.9));
	this->BaselayerCircleRight->setColor(new ColorRGBA(0.18, 0.8, 0.44, 0.9));

	this->accepted = false;
	this->rejected = false;
	this->laneChange = 0;
	this->blinkerStart = 0;
	this->blinkerOn = 0;
	this->targetSpeed = m_Data.md_TargetSpeed_In;
	this->automationEnabled = 1;	//???
	this->playDefaultSound = 0;

	this->showDefaultAction(false, 20);	// hide objects

	// hide objects
	if (!this->decisionDefault) 
	{
		this->showDefaultAction(false, 20);
		this->decisionDefault = false;
		// hide default-Icon
		this->BaselayerDefaultA->setVisibility(false, 20);
		this->BaselayerDefaultB->setVisibility(false, 20);
		this->BaselayerDefaultC->setVisibility(false, 20);
	}

	this->showInterface(false, 20);
	this->ArrowDown->setVisibility(false, 20);
	this->ArrowLeft->setVisibility(false, 20);
	this->IconRejectMiddle->setVisibility(false, 20);
	this->IconAcceptMiddle->setVisibility(false, 20);
	this->BaselayerCircleLeftMiddle->setVisibility(false, 20);
	this->BaselayerCircleRightMiddle->setVisibility(false, 20);
}

double cSPUCooperation_and_Interface::SlowDown()
{
	// ==========================================================================================
	// returns the new velocity v for the EGO-Car depending on the driven distance
	// the function computing v is a 'Rampenfunktion'
	// ==========================================================================================
	if (this->v > this->v_end)	
	{
		//current velocity bigger than desired velocity

		this->x_position = m_Data.md_position_x;	// get current position

		this->v = this->v_start + (this->delta_v / this->d) * (this->x_position - this->x_start);	// Compute new v
	}
	else
	{
		// cooperation is finished
		this->cooperation_finished = true;
	}
	return this->v;
}

void cSPUCooperation_and_Interface::showInterface(bool show, double speed) 
{
	// ==========================================================================================
	// shows Interface to driver in HUD
	// ==========================================================================================
	this->BaselayerCircleBig->setVisibility(show, speed);
	this->BaselayerCircleLeft->setVisibility(show, speed);
	this->BaselayerCircleRight->setVisibility(show, speed);
	this->IconReject->setVisibility(show, speed);
	this->IconAccept->setVisibility(show, speed);
	this->Street->setVisibility(show, speed);
	this->Timer->setVisibility(show, speed);
}

void cSPUCooperation_and_Interface::showDefaultAction(bool show, double speed)
{
	// ==========================================================================================
	// shows the driver the default-action to driver, which will happen, if he doesn't accept or reject
	// 0->REJECT, 1->ACCEPT, 2->STOP_AUTOMATION
	// ==========================================================================================
	if ((int)m_Data.mi_DefaultAction == 0) {
		this->Default0->setVisibility(show, speed);
	}
	if ((int)m_Data.mi_DefaultAction == 1) {
		this->Default1->setVisibility(show, speed);
	}
	if ((int)m_Data.mi_DefaultAction == 2) {
		this->Default2->setVisibility(show, speed);
	}
}

void cSPUCooperation_and_Interface::mapOutput()
{
	// ==========================================================================================
	// sets output variables
	// ==========================================================================================

	// Cooperation

	// cookie
	m_Data.md_velocity_Out = this->v;
	m_Data.mi_CooperationState_Out = this->state;
	m_Data.md_DecisionTime_Out = this->decisionTime;
	m_Data.mi_LaneChange_Out = this->laneChange;
	m_Data.mb_Accepted_Out = this->accepted;
	m_Data.md_TargetSpeed_Out = this->targetSpeed;
	m_Data.mb_BlinkerStartLinks_Out = this->blinkerStart;
	m_Data.mb_BlinkerOnLinks_Out = this->blinkerOn;
	m_Data.mb_AutomationEnabled_Out = this->automationEnabled;
	m_Data.mb_DefaultSound_Out = this->playDefaultSound;
	m_Data.mb_AcceptSound_Out = this->playAcceptSound;
	m_Data.mb_RejectSound_Out = this->playRejectSound;
	m_Data.mb_Accepted_Out = this->accepted;
	m_Data.mb_Accepted1_Out = this->accepted_arr[0];
	m_Data.mb_Rejected1_Out = this->rejected_arr[0];
	m_Data.mb_Accepted2_Out = this->accepted_arr[1];
	m_Data.mb_Rejected2_Out = this->rejected_arr[1];
	m_Data.mb_Accepted3_Out = this->accepted_arr[2];
	m_Data.mb_Rejected3_Out = this->rejected_arr[2];
	m_Data.mb_Accepted4_Out = this->accepted_arr[3];
	m_Data.mb_Rejected4_Out = this->rejected_arr[3];
	m_Data.mb_Accepted5_Out = this->accepted_arr[4];
	m_Data.mb_Rejected5_Out = this->rejected_arr[4];
	m_Data.mb_Accepted6_Out = this->accepted_arr[5];
	m_Data.mb_Rejected6_Out = this->rejected_arr[5];
	m_Data.mb_Accepted8_Out = this->accepted_arr[7];
	m_Data.mb_Rejected8_Out = this->rejected_arr[7];
	m_Data.mb_Accepted9_Out = this->accepted_arr[8];
	m_Data.mb_Rejected9_Out = this->rejected_arr[8];

	m_Data.mb_ObjBaselayerDefaultAVisible_Out = BaselayerDefaultA->getVisibility();
	m_Data.mb_ObjBaselayerDefaultAOpacity_Out = 1;
	m_Data.mb_ObjBaselayerDefaultBVisible_Out = BaselayerDefaultB->getVisibility();
	m_Data.mb_ObjBaselayerDefaultBOpacity_Out = 1;
	m_Data.mb_ObjBaselayerDefaultCVisible_Out = BaselayerDefaultC->getVisibility();
	m_Data.mb_ObjBaselayerDefaultCOpacity_Out = 1;

	// =====================================
	// Interface
	// =====================================

	// Request Interface
	m_Data.mb_ObjBaselayerCircleBigVisible_Out = BaselayerCircleBig->getVisibility();
	m_Data.md_ObjBaselayerCircleBigOpacity_Out = BaselayerCircleBig->getOpacity();

	m_Data.mb_ObjBaselayerCircleLeftVisible_Out = BaselayerCircleLeft->getVisibility();
	m_Data.md_ObjBaselayerCircleLeftOpacity_Out = BaselayerCircleLeft->getOpacity();
	m_Data.md_ObjBaselayerCircleLeftColorRed_Out = BaselayerCircleLeft->getColorObject()->getColR();
	m_Data.md_ObjBaselayerCircleLeftColorGreen_Out = BaselayerCircleLeft->getColorObject()->getColG();
	m_Data.md_ObjBaselayerCircleLeftColorBlue_Out = BaselayerCircleLeft->getColorObject()->getColB();

	m_Data.mb_ObjBaselayerCircleRightVisible_Out = BaselayerCircleRight->getVisibility();
	m_Data.md_ObjBaselayerCircleRightOpacity_Out = BaselayerCircleRight->getOpacity();
	m_Data.md_ObjBaselayerCircleRightColorRed_Out = BaselayerCircleRight->getColorObject()->getColR();
	m_Data.md_ObjBaselayerCircleRightColorGreen_Out = BaselayerCircleRight->getColorObject()->getColG();
	m_Data.md_ObjBaselayerCircleRightColorBlue_Out = BaselayerCircleRight->getColorObject()->getColB();

	m_Data.mb_ObjIconRejectVisible_Out = IconReject->getVisibility();
	m_Data.md_ObjIconRejectOpacity_Out = IconReject->getOpacity();
  
	m_Data.mb_ObjIconAcceptVisible_Out = IconAccept->getVisibility();
	m_Data.md_ObjIconAcceptOpacity_Out = IconAccept->getOpacity();
  
	m_Data.mb_ObjArrowDownVisible_Out = ArrowDown->getVisibility();
	m_Data.md_ObjArrowDownOpacity_Out = ArrowDown->getOpacity();
  
	m_Data.mb_ObjArrowLeftVisible_Out = ArrowLeft->getVisibility();
	m_Data.md_ObjArrowLeftOpacity_Out = ArrowLeft->getOpacity();

	m_Data.mb_ObjStreetVisible_Out = Street->getVisibility();
	m_Data.md_ObjStreetOpacity_Out = Street->getOpacity();

	m_Data.mb_ObjTimerVisible_Out = Timer->getVisibility();
	m_Data.md_ObjTimerOpacity_Out = Timer->getOpacity();
	m_Data.md_ObjTimerValue_Out = Timer->getValue();

	//
	m_Data.mb_ObjBaselayerCircleLeftMiddleVisible_Out = BaselayerCircleLeftMiddle->getVisibility();
	m_Data.md_ObjBaselayerCircleLeftMiddleOpacity_Out = BaselayerCircleLeftMiddle->getOpacity();

	m_Data.mb_ObjBaselayerCircleRightMiddleVisible_Out = BaselayerCircleRightMiddle->getVisibility();
	m_Data.md_ObjBaselayerCircleRightMiddleOpacity_Out = BaselayerCircleRightMiddle->getOpacity();

	m_Data.mb_ObjIconRejectMiddleVisible_Out = IconRejectMiddle->getVisibility();
	m_Data.md_ObjIconRejectMiddleOpacity_Out = IconRejectMiddle->getOpacity();

	m_Data.mb_ObjIconAcceptMiddleVisible_Out = IconAcceptMiddle->getVisibility();
	m_Data.md_ObjIconAcceptMiddleOpacity_Out = IconAcceptMiddle->getOpacity();

	// Default
	m_Data.mb_ObjDefault0_Visible_Out = Default0->getVisibility();
	m_Data.md_ObjDefault0_Opacity_Out = Default0->getOpacity();

	m_Data.mb_ObjDefault1_Visible_Out = Default1->getVisibility();
	m_Data.md_ObjDefault1_Opacity_Out = Default1->getOpacity();

	m_Data.mb_ObjDefault2_Visible_Out = Default2->getVisibility();
	m_Data.md_ObjDefault2_Opacity_Out = Default2->getOpacity();

	// Sounds
	m_Data.mb_PlaySoundRequest_Out = this->playRequestSound;
	m_Data.mb_PlaySoundAccept_Out = this->playAcceptSound;
	m_Data.mb_PlaySoundReject_Out = this->playRejectSound;
}

void cSPUCooperation_and_Interface::Cleanup()
{
}

