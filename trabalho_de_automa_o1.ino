// Pinos dos LEDs
#define LED_PORTAO   2
#define LED_SALA     3
#define LED_CORREDOR 4
#define LED_COZINHA  5
#define LED_QUARTO   6
#define LED_JARDIM   7

// Variáveis de controle
int hora = 0;          // formato 0000 a 2359
bool chovendo = false; // variável booleana para simular chuva

void setup() {
  Serial.begin(9600);

  pinMode(LED_PORTAO, OUTPUT);
  pinMode(LED_SALA, OUTPUT);
  pinMode(LED_CORREDOR, OUTPUT);
  pinMode(LED_COZINHA, OUTPUT);
  pinMode(LED_QUARTO, OUTPUT);
  pinMode(LED_JARDIM, OUTPUT);

  Serial.println("Sistema iniciado.");
}

void loop() {
  // 1) AUTOMACAO DA SALA (18:00 até 07:00)
  if ((hora >= 1800 && hora <= 2359) || (hora >= 0 && hora < 700)) {
    digitalWrite(LED_SALA, HIGH);
    Serial.print("Hora = ");
    Serial.println(hora);
  } else {
    digitalWrite(LED_SALA, LOW);
  }

  // 2) AUTOMACAO DO PORTAO, QUARTO, SALA, COZINHA
  // Exemplo: quando o portao acende, começa a sequência
  if (hora == 900) { // exemplo: portão acionado às 09:00
    digitalWrite(LED_PORTAO, HIGH);
    delay(3000);

    digitalWrite(LED_CORREDOR, HIGH);
    delay(4000);

    digitalWrite(LED_SALA, LOW); // desliga sala
    digitalWrite(LED_PORTAO, LOW);
    delay(1000);

    digitalWrite(LED_CORREDOR, LOW);
    delay(5000);

    digitalWrite(LED_COZINHA, HIGH);
    digitalWrite(LED_QUARTO, HIGH);
    delay(5000);

    // todas se apagam
    digitalWrite(LED_COZINHA, LOW);
    digitalWrite(LED_QUARTO, LOW);
    digitalWrite(LED_CORREDOR, LOW);
    digitalWrite(LED_PORTAO, LOW);
  }

  // 3) AUTOMACAO DO JARDIM
  // O jardim só liga de dia, sem chuva, nos intervalos dados
  // para essa parte do código funcionar, modifique a linha 11 para bool chovendo = false;
  if (!chovendo) {
    if ((hora >= 1000 && hora < 1300) || (hora >= 1700 && hora < 1800)) {
      digitalWrite(LED_JARDIM, HIGH);
    } else {
      digitalWrite(LED_JARDIM, LOW);
    }
  } else {
    digitalWrite(LED_JARDIM, LOW);
  }

  // Simulação da passagem do tempo
  delay(1000); // 1 segundo = simula passagem de 1 hora para simplificar
  hora += 100; // avança 1 hora
  if (hora > 2359) {
    hora = 0;
  }
}
