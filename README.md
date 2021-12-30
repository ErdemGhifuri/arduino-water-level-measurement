# WATER LEVEL MEASUREMENT

this is an arduino Project to measure water level and send it to [https://iotghifari.web.app](https://iotghifari.web.app)

## Components

1. Arduino Uno Microcontroller
2. HC-SR04 Sensor
3. NodeMCU ESP8266 Module

## Notes

the sensor will measure the water level based on SONAR principle, then the value will be sent to **http://iotghifari.web.app/post/data?field=field_name&value=field_value** with `field_name` is type of the measured data and `field_value` is the data value

## References

- [Ultrasonic Sensor HC-SR04 with Arduino Tutorial](https://create.arduino.cc/projecthub/abdularbi17/ultrasonic-sensor-hc-sr04-with-arduino-tutorial-327ff6)
- [Getting Started w/ NodeMCU ESP8266 on Arduino IDE © GPL3+](https://create.arduino.cc/projecthub/electropeak/getting-started-w-nodemcu-esp8266-on-arduino-ide-28184f)