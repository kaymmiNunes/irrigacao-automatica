# Sistema de Irrigação Inteligente com ESP8266 e Blynk IoT


Este projeto tem como objetivo o desenvolvimento de um **sistema de irrigação inteligente**, capaz de monitorar a umidade do solo, medir o consumo de água e acionar automaticamente uma bomba hidráulica, com acompanhamento remoto por meio de uma plataforma IoT.

---

### Objetivo Geral

Desenvolver um sistema automatizado de irrigação utilizando microcontrolador com conectividade Wi-Fi, sensores e plataforma IoT para monitoramento e controle remoto.

### Objetivos Específicos

* Monitorar a umidade do solo em tempo real;
* Controlar automaticamente o acionamento de uma bomba d’água;
* Medir o fluxo e o volume de água utilizado na irrigação;
* Permitir a configuração remota dos limites de umidade;
* Exibir dados de consumo e status do sistema em aplicativo móvel;
* Aplicar conceitos de interrupções, controle por tempo e IoT.

---

### Sensores Utilizados

* **Sensor de Umidade do Solo**: responsável por medir o nível de umidade, permitindo determinar a necessidade de irrigação.
* **Sensor de Fluxo de Água**: utilizado para medir a vazão e calcular o volume de água consumido durante o funcionamento do sistema.

### Plataforma IoT

A plataforma IoT utilizada permite a comunicação entre o microcontrolador e o aplicativo móvel, possibilitando visualização de dados, controle de atuadores e configuração remota do sistema.

---

### Hardware

* ESP8266 (NodeMCU ou equivalente);
* Sensor de umidade do solo;
* Sensor de fluxo de água;
* Módulo relé;
* Bomba d’água;
* Fonte de alimentação;
* Protoboard e jumpers.

### Software

* Arduino IDE;
* Plataforma Blynk IoT;
* Biblioteca ESP8266WiFi;
* Biblioteca Blynk.

---

## Funcionamento do Sistema

O sistema opera da seguinte forma:

* O sensor de umidade realiza leituras periódicas do solo;
* Caso a umidade esteja abaixo do limite mínimo configurado, a bomba é acionada;
* Quando a umidade atinge o limite máximo, a bomba é desligada;
* O sensor de fluxo contabiliza pulsos para cálculo da vazão e do volume de água;
* Os dados são enviados à plataforma IoT e exibidos no aplicativo móvel;
* O usuário pode acompanhar o sistema e ajustar parâmetros remotamente.

---

## lataforma IoT e Interface do Usuário

A interface do usuário foi desenvolvida no aplicativo móvel da plataforma IoT, utilizando widgets para:

* Exibição da umidade do solo;
* Configuração dos limites mínimo e máximo de umidade;
* Visualização do consumo de água (diário, mensal ou acumulado);
* Indicação do estado da bomba (ligada/desligada);
* Controle manual (opcional).

---

## Resultados Esperados

Com a implementação do sistema, espera-se:

* Redução do desperdício de água;
* Automatização eficiente do processo de irrigação;
* Maior controle e monitoramento do consumo hídrico;
* Aplicação prática de conceitos de IoT e sistemas embarcados;
* Viabilidade de uso em ambientes educacionais e experimentais.

---

## Instruções de Uso

> **Observação:** caso tenha interesse entre em contato pelo e-mail: kaymminunes@gmail.com

---

## Autoria

- Kaymmi Nunes Barbosa 
& 
- Erik de Souza Brito
