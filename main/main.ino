#define BUTTON A0
bool up = false;
int gameSpeed = 1000, count1 = 7, count2 = 0, jump = 2, buttonState = 0, cactus = 1;

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
  if(count2 == 6){        // Reinicia os cactos
    cactus = random(2);
    if(cactus == 0){
      count1 = 7;
    }else{
      count1 = 13;
    }
    count2 = 0;
    gameSpeed = 350 * random(1,3);  // Altera a velocidade do jogo
  }
  
  buttonState = analogRead(BUTTON);
  
  if(buttonState < 1000 && up == false){        // Verifica onde esta o jogador
    digitalWrite(jump,HIGH);
  }
  else if(buttonState > 1000 && up == false){
    digitalWrite(jump,LOW);
    jump += 6;
    digitalWrite(jump,HIGH);
    up = true;
  }
  else if(up == true){
    digitalWrite(jump,LOW);
    jump -= 6;
    digitalWrite(jump,HIGH);
    up = false;
  }

  if(count1 == 2){                                              // Verifica se o jogador morreu ou não
    if(digitalRead(count1) == HIGH){
      while(true){
        Serial.print("Você morreu, porfavor resete o programa.\n");
        delay(60000);
      } 
    }
  }else if(count1 == 8){
    if(digitalRead(count1) == HIGH){
      while(true){
        Serial.print("Você morreu, porfavor resete o programa.\n");
        delay(60000);
      } 
    }
  }

  digitalWrite(count1,HIGH);  // Desenha o cacto
  delay(gameSpeed);           // Velocidade das luzes
  digitalWrite(count1,LOW);   // Apaga o cacto

  count1--;
  count2++;
}
