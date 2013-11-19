boolean debug = false;
boolean testMode = false;
boolean servoCounting = false;
boolean posCounting = false;

byte numString[6];
int powers[] = {1,10,100,1000};

byte numCount = 0;
unsigned short total = 0;
short inServo = -1;
short inPos = -1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}



void loop() {
  // put your main code here, to run repeatedly: 
  if (Serial.available()
  {
    char inChar = (char)serial.read();
    switch(inChar)
    {
      case '#':
        servoCounting = true;
        numCount = 0;
        inServo = -1;
        inPos = -1;
        break;
      case 'D':
        //printStatus(serial);
        break; 
      case 'P':
        if(servoCounting){
          //inServo = tallyCount();
          servoCounting = false;
        }
        posCounting =  true;
        numCount = 0;
        break; 
      case '\r':
      case '\n':
        if(posCounting){
          //inPos = tallyCount();
          posCounting = false;
        }
        if((inServo >=0)&&(inServo <=31)&&(((inPos >= 500)&&(inPos <= 2500))||(inPos == -1))){
          //changeServo(inServo,inPos);        
          inServo = -1;
          inPos = -1;
        }
        numCount = 0;
        break;
      case 'V':
        Serial.println("SERVOTOR32_v2.0");
        break;
      case 'C':
        for(int i=0; i<32; i++){
          changeServo(i, 1500);
        }
        Serial.println("All Centered");
        break;
      case 'K':
        for(int i=0; i<32; i++){
          changeServo(i,-1);
        }
        Serial.println("All Turned Off");
        break;
      case 'L':
        if(servoCounting){
          inServo = tallyCount();
          servoCounting = false;
        }
        //changeServo(inServo, -1);
        break;
      default:
        if((inChar > 47)&&(inChar < 58)){
          if(numCount<4){
            numString[numCount] = inChar-48;
            numCount++;
          }
        }
        break;
    }
  }
}
