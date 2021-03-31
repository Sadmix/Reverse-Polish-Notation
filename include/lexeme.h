#include <cstdint>
#include <string>
#include <map>

class Lexeme
{
protected:
    uint32_t field; // bits[31:29] - type, bits[29:0] - values (depend on type)

public:
    Lexeme() = default;
    Lexeme(int type, int value);
    ~Lexeme();
    int getValue();
    int getType();
    
    friend bool operator< (const Lexeme &a, const Lexeme &b);
};
