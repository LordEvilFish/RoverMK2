#include <Servo.h>
#include <SoftwareSerial.h>

Servo m_servo1;  // create servo object to control a servo
Servo m_servo2;  // create servo object to control a servo
Servo m_servo3;  // create servo object to control a servo
Servo m_servo4;  // create servo object to control a servo

Servo a_servo1;
Servo a_servo2;
Servo a_servo3;
Servo a_servo4;

//SoftwareSerial hc06(2,3);
char usr;
bool arm;
int pos1 = 90;
int pos2 = 90;

void setup() {
  Serial.begin(9600);
  //Robot chassis pins
  m_servo1.attach(14);
  m_servo2.attach(15);
  m_servo3.attach(16);
  m_servo4.attach(17);
  //robot arm pins
  a_servo1.attach(7);
  a_servo2.attach(6);
  a_servo3.attach(5);  
  a_servo4.attach(4);

  a_servo2.write(90);  // attaches the servo on pin 9 to the servo object  
  a_servo3.write(90);  // attaches the servo on pin 9 to the servo object  
  arm = false;
  Serial.println("Uno BEGIN");
}

void loop() { 
  if(Serial.available()) {
    usr = Serial.read();

    //CAR CHASSIS PINS
    if (usr == '1'){
      m_servo1.attach(14);  // attaches the servo on pin 9 to the servo object  
      m_servo2.attach(15);  // attaches the servo on pin 9 to the servo object  

      m_servo3.attach(16);  // attaches the servo on pin 9 to the servo object  
      m_servo4.attach(17);  // attaches the servo on pin 9 to the servo object  

      m_servo1.write(0);  // attaches the servo on pin 9 to the servo object  
      m_servo2.write(180);  // attaches the servo on pin 9 to the servo object        

      m_servo3.write(180);  // attaches the servo on pin 9 to the servo object  
      m_servo4.write(0);  // attaches the servo on pin 9 to the servo object  

      Serial.println("moving forward"); 

    } 
    else if (usr == '4'){

      m_servo1.attach(14);  // attaches the servo on pin 9 to the servo object  
      m_servo2.attach(15);  // attaches the servo on pin 9 to the servo object  

      m_servo3.attach(16);  // attaches the servo on pin 9 to the servo object  
      m_servo4.attach(17);  // attaches the servo on pin 9 to the servo object  

      m_servo1.write(180);  // attaches the servo on pin 9 to the servo object  
      m_servo2.write(0);  // attaches the servo on pin 9 to the servo object        

      m_servo3.write(0);  // attaches the servo on pin 9 to the servo object  
      m_servo4.write(180);  // attaches the servo on pin 9 to the servo object  

    }   
    else if (usr == '2'){  
      m_servo1.attach(14);  // attaches the servo on pin 9 to the servo object  
      m_servo2.attach(15);  // attaches the servo on pin 9 to the servo object  

      m_servo3.attach(16);  // attaches the servo on pin 9 to the servo object  
      m_servo4.attach(17);  // attaches the servo on pin 9 to the servo object  

      m_servo1.write(0);  // attaches the servo on pin 9 to the servo object  
      m_servo2.write(0);  // attaches the servo on pin 9 to the servo object        

      m_servo3.write(0);  // attaches the servo on pin 9 to the servo object  
      m_servo4.write(0);  // attaches the servo on pin 9 to the servo object  

      Serial.println("moving forward"); 

    } 
    else if (usr == '3'){ 
      m_servo1.attach(14);  // attaches the servo on pin 9 to the servo object  
      m_servo2.attach(15);  // attaches the servo on pin 9 to the servo object  

      m_servo3.attach(16);  // attaches the servo on pin 9 to the servo object  
      m_servo4.attach(17);  // attaches the servo on pin 9 to the servo object  

      m_servo1.write(180);  // attaches the servo on pin 9 to the servo object  
      m_servo2.write(180);  // attaches the servo on pin 9 to the servo object        

      m_servo3.write(180);  // attaches the servo on pin 9 to the servo object  
      m_servo4.write(180);  // attaches the servo on pin 9 to the servo object  

      Serial.println("moving forward"); 

    }         
    else if (usr == 's'){
      m_servo1.detach();  // attaches the servo on pin 9 to the servo object
      m_servo2.detach();  // attaches the servo on pin 9 to the servo object
      m_servo3.detach();  // attaches the servo on pin 9 to the servo object
      m_servo4.detach();  // attaches the servo on pin 9 to the servo object

      a_servo1.detach();
      //a_servo2.detach();
      //a_servo3.detach();
      a_servo4.detach();
      arm = false;

      Serial.println("stop moving");
    } 

    /////// ROBOT ARM PINS

    else if(usr == 'q'){
      a_servo1.attach(7);
      a_servo1.write(20);
    }
    else if(usr == 'w'){
      a_servo1.attach(7);
      a_servo1.write(160);
    }    

    else if(usr == 'e'){
      a_servo2.attach(6);
        if(pos1 < 180){
          pos1 += 10;
        }
      a_servo2.write(pos1);

    }    
    else if(usr == 'r'){
      a_servo2.attach(6);
      if(pos1 > 0){
        pos1 -= 10;
      }
      a_servo2.write(pos1);

    }   

    else if(usr == 't'){
      a_servo3.attach(5);
      if(pos2 < 180){
        pos2 += 10;
      }
      a_servo3.write(pos2);

    }    
    else if(usr == 'y'){
      a_servo3.attach(5);
      if(pos2 > 0){
        pos2 -= 10;
      }
      a_servo3.write(pos2);

    }       
    
     

    else if(usr == 'u'){
      a_servo4.attach(4);
      a_servo4.write(90);
    }  
    else if(usr == 'i'){
      a_servo4.attach(4);
      a_servo4.write(180);
    }        

  delay(50);              
  }
}