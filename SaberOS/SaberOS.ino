//Pins
   int switchPin = 2;
// int bladeMosPin = ;
// int swingPin = ;
// Clash Sensor is analog A1
// int soundCardPin = ;

//Extras: Delete if not applicable
// bool kyberCrystal = ;
// int kyberCrystalLEDPin = ;
// int buttonLED = ;

//Properties
// bool isCorrupted = ;


//Needed info
//lightsaber on?
bool LSon = false;
int LSStat = 0;//for debugging


//Button Properties
  //Button press Timer(ms)
int SoundPFChangeTime = 2000;
int BladeLockTime = 500;

float btnPressTimer = 0;
int btnDebounce = 250;
int ONOFFSensitivity = 210;

//Sound Profile Properties 
  //current sound profile
int soundPF = 1;
 //Max sound profile number
int MaxSoundPF = 5;

//Clash Sensor Properties
int ClashSensor;//Variable to store analog value (0-1023)
int ClashSensitivity = 900;
int ClashDebounce = 1000;

 //Randomizer analog pins
 // int RandPin1 = ;
 // int RandPin2 = ;




void setup() {

  //For PC communication
  Serial.begin(9600);

  //setup switchPin to Input
  pinMode(switchPin, INPUT_PULLUP);


  //setup bladeMosPin to Output
  //setup buttonLED to Output
  //setup clashPin to Input
  //setup swingPin to Input
  //setup soundCardPin to Output

  //setup kyberCrystal to Output

  //ensure blade is OFF at start
  //Turn on kyberCrystal
  //Turn on ButtonLED

  
 


}

void loop() {
  // put your main code here, to run repeatedly:

  //is blade on or off

//Saber is OFF
  if (LSon == false)
  {
        
    
      //Scans for button input and adds to timer
       while (digitalRead(switchPin)==HIGH){

        delay(100);
        btnPressTimer = btnPressTimer + 100;

        //This changes sound profile to next profile if lightsaber is off, and button is pressed for longer than 3sec 
     if (btnPressTimer >= SoundPFChangeTime){

        if(soundPF < MaxSoundPF) {
          
          soundPF++; btnPressTimer = 0;
         
         //used for debugging v01
          Serial.println();
          Serial.println("Sound Profile Changed!");
          Serial.println();
          
          }//if end
          
          else if (soundPF == MaxSoundPF) {
            
            soundPF = 1; btnPressTimer = 0;
          
          //used for debugging v01
          Serial.println();
          Serial.println("Sound Profile Changed!");
          Serial.println();
          }//elseif end

          
            delay (btnDebounce);
      
    }//else if end (<3sec)

        //used for debugging v01
        Serial.println();
        Serial.print("Saber on : ");
        Serial.print(LSStat);
        Serial.println();
        Serial.print("ms = ");
        Serial.print(btnPressTimer);
        Serial.println();
        Serial.print("Sound Profile = ");
        Serial.print(soundPF);

            
        }//While Loop end



      //This If turns lightsaber on if it is off, and button is pressed for less than 3sec
      if (btnPressTimer > ONOFFSensitivity  && btnPressTimer < SoundPFChangeTime){
 
        LSon = true;
        //used for debugging v01
        Serial.println();
        Serial.println("Lightsaber ON");
        Serial.println();
        LSStat = 1;
        btnPressTimer = 0;

       delay (btnDebounce);
          
        }//if end (3sec)
        
      
      btnPressTimer = 0;  
  }//if (LS = off) end 

//Saber is ON
  else if (LSon == true)
  {
    
//Scans for button input and adds to timer
       while (digitalRead(switchPin)== HIGH){

        delay(100);
        btnPressTimer = btnPressTimer + 100;

        //BladeLock Feature
      //Checks for longer press time, activates clash on press if saber is ON and button is pressed longer than Blade lock time
        if (btnPressTimer > BladeLockTime && digitalRead(switchPin)== HIGH){
          
            while (digitalRead(switchPin)== HIGH){
              
                 Serial.println("Lightsaber Blade Lock!");
            
            }//whileEnd
            
       btnPressTimer = 0;
     }//BladeLock If End


        //used for debugging v01
        Serial.println();
        Serial.print("Saber on : ");
        Serial.print(LSStat);
        Serial.println();
        Serial.print("ms = ");
        Serial.print(btnPressTimer);
        Serial.println();
        Serial.print("Sound Profile = ");
        Serial.print(soundPF);

    
        }//While Loop end

//This turns OFF the lightsaber if it is on and button is pressed for less than 1 sec
       if (btnPressTimer > ONOFFSensitivity  && btnPressTimer <= BladeLockTime){

        
 
          LSon = false;
        
         //used for debugging v01
         Serial.println();
         Serial.println("Lightsaber OFF");
         Serial.println();
         LSStat = 0;
         btnPressTimer = 0;
         //must be at the end of the function
         delay (btnDebounce);


/*TODO
 * Activate Blade
 * Activate Button LED
 * Activatr Sound
 * Scan for clash
 * Scan for Swing
 * 
 */
           
          
        }//if end (3sec)

//Clash Sensing : Scans for clash 
     ClashSensor = analogRead(A1);
     if (ClashSensor >= ClashSensitivity){

          Serial.println();    
          Serial.print("Clash!");
          Serial.println(ClashSensor);    
          
          ClashSensor = 0;
          delay(ClashDebounce);
  }//if (Clash Sense) end    


    btnPressTimer = 0;
  }// if (LS = ON) end
  
 

}//Loop END
