import processing.serial.*;
Serial myPort;
String[] temp = new String[1];

void setup () {
  myPort = 
    new Serial(this, Serial.list()[0], 9600);

}

void draw () {
  if (myPort.available() > 0) {
    temp[0] = str(myPort.read());
  }
  println(temp[0]);
  saveStrings("temperature.txt", temp);

}
