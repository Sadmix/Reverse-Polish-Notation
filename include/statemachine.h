#include <fstream>
#include <vector>
#include <map>

class StateMachine
{
private:
    int state;
    std::vector<std::vector<int>> fs;
    std::vector<std::vector<int>> fy;

    void fillTable(std::string fileName, std::vector<std::vector<int>> &table);
    int sym_to_code(char sym);
public:
    StateMachine(std::string fs_file, std::string fy_file);
    void update(std::string fs_file, std::string fy_file);
    void reset();
    int input(char in);
    int input(int in);
    ~StateMachine();
};