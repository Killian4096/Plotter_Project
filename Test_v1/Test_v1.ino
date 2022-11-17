#define P1 3
#define P2 4
#define P3 5
#define P4 6

#define P5 8
#define P6 9
#define P7 10
#define P8 11

#define t 2
#define cycle 200

bool P1_state = 1;
bool P2_state = 0;
bool P3_state = 1;
bool P4_state = 0;

bool P5_state = 1;
bool P6_state = 0;
bool P7_state = 1;
bool P8_state = 0;

void write_values(){
  digitalWrite(P1, P1_state);
  digitalWrite(P2, P2_state);
  digitalWrite(P3, P3_state);
  digitalWrite(P4, P4_state);
  digitalWrite(P5, P5_state);
  digitalWrite(P6, P6_state);
  digitalWrite(P7, P7_state);
  digitalWrite(P8, P8_state);
}

void spin_clockwise_1(){
  bool buf_val;

  buf_val = P4_state;
  P4_state = not(P3_state);
  P3_state = (buf_val);
  write_values();

  delay(t);

  buf_val = P2_state;
  P2_state = not(P1_state);
  P1_state = (buf_val);
  write_values();

  delay(t);

}

void spin_clockwise_2(){
  bool buf_val;

  buf_val = P8_state;
  P8_state = not(P7_state);
  P7_state = (buf_val);
  write_values();

  delay(t);

  buf_val = P6_state;
  P6_state = not(P5_state);
  P5_state = (buf_val);
  write_values();

  delay(t);

}

void spin_counterclockwise_1(){
  bool buf_val;

  buf_val = P2_state;
  P2_state = not(P1_state);
  P1_state = (buf_val);
  write_values();

  delay(t);

  buf_val = P4_state;
  P4_state = not(P3_state);
  P3_state = (buf_val);
  write_values();

  delay(t);
}

void spin_counterclockwise_2(){
  bool buf_val;

  buf_val = P6_state;
  P6_state = not(P5_state);
  P5_state = (buf_val);
  write_values();

  delay(t);

  buf_val = P8_state;
  P8_state = not(P7_state);
  P7_state = (buf_val);
  write_values();

  delay(t);
}

void setup() {
  // put your setup code here, to run once:
  pinMode(P1, OUTPUT);
  pinMode(P2, OUTPUT);
  pinMode(P3, OUTPUT);
  pinMode(P4, OUTPUT);
  pinMode(P5, OUTPUT);
  pinMode(P6, OUTPUT);
  pinMode(P7, OUTPUT);
  pinMode(P8, OUTPUT);
  
}

void loop() {
  for(int i=0; i < cycle; i++){
    spin_clockwise_1();
    spin_counterclockwise_2();
  }
  for(int i=0; i < cycle; i++){
    spin_clockwise_1();
    spin_clockwise_2();
  }
  for(int i=0; i < cycle; i++){
    spin_counterclockwise_1();
    spin_clockwise_2();
  }
  for(int i=0; i < cycle; i++){
    spin_counterclockwise_1();
    spin_counterclockwise_2();
  }
}
