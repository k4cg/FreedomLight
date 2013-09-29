

//  Processing sketch to run with this example
// =====================================================
 
 // Processing UDP example to send and receive string data from Arduino 
 // press any key to send the "Hello Arduino" message
 
 // Import UDP library
 import hypermedia.net.*;
 
 UDP udp;  // define the UDP object
 String ip       = "10.88.88.177";  // the remote IP address
 int port        = 8888;    // the destination port
 
 int mode=0;
 int globalR=255, globalG=255, globalB=255;
 int rauR=0, rauG=0, rauB=0;
 int letR=0, letG=0, letB=0;
 int freR=0, freB=0, freG=0;
 int rinR=0, rinB=0, rinG=0;
 String Pos = "rau";
 int ms = millis();
 int s = second();
 
 void setup() {
   
   // make window 
   size(768, 768);
   noStroke();
   background(255);
   
   udp = new UDP( this, 6000 );  // create a new datagram connection on port 6000
   //udp.log( true );            // <-- printout the connection activity
   udp.listen( true );           // and wait for incoming message  
 }
 
 void draw() {
   
   // define colors for ui 
   color backColor = color(50,20,0);
   color rauteColor = color(rauR, rauG, rauB);
   color letColor = color(letR, letG, letB);
   color freedomColor = color(freR, freG, freB);
   color ringColor = color(rinR, rinG, rinB);
   color trennColor = color(50, 50, 50);
   color flaeche1Color = color(0,255, 30);
   color flaeche2Color = color(255,255, 30);
   color flaeche3Color = color(255,0, 30);

   //Raute
   fill(backColor);
   rect(10, 5, 100, 120, 10);
   textSize(150);
   fill(rauteColor);
   text("#", 12, 118);
   //LET
   fill(backColor);
   rect(115, 5, 250, 120, 10);
   fill(letColor);
   text("LET", 105, 118);
   //FREEDOM
   fill(backColor);
   rect(370, 5, 100, 120, 10);
   fill(freedomColor);
   text("F", 377, 118);
   fill(backColor);
   rect(10, 180, 460, 120, 10);
   fill(freedomColor);
   text("R", 3, 295);
   text("E", 93, 295);
   text("E", 170, 295);
   text("D", 248, 295);
   text("O", 353, 295);
   fill(backColor);
   rect(10, 355, 120, 120, 10);
   fill(freedomColor);
   text("M", 5, 470);
   //RING
   fill(backColor);
   rect(135, 355, 335, 120, 10);
   fill(ringColor);
   text("R", 135, 470);
   text("I", 227, 470);
   text("N", 261, 470);
   text("G", 363, 470);
   //TRENNSTRICH
   fill(trennColor);
   rect(483, 5, 5, 528, 1);
   rect(620, 5, 5, 528, 1);
   rect(0, 528, 768, 5,1);
   //SCHALTFLAECHE1
   fill(flaeche1Color);
   rect(500, 5, 100, 120, 10);
   //SCHALTFLAECHE2   
   fill(flaeche2Color);
   rect(500, 180, 100, 120, 10);
   //SCHALTFLAECHE3   
   fill(flaeche3Color);   
   rect(500, 355, 100, 120, 10);
   //BRIHGTNESS
   fill(255);
   stroke(0);
   rect(645, 5, 100, 512);
   noStroke();
   int pos=4;
   for(int x=255; x>=0; x--){
     pos = int(pos + 2);
     fill(x);
     rect(646, pos, 99, 2);
   }
  
  int r=255;
  int g=0;
  int b=0;
  for(int x=0; x<=768; x++)
  {
    if(x<=255){
      fill(r,0,b);
      rect(x,545,1,200);
      r--;
      b++;
    }
    if(x>255 && x<=511){
      fill(0,g,b);
      rect(x,545,1,200);
      b--;
      g++;
    }
    if(x>511){
      fill(r,g,0);
      rect(x,545,1,200);
      g--;
      r++;
    }
  }
 }
 void mouseDragged(){
   colorLFR();
   brightnessLFR();
 }
 
 void mouseClicked() {
   
   colorLFR();
   brightnessLFR();
   
  if(picturePos()=="neo"){
    mode=0;
    print(mode=0);
   }
  else if(picturePos()=="pul"){
    mode=1;
    print("mode=1");
   }
  else if(picturePos()=="ran"){
    mode=2;
    print("mode=2");
  }
  
  if(picturePos()=="rau" || picturePos()=="let" || picturePos()=="fre" || picturePos()=="rin") {
  
    switch(mode){
  
      case 0:
          neon();
          break;
      case 1:
          pulse();
          break;
      case 2:
          random();
          break;
      default:
          random();
    }
  }
  
}
 
void receive( byte[] data ) {       // <-- default handler
 //void receive( byte[] data, String ip, int port ) {  // <-- extended handler
 
 for(int i=0; i < data.length; i++) 
   print(char(data[i]));  
   println();   
 }
 
 // detecting the position under the mouse
 String picturePos() {
  if(mouseX>10 && mouseX<110 && mouseY>5 && mouseY<130){
    Pos = "rau";
    return "rau";
  }
  else if (mouseX>115 && mouseX<365 && mouseY>5 && mouseY<130){
    Pos = "let";
    return "let";
  }
  else if ((mouseX>370 && mouseX<470 && mouseY>5 && mouseY<130)||
            (mouseX>10 && mouseX<470 && mouseY>180 && mouseY<300) ||
            (mouseX>10 && mouseX<110 && mouseY>355 && mouseY<470)){
    Pos = "fre";
    return "fre";
  }
  else if (mouseX>115 && mouseX<470 && mouseY>355 && mouseY<470){
    Pos = "rin";
    return "rin";
  }
  else if(mouseX>500 && mouseX<600 && mouseY>5 && mouseY<130){
//        print("neo\n");
    return "neo";
  }
  else if(mouseX>500 && mouseX<600 && mouseY>180 && mouseY<300){
//        print("pul\n");
    return "pul";
  }
  else if(mouseX>500 && mouseX<600 && mouseY>355 && mouseY<470){
//        print("ran\n");
    return "ran";
  }
    else if(mouseX>630){
//        print("dim\n");
    return "dim";
  }
  else if(mouseY>545){
//        print("RGB\n");
    return "RGB";
  }
      
   return "bla";
 }
 
 // neon light turn on simulator
void neon() {
  
  for (int i=0; i <= 10; i++) {
    turnon();
    delay(int(random(10,100)));
    turnoff();
    delay(int(random(10,100)));
  }
  turnon();
}

// simply turn off all the pins
void turnoff() {
  String out = "000-000-000-" + Pos;
  udp.send(out, ip, port);
}

//simply turn on all the pins
void turnon() {
 if(Pos=="rau"){
   udp.send(outString(rauR, rauG,rauB), ip, port);
 }
 else if(Pos=="let"){
   udp.send(outString(letR, letG, letB), ip, port);
 }
 else if(Pos=="fre"){
   udp.send(outString(freR, freG, freB), ip, port);
 }
 else if(Pos=="rin"){
   udp.send(outString(rinR, rinG, rinB), ip, port);
 }
}

// fade in
void pulseUp() {  
  for (int i=1; i <= 255; i++) {
    udp.send(outString(i,i,i), ip, port);
    if(i>25) i++;
    if(i>50) i++;
    if(i>150)i++;
    if(i>200)i++;
    delay(8);
  }
}

// fade out
void pulseDown() {  
  for (int i=255; i >= 0; i--) {
    udp.send(outString(i,i,i), ip, port);
    if(i>25) i--;
    if(i>50) i--;
    if(i>150)i--;
    if(i>200)i--;
    delay(8);
  }
}  

//pulse
void pulse(){
  pulseDown();
  pulseUp();
}

void random(){
  globalR = int(random(256));
  globalG = int(random(256));
  globalB = int(random(256));
  if((globalR<200 && globalG<200 && globalB<200) || (globalR>50 && globalG>50 && globalB>50))
  random();
  udp.send(outString(globalR, globalG, globalB), ip, port);
}

// transmit brightness for right brightness panel 
void brightnessLFR(){
  if(mouseX>4 && mouseX>646 && mouseY<517 && (ms+75)<millis()){
    ms = millis();
    float factor = 255/float(max(globalR, globalG, globalB));
    float wert = (255/(255-(mouseY-6)/2));
    print(wert);
    print(' ');
    // haerter typisieren & udp send
    udp.send(outString(int(float(globalR) * factor/wert), int(float(globalG) * factor/wert), int(float(globalB) * factor/wert)), ip, port);
  }
}

// transmit rgb values from color panel at the bottom
void colorLFR(){
  if(mouseY>545 && mouseY<745 && (ms+125)<millis()){
    ms=millis();
    if(mouseX>=0 && mouseX<256){
      globalR=255-mouseX;
      globalG=0;
      globalB=mouseX;
    }
    if(mouseX>=256 && mouseX<512){
      globalR=0;
      globalG=mouseX-255;
      globalB=511-mouseX;
    }
    if(mouseX>=512 && mouseX<=767){
      globalR=mouseX-511;
      globalG=767-mouseX;
      globalB=0;
    }
    udp.send(outString(globalR, globalG, globalB), ip, port);
  }
  
}
  

String outString(int R, int G, int B) {
  
 if(Pos=="rau"){
   rauR = R;
   rauG = G;
   rauB = B;
 }
 else if(Pos=="let"){
   letR = R;
   letG = G;
   letB = B;
 }
 else if(Pos=="fre"){
   freR = R;
   freG = G;
   freB = B;
 }
 else if(Pos=="rin"){
   rinR = R;
   rinG = G;
   rinB = B;
 }
 redraw();
 
 String out;
 
 if(R>99) out = str(R);
 else if (R>9) out = "0" + str(R);
 else out = "00" + str(R);
 
 out = out + "-";
 
 if(G>99) out = out + str(G);
 else if (G>9) out = out + "0" + str(G);
 else out = out + "00" + str(G);
 
 out = out + "-";
 
 if(B>99) out = out + str(B);
 else if (B>9) out = out + "0" + str(B);
 else out = out + "00" + str(B);
 
 out = out + "-" + Pos;
 
 return out;
}
