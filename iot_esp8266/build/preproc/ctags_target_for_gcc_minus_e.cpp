# 1 "/mnt/sdb1/HCRL/IoT/iot_esp8266/iot_esp8266.ino"
# 2 "/mnt/sdb1/HCRL/IoT/iot_esp8266/iot_esp8266.ino" 2
# 3 "/mnt/sdb1/HCRL/IoT/iot_esp8266/iot_esp8266.ino" 2
# 4 "/mnt/sdb1/HCRL/IoT/iot_esp8266/iot_esp8266.ino" 2

const uint8_t dht_pin = D4;

DHT dht(dht_pin, DHT11);

void setup()
{
    Serial.begin(115200);
    Serial.println("DHT11 begin!");

    dht.begin();
}

void loop()
{
    // check value is not a number?
    if (isnan(dht.readTemperature()) || isnan(dht.readHumidity()))
    {
        Serial.println("Failed to read data from DHT11 :(");
    }
    else
    {
        Serial.printf("Temperature : %.1f *C, Humidity : %.0f", dht.readTemperature(), dht.readHumidity());
        Serial.println("%");
    }
    delay(1000);
}
