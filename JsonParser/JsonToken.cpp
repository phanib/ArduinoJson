
#include "JsonToken.h"

using namespace ArduinoJson::Parser;

JsonToken JsonToken::nextSibling() const
{
    jsmntok_t* t = token;
    int yetToVisit = 1;
    
    while (yetToVisit)
    {
        yetToVisit += t->size - 1;
        t++;
    }

    return JsonToken(json, t);
}