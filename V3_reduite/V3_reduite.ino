
#include "StandardCplusplus.h"
#include "vector"

//#include <Arduino.h>
#include "Sensor.h"
#include "Motor.h"
#include "Button.h"
#include "ControlPanel.h"
#include "SensorType.h"




using namespace std;
int choice = -1;
int locations = 4;

//------Motors-------://
	Motor motor_l = Motor(9,8,10);
  #define MOTEURDROIT 0
	Motor motor_r = Motor(7,6,5);
  #define MOTEURGAUCHE 1
//------Sensor--------://
Sensor  sensorLineRight = Sensor(11, A1, 500, SensorType::line, 1);
Sensor  sensorLineLeft = Sensor(12, A0, 500, SensorType::line, -1);

#define LINERIGHT 1 
#define LINELEFT  2


//------buttons-------://
Button btn_left = Button(3);
Button btn_right = Button(4);
Button btn_valid = Button(2);
    
//------Controls-------://
ControlPanel controls(5);



void setup() {

    //------motor init-------://
    //motor_l.init();
    //motor_r.init();
    
    //------Controls init-------://
    controls.addButton(btn_right);
    controls.addButton(btn_left);
    controls.addButton(btn_valid);
pinMode(8,OUTPUT);
pinMode(9,OUTPUT);
pinMode(10,OUTPUT);

pinMode(7,OUTPUT);
pinMode(6,OUTPUT);
pinMode(5,OUTPUT);

digitalWrite( 6, LOW);  //tourne que dans ce sens...
digitalWrite( 7, HIGH );

digitalWrite( 8, LOW);   //tourne que dans ce sens...
digitalWrite( 9, HIGH );
	
	//Initialisation de la communication s�rie � 9600 Baud
	Serial.begin(9600);

}

void loop() {
  
DemoMoteur();

}

//*********************************************************************************Boutons

void Test_Bouton()
{
  btn_left.readValue();
  btn_right.readValue();
  btn_valid.readValue();
  
  Serial.print("Bouton Gauche :" );
  Serial.println(btn_left.getValue());
  
  Serial.print("Bouton Droit : ");
  Serial.println(btn_right.getValue());

  Serial.print("Bouton Centre : ");
  Serial.println(btn_valid.getValue());  
}


//*********************************************************************************Capteur de ligne

int GetDataCapteur(int NumCapt)
{
  if(NumCapt==1) { sensorLineRight.read(); return sensorLineRight.getValue();}
  if(NumCapt==2) { sensorLineLeft.read(); return sensorLineLeft.getValue();}
}

void DisplayDataCapteur()
{
    Serial.print("Capteur Droite : ");
    Serial.println(GetDataCapteur(LINERIGHT));
    Serial.print("Capteur Gauche : ");
    Serial.println(GetDataCapteur(LINELEFT));

    delay(300);
}

//*********************************************************************************MOTEUR

void Avance(int NumMoteur,int puissance)
{
  
if(NumMoteur==1){analogWrite(5,map(puissance, 0, 100, 0, 255));} //droite
if(NumMoteur==0){analogWrite(10,map(puissance, 0, 100, 0, 255));} //gauche


}

void DemoMoteur()
{

Avance(MOTEURDROIT,50);

delay(1000);

Avance(MOTEURDROIT,0);

delay(1000);

Avance(MOTEURGAUCHE,50);

delay(1000);

Avance(MOTEURGAUCHE,0);

delay(1000);

}



