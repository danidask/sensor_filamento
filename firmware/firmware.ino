const byte encoderPin = 2; //pin con interrupcion
const byte pausaPin = 3; //manda señal de pausa al controlador de la impresora
const byte retardo = 3000; //milisegundos de retardo entre lecturas
volatile byte pasos = 0;

void setup() {
  pinMode(encoderPin, INPUT_PULLUP);
  pinMode(pausaPin, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(encoderPin), contarpasos, CHANGE);
  digitalWrite(pausaPin, LOW);
}

void loop() {
  //aqui rutina de inicio (cuando empieza a contar)
  //habra que esperar a que cuente un poco
  while (true) {
     delay(retardo);
     if (pasos == 0)
       break;
     pasos = 0;
  }
  digitalWrite(pausaPin, HIGH);
  delay(500);
  digitalWrite(pausaPin, LOW);
}

void contarpasos() {
  pasos++;
}
