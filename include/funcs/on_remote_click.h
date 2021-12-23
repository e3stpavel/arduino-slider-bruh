/*
 * Handles remote controller click action and depending on button clicked do something
 *
 * @author default
 * @returns char
 */

char on_remote_click() 
{
  char recieved;

  if (IrReceiver.decode())
  {
    // Print a short summary of received data
    IrReceiver.printIRResultShort(&Serial);

    if (IrReceiver.decodedIRData.protocol == UNKNOWN)
    {
      // We have an unknown protocol here, print more info
      IrReceiver.printIRResultRawFormatted(&Serial, true);
    }

    Serial.println();
    
    // Enable receiving of the next value
    IrReceiver.resume(); 

    // Check the received data and perform actions according to the received command

    //Serial.println(IrReceiver.decodedIRData.command);

    if (IrReceiver.decodedIRData.command == 0x16) 
    {
      Serial.println("0");
      recieved = '0';
    }
    else if (IrReceiver.decodedIRData.command == 0xC)
    {
      Serial.println("1");
      recieved = '1';
    }
    else if (IrReceiver.decodedIRData.command == 0x18)
    {
      Serial.println("2");
      recieved = '2';
    }
    else if (IrReceiver.decodedIRData.command == 0x5E)
    {
      Serial.println("3");
      recieved = '3';
    }
    else if (IrReceiver.decodedIRData.command == 0x8)
    {
      Serial.println("4");
      recieved = '4';
    }
    else if (IrReceiver.decodedIRData.command == 0x1C)
    {
      Serial.println("5");
      recieved = '5';
    }
    else if (IrReceiver.decodedIRData.command == 0x5A)
    {
      Serial.println("6");
      recieved = '6';
    }
    else if (IrReceiver.decodedIRData.command == 0x42)
    {
      Serial.println("7");
      recieved = '7';
    }
    else if (IrReceiver.decodedIRData.command == 0x52)
    {
      Serial.println("8");
      recieved = '8';
    }
    else if (IrReceiver.decodedIRData.command == 0x4A)
    {
      Serial.println("9");
      recieved = '9';
    }
    else if (IrReceiver.decodedIRData.command == 0x15)
    {
      Serial.println("+");
      recieved = '+';
    }
    else if (IrReceiver.decodedIRData.command == 0x7)
    {
      Serial.println("-");
      recieved = '-';
    }
    // TODO: dot handling
    else if (IrReceiver.decodedIRData.command == 0x9)
    {
      Serial.println('.');
      recieved = '.';
    }
    else {
      Serial.println("no support");
    }
  }

  return recieved;
}