#define BUTTON A0 
int jump = 2, buttonState = 0, countJump = 0;
bool up = false, down = false, mid = false;
int count1 = 5, count2 = 9, count3 = 0;

void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(BUTTON, INPUT);
  Serial.begin(9600);
}

void loop() {
  if(count3 == 4){  // Reinicia os cactos
    count1 = 5;
    count2 = 9;
    count3 = 0;
  }
  
  buttonState = analogRead(BUTTON);
  digitalWrite(count1,HIGH);  // Desenha os cactos
  digitalWrite(count2,HIGH);
  
  if(buttonState < 1000 && up == false && down == false && mid == false){  // Mantem o personagem aceso
    digitalWrite(jump,HIGH);
  }
  else if(buttonState > 1000 && up == false && down == false && mid == false){  // LED baixo aceso e tem q subir mais 2
    digitalWrite(jump,LOW);
    jump += 4;
    digitalWrite(jump,HIGH);
    up = true;
  }
  else if(up == true){   // LED meio aceso e tem q subir mais 1
    digitalWrite(jump,LOW);
    jump += 4;
    digitalWrite(jump,HIGH);
    up = false;
    down = true;
  }
  else if(down == true && mid == false){ // LED topo aceso e tem q cair mais 2
    digitalWrite(jump,LOW);
    jump -= 4;
    digitalWrite(jump,HIGH);
    mid = true;
  }
  else if(down = true && mid == true){  // LED meio aceso e tem q cair mais 1
    digitalWrite(jump,LOW);
    jump -= 4;
    digitalWrite(jump,HIGH);
    down = false;
    mid = false;
  }
            
  if(count1 == 1){                                              // Jogador morreu
    if(digitalRead(count1) == HIGH){
      while(true){
        Serial.print("Você morreu, porfavor resete o programa.\n");
        delay(5000);
      } 
    }
  }else if(count2 == 5){
    if(digitalRead(count2) == HIGH){
      while(true){
        Serial.print("Você morreu, porfavor resete o programa.\n");
        delay(5000);
      } 
    }
  }
  delay(2000);                // Mantem o LED do cacto aceso por 2 segundos
  digitalWrite(count1,LOW);   // Apaga os cactos
  digitalWrite(count2,LOW);
  
  
  count1--;
  count2--;
  count3++;
}
