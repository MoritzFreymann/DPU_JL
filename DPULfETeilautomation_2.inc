Executeable = true;

	

	DPULfETeilautomationSandra Teilautomation
	
	{
		Computer = {OPERATOR};
		Index = 80;
		steeringScale = -400;     
		
		enabled = 0;
		activate = 0;
		isActive = 0;
		
		acceleratorScale = 1.0;  		# LS: Skaliert die Beschleunigung des ACC; ehemals auf 1.0
		brakeScale=1.0;	
		
		Input.ownBrakeScale = -12;
		
		Parameter.longitudinalThreshold = 0.99;
		Parameter.lateralThreshold = 20.0;
	};	
	

	
	DPUSCNXHedgehogKiller TeilautomationAn
	{
		Computer = {OPERATOR};
		Index = 70;
		Family = "Automation";
		Name1 = "Verfuegbar";
		Name2 = "LaneChange";
		Name3 = "Aktivieren";
		Default1 = 0;
	};
	
	DPUSCNXHedgehogKiller ~Malfunction
	{
		Computer = {OPERATOR};
		Index = 90;
		Family = "MALFUNCTION";
		Name1 = "Init";
		Default1 = 0;
	};

	
	DPUSCNXHedgehogKiller SoundAn
	{
		Computer = {OPERATOR};
		Index = 140;
		Family = "Sound";
		Name1 = "Verfuegbar";
		Name2 = "TOR";
		Name3 = "Blinker";
		Default1 = 0;
	};
	
	
	DPUComparator AktivierenKupplung	
	{
		Computer={OPERATOR};
		Index=70;
		Min=550;
		Max=600;
		
	};
	
	DPUFlipFlop ToggleKupplung
	{
		Computer={OPERATOR};
		Index=70;
	};
	
	DPUBooleanGate ~AND
	{
		Computer = {MOCKUP};
		Index = 5;
		Channels = 2;
		Gate = AND;
	};
	
	
	Connections = 
	{
	
		VDyn.AcceleratorPedal			<->	Teilautomation.Input.acceleratorPedal,
		VDyn.BrakePedal					<->	Teilautomation.Input.brakePedal,
		VDyn.SteeringWheel				<->	Teilautomation.Input.steeringWheel,
		VDyn.v							<->	Teilautomation.Input.velocity,
		VDyn.X							<->	Teilautomation.Input.X,
		VDyn.Y							<->	Teilautomation.Input.Y,
		VDyn.yaw						<->	Teilautomation.Input.yaw,

		Teilautomation.Output.steeringWheel			<->	~Steeringwheel.ControlPosition,
		Teilautomation.Output.acceleratorPedal			<->	~MSTVeda.AcceleratorPedal,
		Teilautomation.Output.brakePedal			<->	~MSTVeda.BrakePedal,

		Teilautomation.Sensodrive.EnableWheelPositionControl	<->	~Steeringwheel.EnableWheelPositionControl,   
		Teilautomation.Sensodrive.FrictionGain			<->	~Steeringwheel.FrictionGain,
		Teilautomation.Sensodrive.GainKlw			<->	~Steeringwheel.GainKlw,
		Teilautomation.Sensodrive.OptFri2Factor		<->	~Steeringwheel.OptFri2Factor,
		Teilautomation.Sensodrive.OptFriGain			<->	~Steeringwheel.OptFriGain,
		Teilautomation.Sensodrive.StiffnessGain		<->	~Steeringwheel.StiffnessGain,
	
		Cooperation_and_Interface.TargetSpeed_Out <-> Teilautomation.Input.speedVelocity,
		Teilautomation.isActive 	 -> Cooperation_and_Interface.AutomationActive_In,
	
		TeilautomationAn.Out1 				<-> ~AND.In1,
		Cooperation_and_Interface.AutomationEnabled_Out 	<-> ~AND.In2,
		~AND.Out 							<-> Teilautomation.enabled,
		
		~SensoPedale.Kupplung <-> AktivierenKupplung.In,
		AktivierenKupplung.Less ->Teilautomation.activate
	
			
	};