#include <iostream>
#include <vector>
#include <functional>
#include <stack>
#include "lexeme.h"
#include "statemachine.h"

int main(int argc, char const *argv[])
{
    // =====================================================
    // Memory section
    // =====================================================

    std::map<std::string, int> map; // map: id - num in array
    std::vector<int> arr;           // array of variables values

    // =====================================================
    // Phase 1
    // =====================================================

    std::string id_cell;            // id forming cell
    int id_num = 0;                 // for increment
    int num_cell = 0;               // number forming cell
    std::vector<Lexeme> lexemes;    // output array of lexemes
    char sym;                       // symbol for reading file
    std::ifstream exp("../in.txt"); // script file

    // map: yi - function
    std::map<int, std::function<void()>> phaseOneY = 
    {
        {0, [&](){}},
        {1, [&]()                               
            {
                id_cell.push_back(sym);                     // y1
            }
        },
        {2, [&]()
            {
                map.insert({id_cell, id_num}); 
                id_num++;                                   // y2
                id_cell.clear();
            }
        },
        {3, [&]()
            {
                lexemes.push_back(Lexeme(2, int(sym)));     // y3
            }
        },
        {4, [&]()
            {
                num_cell = num_cell*10 + sym - '0';   // y4
            }
        },
        {5, [&]()
            {
                int id = map.at(id_cell);                   // y5
                id_cell.clear();
                lexemes.push_back(Lexeme(1, id));
                lexemes.push_back(Lexeme(2, int(sym)));
            }
        },
        {6, [&]()
            {
                int id = map.at(id_cell);                   // y6
                id_cell.clear();
                lexemes.push_back(Lexeme(1, id));
                lexemes.push_back(Lexeme(2, int(sym)));
            }
        },
        {7, [&]()
            {
                lexemes.push_back(Lexeme(0, num_cell));
                num_cell = 0;                               // y7
                lexemes.push_back(Lexeme(2, int(sym)));
            }
        },
        {8, [&]()
            {
                lexemes.push_back(Lexeme(0, num_cell));
                num_cell = 0;                               // y8
                lexemes.push_back(Lexeme(2, int(sym)));
            }
        },
        {9, [&]()
            {
                lexemes.push_back(Lexeme(2, int(sym)));     // y9
            }
        }
    };

    StateMachine mp("../fs.txt", "../fy.txt"); // form state machine from fs and fy tables

    while (!exp.eof())
    {
        exp.get(sym);
        if (sym != '\n')
        {
            phaseOneY.at(mp.input(sym))();      // call yi at state machine state changing
        }
    }

    // =====================================================
    // Phase 1 END
    // =====================================================

    // =====================================================
    // Phase 2
    // =====================================================

    // update state-machine for 2nd phase
    mp.update("../fs2.txt", "../fy2.txt");

    // Output RPN array
    std::vector<Lexeme> rpn_arr;

    // MP-stack
    std::stack<Lexeme> stack;
    stack.push(Lexeme(2, int('@')));

    // Rang tape map: lexeme - rang
    std::map<Lexeme, int> Rt =
    {
        {Lexeme(2, int('(')), 3},
        {Lexeme(2, int(')')), 0},
        {Lexeme(2, int('+')), 1},
        {Lexeme(2, int('-')), 1},
        {Lexeme(2, int('*')), 2},
        {Lexeme(2, int('/')), 2},
        {Lexeme(2, int(';')), -1}
    };

    // Rang stack map: lexeme - rang
    std::map<Lexeme, int> Rs =
    {
        {Lexeme(2, int('(')), -1},
        {Lexeme(2, int('+')), 1},
        {Lexeme(2, int('-')), 1},
        {Lexeme(2, int('*')), 2},
        {Lexeme(2, int('/')), 2},
        {Lexeme(2, int('@')), -2}
    };

    // map: yi - function
    std::map<int, std::function<void(Lexeme)>> phaseTwoY = 
    {
        {0, [&](Lexeme lexeme)
            {}
        },
        {1, [&](Lexeme lexeme)
            {
                rpn_arr.push_back(lexeme);
            }
        },
        {2, [&](Lexeme lexeme)
            {
                stack.push(lexeme);
            }
        },
        {3, [&](Lexeme lexeme)
            {
                rpn_arr.push_back(stack.top()); 
                stack.pop();
            }
        },
        {4, [&](Lexeme lexeme)
            {
                stack.pop();
            }
        },
        {5, [&](Lexeme lexeme)
            {
                rpn_arr.push_back(lexeme);
            }
        }
    };

    int x = 0; // stm input signal

    // Analyser. Forms stm input signal
    for (int i = 0; i < lexemes.size(); i++)
    {
        Lexeme lexeme = lexemes[i];
        int lexeme_type = lexeme.getType();
        if(lexeme_type == 0 || lexeme_type == 1)
        {
            x = 1;
        }
        else if(lexeme_type == 2)
        {
            char lexeme_val = char(lexeme.getValue());
            int rt_ = Rt.at(lexeme);
            int rs_ = Rs.at(stack.top());
            if (rt_ > rs_)
            {
                if (lexeme_val != ';' && lexeme_val != ')')
                {
                    x = 2;
                }
                else if(lexeme_val != ')')
                {
                    x = 5;
                }
                else if (lexeme_val != ';')
                {
                    x = 4;
                }

            }
            else
            {
                x = 3;
                i--;
            }
        }
        else 
        {
            x = 0;
        }
        phaseTwoY.at(mp.input(x))(lexeme); // call funcion on x
    }

    // =====================================================
    // Phase 2 END
    // =====================================================

    // =====================================================
    // Phase 3
    // =====================================================

    // map: char - operation
    std::map<char, std::function<int(int, int)>> operations =
    {
        {'+', [](int a, int b){ return a+b;}}, // addition
        {'-', [](int a, int b){ return a-b;}}, // substraction
        {'*', [](int a, int b){ return a*b;}}, // multiplication
        {'/', [](int a, int b){ return a/b;}}  // division
    };

    Lexeme a, b; // Operand1 and Operand2

    // Analyser and combinational scheme
    for (auto lexeme : rpn_arr)
    {
        if(lexeme.getType() == 0 || lexeme.getType() == 1)
        {
            stack.push(lexeme); 
        }
        else if(lexeme.getType() == 2)
        {
            // if ';' then store result in arr
            if (char(lexeme.getValue()) == ';')
            {
                arr.push_back(stack.top().getValue());
                stack.pop();
                continue;
            }

            // get operands from mp-stack
            b = stack.top();
            stack.pop();
            a = stack.top();
            stack.pop();
            int a_val, b_val;

            // if operand type is 1 then get it value from arr
            // else get it value via it getValue() 
            if(a.getType() == 1)
                a_val = arr[a.getValue()];
            else
                a_val = a.getValue();
            if(b.getType() == 1)
                b_val = arr[b.getValue()];
            else
                b_val = b.getValue();
            
            // stores result of operation in stack
            stack.push(Lexeme(0, operations.at(char(lexeme.getValue()))(a_val, b_val)));
        }
    }

    // =====================================================
    // Phase 3 END
    // =====================================================

    // =====================================================
    // Print
    // =====================================================

    for(auto p : map)
    {
        std::cout << std::get<0>(p) << " = " << arr[std::get<1>(p)] << std::endl;
    }

    // =====================================================
    // Print END
    // =====================================================

    return 0;
}