import processing.serial.*;

Serial s;
int x= 0; 
int[] pixller_int;
String [] pixller;
int[] location;
void setup() { 
  s=new Serial(this, "com3", 9600);
  size(1200, 500);
  
  pixller_int =new int[8];
  pixller=new String[8];
  location=new int[8];
} 
int y=0;
void draw() {  
       
       background(0);  
        noStroke();
        fill(#ffffff);
   ellipse(600,y , 80, 120);
  String x=" ";
  if (s.available()>0) {  
    x= s.readString(); 
    pixller=x.split(" ");
        println(pixller.length);
    if (pixller.length==9) {
      for (int i=0; i<8; i++) {
        pixller_int[i]=int(pixller[i]); 
        print(pixller_int[i]);
      }
      println();
    }
    for (int i=0; i<8; i++) {
      if (pixller_int[i]==1) {
        location[i]=i*75;
        y=i*62;
        //noStroke();
        //fill(#ffffff);
        //ellipse(600, i*62, 80, 120);
      }
    }
  }



 
text(x, 10, 10);
}