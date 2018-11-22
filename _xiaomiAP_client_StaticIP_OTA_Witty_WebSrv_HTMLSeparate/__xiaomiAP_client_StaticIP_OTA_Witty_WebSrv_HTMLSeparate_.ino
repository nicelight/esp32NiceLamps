// пока тесты, юзаем  192.168.1.201/mech?button=51 192.168.1.201/mech?button=52

#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ArduinoOTA.h> // Библиотека для OTA-прошивки
#include "HTML_pages.h"

const char* ssid = "mi5"; //Имя точки доступа WIFI
const char* password = "verylongwifipassword"; //пароль точки доступа WIFI

ESP8266WebServer server(80);

const int LDR = A0;
const int BUTTON = 4;
const int RED = 15;
const int GREEN = 12;
const int BLUE = 13;

byte effects = 0;

void handleRoot() {
  // вывод страницы
  server.send(200, "text/html", html_main_page); // эта страница описана как static const char в файле HTML_pages.h
}//handle root

void handleLeds() {
  if (server.hasArg("red")) {
    if (server.arg("red") == "1") {
      // плавно включим красный
      for (int i = 0; i <= 255; i++) {
        analogWrite(RED, i);
        delay(2);
      }
      server.send(200, "text/html", html_main_page); // эта страница описана как static const char в файле HTML_pages.h
    }
    if (server.arg("red") == "0") {
      // плавно поутшим красный 
      for (int i = 255; i >= 0; i--) {
        analogWrite(RED, i);
        delay(2);
      }
      server.send(200, "text/html", html_main_page); // эта страница описана как static const char в файле HTML_pages.h
    }
  }//has.arg red
  if (server.hasArg("green")) {
    if (server.arg("green") == "1") {
      // плавно включим зеленый
      for (int i = 0; i <= 255; i++) {
        analogWrite(GREEN, i);
        delay(2);
      }
      server.send(200, "text/html", html_main_page); // эта страница описана как static const char в файле HTML_pages.h
    }
    if (server.arg("green") == "0") {
      // плавно поутшим зеленый 
      for (int i = 255; i >= 0; i--) {
        analogWrite(GREEN, i);
        delay(2);
      }
      server.send(200, "text/html", html_main_page); // эта страница описана как static const char в файле HTML_pages.h
    }
  }//has.arg green
  if (server.hasArg("blue")) {
    if (server.arg("blue") == "1") {
      // плавно включим синий
      for (int i = 0; i <= 255; i++) {
        analogWrite(BLUE, i);
        delay(2);
      }
      server.send(200, "text/html", html_main_page); // эта страница описана как static const char в файле HTML_pages.h
    }
    if (server.arg("blue") == "0") {
      // плавно поутшим синий 
      for (int i = 255; i >= 0; i--) {
        analogWrite(BLUE, i);
        delay(2);
      }
      server.send(200, "text/html", html_main_page); // эта страница описана как static const char в файле HTML_pages.h
    }
  }//has.arg blue
}//handle leds

void handleNotFound() {
  //digitalWrite(led, 1);
  String message = "File Not Found\n\n"; // \n\n - принудтельный перевод строки
  message += "URI: ";
  message += server.uri(); // пропишет тот адрес на который пользователь хотел попасть
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET) ? "GET" : "POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";
  for (uint8_t i = 0; i < server.args(); i++) {
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }
  server.send(404, "text/plain", message);
  //digitalWrite(led, 0);
}

void setup(void) {

  pinMode(BUTTON, INPUT_PULLUP); //кнопка на плате wetty
  pinMode(RED, OUTPUT); //
  digitalWrite(RED, 0);
  pinMode(BLUE, OUTPUT); //
  digitalWrite(BLUE, 0);
  pinMode(GREEN, OUTPUT); //
  digitalWrite(GREEN, 0);

  Serial.begin(115200); // скорость ограничиваю ибо под квесты Fantasmia прогу адаптирую
  delay(10);
  Serial.println("");
  Serial.println("");
  Serial.println("");
  WiFi.disconnect(); // завершим все wifi соединения
  WiFi.softAPdisconnect(); // отключаем точку доступа ( если вдруг успела сформироваться)
  WiFi.mode(WIFI_OFF); // отключаем вайфай физически
  delay(500);
  Serial.println("wifi force disconnecting...");
  // поднимаем соединение со статическим адресом
  WiFi.mode(WIFI_STA);
  WiFi.config(IPAddress(192, 168, 43, 241), IPAddress(192, 168, 43, 1), IPAddress(255, 255, 255, 0), IPAddress(192, 168, 43, 1));
  WiFi.begin(ssid, password);
  Serial.print("Connecting to wifi: ");
  Serial.print(ssid);
  Serial.print("  with pass:");
  Serial.println(password);
  Serial.print("  static ip :");
  Serial.println(WiFi.localIP());

  // ждем пока подключение произойдет
  while (WiFi.status() != WL_CONNECTED) {
    digitalWrite(RED, 1);
    delay(50);
    digitalWrite(RED, 0);
    delay(450);
    Serial.print(".");
  }
  Serial.print("  Connected with static ip: ");
  Serial.println(WiFi.localIP());
  for (int i = 0; i < 5; i++) {
    delay(130);
    digitalWrite(GREEN, 1);
    delay(70);
    digitalWrite(GREEN, 0);
  }

  ArduinoOTA.setHostname("esp_Witty_BME280_test_ip241"); // Задаем имя сетевого порта
  //  ArduinoOTA.setPassword((const char *)"0000"); // Задаем пароль доступа для удаленной прошивки
  ArduinoOTA.begin(); // Инициализируем OTA
  Serial.print("OTA HostName: ");
  Serial.println("esp_Witty_BME280_test_ip241");

  // Создание точки доступа
  //  WiFi.mode(WIFI_AP);
  // WiFi.softAP("Fantasmia", "testquest");
  // WiFi.softAP(ssid, password);
  // Serial.println("AP opend");

  server.on("/leds", handleLeds);
  server.on("/", handleRoot);
  server.on("/page2", []() {
    server.send(200, "text/plain", "page 2 also works well");
  });

  server.onNotFound(handleNotFound);
  server.begin();
  Serial.println("HTTP server started");
}//setup

void loop(void) {
  ArduinoOTA.handle(); // Всегда готовы к прошивке по воздуху.
  server.handleClient();

  switch (effects) {
    case 0:
      break;
    case 1:
      break;

  }//switch effects
}//loop
