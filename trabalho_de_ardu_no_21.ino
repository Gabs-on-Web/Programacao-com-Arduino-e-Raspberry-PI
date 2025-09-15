int pinoLDR = A0;   // Pino Analógico onde o LDR(photoresistor) está ligado
int pinoLED = 9;    // Pino onde está o LED
int limite = 500;   // Limitador para descobrir quando está claro/escuro

void setup() {
  pinMode(pinoLED, OUTPUT);
  Serial.begin(9600);  // Para monitorar os valores do LDR no Serial Monitor
}

void loop() {
  int valorLuz = analogRead(pinoLDR); // Lê o valor do LDR (0 a 1023)

  Serial.println(valorLuz); // Mostra no Serial Monitor

  if (valorLuz < limite) {
    // Se a leitura for menor que o limite = ambiente escuro
    digitalWrite(pinoLED, HIGH);  // Acende LED
  } else {
    // Se a leitura for maior ou igual = ambiente claro
    digitalWrite(pinoLED, LOW);   // Apaga LED
  }

  delay(200); // Pequeno atraso para estabilidade
}
