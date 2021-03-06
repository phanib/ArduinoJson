// Copyright Benoit Blanchon 2014
// MIT License
//
// Arduino JSON library
// https://github.com/bblanchon/ArduinoJson

#include <gtest/gtest.h>
#include <ArduinoJson.h>

TEST(DynamicJsonBuffer_Object_Tests, GrowsWithObject) {
  DynamicJsonBuffer json;

  JsonObject &obj = json.createObject();
  ASSERT_EQ(JSON_OBJECT_SIZE(0), json.size());

  obj["hello"];
  ASSERT_EQ(JSON_OBJECT_SIZE(1), json.size());

  obj["world"];
  ASSERT_EQ(JSON_OBJECT_SIZE(2), json.size());

  obj["world"];  // <- same value, should not grow
  ASSERT_EQ(JSON_OBJECT_SIZE(2), json.size());
}
