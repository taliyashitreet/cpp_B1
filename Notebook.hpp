#include <map>
#include <string>
#include <iostream>
#include "Direction.hpp"
using ariel::Direction;
using std::string;
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

namespace ariel
{
    class Notebook
    {
        private:
        map<int, map<int, char*>> n;
        

    public:
        void write(int page, int row, int col, Direction, string text);
        string read(int page, int row, int col, Direction, int len);
        void erase(int page, int row, int col, Direction, int len);
        string show(int page);
        ~Notebook();
    };
}