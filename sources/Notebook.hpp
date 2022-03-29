#include "Direction.hpp"
#include <iostream>
#include <unordered_map>
#include <string>

#define COL_MAX 100
#define MAX_CHAR '}'
#define MIN_CHAR ' '


namespace ariel{
    class Notebook
    {
    private:
        std::unordered_map< int, std::unordered_map< int, char[COL_MAX]>> book; // -> page|row -> row text
        
    public:
        Notebook();
        void write(int page, int row, int col, Direction direction, std::string const &str);
        std::string read(int page, int row, int col, Direction direction, int length);
        void erase(int page, int row, int col, Direction direction, int length);
        void show(int page_to_show);
    };
    
}