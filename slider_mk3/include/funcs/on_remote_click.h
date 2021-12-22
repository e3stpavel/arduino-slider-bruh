/*
 * Handles remote controller click action and depending on button clicked do something
 *
 * @author default
 * @returns void
 */

void on_remote_click() 
{
  // Print a short summary of received data
  IrReceiver.printIRResultShort(&Serial);

  if (IrReceiver.decodedIRData.protocol == UNKNOWN)
  {
    // We have an unknown protocol here, print more info
    IrReceiver.printIRResultRawFormatted(&Serial, true);
  }

  Serial.println();

  /*
    * !!!Important!!! Enable receiving of the next value,
    * since receiving has stopped after the end of the current received data packet.
    */
  
  // Enable receiving of the next value
  IrReceiver.resume(); 

  /*
    * Finally, check the received data and perform actions according to the received command
    */

  Serial.println(IrReceiver.decodedIRData.command);
  
  /*if (IrReceiver.decodedIRData.command == 0x10) 
  {
    // do something
  } 
  else if (IrReceiver.decodedIRData.command == 0x11) 
  {
    // do something else
  }*/
}