// INICIO CONFIGURACIÓN ESTATIICA
// Tipos de mensajes
const byte COMMAND = 0x00;
const byte DELTA_STATUS = 0x01;
const byte DATA_REQUEST = 0x02;

// Identificación de mensajes
const byte MSG_ID_START_ADQ = 0x00;
const byte MSG_ID_STOP_ADQ = 0x01;
const byte MSG_ID_SIGNALS_CFG = 0x02;
const byte MSG_ID_PARAMETERS_CFG = 0x03;

// Identificación de señales
const byte SIGNAL_ID_D1 = 0x00;
const byte SIGNAL_ID_D2 = 0x01;
const byte SIGNAL_ID_D3 = 0x02;
const byte SIGNAL_ID_aVL = 0x03;
const byte SIGNAL_ID_aVR = 0x04;
const byte SIGNAL_ID_aVF = 0x05;
const byte SIGNAL_ID_V1 = 0x06;
const byte SIGNAL_ID_V2 = 0x07;
const byte SIGNAL_ID_V3 = 0x08;
const byte SIGNAL_ID_V4 = 0x09;
const byte SIGNAL_ID_V5 = 0x10;
const byte SIGNAL_ID_V6 = 0x11;

// FIN CONFIGURACIÓN ESTÁTICA

struct Message{
  byte type;
  byte messageID;
  byte signalID;
  unsigned int data;
  unsigned long timeStamp;
};
