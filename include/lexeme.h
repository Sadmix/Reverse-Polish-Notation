#include <cstdint>
#include <string>
#include <map>

class Lexeme
{
private:
    uint32_t field;
public:
    Lexeme(int type, int value);
    ~Lexeme();
    int getValue();
    int getType();
};