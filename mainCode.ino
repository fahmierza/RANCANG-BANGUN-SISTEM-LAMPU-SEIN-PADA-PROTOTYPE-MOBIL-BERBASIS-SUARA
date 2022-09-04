String voice;
String kiri = "kiri";
String kanan = "kanan";
String hazard = "Hazard";
String berhenti = "berhenti";
String hidupkan = "hidupkan";
String matikan = "matikan";
int LEFTb = 8;
int LEFTd = 10;
int RIGHTb = 12;
int RIGHTd = 13;
int LIGHT1 = 9;
int LIGHT2 = 11;
int sign;
void LEFTon(){
    digitalWrite (LEFTb, HIGH);
    digitalWrite (LEFTd, HIGH);
    digitalWrite (RIGHTb, LOW);
    digitalWrite (RIGHTd, LOW);
    delay(500);
}

void RIGHTon(){
    digitalWrite (LEFTb, LOW);
    digitalWrite (LEFTd, LOW);
    digitalWrite (RIGHTb, HIGH);
    digitalWrite (RIGHTd, HIGH);
    delay(500);
}

void HAZARDon(){
    digitalWrite (LEFTb, HIGH);
    digitalWrite (LEFTd, HIGH);
    digitalWrite (RIGHTb, HIGH);
    digitalWrite (RIGHTd, HIGH);
    delay(500);
}

void ALLoff(){
    digitalWrite (LEFTb, LOW);
    digitalWrite (LEFTd, LOW);
    digitalWrite (RIGHTb, LOW);
    digitalWrite (RIGHTd, LOW);
    delay(500);
}

void setup() {
  Serial.begin(9600);
  pinMode(LEFTb, OUTPUT);
  pinMode(LEFTd, OUTPUT);
  pinMode(RIGHTb, OUTPUT);
  pinMode(RIGHTd, OUTPUT);
  pinMode(LIGHT1, OUTPUT);
  pinMode(LIGHT2, OUTPUT);
}

void loop() {
  ALLoff();
  while(Serial.available()){
    delay(10);
    char c = Serial.read();
    if(c=='#'){
      break;
    }
    voice += c;
  }
  
  if(voice.length() > 0){
    Serial.println(voice);
    if(voice == kiri){
      sign = 1;
    }
    else if(voice == kanan){
      sign = 2;
    }
    else if(voice == hazard){
      sign = 3;
    }
    else if(voice == berhenti){
      sign = 4;
    }
    else if(voice == hidupkan){
      digitalWrite (LIGHT1, HIGH);
      digitalWrite (LIGHT2, HIGH);
      HAZARDon();
      ALLoff();
      HAZARDon();
      ALLoff();
      HAZARDon();
      ALLoff();
    }
    else if(voice == matikan){
      HAZARDon();
      ALLoff();
      HAZARDon();
      ALLoff();
      HAZARDon();
      ALLoff();
      digitalWrite (LIGHT1, LOW);
      digitalWrite (LIGHT2, LOW);
    }
    voice = "";
  }
      
  if(sign == 1){
    LEFTon();
  }
  else if(sign == 2){
    RIGHTon();
  }
  else if(sign == 3){
    HAZARDon();
  }else{ALLoff();}

}
