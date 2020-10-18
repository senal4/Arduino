
        
        //----------------------------Speeds-----------------------//
        int mspeed_high=100; //Motor Speed High
        int mspeed_low=30; //Motor Speed Low
        #define reverse_speed 50
        int slow_speed = 40;

         int sm=0;
         int spm=180;
         int shm=135;
        //--------------------------------------------------------//
        int s1=2;
        int s2=3;
        int s3=4;
        int s4=5;
        int s5=6;
        int s6=7;
        //----------------------Turns-----------------------------//
        #define delayturn 400
        #define delayforward 130
        #define reverse_delay 590
        
        #define delayturn_fixleft 400
        #define delayforward_fixleft 0
        //--------------------------------------------------------//

//---------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------//
        
        int LeftMotorBackward=A1;
        int LeftMotorForward=A2;
        int RightMotorForward=A4;
        int RightMotorBackward=A3;



void setup() {
  //-----------------------------Motors-------------------------------------//
    pinMode(LeftMotorBackward,OUTPUT);
    pinMode(LeftMotorForward,OUTPUT);
    pinMode(RightMotorForward,OUTPUT);
    pinMode(RightMotorBackward,OUTPUT);
  //------------------------------------------------------------------------//
    pinMode(s1,INPUT);
    pinMode(s2,INPUT);
    pinMode(s3,INPUT);  
    pinMode(s4,INPUT);  
    pinMode(s5,INPUT);
    pinMode(s6,INPUT);      
  //------------------------------------------------------------------------//
  Serial.begin(9600); 

   // moveForward(100);
  delay(200);
}


//---------------------------------------------------------------------------------//
//------------------------------Motor Functions------------------------------------//
//---------------------------------------------------------------------------------//

void moveForward(){
    analogWrite(LeftMotorForward,shm);
    analogWrite(LeftMotorBackward,sm);
    analogWrite(RightMotorForward,shm);
    analogWrite(RightMotorBackward,sm);

}

void moveRight(){
    analogWrite(LeftMotorForward,shm);
    analogWrite(LeftMotorBackward,sm);
    analogWrite(RightMotorForward,sm);
    analogWrite(RightMotorBackward,sm);
}
void moveLeft(){
    analogWrite(LeftMotorForward,sm);
    analogWrite(LeftMotorBackward,sm);
    analogWrite(RightMotorForward,shm);
    analogWrite(RightMotorBackward,sm);
}

void moveRightl_with_fwd(){          
    analogWrite(LeftMotorForward,shm);
    analogWrite(LeftMotorBackward,sm);
    analogWrite(RightMotorForward,shm);
    analogWrite(RightMotorBackward,sm);
    delay(delayforward);   
    analogWrite(LeftMotorForward,shm);
    analogWrite(LeftMotorBackward,sm);
    analogWrite(RightMotorForward,sm);
    analogWrite(RightMotorBackward,spm);
    delay(delayturn);

}

void moveLeftl_with_fwd(){      
    analogWrite(LeftMotorForward,shm);
    analogWrite(LeftMotorBackward,sm);
    analogWrite(RightMotorForward,shm);
    analogWrite(RightMotorBackward,sm);
    delay(delayforward);
    
    analogWrite(LeftMotorForward,sm);
    analogWrite(LeftMotorBackward,spm);
    analogWrite(RightMotorForward,shm);
    analogWrite(RightMotorBackward,sm);
    delay(delayturn);
}

void stopMotors(){ 
    analogWrite(LeftMotorForward,sm);
    analogWrite(RightMotorForward,sm);
    analogWrite(LeftMotorBackward,sm);
    analogWrite(RightMotorBackward,sm);
}

void moveBack(){
    analogWrite(LeftMotorForward,sm);
    analogWrite(RightMotorForward,sm);
    analogWrite(LeftMotorBackward,shm);
    analogWrite(RightMotorBackward,shm);
}
void allwhite(){  
    analogWrite(LeftMotorForward,sm);
    analogWrite(LeftMotorBackward,shm);
    analogWrite(RightMotorForward,shm);
    analogWrite(RightMotorBackward,sm);
}


//Unloading Areas /////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////

//--------------------------Hacked Motor Functions---------------------------------//
void moveRightl_nofwd(){ 
    analogWrite(LeftMotorForward,shm);
    analogWrite(LeftMotorBackward,sm);
    analogWrite(RightMotorForward,sm);
    analogWrite(RightMotorBackward,spm);

}

void moveLeftl_nofwd(){  
    analogWrite(LeftMotorForward,sm);
    analogWrite(LeftMotorBackward,spm);
    analogWrite(RightMotorForward,shm);
    analogWrite(RightMotorBackward,sm);
}
void moveLeftl_fixleft(){       
    analogWrite(LeftMotorForward,spm);
    analogWrite(LeftMotorBackward,sm);
    analogWrite(RightMotorForward,shm);
    analogWrite(RightMotorBackward,sm);
    delay(delayforward_fixleft);
    
    analogWrite(LeftMotorForward,sm);
    analogWrite(LeftMotorBackward,spm);
    analogWrite(RightMotorForward,shm);
    analogWrite(RightMotorBackward,sm);
    delay(delayturn_fixleft);
}
//---------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------//




//---------------------------------------------------------------------------------//
//-----------------------------Helper Functions------------------------------------//
//---------------------------------------------------------------------------------//
void updateSensors(){
    s1=digitalRead(2);
    s2=digitalRead(3);
    s3=digitalRead(4);
    s4=digitalRead(5);
    s5=digitalRead(6);
    s6=digitalRead(7);
}

void loop() {

    
    //100000
    if(s1==HIGH && s2==LOW && s3==LOW && s4==LOW && s5==LOW && s6==LOW){
      moveLeft();
   }
    //010000
    else if(s1==LOW && s2==HIGH && s3==LOW && s4==LOW && s5==LOW && s6==LOW){
      moveLeft();
    }
    //001000
    else if(s1==LOW && s2==LOW && s3==HIGH && s4==LOW && s5==LOW && s6==LOW){
      moveForward();
    }
    //000100
    else if(s1==LOW && s2==LOW && s3==LOW && s4==HIGH && s5==LOW && s6==LOW){
      moveForward();
    }
    //000010
    else if(s1==LOW && s2==LOW && s3==LOW && s4==LOW && s5==HIGH && s6==LOW){
      moveRight();
    }
    //000001
    else if(s1==LOW && s2==LOW && s3==LOW && s4==LOW && s5==LOW && s6==HIGH){
      moveRightl_nofwd();
    }

    //-----------------------------------------------------------------------------//
    //Two Sensors
    
    //110000
    else if(s1==HIGH && s2==HIGH && s3==LOW && s4==LOW && s5==LOW && s6==LOW){
      moveLeft();
    }
    //011000
    else if(s1==LOW && s2==HIGH && s3==HIGH && s4==LOW && s5==LOW && s6==LOW){
      moveLeft();
    }
    //001100
    else if(s1==LOW && s2==LOW && s3==HIGH && s4==HIGH && s5==LOW && s6==LOW){
      moveForward();
    }
    //000110
    else if(s1==LOW && s2==LOW && s3==LOW && s4==HIGH && s5==HIGH && s6==LOW){
      moveRight();
    }
    //000011
    else if(s1==LOW && s2==LOW && s3==LOW && s4==LOW && s5==HIGH && s6==HIGH){
      moveRight();
    }

    //-----------------------------------------------------------------------------//
    //Three Sensors
    
    //111000
    else if(s1==HIGH && s2==HIGH && s3==HIGH && s4==LOW && s5==LOW && s6==LOW){
      moveLeft();
    }
    //011100
    else if(s1==LOW && s2==HIGH && s3==HIGH && s4==HIGH && s5==LOW && s6==LOW){
      moveLeft();
    }
    //001110
    else if(s1==LOW && s2==LOW && s3==HIGH && s4==HIGH && s5==HIGH && s6==LOW){
      moveRight();
    }
    //000111
    else if(s1==LOW && s2==LOW && s3==LOW && s4==HIGH && s5==HIGH && s6==HIGH){
      moveRight();
    }
    
    //-----------------------------------------------------------------------------//
    //Four Sensors
    
    //111100 or 111110 or 111000
    else if((s1==HIGH && s2==HIGH && s3==HIGH && s4==HIGH && s5==LOW && s6==LOW) || 
            (s1==HIGH && s2==HIGH && s3==HIGH && s4==HIGH && s5==HIGH && s6==LOW)) {
            //(s1==HIGH && s2==HIGH && s3==HIGH && s4==LOW && s5==LOW && s6==LOW)){
      //delay(2000);
      stopMotors();
      moveRightl_nofwd();
      delay(50);
      stopMotors();
      //delay(2000);
      updateSensors();
      if(s1==LOW && s2==LOW && s3==LOW && s4==LOW && s5==LOW && s6==LOW){
          while (s1==HIGH || s2==HIGH || s3==HIGH || s4==HIGH || s5==HIGH || s6==HIGH){
              updateSensors();
              allwhite();
          }
      }
      else{
          moveRight();
      }
    }
    //011110
    else if(s1==LOW && s2==HIGH && s3==HIGH && s4==HIGH && s5==HIGH && s6==LOW){
        moveRightl_nofwd();
        delay(200);
    }
    
    //-----------------------------------------------------------------------------//
    //Else Sensors
    //001111
    else if(s1==LOW && s2==LOW && s3==HIGH && s4==HIGH && s5==HIGH && s6==HIGH){
      moveRightl_with_fwd();
    }
    //000000
    else if(s1==LOW && s2==LOW && s3==LOW && s4==LOW && s5==LOW && s6==LOW){
      allwhite();
    }
    //111111
    else if(s1==HIGH && s2==HIGH && s3==HIGH && s4==HIGH && s5==HIGH && s6==HIGH){
      moveRightl_with_fwd();
    }
    //101100
    else if(s1==HIGH && s2==LOW && s3==HIGH && s4==HIGH && s5==LOW && s6==LOW){
      moveForward();
    }
    //100100
    else if(s1==HIGH && s2==LOW && s3==LOW && s4==HIGH && s5==LOW && s6==LOW){
      moveForward();
    }
    //001101
    else if(s1==LOW && s2==LOW && s3==HIGH && s4==HIGH && s5==LOW && s6==HIGH){
      moveForward();
    }
    //001001
    else if(s1==LOW && s2==LOW && s3==HIGH && s4==LOW && s5==LOW && s6==HIGH){
      moveForward();
    }
    
}

//---------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------//
//----------Do basic line following (No 90 degree or L turns) Section 2------------//
//---------------------------------------------------------------------------------//
void basic_line_follow(){
    updateSensors();
    //One Sensor
    
    //100000
    if(s1==HIGH && s2==LOW && s3==LOW && s4==LOW && s5==LOW && s6==LOW){
      moveLeft();
    }
    //010000
    else if(s1==LOW && s2==HIGH && s3==LOW && s4==LOW && s5==LOW && s6==LOW){
      moveLeft();
    }
    //001000
    else if(s1==LOW && s2==LOW && s3==HIGH && s4==LOW && s5==LOW && s6==LOW){
      moveLeft();
    }
    //000100
    else if(s1==LOW && s2==LOW && s3==LOW && s4==HIGH && s5==LOW && s6==LOW){
      moveRight();
    }
    //000010
    else if(s1==LOW && s2==LOW && s3==LOW && s4==LOW && s5==HIGH && s6==LOW){
      moveRight();
    }
    //000001
    else if(s1==LOW && s2==LOW && s3==LOW && s4==LOW && s5==LOW && s6==HIGH){
      moveRight();
    }
    
    
    //-----------------------------------------------------------------------------------//
    //Two Sensors
    
    //110000
    else if(s1==HIGH && s2==HIGH && s3==LOW && s4==LOW && s5==LOW && s6==LOW){
      moveLeft();
    }
    //011000
    else if(s1==LOW && s2==HIGH && s3==HIGH && s4==LOW && s5==LOW && s6==LOW){
      moveLeft();
    }
    //001100
    else if(s1==LOW && s2==LOW && s3==HIGH && s4==HIGH && s5==LOW && s6==LOW){
      moveForward();
    }
    //000110
    else if(s1==LOW && s2==LOW && s3==LOW && s4==HIGH && s5==HIGH && s6==LOW){
      moveRight();
    }
    //000011
    else if(s1==LOW && s2==LOW && s3==LOW && s4==LOW && s5==HIGH && s6==HIGH){
      moveRight();
    }
}
//---------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------//
// This function is called when robot passed 4 way junction and turn to the right direction
void line_follow_2_unloading(){
  updateSensors();
  //One Sensor
  
  //100000
  if(s1==HIGH && s2==LOW && s3==LOW && s4==LOW && s5==LOW && s6==LOW){
    moveLeft();
  }
  //010000
  else if(s1==LOW && s2==HIGH && s3==LOW && s4==LOW && s5==LOW && s6==LOW){
    moveLeft();
  }
  //001000
  else if(s1==LOW && s2==LOW && s3==HIGH && s4==LOW && s5==LOW && s6==LOW){
    moveLeft();
  }
  //000100
  else if(s1==LOW && s2==LOW && s3==LOW && s4==HIGH && s5==LOW && s6==LOW){
    moveRight();
  }
  //000010
  else if(s1==LOW && s2==LOW && s3==LOW && s4==LOW && s5==HIGH && s6==LOW){
    moveRight();
  }
  //000001
  else if(s1==LOW && s2==LOW && s3==LOW && s4==LOW && s5==LOW && s6==HIGH){
    moveRight();
  }
  
  
  //-----------------------------------------------------------------------------------//
  //Two Sensors
  
  //110000
  else if(s1==HIGH && s2==HIGH && s3==LOW && s4==LOW && s5==LOW && s6==LOW){
    moveLeft();
  }
  //011000
  else if(s1==LOW && s2==HIGH && s3==HIGH && s4==LOW && s5==LOW && s6==LOW){
    moveLeft();
  }
  //001100
  else if(s1==LOW && s2==LOW && s3==HIGH && s4==HIGH && s5==LOW && s6==LOW){
    moveForward();
  }
  //000110
  else if(s1==LOW && s2==LOW && s3==LOW && s4==HIGH && s5==HIGH && s6==LOW){
    moveRight();
  }
  //000011
  else if(s1==LOW && s2==LOW && s3==LOW && s4==LOW && s5==HIGH && s6==HIGH){
    moveRight();
  }



// Check if something in range
// If something in range lower the main arm and close the hook to grab and lift the arm with the box
// If not just pass



    /*Serial.print(red);
    Serial.print("\t");
    Serial.print(green);
    Serial.print("\t");
    Serial.print(blue);
    Serial.print("\t\n");*/
/*    if (red > green) {
      if (green > red) {
        return 2;
      }
      else{
        return 1;
      }
    }
    else{
      if (blue > green){
        return 3;
      }
      else{
        return 2;
      }
    }*/
}


