#include "lexeme.h"

Lexeme::Lexeme(int type, int value)
{
    field = ((uint32_t(value) & 0x3FFFFFFF) | uint32_t(type) << 30);
}

Lexeme::~Lexeme()
{

}

int Lexeme::getValue()
{
    return field & 0x3FFFFFFF;
}

int Lexeme::getType()
{
    return field >> 30;
}