#ifndef BOARD_CPP
#define BOARD_CPP

#include "Direction.hpp"
#include <map>
#include <string>

struct Bound {
    // public:
    unsigned long min_x;
    unsigned long size_x;
    unsigned long min_y;
    unsigned long size_y;
    Bound() {
        size_x = 0;
        size_y = 0;
        min_x = (unsigned long)(-1);
        min_y = (unsigned long)(-1);
    }
};

namespace ariel {
    class Notebook {
    private:
        static char empty_val;
        Bound bound;
        std::map<std::pair<unsigned int, std::pair<unsigned int, unsigned int>>, char>
                noteBook;
        void setCharAt(unsigned int page, unsigned int x, unsigned int y, char c);
        char charAt(unsigned int page, unsigned int x, unsigned int y) const;
        void updateBound(unsigned long start_x, unsigned long start_y, unsigned long size_x, unsigned long size_y);

    public:
     
        void write(unsigned int page, unsigned int row, unsigned int column, Direction direction, const std::string &message);
       
        std::string read(unsigned int page, unsigned int row, unsigned int column, Direction direction, unsigned int length) const;
        void erase(unsigned int page, unsigned int row, unsigned int column, Direction direction, unsigned int length);

       
        void show(unsigned int pages) const;

        bool checkCharAt(unsigned int page, unsigned int x, unsigned int y);
    };
} 

#endif
