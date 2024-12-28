#define BLYNK_PRINT Serial 
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Keypad.h>

char auth[] = "cgy7flwribLYtos4atCxzvND6tE-HNrV";
char ssid[] = "Sidd123";
char pass[] = "Sidd@123";

#define BLYNK_MAX_SENDBYTES

#define en 1

#define ii A0

#define lo 15
const int ProxSensor=10;
int inputVal = 0;

BlynkTimer timer;
 
String password = "2005";
String mypassword;

int counter = 0; 
int attempts = 0; 
int max_attempts = 3; 

 
const byte n_rows = 4;
const byte n_cols = 4;
 
char keys[n_rows][n_cols] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
 
byte colPins[n_rows] = {D3, D2, D1, D0};
byte rowPins[n_cols] = {D7, D6, D5, D4};
 
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, n_rows, n_cols); 



void setup(){

  //Serial.begin(9600);
    Blynk.begin(auth, ssid, pass); 
  pinMode(ProxSensor,INPUT);
//Serial.println("Enter password");
pinMode(en,OUTPUT);
pinMode(lo,OUTPUT);
//Serial.flush();
//Serial.println("HII");
//timer.setInterval(1000L,keyy);

}
 
void loop(){



Blynk.virtualWrite(1, HIGH);  
Blynk.virtualWrite(15,HIGH);

int jk = analogRead(ii);
Serial.println(jk);
delay(100);  


   char key = keypad.getKey();
  
if(digitalRead(ProxSensor)==LOW)     
  {
   //Serial.println("detected");
   Blynk.notify("Someone Entered car");
    //Serial.println("not detected");    
    delay(100);
  }
  
  
  
  if (key){
    //Serial.println(key);
    counter = counter + 1; 
    //Serial.print("*");
  }
  if (key == '1')
  {
 
    mypassword = mypassword + 1;   
  }
  
    if (key == '2')
  {
 
    mypassword = mypassword + 2;  
  }
  
  if (key == '3')
  {
 
    mypassword = mypassword + 3; 
  }
  
   if (key == '4')
  {
  
    mypassword = mypassword + 4;  
  }
  
  if (key == '5')
  {
  
    mypassword = mypassword + 5;
  }
  
   if (key == '6')
  {
   
    mypassword = mypassword + 6; 
  }
  
   if (key == '7')
  {
 
    mypassword = mypassword + 7; 
  }
 
   if (key == '8')
  {
 
    mypassword = mypassword + 8; 
  }
  
  if (key == '9')
  {
 
    mypassword = mypassword + 9;
  }
             
                 if (key == '0')
  {
 
    mypassword = mypassword + 0; 
  }
  
  
        if (key == '*')
  {
    //Serial.println(mypassword); 
    
if ( password == mypassword )
{
delay(100); 
mypassword = ""; 
counter = 0; 
//Serial.println("Correct");
//Serial.println("Enter password");
}
else
{
//Serial.println("wrong");
attempts = attempts + 1; 
if (attempts >= max_attempts)
{ 
  //Serial.println("Locked Out");
  Blynk.notify("Entered Wrong password 3 times");
    // Blynk.notify("Some broke into car");

inputVal = digitalRead(ProxSensor);

attempts = 0; 
}
mypassword = ""; 
counter = 0;   
//Serial.println("Wrong Password");
delay(100);
 
 
//Serial.println("max attempts 3");
delay(100);
//Serial.println("Enter password");
}
}  

  Blynk.run();
  timer.run();
  
}
