int layer[2] = {9,10}; //initializing and declaring LED layers
int column[4] = {2,3,4,5};
int time = 1000;
int colNum = 4;
int layerNum = 2; 

void setup() {
  for(int i=0; i<layerNum; i++){
    pinMode(layer[i], OUTPUT);
  }

  for(int i=0; i<colNum; i++){
    pinMode(column[i], OUTPUT);
  }
}

void loop() {
  turnEverythingOff();
  delay(time);
  flickerOn();
  delay(time);
 turnEverythingOn();
 delay(time);

  turnOnAndOffAllByLayerUpAndDownNotTimed();
  delay(time);
  layerstompUpAndDown();
  delay(time);
  spiralInAndOut();
  delay(time);
  turnOnAndOffAllByColumnSideways();
 delay(time);

 //oneByOne();
 //delay(time);
}

void turnEverythingOff(){
  for(int i = 0; i<colNum; i++){
    digitalWrite(column[i], HIGH);
  }

  for(int i = 0; i<layerNum; i++){
    digitalWrite(layer[i], LOW);
  }
}

void turnEverythingOn(){
  for(int i = 0; i<colNum; i++){
    digitalWrite(column[i], LOW);
  }

  for(int i = 0; i<layerNum; i++){
    digitalWrite(layer[i], HIGH);
  }
}

void turnColumnsOff(){
  for(int i = 0; i<colNum; i++){
    digitalWrite(column[i], HIGH);
  }
}

void flickerOn(){
  int i = 150;
  while(i != 0){
    turnEverythingOn();
    delay(i);
    turnEverythingOff();
    delay(i);
    i-= 5;
  }
}

void turnOnAndOffAllByLayerUpAndDownNotTimed(){
  int x = 150;
  for(int i = 5; i != 0; i--){
    turnEverythingOn();
    
    for(int i = layerNum; i!=0; i--){
      digitalWrite(layer[i-1], LOW);
      delay(x);
    }
    
    for(int i = 0; i<layerNum; i++){
      digitalWrite(layer[i], HIGH);
      delay(x);
    }
    
    for(int i = 0; i<layerNum; i++){
      digitalWrite(layer[i], LOW);
      delay(x);
    }
    
    for(int i = layerNum; i!=0; i--){
      digitalWrite(layer[i-1], HIGH);
      delay(x);
    }
  }
}

void turnOnAndOffAllByColumnSideways(){
  int x = 150;
  turnEverythingOff();
  
  for(int i = 0; i<layerNum; i++){   //turn on layers
    digitalWrite(layer[i], HIGH);
  }
  
  for(int y = 0; y<layerNum-1; y++){  
    for(int i = 0; i<layerNum; i++){  //turns on columns 0-1 //goes by 4s in the 4x4 and 2s in the 2x2
      digitalWrite(column[i], LOW);
      delay(x);
    }
    
    for(int i = layerNum; i<layerNum*2; i++){    //turns on columns 2-3
    digitalWrite(column[i], LOW);              //larger cube would have layerNum*2, then layerNum*3 for next loop
      delay(x);
    }
    
    
    for(int i = 0; i<layerNum; i++){   //turn off columns 0-1
      digitalWrite(column[i], HIGH);
      delay(x);
    }
   
    for(int i = layerNum; i<layerNum*2; i++){         //turn off columns 2-3
      digitalWrite(column[i], HIGH);
      delay(x);
    }
   
    
    for(int i = layerNum; i<layerNum*2; i++){       //going in descending order now: turn on columns 2-3
      digitalWrite(column[i], LOW);
      delay(x);
    }
    
    for(int i = 0; i<layerNum; i++){  //turn on columns 0-1
      digitalWrite(column[i], LOW);
      delay(x);
    }
    
   
    for(int i = layerNum; i<layerNum*2; i++){   //turn off columns 2-3
      digitalWrite(column[i], HIGH);
      delay(x);
    }
    
    for(int i = 0; i<layerNum; i++){     //turn off columns 0-1
      digitalWrite(column[i], HIGH);
      delay(x);
    }
  }
}

//up and down single layer stomp
void layerstompUpAndDown(){
  int x = 150;
  
  for(int i = 0; i<layerNum; i++){       //turning off layers
    digitalWrite(layer[i], LOW);
  }
  
  for(int y = 0; y<layerNum+1; y++){
    
    for(int count = 0; count<1; count++){ 
      for(int i = 0; i<layerNum; i++){
        digitalWrite(layer[i], HIGH);
        delay(x);
        digitalWrite(layer[i], LOW);
      }
      for(int i = layerNum; i !=0; i--){
        digitalWrite(layer[i-1], HIGH);
        delay(x);
        digitalWrite(layer[i-1], LOW);
      }
    }
    
    for(int i = 0; i<layerNum; i++){
      digitalWrite(layer[i], HIGH);
      delay(x);
    }
    
    for(int i = layerNum; i!=0; i--){
      digitalWrite(layer[i-1], LOW);
      delay(x);
    }
  }
}

//spiral in and out
void spiralInAndOut(){
  turnEverythingOn();
  int x = 150;
  for(int i = 0; i<6; i++){
    //spiral in clockwise
    digitalWrite(column[0], HIGH);
    delay(x);
    digitalWrite(column[1], HIGH);
    delay(x);
    digitalWrite(column[2], HIGH);
    delay(x);
    digitalWrite(column[3], HIGH);
    delay(x);
//spiral out counter clockwise
    digitalWrite(column[3], LOW);
    delay(x);
    digitalWrite(column[2], LOW);
    delay(x);
    digitalWrite(column[1], LOW);
    delay(x);
    digitalWrite(column[0], LOW);
    delay(x);
//spiral in counter clock wise
    digitalWrite(column[0], HIGH);
    delay(x);
    digitalWrite(column[3], HIGH);
    delay(x);
    digitalWrite(column[2], HIGH);
    delay(x);
    digitalWrite(column[1], HIGH);
    delay(x);
//spiral out clock wise
    digitalWrite(column[1], LOW);
    delay(x);
    digitalWrite(column[2], LOW);
    delay(x);
    digitalWrite(column[3], LOW);
    delay(x);
    digitalWrite(column[0], LOW);
    delay(x);
  }
}


void oneByOne(){
  int x = 100;
  turnEverythingOff();
 
  for(int j = 0; j<layerNum; j++){
    digitalWrite(layer[j], HIGH);
    
    for(int i = 0; i<colNum; i++){
       digitalWrite(column[i], LOW);
       delay(x);
       digitalWrite(column[i], HIGH);
       delay(x);
    }
  }
  

}
