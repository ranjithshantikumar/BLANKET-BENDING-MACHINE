/*
           ------------------>>>>>>>>>>>>>>>>>> BLANKET BENDING PROGRAM WITH LOGIC INVERTED<<<<<<<<<<<<<<<<<<<<<---------------------- 
                                                fork ->3 version changed-->4 edit---> 6 
                                                   program version : 3.4.6
              This is a program to replace the old blanket bending running obselete mu c of 8081 series
 
     All logics have been made to match the old board so that it is to easy replacem without any major circuit wiring
     
     Note to programmer: two forks of the earlier program contains logics inverted ,
     in case of corruption in this program, hints has been left in "plate bending final prog" file(pls note file name is plate instead of blanket).pls change logic in those file.
      Care has been taken to avoid any major bugs and testing has been done extensively ,
      pls report the bug if any before making any changes ,since any logic can lead to catostropic failure to machine/personnel safety
 
 major changes in old program ----> pin change of on board led 13 to 11 since during start board delivers power to led and makes output jittery
 pls never ever connect the board directly in the machine and change program as in foil wrapper machine
 
 pls note in comment inside the code loop as "LOGIC CHANGE LAST EDIT" AND "LAST EDIT" should not be edited
 Q1 signal is define as led,
 program starts only when Reset p/b is first pressed(0V AS INPUT FROM TO BOARD) ,Action p/b (does nothing without first pressing Reset p/b
 repeated pressing of Action button during running cycle does not revert the program to start position
 only after completion of the program cycle does the board takes the signal from inputs again
 
 program and logic created by  R.saravanakumar & E.Ranjithkumar
 first edit  full program done on oct/nov 17  
 fifth edit on jan 3/1/18
 last edit (6th) date 31/3/18
    -------------->>>>PROGRAMME SAVED IN MAILROOM PC AND HARD COPY FILED FOR FUTURE REFERENCE,Program file name :"BLANKET_BENDING_LOGIC_CHANGE_FINAL.ino" <<<<<<<--------------
 */
int led = 11;
const int Q2 = 2;    
const int Q3 = 3;   
const int Q4 = 4;    
const int Q5 = 5;    
const int Q6 = 6; 
const int Q7 = 7;    
const int Q8 = 8;   
const int ActioN = 9;  
int ReseTpin = 10;
int statE = 1;//LOGIC CHANGE LAST EDIT
int statEr = 1; //LOGIC CHANGE LAST EDIT
int ledState = HIGH;//LOGIC CHANGE LAST EDIT
int lastButtonState = HIGH; //LOGICHANGE LAST EDIT ;( 
long lastDebounceTime = 0;  // the last time the output pin was toggled
long debounceDelay = 50; 

void setup() 
{
 pinMode(ActioN ,INPUT);     // initialize the button pin as a input:
 pinMode(ReseTpin ,INPUT);   // initialize the button pin as a input: 
 pinMode(led, OUTPUT);         // initialize the LED's as an output:
  pinMode(Q2, OUTPUT);
  pinMode(Q3, OUTPUT);
  pinMode(Q4, OUTPUT);
  pinMode(Q5, OUTPUT);
  pinMode(Q6, OUTPUT);
  pinMode(Q7, OUTPUT);
  pinMode(Q8, OUTPUT);
  pinMode(led, OUTPUT);
  digitalWrite(led, ledState);
  digitalWrite(Q2, HIGH);
  digitalWrite(Q3, HIGH);
  digitalWrite(Q4, HIGH);
  digitalWrite(Q5, HIGH);
  digitalWrite(Q6, HIGH);
  digitalWrite(Q7, HIGH);
  digitalWrite(Q8, HIGH);
}
void bending()
{
  digitalWrite(led, LOW);
  delay(1000);
  digitalWrite(Q3,LOW);
    delay(2000);
  digitalWrite(Q2,LOW);
//  digitalWrite(led, LOW);
    delay(1000);
  digitalWrite(Q3,HIGH);
    delay(1000);
  digitalWrite(Q4,LOW);
  digitalWrite(Q5,LOW);
   delay(1000);
  digitalWrite(Q6,LOW);
  digitalWrite(Q7,LOW);
    delay(2000);
  digitalWrite(Q6,HIGH);
    digitalWrite(Q7,HIGH);
      delay(2000);
  digitalWrite(Q6,LOW);
    delay(2000);
  digitalWrite(Q6,HIGH);
    delay(1000);
 digitalWrite(Q5,HIGH);
digitalWrite(Q4,HIGH);
  delay(2000);
digitalWrite(led,HIGH);
delay(2000);
digitalWrite(Q5,LOW);
delay(2000);
digitalWrite(Q7,LOW);
delay(2000);
digitalWrite(Q7,HIGH);
delay(1000);
digitalWrite(Q5,HIGH);
delay(1000);
digitalWrite(Q2,HIGH);
delay(1000);
digitalWrite(Q8,LOW);
delay(1000);
digitalWrite(Q8,HIGH);
//digitalWrite(led, HIGH);
delay(2000);
//int ledState =digitalRead(13);// recent edit
//int led =digitalRead(13);  //recent edit
//ledState =digitalRead(led);//recent edit
}
void loop() {
  int statE =digitalRead(9);
   int ledState =digitalRead(11);
  if((statE == LOW) && (ledState == LOW))//LAST EDIT LED STATE CHANGE AND STATEe LOGIC CHANGE
  {
    bending();
    }
// int ledState =digitalRead(13);
//int led =digitalRead(13);  //recent edit
ledState =digitalRead(led);//recent edit
   digitalWrite(led, ledState); 
   delay(50);
 // read the state of the switch into a local variable:
  int reading = digitalRead(ReseTpin);

  // check to see if you just pressed the button 
  // (i.e. the input went from LOW to HIGH),  and you've waited 
  // long enough since the last press to ignore any noise:  

  // If the switch changed, due to noise or pressing:
  if (reading != lastButtonState) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  } 
  
  if ((millis() - lastDebounceTime) > debounceDelay) {
    // whatever the reading is at, it's been there for longer
    // than the debounce delay, so take it as the actual current state:

    // if the button state has changed:
    if (reading != statEr) {
      statEr = reading;

      // only toggle the LED if the new button state is HIGH
      if (statEr== LOW) { // LAST EDIT BUG IS A FEATURE CHANGE TO HIGH TO SEE THE EFFECT
        ledState = !ledState;
      }
    }
  }
  
  // set the LED:
  digitalWrite(led, ledState);

  // save the reading.  Next time through the loop,
  // it'll be the lastButtonState:
  lastButtonState = reading;
  }


