//motor A
  #define enA 7
  #define in1 6
  #define in2 5
//motor B
  #define in3 4
  #define in4 3
  #define enB 2
//Cảm biến hồng ngoại
  #define hn_phai 22 //Hướng phải
  #define hn_trai 26 //Hướng trái
  #define hn_giua 30 //Giữa
//Cảm biến dò line
  #define line1 50 //Trên-phải
  #define line3 42 //Trên-trái
  #define line2 38 //Dưới-trái
  #define line4 46 //Dưới phải
//Khai báo biến
  String Str;
  int k, i, lineR, lineL;
  int giatri;
  int GT[] = {0, 64, 127, 191, 255};
  int x;
void setup() {
  pinMode(line1,INPUT);
  pinMode(line2,INPUT);
  pinMode(line3,INPUT);
  pinMode(line4,INPUT);
   
  pinMode(hn_trai,INPUT);
  pinMode(hn_phai,INPUT);
  pinMode(hn_giua,INPUT);
   
  pinMode(enA,OUTPUT);
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(enB,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  Serial.begin(9600);
}

void loop (){
  k=0;
  lineR = digitalRead(line3);
  lineL = digitalRead(line1);
  
  if(lineR == LOW && lineL == HIGH)
   { 
        k++;  
   }
   if(lineR == HIGH && lineL == LOW)
   {
        k++;
   }
   if ((lineR == LOW && lineL == LOW) || k==2) 
    {
        lui1s();
        xoaygoc(30); //180 độ
        k=0;
    }
   else 
     {
       if(digitalRead(hn_trai) == HIGH && digitalRead(hn_phai) == HIGH && digitalRead(hn_giua) == HIGH)
          {
            xoay(GT[4],GT[4]); //theo chiều kim đồng hồ
            Serial.println("Xoay"); 
          }
        else if(digitalRead(hn_trai) == LOW && digitalRead(hn_giua) == HIGH)
          {
            xoaynguoc(GT[4],GT[4]); // ngược kim đồng hồ
            Serial.println("1");
          }
        else if(digitalRead(hn_phai) == LOW && digitalRead(hn_giua) == HIGH)
          {
            xoay(GT[4],GT[4]);
            Serial.println("2");
          }
        else
          {
            dithang(GT[4]);
            Serial.println("3");
          }
     }
}
void lui1s() {
  for(int i =0;i<=10;i++){
        dilui(GT[4],GT[4]);
        delay(40);
        Serial.println("Lui");
      }
}
void xoaygoc(int x) {
        for(int i =0;i<=10;i++){
        xoay(GT[3],GT[3]);
        delay(x);
      }
}
void dithang(int x){
  //motor A di tien
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  analogWrite(enA,x);
//  motor B
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
  analogWrite(enB,x);
}
void dilui(int x, int y){
  //motor A di tien
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  analogWrite(enA,x);
//  motor B
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  analogWrite(enB,y);
}
void xoaynguoc(int x, int y){
  //motor A di tien
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  analogWrite(enA,x);
//  motor B
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  analogWrite(enB,y);
}
void xoay(int x, int y){
  //motor A di tien
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  analogWrite(enA,x);
//  motor B
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
  analogWrite(enB,y);
}
