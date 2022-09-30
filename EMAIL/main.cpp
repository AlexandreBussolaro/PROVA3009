#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP_Mail_Client.h>
#define WIFI_SSID "PROF.RAFAEL"
#define WIFI_PASSWORD ""
#define SMTP_HOST "alexandrebussolaro@gmail.com"
#define SMTP_PORT 465
// Credenciais
#define AUTHOR_EMAIL "alexandrebussolaro@gmail.com"
#define AUTHOR_PASSWORD "lkitfrdvconajany"
// Para
#define RECIPIENT_EMAIL "lucas.eduardoz2001@gmail.com"
// Sessão SMTP usado para envio de e-mail
SMTPSession smtp;
//Função
void Email(){
// Habilita o debug via porta serial
// * nenhum debug - 0
// * depuração básica - 1
smtp.debug(1);
// Declara os dados de configuração da sessão 32
ESP_Mail_Session session;
// Set configuração
session.server.host_name = SMTP_HOST;
session.server.port = SMTP_PORT;
session.login.email = AUTHOR_EMAIL;
session.login.password = AUTHOR_PASSWORD;
session.login.user_domain = "lkitfrdvconajany";
// Declara a classe da mensagem
SMTP_Message message;
// Configura os cabeçalhos das mensagens
message.sender.name = "TA CHOVENDO";
message.sender.email = AUTHOR_EMAIL;
message.subject = "Teste CHUVA";
message.addRecipient("---", RECIPIENT_EMAIL);
//Editar a mensagem com HTML
String htmlMsg = "<div style=\"color:#2f4468;\"><h1>TESTE!</h1><p>- Consegui
mandar </p></div>";
message.html.content = htmlMsg.c_str();
message.html.content = htmlMsg.c_str();
message.text.charSet = "us-ascii";
message.html.transfer_encoding = Content_Transfer_Encoding::enc_7bit;
if (!smtp.connect(&session))
return;
// Envia o e-mail e fecha a sessão
if (!MailClient.sendMail(&smtp, &message)){
Serial.println("Erro ao enviar Email, " + smtp.errorReason());
}
}
void setup() {
Serial.begin(9600);
Serial.print("Connecting to AP");
WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
while (WiFi.status() != WL_CONNECTED){
Serial.print(".");
millis(200);
}
Serial.println("");
Serial.println("WiFi connected.");
Serial.println("IP address: ");
Serial.println(WiFi.localIP());
Serial.println();
Email();
}
void loop() {
}