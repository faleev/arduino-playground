#include <TimerOne.h>
#include <Wire.h>
#include <MultiFuncShield.h>
#include <DallasTemperature.h>
#include "DHT.h"
#include "SparkFunHTU21D.h"

#define DHTPIN 5
#define DHTTYPE DHT11
#define ONE_WIRE_BUS 6

DHT myDHT11(DHTPIN, DHTTYPE);
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature myDS18B20(&oneWire);
HTU21D myHTU21D;

void setup()
{
    Timer1.initialize();
    MFS.initialize(&Timer1);

    Serial.begin(9600);
    myDHT11.begin();
    myHTU21D.begin();

    MFS.beep();
    MFS.write("----");
    delay(1000);
}

void loop()
{
    float DHT11_temp = myDHT11.readTemperature();
    float DHT11_humd = myDHT11.readHumidity();
    float DHT11_hif = myDHT11.computeHeatIndex(DHT11_temp, DHT11_humd, false);

    float HTU21D_humd = myHTU21D.readHumidity();
    float HTU21D_temp = myHTU21D.readTemperature();

    myDS18B20.requestTemperatures();
    float DS18B20_temp = myDS18B20.getTempCByIndex(0);

    writeData(DHT11_temp, "DHT11 Temperature: ", LED_1);
    delay(2000);

    writeData(HTU21D_temp, "HTU21D Temperature: ", LED_2);
    delay(2000);

    writeData(DHT11_humd, "DHT11 Humidity: ", LED_3);
    delay(2000);

    writeData(HTU21D_humd, "HTU21D Humidity: ", LED_4);
    delay(2000);

    writeData(DS18B20_temp, "DHTDS18B20 Temperature: ", LED_1 | LED_2);
    delay(2000);
}

void writeData(float val, String msg, byte nLED)
{
    Serial.print(msg);
    Serial.print(val);
    Serial.print("\n");

    MFS.write((float)val, 1);
    MFS.writeLeds(LED_ALL, OFF);
    MFS.writeLeds(nLED, ON);
}
