#include <WiFi.h>
#include <ESPAsyncWebServer.h>

// Configurar rede Wi-fi:
const char* ssid = "NOME_DA_SUA_REDE";
const char* password = "SENHA_DA_SUA_REDE";
AsyncWebServer server(80);

//PÁGINA HTML + CSS + JS
const char index_html[] PROGMEM = R"rawliteral(

)rawliteral";

// SENSORES:
const int
sensor_gas = 2,
sensor_temperatura = ,
led = ;

// FUNÇÂO DE CONVERSÂO DOS DADOS:
String conversao() {

  return String(valor_gas);
  return String(valor_temp);
  return String(valor_led);
  
}

// CONFIGURAÇÂO DE PINOS:
void setup() {
  Serial.begin(115200);
  pinMode(sensor_gas, INPUT);
  pinMode(sensor_temperatura, INPUT);
  pinMode(led, OUTPUT);

  // CONEXÂO AO WIFI:
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Conectando ao Wi-Fi...");
  }
  Serial.println("");
  Serial.print("Conectado! Endereço IP: ");
  Serial.println(WiFi.localIP());

  // CARREGAMENTO PÁGINA WEB:
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_literal(200, "text/html", index_html);
  });

  // ROTAS DO JS:
  server.on("/sensor", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(200, "text/plain", valor_gas());
    request->send(200, "text/plain", valor_temp());
    request->send(200, "text/plain", valor_led());
  });
  
  server.begin();
}

void loop() {
  // SENSOR GAS:
  String valor_gas ="Erro ao Ler";
  int V_gas = digitalRead(sensor_gas);
  if (V_gas == LOW){
    Serial.println("gas => valor reconhecido");
    valor_gas ="Ausente";
  }
  if else (V_gas == HIGH){
    Serial.println("gas => valor reconhecido");
    valor_gas ="Presente";
  }
  else {
    Serial.println("Err - gas => valor não reconhecido");
  }

  // SENSOR TEMP.:
  int valor_temp = 99;
  int V_temp = digitalRead(sensor_gas);
  if (V_temp == LOW){
    Serial.println("gas => valor reconhecido");
    V_temp = valor_temp;
  }
  if else (V_temp == HIGH){
    Serial.println("gas => valor reconhecido");
    V_temp = valor_temp;
  }
  else {
    Serial.println("Err - gas => valor não reconhecido");
  }
  
  // LED.:
  String valor_led ="Erro ao Ler";
  int V_led = digitalRead(led);
  if (V_led == LOW){
    Serial.println("gas => valor reconhecido");
    valor_led = "desligado";
  }
  if else (V_led == HIGH){
    Serial.println("gas => valor reconhecido");
    valor_led = "ligado";
  }
  else {
    Serial.println("Err - gas => valor não reconhecido");
    valor_led = "erro no digital";
  }

}
