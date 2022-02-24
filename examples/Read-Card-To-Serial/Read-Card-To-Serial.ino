/**
 **************************************************
 *
 * @file        Read-Card-To-Serial.ino
 * @brief       A simple example to interface with rdm6300 rfid reader.
 *
 *              Connect the rdm6300 to VCC=5V, GND=GND, TX=any GPIO (this case GPIO-04)
 *              Note that the rdm6300's TX line is 3.3V level,
 *              so it's safe to use with both AVR* and ESP* microcontrollers.
 *
 * This example uses SoftwareSerial, please read its limitations here:
 * https://www.arduino.cc/en/Reference/softwareSerial
 *
 * 
 *
 * Modified by: soldered.com for use with https://solde.red/333154
 *
 *
 *
 * @authors     Arad Eizen (https://github.com/arduino12).
 ***************************************************/

#include "RDM6300-SOLDERED.h"

#define RDM6300_RX_PIN 8
#define READ_LED_PIN   13

RDM6300 rdm6300(RDM6300_RX_PIN);

void setup()
{
    // Initialize Serial
    Serial.begin(115200);

    // Set led pin to output
    pinMode(READ_LED_PIN, OUTPUT);
    digitalWrite(READ_LED_PIN, LOW);

    // Begin RDM6300
    rdm6300.begin();

    Serial.println("\nPlace RFID tag near the rdm6300...");
}

void loop()
{
    /* if non-zero tag_id, update() returns true- a new tag is near! */
    if (rdm6300.update())
        Serial.println(rdm6300.get_tag_id(), HEX);  //Print ID of tag that is near

    // Turn led on if card is near
    digitalWrite(READ_LED_PIN, rdm6300.is_tag_near());

    delay(10);
}
