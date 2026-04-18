#include <ArduinoJson.h>  
#include <FastLED.h>     
#include <WiFi.h>         
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 
#define SCREEN_HEIGHT 64 
#define OLED_RESET    -1
#define NUM_LEDS 5
#define DATA_PIN 4

CRGB leds[NUM_LEDS];

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

const char* ssid = "logos";                
const char* password = "aj_rocks!";                   
String APIKEY = "ccc6d2cd259d69e9f4de8feafc9ad66d";
String CityID = "4765691";         
bool id = false;
WiFiClient client;
char servername[] = "api.openweathermap.org";            
String result;


void setup() {
  Serial.begin(115200);


//led setup
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(100);
  
//  Serial.print("Connecting to ");
  WiFi.mode(WIFI_STA);   //   create wifi station
 // Serial.println(ssid);
  WiFi.begin(ssid, password);

  Wire.begin(0, 1); // SDA = 0, SCL = 1
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.display();
  delay(200);
  display.clearDisplay();
  display.setTextSize(1);             // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE, SSD1306_BLACK);        // Draw white text on black backround
  display.setCursor(0, 0);            // Start at top-left corner
  display.print("Connecting.");
  display.display();

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
 //   Serial.print(".");
    display.print(".");
    display.display();
  }

 // Serial.println("");
 // Serial.println("IP address: ");
  //Serial.println(WiFi.localIP());
  display.clearDisplay();
  display.setCursor(0, 0);
  display.println("Connected ");
  display.println("IP Address: ");
  display.println(WiFi.localIP());
  display.display();
  delay(1000);
  display.clearDisplay();

}

void loop()                    
{
  if (client.connect(servername, 80))
  { 
    client.println("GET /data/2.5/weather?id=" + CityID + "&units=metric&APPID=" + APIKEY);
    client.println("Host: api.openweathermap.org");
    client.println("User-Agent: ArduinoWiFi/1.1");
    client.println("Connection: close");
    client.println();
  }
  else {
    //Serial.println("connection failed");        
    //Serial.println();
    display.print("error: check serial port");
  }

  while (client.connected() && !client.available())
    delay(1);                                         
  while (client.connected() || client.available())
  { //connected or data available
    char c = client.read();                     
    result = result + c;
  }

  client.stop();                                    
  result.replace('[', ' ');
  result.replace(']', ' ');
  //Serial.println(result);
  char jsonArray [result.length() + 1];
  result.toCharArray(jsonArray, sizeof(jsonArray));
  jsonArray[result.length() + 1] = '\0';
  StaticJsonDocument<1024> doc;
  DeserializationError  error = deserializeJson(doc, jsonArray);


  if (error) {
   // Serial.print(F("deserializeJson() failed with code "));
   // Serial.println(error.c_str());
    display.print("error: check serial port");
    return;
  }

  String location = doc["name"];
  int temperature = doc["main"]["temp"];
  int humidity = doc["main"]["humidity"];
  int weatherId = doc["weather"][0]["id"];



/*   Serial.println();
  Serial.print("Country: ");
  Serial.println(country);
  Serial.print("Location: ");
  Serial.println(location);
  Serial.print("Location ID: ");
  Serial.println(id);
  Serial.printf("Temperature: %d°C\r\n", temperature);
  Serial.printf("Humidity: %d %%\r\n", humidity);
  Serial.printf("Pressure: %.2f hpa\r\n", pressure);
  Serial.printf("Wind speed: %.1f m/s\r\n", Speed);
  Serial.printf("Wind degree: %d°\r\n", degree);
  Serial.printf("Longitude: %.2f\r\n", longitude);
  Serial.printf("Latitude: %.2f\r\n", latitude); */
  
  display.clearDisplay();
  display.setCursor(0, 0);            // Start at top-left corner (will calibrate to make it centered once i have the parts)

  display.println();
  display.setTextColor(SSD1306_WHITE, SSD1306_BLACK);
  display.print("Temp(F): ");
  display.print((temperature - 273.15) * 9/5 + 32); // the fromula to change the kelvin into freedom units
  
  display.display();
  
  //LED LOGIC 

  //Note: I will change add add to these colors once I see how they acutally look on the final product. 
  if (weatherId >= 200 && weatherId < 300) {
    // 2xx = Thunderstorm: Purple
    setGeoidColor(150, 0, 255); 
  } else if (weatherId >= 300 && weatherId < 600) {
    // 3xx & 5xx = Rain:  Blue
    setGeoidColor(0, 0, 255);
  } else if (weatherId == 800) {
    // 800 = Clear:  Warm Orange/Yellow
    setGeoidColor(255, 100, 0);
  } else {
    // Default for Clouds/Mist: White
    setGeoidColor(100, 100, 100);
  }


  delay(600000);     // 10 min delay

}

//made a function to make setting colors easier
void setGeoidColor(int r, int g, int b) {
  for(int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB(r, g, b);
  }
  FastLED.show();
}