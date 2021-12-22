uint16_t IR_recieve_data()
{
  uint16_t recieved_data;

  if (IrReceiver.decode()) {
    // Print a short summary of received data
    IrReceiver.printIRResultShort(&Serial);
    if (IrReceiver.decodedIRData.protocol == UNKNOWN) {
        // We have an unknown protocol here, print more info
        Serial.println("unknows");
        IrReceiver.printIRResultRawFormatted(&Serial, true);
    }
    Serial.println();

    /*
      * !!!Important!!! Enable receiving of the next value,
      * since receiving has stopped after the end of the current received data packet.
      */
    IrReceiver.resume(); // Enable receiving of the next value

    /*
      * Finally, check the received data and perform actions according to the received command
      */
    recieved_data = IrReceiver.decodedIRData.command;
    
    if (IrReceiver.decodedIRData.command == 0x10) {
      Serial.println("0x10");
    } 
    else if (IrReceiver.decodedIRData.command == 0x11) {
      Serial.println("0x11");
    }
  }

  return recieved_data;
}