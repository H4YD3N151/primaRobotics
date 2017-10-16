//Declare any variables shared between functions here
float myPosA[3];
float myPosB[3];
float attitudeA[3];
float attitudeB[3];
int counter;

void init(){
    
    myPosA[0] = 0.6;
    myPosA[1] = -0.6;
    myPosA[2] = 0;
    
    myPosB[0] = 0;
    myPosB[1] = 0;
    myPosB[2] = 0;
    
    attitudeA[0] = -0.6;
    attitudeA[1] = 0.6;
    attitudeA[2] = 0;
    
    attitudeB[0] = 0;
    attitudeB[1] = 0;
    attitudeB[2] = 0;    
    
    counter = 0;
    
	//This function is called once when your code is first loaded.

	//IMPORTANT: make sure to set any variables that need an initial value.
	//Do not assume variables will be set to 0 automatically!
}

void loop(){
	//This function is called once per second.  Use it to control the satellite.

    api.setPositionTarget(myPosA);
    if(counter == 40){
        game.startDrill();
        api.setAttitudeTarget(attitudeA);
        //when the timer hits 40 sec the drill starts and the shpere spins
    }
    if(counter > 62){
        api.setPositionTarget(myPosB);
        game.pickupSample();
        game.stopDrill();
        api.setAttitudeTarget(attitudeB);
        //at 62 sec the drill stops, the sample is picked up, and the sphere moves to base
    }
    if(counter == 100){
        game.dropSample(0);
        //at 100 sec the sphere drops the sample at base
    }
    counter++;
}
