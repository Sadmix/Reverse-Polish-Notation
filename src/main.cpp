#include <iostream>
#include <list>
#include <functional>
#include "lexeme.h"
#include "statemachine.h"

int main(int argc, char const *argv[])
{
    std::map<std::string, int> map;
    std::vector<int> arr;
    std::string id_cell; 
    int id_num = 0;
    int num_cell = 0;
    std::vector<Lexeme> lexemes;
    char sym;
    std::ifstream exp("../in.txt");
    
    std::map<int, std::function<void()>> phaseOneY = {
        {0, [&](){}},
        {1, [&]()
            {
                id_cell.push_back(sym);
            }
        },
        {2, [&]()
            {
                map.insert({id_cell, id_num}); 
                id_num++; 
                id_cell.clear();
            }
        },
        {3, [&]()
            {
                lexemes.push_back(Lexeme(2, int(sym)));
            }
        },
        {4, [&]()
            {
                num_cell += num_cell*10 + int(sym - '0');
            }
        },
        {5, [&]()
            {
                lexemes.push_back(Lexeme(1, id_num-1));
                lexemes.push_back(Lexeme(2, int(sym)));
            }
        },
        {6, [&]()
            {
                int id = map.at(id_cell);
                id_cell.clear();
                lexemes.push_back(Lexeme(1, id));
                lexemes.push_back(Lexeme(2, int(sym)));
            }
        },
        {7, [&]()
            {
                lexemes.push_back(Lexeme(0, num_cell));
                num_cell = 0;
                lexemes.push_back(Lexeme(2, int(sym)));
            }
        },
        {8, [&]()
            {
                lexemes.push_back(Lexeme(0, num_cell));
                num_cell = 0;
                lexemes.push_back(Lexeme(2, int(sym)));
            }
        },
        {9, [&]()
            {
                lexemes.push_back(Lexeme(2, int(sym)));
            }
        }
    };

    StateMachine mp("../fs.txt", "../fy.txt");

    // phase 1
    while (!exp.eof())
    {
        exp.get(sym);
        if (sym != '\n')
        {
            phaseOneY.at(mp.input(sym))();
        }
    }

    // phase 2

    

    return 0;
}
