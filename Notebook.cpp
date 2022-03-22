//
// Created by cheer on 3/19/2022.
//

#include "Notebook.hpp"
#include <iostream>
#include <stdexcept>

using namespace std;
const int maxSym = 100;
namespace ariel {

    typedef unsigned int uint;
    typedef unsigned long ulong;


    void Notebook::write(unsigned int page, unsigned int row, unsigned int column, Direction direction, const std::string &message) {
        uint length = message.length();
        if (length == 0) {
            return;
        }
        if(column + length > maxSym){
            cout << "throw invalid_argument(\"error\")" << endl;
        }
        if (direction == Direction::Horizontal) {
            ulong size_y = 1;
            if (column > bound.min_x) {
                length += column - bound.min_x;
            }

            // same but for the y axis.
            if (row > bound.min_y) {
                size_y += row - bound.min_y;
            }
            if (bound.min_x > column) {
                bound.min_x = column;
            }

            if (bound.min_y > row) {
                bound.min_y = row;
            }

            if (bound.size_x < length) {
                bound.size_x = length;
            }

            if (bound.size_y < size_y) {
                bound.size_y = size_y;
            }
            for (uint i = 0; i < length; i++) {
                uint x = column + i;
                if(checkCharAt(page, x, row)){
//                    throw invalid_argument("error");
                    return;
                }

            }
        } else {
            ulong size_y = length;
            ulong length_1 = 1;
            if (column > bound.min_x) {
                length_1 += column - bound.min_x;
            }

            // same but for the y axis.
            if (row > bound.min_y) {
                size_y += row - bound.min_y;
            }
            if (bound.min_x > column) {
                bound.min_x = column;
            }

            if (bound.min_y > row) {
                bound.min_y = row;
            }

            if (bound.size_x < length_1) {
                bound.size_x = length_1;
            }

            if (bound.size_y < size_y) {
                bound.size_y = size_y;
            }
            for (uint i = 0; i < length; i++) {
                uint y = row + i;
                if(checkCharAt(page, column, y)){
//                    throw invalid_argument("error");
                    return;
                }

            }
        }

        if (direction == Direction::Horizontal) {
            ulong size_y = 1;
            if (column > bound.min_x) {
                length += column - bound.min_x;
            }

            // same but for the y axis.
            if (row > bound.min_y) {
                size_y += row - bound.min_y;
            }
            if (bound.min_x > column) {
                bound.min_x = column;
            }

            if (bound.min_y > row) {
                bound.min_y = row;
            }

            if (bound.size_x < length) {
                bound.size_x = length;
            }

            if (bound.size_y < size_y) {
                bound.size_y = size_y;
            }            for (uint i = 0; i < length; i++) {
                uint x = column + i;
                noteBook[{page, {x, row}}] = message.at(i);
//                setCharAt(page, x, row, message.at(i));
//                noteBook[{page, {x, y}}] = c;
            }

        } else {
            ulong size_y = length;
            ulong length_1 = 1;
            if (column > bound.min_x) {
                length_1 += column - bound.min_x;
            }

            // same but for the y axis.
            if (row > bound.min_y) {
                size_y += row - bound.min_y;
            }
            if (bound.min_x > column) {
                bound.min_x = column;
            }

            if (bound.min_y > row) {
                bound.min_y = row;
            }

            if (bound.size_x < length_1) {
                bound.size_x = length_1;
            }

            if (bound.size_y < size_y) {
                bound.size_y = size_y;
            }
            for (uint i = 0; i < length; i++) {
                uint y = row + i;
                noteBook[{page, {column, y}}] = message.at(i);
//                setCharAt(page, column, y, message.at(i));
//                noteBook[{page, {x, y}}] = c;
            }

        }
    }

    std::string Notebook::read(unsigned int page, uint row, uint column, Direction direction, uint length) const {
        if (length == 0) {
            return "";
        }
        if(direction == Direction::Horizontal && column + length > maxSym){
            cout << "throw invalid_argument(\"error\")" << endl;
        }

        string message;
        if (direction == Direction::Horizontal) {
            for (uint i = 0; i < length; i++) {
                uint x = column + i;
                pair<unsigned int, pair<unsigned int, unsigned int>> key = make_pair(page, make_pair(x, row));
                if (noteBook.count(key) == 1) {
                    message += noteBook.at(key);
                }
                else{
                    message += '_';
                }
            }
        } else {
            for (uint i = 0; i < length; i++) {
                uint y = row + i;
                pair<unsigned int, pair<unsigned int, unsigned int>> key = make_pair(page, make_pair(column, y));
                if (noteBook.count(key) == 1) {
                    message += noteBook.at(key);
                }
                else{
                    message += '_';
                }
            }
        }

        return message;
    }

    void Notebook::show(unsigned int pages) const {
        if (bound.size_x == 0) {
            return;
        }
        for (uint i = 0; i < bound.size_y + 2; i++) {
            auto space = to_string(bound.min_y + i - 1) + ": ";
            while (space.length() < to_string(bound.min_y + bound.size_y + 2).length() + 2) {
                space += " ";
            }
            cout << space << read(pages, bound.min_y + i - 1, bound.min_x - 2, Direction::Horizontal, bound.size_x + 4) << endl;
        }
    }

    void Notebook::erase(unsigned int page, unsigned int row, unsigned int column, Direction direction, unsigned int length) {
        if (length == 0) {
            // do nothing
            return;
        }
        if(direction == Direction::Horizontal && column + length > maxSym){
            cout << "throw invalid_argument(\"error\")" << endl;
        }


        if (direction == Direction::Horizontal) {
            ulong size_y = 1;
            if (column > bound.min_x) {
                length += column - bound.min_x;
            }

            // same but for the y axis.
            if (row > bound.min_y) {
                size_y += row - bound.min_y;
            }
            if (bound.min_x > column) {
                bound.min_x = column;
            }

            if (bound.min_y > row) {
                bound.min_y = row;
            }

            if (bound.size_x < length) {
                bound.size_x = length;
            }

            if (bound.size_y < size_y) {
                bound.size_y = size_y;
            }
            for (uint i = 0; i < length; i++) {
                uint x = column + i;
                noteBook[{page, {x, row}}] = '~';
            }
        } else {
            ulong size_y = length;
            ulong length_1 = 1;
            if (column > bound.min_x) {
                length_1 += column - bound.min_x;
            }

            // same but for the y axis.
            if (row > bound.min_y) {
                size_y += row - bound.min_y;
            }
            if (bound.min_x > column) {
                bound.min_x = column;
            }

            if (bound.min_y > row) {
                bound.min_y = row;
            }

            if (bound.size_x < length_1) {
                bound.size_x = length_1;
            }

            if (bound.size_y < size_y) {
                bound.size_y = size_y;
            }
            for (uint i = 0; i < length; i++) {
                uint y = row + i;
                noteBook[{page, {column, y}}] = '~';
            }
        }
    }
    bool Notebook::checkCharAt(unsigned int page, unsigned int x, unsigned int y) {
        pair<unsigned int, pair<unsigned int, unsigned int>> key = make_pair(page, make_pair(x, y));

        if (noteBook.count(key) == 1) {
            return true;
        }
        return false;
    }

}