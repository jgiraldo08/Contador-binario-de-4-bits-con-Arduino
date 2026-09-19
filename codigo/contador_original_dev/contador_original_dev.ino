const int BIT0 = 4;
const int BIT1 = 5;
const int BIT2 = 6;
const int BIT3 = 7;

int tiempo_espera = 500;

void setup()
{
  pinMode(BIT0, OUTPUT);
  pinMode(BIT1, OUTPUT);
  pinMode(BIT2, OUTPUT);
  pinMode(BIT3, OUTPUT);
}

void loop()
{
  // numero 0
  digitalWrite(BIT0, LOW);
  digitalWrite(BIT1, LOW);
  digitalWrite(BIT2, LOW);
  digitalWrite(BIT3, LOW);
  delay(tiempo_espera);
  
  // numero 1
  digitalWrite(BIT0, HIGH);
  digitalWrite(BIT1, LOW);
  digitalWrite(BIT2, LOW);
  digitalWrite(BIT3, LOW);
  delay(tiempo_espera);
  
  // numero 2
  digitalWrite(BIT0, LOW);
  digitalWrite(BIT1, HIGH);
  digitalWrite(BIT2, LOW);
  digitalWrite(BIT3, LOW);
  delay(tiempo_espera);

  // numero 3
  digitalWrite(BIT0, LOW);
  digitalWrite(BIT1, LOW);
  digitalWrite(BIT2, HIGH);
  digitalWrite(BIT3, LOW);
  delay(tiempo_espera);

  // numero 4
  digitalWrite(BIT0, LOW);
  digitalWrite(BIT1, LOW);
  digitalWrite(BIT2, LOW);
  digitalWrite(BIT3, HIGH);
  delay(tiempo_espera);
  
}