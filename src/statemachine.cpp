#include "statemachine.h"


// constructor: read fs.txt and fy.txt and form fs and fy
StateMachine::StateMachine(std::string fs_file, std::string fy_file)
{
    state = 0;
    fillTable(fs_file, fs);
    fillTable(fy_file, fy);
}

StateMachine::~StateMachine()
{

}

// map symbols to nums(codes)
int StateMachine::sym_to_code(char sym)
{
    std::map<char, int> a = {
        {'=', 2},
        {'(', 3},
        {')', 5},
        {';', 6},
        {'+', 4},
        {'-', 4},
        {'*', 4},
        {'/', 4}
    };
    if((sym >= 'A' && sym <= 'Z') || (sym >= 'a' && sym <= 'z'))
    {
        return 0;
    } 
    else if(sym >= '0' && sym <= '9')
    {
        return 1;
    }
    else
    {
        return a.at(sym);
    }
}

// change state and return semantic
int StateMachine::input(char in)
{
    int code = sym_to_code(in);
    int output = fy[code][state];
    state = fs[code][state];
    return output;
}

void StateMachine::reset()
{
    state = 0;
}


void StateMachine::fillTable(std::string fileName, std::vector<std::vector<int>> &table)
{

    std::ifstream tableFile(fileName);
    char transit;
    std::vector<int> raw;
    while (!tableFile.eof())
    {
        tableFile.get(transit);
        if (transit >= '0' && transit <= '9')
        {
            raw.push_back(int(transit - '0'));
        }
        else if (transit == '\n')
        {
            table.push_back(raw);
            raw.clear();
        }
    }
    raw.erase(raw.end()-1);
    table.push_back(raw);
}

void StateMachine::setTables(std::string fs_file, std::string fy_file)
{
    state = 0;
    fillTable(fs_file, fs);
    fillTable(fy_file, fy);
}