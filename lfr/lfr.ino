// Startup
void setup() {

  // read seed for harder randomization
  randomSeed(analogRead(0));

  turnoff();
  delay(1000);
  
  neon();
  delay(3000);
  
  // blink raute once in purple
  glow("raute", 175, 94, 112);
  delay(1000);

  turnoff();
  delay(1000);

}

// Runtime
void loop() {
  farblauf();
  delay(1000);
  harmonischausrasten();
  delay(1000);
  whiteout();
  delay(1000);
  vollhartausrasten();
  delay(1000);
  vollausrasten();
  delay(2000);
  karusell();
  delay(1000);
  onebyone();
  delay(1000);
  pulseup();
  delay(1000);
  hartausrasten();
  delay(1000);
}
//variables

boolean ledHon = false    //is true when Hash is on
boolean ledLon = false    //is true when Let is on
boolean ledFon = false    //is true when Freedom is on
boolean ledRon = false    //is true when Ring is on
boolean ledHwhite = false    //is true when Hash is full white
boolean ledLwhite = false    //is true when Let is full white
boolean ledFwhite = false    //is true when Freedom is full white
boolean ledRwhite = false    //is true when Ring is on   

// Functions


// more usable glow function
void glow(String inst, int r, int g, int b) {

  // replaces switch case with if conditions
  // because of crappy string comparsion.
  if (inst == "raute") {
    analogWrite(2, r);
    analogWrite(3, g);
    analogWrite(4, b);
        if (r >= 1 || g >= 1 || b >=1) { //checks if the LED is on by
            ledHon = true;               //comparing the rgb values
        }                                //used for the neon function
        else {                           //...stuff...
            ledHon = false;
        }
        if (if (r = 255 || g = 255 || b = 255)) { //check if segment is full white
        	ledHwhite = true;
        }
        else {
        	ledHwhite = false;
        }
  } else if (inst == "let") {
    analogWrite(7, r);
    analogWrite(5, g);
    analogWrite(6, b);
        if (r >= 1 || g >= 1 || b >=1) {
            ledLon = true;
        }
        else {
            ledLon = false;
        }
        if (if (r = 255 || g = 255 || b = 255)) {
        	ledLwhite = true;
        }
        else {
        	ledLwhite = false;
        }

  } else if (inst == "freedom") {
    analogWrite(8, r);
    analogWrite(9, g);
    analogWrite(10, b);
        if (r >= 1 || g >= 1 || b >=1) {
            ledFon = true;
        }
        else {
            ledFon = false;
        }
        if (if (r = 255 || g = 255 || b = 255)) {
        	ledFwhite = true;
        }
        else {
        	ledFwhite = false;
        }

  } else if (inst == "ring") {
    analogWrite(11, r);
    analogWrite(12, g);
    analogWrite(13, b);
            if (r >= 1 || g >= 1 || b >=1) {
            ledRon = true;
        }
        else {
            ledRon = false;
        }
        if (if (r = 255 || g = 255 || b = 255)) {
        	ledRwhite = true;
        }
        else {
        	ledRwhite = false;
        }

  }

}

//do some fancy neon turnon effects, heavily randomized, !!WARNING EPILEPSY!!

void neonmany(){
int neonmillis = millis;     //set neonmillis to actual millis
int neonduration = 5000;     //approximately the duration of the blinking
    while(neonmillis + neonduration < millis) { 
        RLFR = random(0,3); //randomizer for the case operation to apply the 
        switch (RLFR) {       //blinking effect to each word seperatly
            case 0:         //used for the hash
                delay(random(10, 100));
                if (ledHon == false) {
                    glow("raute", random(10,255), random(10,255), random(10,255)); //Randomize the Color of the Blink
                }																	//10 for the minimal glow of ~4%
                else {
                    turnoff();
                }
				break;
			case 1: 
				delay(random(10, 100));
                if (ledLon == false) {
                    glow("let", random(10,255), random(10,255), random(10,255));
                }
                else {
                    turnoff();
                }
				break;
			case 2: 
				delay(random(10, 100));
                if (ledFon == false) {
                    glow("freedom", random(10,255), random(10,255), random(10,255));
                }
                else {
                    turnoff();
                }
				break;
			case 3: 
				delay(random(10, 100));
                if (ledRon == false) {
                    glow("ring", random(10,255), random(10,255), random(10,255));
                }
                else {
                    turnoff();
                }
				break;
}
    }
int turnonmillis = millis;
	while(ledHwhite == false && ledLwhite == false && ledFwhite == false && ledRwhite == false)
    
}


// simply turn off all the pins
void turnoff() {

  glow("raute", 0, 0, 0);
  glow("let", 0, 0, 0);
  glow("freedom", 0, 0, 0);
  glow("ring", 0, 0, 0);
}

void turnon() {
  glow("raute", 255, 255, 255);
  glow("let", 255, 255, 255);
  glow("freedom", 255, 255, 255);
  glow("ring", 255, 255, 255);
  
}

// do random things
void hartausrasten() {  

  // random colors 10 times with short delay
  // pretty much code duplication in here
  for (int i=0; i <= 10; i++) {
    int rr = random(0,255);
    int gr = random(0,255);
    int br = random(0,255);
    glow("raute", rr, gr, br);

    rr = random(0,255);
    gr = random(0,255);
    br = random(0,255);
    glow("let", rr, gr, br);

    rr = random(0,255);
    gr = random(0,255);
    br = random(0,255);
    glow("freedom", rr, gr, br);

    rr = random(0,255);
    gr = random(0,255);
    br = random(0,255);
    glow("ring", rr, gr, br);
    delay(100);
  }
}

// do freedom let glow up in red
void pulseup() {  
  for (int i=1; i <= 255; i++) {
    glow("freedom", i, 0, 0);
    delay(30);
  }
}

// neon light turn on simulator
void neon() {
  
  for (int i=0; i <= 10; i++) {
    turnon();
    delay(random(10,100));
    turnoff();
    delay(random(10,100));
  }
  turnon();
}


// turn words on one by one 
void onebyone() {
  turnoff();
  for (int pin=0; pin < 4; pin++) {
    for (int i=0; i <= 255; i++) {
      
      if(pin == 0)
        glow("raute", i, i, i);
      else if(pin == 1)
        glow("let", i, i, i);
      else if(pin == 2)
        glow("freedom", i, i, i);
      else
        glow("ring", i, i, i);
        
      delay(5);
    }
  }
  
  for (int pin=0; pin < 4; pin++) {
    
    int cr = random(0,255);
    int cg = random(0,255);
    int cb = random(0,255);
    
    for (int i=0; i <= 255; i++) {
      
      if(pin == 0)
        glow("raute", min(cr,i), min(cg,i), min(cb,i));
      else if(pin == 1)
        glow("let", min(cr,i), min(cg,i), min(cb,i));
      else if(pin == 2)
        glow("freedom", min(cr,i), min(cg,i), min(cb,i));
      else
        glow("ring", min(cr,i), min(cg,i), min(cb,i));
        
      delay(5);
    }
  }
  
  for (int pin=0; pin < 4; pin++) {
    
    for (int i=255; i > 0; i--) {
      
      if(pin == 0)
        glow("raute", i, i, i);
      else if(pin == 1)
        glow("let", i, i, i);
      else if(pin == 2)
        glow("freedom", i, i, i);
      else
        glow("ring", i, i, i);
        
      delay(5);
    }
  }
}

// turns words on and off with random colors
void karusell() {

  int interval = 100;
  
  for(int i=0; i<20; i++) {
    glow("raute",0,0,0);
    delay(interval);
    glow("let",0,0,0);
    delay(interval);
    glow("freedom",0,0,0);
    delay(interval);
    glow("ring",0,0,0);
    delay(interval);
    
    glow("raute",random(0,255),random(0,255),random(0,255));
    delay(interval);
    glow("let",random(0,255),random(0,255),random(0,255));
    delay(interval);
    glow("freedom",random(0,255),random(0,255),random(0,255));
    delay(interval);
    glow("ring",random(0,255),random(0,255),random(0,255));
    delay(interval);
  } 
}


// turns on and off al words in random colors
void vollausrasten() {

    for(int i=0; i<100; i++) {
      int cr = random(0,255);
      int cg = random(0,255);
      int cb = random(0,255);
      
      glow("raute",cr,cg,cb);
      glow("let",cr,cg,cb);
      glow("freedom",cr,cg,cb);
      glow("ring",cr,cg,cb);
      
      delay(50);
      turnoff();
      delay(50);
    }
}

// Turns on and off words in random colors
void vollhartausrasten() {

    boolean disable = false;
    int pin = 0;
    for(int i=0; i<3000; i++) {
      pin = random(0,4);
      if(disable) {
        if(pin == 0)
          glow("raute", 0, 0, 0);
        else if(pin == 1)
          glow("let", 0, 0, 0);
        else if(pin == 2)
          glow("freedom", 0, 0, 0);
        else
          glow("ring", 0, 0, 0);
          
        disable = false;
      } else {
        if(pin == 0)
          glow("raute",random(0,255),random(0,255),random(0,255));
        else if(pin == 1)
          glow("let",random(0,255),random(0,255),random(0,255));
        else if(pin == 2)
          glow("freedom",random(0,255),random(0,255),random(0,255));
        else
          glow("ring",random(0,255),random(0,255),random(0,255));
        
        disable = true;
      }
      
      delay(10);
    }
    
    turnoff();
}

// Fades out from white
void whiteout() {
  turnon();
  
  for(int i=255; i>0; i--) {
    glow("raute",i,i,i);
    glow("let",i,i,i);
    glow("freedom",i,i,i);
    glow("ring",i,i,i);
    delay(20);
  }
  
  turnoff();
}

void harmonischausrasten() {
  for(int i = 0; i < 5; i++) {
    int wait = 1000;
    glow("raute", 255,0,0);
    glow("let", 0, 255, 0);
    glow("freedom", 0, 0, 255);
    glow("ring", 255, 255,0);
    delay(wait);
    glow("raute", 255,255,0);
    glow("let", 255, 0, 0);
    glow("freedom", 0, 255, 0);
    glow("ring", 0, 0,255);
    delay(wait);
    glow("raute", 0,0, 255);
    glow("let", 255, 255, 0);
    glow("freedom", 255, 0, 0);
    glow("ring", 0, 255, 0);
    delay(wait);
    glow("raute", 0,255,0);
    glow("let", 0, 0, 255);
    glow("freedom", 255, 255, 0);
    glow("ring", 255, 0,  0);
    delay(wait);
  }
}
 
void farblauf() {
  for(int h = 0; h < 6; h++) {
   for(int i = 0; i < 6; i++) {
    for(int j = 0; j < 255; j++) {
      switch(i) {
      case 0:
        glow("raute", random(0,255), j, random(0,255));
        glow("let", j, random(0,255), random(0,255));
        glow("freedom", random(0,255), j, random(0,255));
        glow("ring", random(0,255), random(0,255), j);
        break;
      case 1:
        glow("raute", 255 - j, random(0,255), random(0,255));
        glow("let", random(0,255), 255 - j, 0);
        glow("freedom", random(0,255), random(0,255), 255 -j);
        glow("ring", random(0,255), 255 - j, random(0,255));
        break;  
      case 2:
        glow("raute", random(0,255), random(0,255), 0 + j);
        glow("let", random(0,255), random(0,255), 0 + j);
        glow("freedom", 0 + j, random(0,255), random(0,255));
        glow("ring", 0 + j, random(0,255), random(0,255));
        break;
      case 3:
        glow("raute", random(0,255), 255 - j, random(0,255));
        glow("let", 255 - j, random(0,255), random(0,255));
        glow("freedom", random(0,255), random(0,255), 255 - j);
        glow("ring", random(0,255), random(0,255), 255 -j);
        break;
      case 4:
        glow("raute", 0 + j, random(0,255), random(0,255));
        glow("let", random(0,255), 0 + j, random(0,255));
        glow("freedom", random(0,255), 0 + j, random(0,255));
        glow("ring", random(0,255), 0 + j, random(0,255));
        break;
      case 5:
        glow("raute", random(0,255), random(0,255), 255 - j);
        glow("let", random(0,255), random(0,255), 255 - j);
        glow("freedom", 255 - j, random(0,255), random(0,255));
        glow("ring", 255 - j, random(0,255), random(0,255));
        break;
      }
    }
    delay(500);
  }
 } 
}
