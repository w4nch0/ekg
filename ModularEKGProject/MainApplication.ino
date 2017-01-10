#include <Arduino.h>
#include "../lib/dataTypes/DataTypes.h"
#include "../lib/messages/MessagesTypeEnumeration.h"
#include "../lib/messages/MessagesIdEnumeration.h"
#include "../lib/signals/SignalIdEnumeration.h"
#include "../lib/messages/MessageStructure.h"

//Prototipes
void processMessage();
void clearBuffer();
void configureADQ();


  boolean isCommandRecived = false;
  boolean isExecutting = false;
  byte messageRecived[8];
  Message message;

  void setup() {
    Serial.begin(115200);
    }

  void loop() {
    if (isCommandRecived) {
      processMessage();
      isCommandRecived = false;
    }else if(isExecutting){
      //TODO
    }
  }


  void serialEvent() {
    while (Serial.available()) {
      Serial.readBytes(messageRecived,8);
      message.type = (messageRecived[0] & B11100000) >>5;
      message.messageID = messageRecived[0] & B00011111;
      message.signalID = messageRecived[1];
      message.data = (((unsigned int)(messageRecived[2]) << 8) & 0xFF00) + messageRecived[3];
      message.timeStamp = (((unsigned long)(messageRecived[4]) << 24) & 0xFF000000)+
                          (((unsigned long)(messageRecived[5]) << 16) & 0xFF0000)+
                          (((unsigned long)(messageRecived[6]) << 8) & 0xFF00)+
                          messageRecived[7];
      isCommandRecived = true;
      clearBuffer();
    }
  }

  void processMessage(){
    switch(message.type){
      case COMMAND:
      //TODO
        switch(message.messageID){
          case MSG_ID_START_ADQ:
          //TODO
          break;
          case MSG_ID_STOP_ADQ:
          //TODO
          break;
          case MSG_ID_SIGNALS_CFG:
          //TODO
          break;
          case MSG_ID_PARAMETERS_CFG:
          //TODO
          break;
          default:
          break;
        }
      break;
      case DELTA_STATUS:
      //TODO
      break;
      case DATA_REQUEST:
      //TODO
      break;
      default:
      //TODO
      break;
    }
  }

  void clearBuffer(){
    for(byte i = 0; i < 8; i++){
      messageRecived[i]=0;
    }
    Serial.flush();
  }
  void configureADQ(){
    //TODO
  }
