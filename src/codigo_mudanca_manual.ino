#include <Arduino.h>

const int relayPin = 16;       // Pino que o relé está conectado
const int moistureSensorPin = A0; // Pino que o sensor de umidade de solo está conectado
const int sensorPin = 5;      // Pino que o sensor de fluxo está conectado

volatile unsigned int pulseCount = 0;
float calibrationFactor = 7.5;  // Fator de calibração (ajuste conforme necessário)
unsigned long previousMillis = 0;
unsigned long umidadePreviousMillis = 0;
unsigned long interval = 1000;  // Intervalo de leitura do sensor de fluxo em milissegundos
unsigned long umidadeInterval = 1000; // Intervalo de leitura da umidade em milissegundos
float accumulatedVolume = 0.0; // Volume acumulado em litros
int umidadeAnterior = 0;
float flowRateAnterior = 0.0;
bool bombaLigada = false;
int umidadeMinima = 10;  // Valor mínimo inicial de umidade
int umidadeMaxima = 30;  // Valor máximo inicial de umidade

void IRAM_ATTR pulseCounter() {
  pulseCount++;
}

void setup() {
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, LOW);
  
  pinMode(moistureSensorPin, INPUT);
  
  Serial.begin(115200);
  
  pinMode(sensorPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(sensorPin), pulseCounter, FALLING);
}

void loop() {
  unsigned long currentMillis = millis();
  unsigned long currentUmidadeMillis = millis();
  int umidade = analogRead(moistureSensorPin);
  int umidadePercentual = map(umidade, 330, 1023, 100, 0);

  if (currentUmidadeMillis - umidadePreviousMillis >= umidadeInterval) {
    umidadePreviousMillis = currentUmidadeMillis;
    
    if (umidadePercentual != umidadeAnterior) {
      umidadeAnterior = umidadePercentual;
      Serial.print("Umidade: ");
      Serial.print(umidadePercentual);
      Serial.println("%");
    }
  }

  if (currentMillis - previousMillis >= interval) {
    detachInterrupt(digitalPinToInterrupt(sensorPin));
    float flowRate = pulseCount / calibrationFactor;
    if (flowRate != flowRateAnterior) {
      flowRateAnterior = flowRate;
      float volume = (flowRate * interval) / 60000.0; // Volume em litros (60,000 ms = 1 min)
      accumulatedVolume += volume; // Acumula o volume calculado

      Serial.print("Fluxo: ");
      Serial.print(flowRate, 2); // Exibe o fluxo com 2 casas decimais
      Serial.print(" L/min\t");

      Serial.print("Volume acumulado: ");
      Serial.print(accumulatedVolume, 2); // Exibe o volume acumulado com 2 casas decimais
      Serial.println(" Litros");
    }
    
    pulseCount = 0;
    previousMillis = currentMillis;
    attachInterrupt(digitalPinToInterrupt(sensorPin), pulseCounter, FALLING);
  }

  // Verifica se há dados disponíveis no buffer do Serial
  if (Serial.available() > 0) {
    char comando = Serial.read(); // Lê o caractere digitado
    int novoValor;
    // Verifica se o caractere é 'm' (umidade mínima) ou 'M' (umidade máxima)
    if (comando == 'm' || comando == 'M') {
      while (!Serial.available()) {
        // Aguarda até que um valor seja digitado no monitor serial
      }
      novoValor = Serial.parseInt(); // Lê o novo valor da umidade
      // Atualiza o valor de umidade mínima ou máxima conforme o comando
      if (comando == 'm') {
        umidadeMinima = novoValor;
        Serial.print("Umidade mínima atualizada para: ");
      } else if (comando == 'M') {
        umidadeMaxima = novoValor;
        Serial.print("Umidade máxima atualizada para: ");
      }
      Serial.println(novoValor);
    }
  }

  // Controle da bomba baseado nos valores de umidade configurados
  if (umidadePercentual <= umidadeMinima && !bombaLigada) {
    digitalWrite(relayPin, HIGH);
    bombaLigada = true;
    Serial.println("Bomba ligada");
  } else if (umidadePercentual >= umidadeMaxima && bombaLigada) {
    digitalWrite(relayPin, LOW);
    bombaLigada = false;
    Serial.println("Bomba desligada");
  }
}
