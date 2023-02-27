#include <ArduinoJson.hpp>
#include <ArduinoJson.h>

void SerializeComplex()
{
    String json;
    StaticJsonDocument<300> doc;
    doc["text"] = "myText";
    doc["id"] = 10;
    doc["status"] = true;
    doc["value"] = 3.14;

    JsonObject obj = doc.createNestedObject("nestedObject");
    obj["key"] = 40;
    obj["description"] = "myDescription";
    obj["active"] = true;
    obj["qty"] = 1.414;

    JsonArray arr = doc.createNestedArray("nestedArray");
    arr.add("B");
    arr.add(45);
    arr.add(2.1728);
    arr.add(false);

    serializeJson(doc, json);
    Serial.println(json);
}

void DeserializeComplex()
{
    String json = "{\"text\":\"myText\",\"id\":10,\"status\":true,\"value\":3.14,\"nestedObject\":{\"key\":40,\"description\":\"myDescription\",\"active\":true,\"qty\":1.414},\"nestedArray\":[\"B\",45,2.1728,true]}";

    StaticJsonDocument<300> doc;
    DeserializationError error = deserializeJson(doc, json);
    if (error) { return; }

    String text = doc["text"];
    int id = doc["id"];
    bool stat = doc["status"];
    float value = doc["value"];

    Serial.println(text);
    Serial.println(id);
    Serial.println(stat);
    Serial.println(value);

    int key = doc["nestedObject"]["key"];
    String description = doc["nestedObject"]["description"];
    bool active = doc["nestedObject"]["active"];
    float qty = doc["nestedObject"]["qty"];

    Serial.println(key);
    Serial.println(description);
    Serial.println(active);
    Serial.println(qty);

    String item0 = doc["nestedArray"][0];
    int item1 = doc["nestedArray"][1];
    float item2 = doc["nestedArray"][2];
    bool item3 = doc["nestedArray"][3];

    Serial.println(item0);
    Serial.println(item1);
    Serial.println(item2);
    Serial.println(item3);
}

void setup()
{
    Serial.begin(9600);

    Serial.println("===== Complex Example =====");
    Serial.println("-- Serialize --");
    SerializeComplex();
    Serial.println();
    Serial.println("-- Deserialize --");
    DeserializeComplex();
    Serial.println();
}

void loop()
{
}