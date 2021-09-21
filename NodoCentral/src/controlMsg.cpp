//************************************************************
// Author: Jesús Muñoz Martínez
// Project: Trabajo Fin de Master: LUCES.
// Master de Sistemas Electrónicos para Entornos Inteligentes
// Root Node.
// Description: Header file from controlMsg.cpp
//
//************************************************************

#include "mesh.h"
#include "configFile.h"
#include <ESP_Mail_Client.h>
#include "config.h"

SMTPSession smtp;


void sendConfig2Nodes(){
    String myConf = loadConfig();
    JSONVar jsonConf = JSON.parse(myConf.c_str());
    jsonConf["type"] = "C"; //C: control/configuration
    jsonConf["email"] = undefined;
    String controlMsg = JSON.stringify(jsonConf);
    sendMessage(controlMsg);
    Serial.println("CTRL: Config sent.");
}




void sendEmail(int node){
    SMTPSession smtp;
    smtp.debug(1);
    String myConf = loadConfig();
    JSONVar jsonConf = JSON.parse(myConf.c_str());
    JSONVar jsonEmail = jsonConf["email"];
    String email = JSON.stringify(jsonEmail);
    int last =email.length()-1;
    email = email.substring(1,last);


    //smtp.callback(smtpCallback);
    ESP_Mail_Session session;

    /* Set the session config */
    session.server.host_name = SMTP_HOST;
    session.server.port = SMTP_PORT;
    session.login.email = email.c_str();
    session.login.password = AUTHOR_PASSWORD;
    session.login.user_domain = "";

    /* Declare the message class */
    SMTP_Message message;

    message.sender.name = "LUCES";
    message.sender.email = email.c_str();;
    message.subject = "LUCES:Aviso de fallo";
    message.addRecipient("LUCES", email.c_str());

    String textMsg = "Hola, Tenemos un problema. La luminaria numero "+String(node)+" presenta un fallo.";
    message.text.content = textMsg.c_str();
    message.text.charSet = "us-ascii";
    message.text.transfer_encoding = Content_Transfer_Encoding::enc_7bit;
    message.priority = esp_mail_smtp_priority::esp_mail_smtp_priority_low;
    message.response.notify = esp_mail_smtp_notify_success | esp_mail_smtp_notify_failure | esp_mail_smtp_notify_delay;

    if (!smtp.connect(&session))
        return;

    if (!MailClient.sendMail(&smtp, &message))
        Serial.println("Error sending Email, " + smtp.errorReason());

}