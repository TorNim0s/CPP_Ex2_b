#include "Notebook.hpp"

using namespace std;

namespace ariel
{

    Notebook::Notebook()
    {
        // We don't need to build
    }

    void Notebook::write(int page, int row, int col, Direction direction, string const &str)
    {

        /*
        ---------BAD CASES------
        */

        if (page < 0 || row < 0 || col < 0)
        {
            throw runtime_error("Cannot accept negetive parameters!");
        }
        if (col >= COL_MAX)
        {
            throw runtime_error("column is more then required");
        }
        if ((col + (int)str.length() >= COL_MAX) && (direction == Direction::Horizontal))
        {
            throw runtime_error("col + the size of the text is out of bound!");
        }

        for (int i = 0; i < str.length(); i++)
        {
            if (str[(unsigned int)i] < MIN_CHAR || str[(unsigned int)i] > MAX_CHAR) // if we got a symbol that we don't accept
            {
                throw runtime_error("Invalid symbol!");
            }
            /*
            --------Horizontal--------
            */
            if (direction == Direction::Horizontal)
            {

                if (book[page][row][col + i] == '~')
                { // if we try to write on a written spot
                    throw runtime_error("Can't write on written place");
                }

                if (book[page][row][col + i] == 0)
                {
                    book[page][row][col + i] = str[(unsigned int)i];
                }
                else
                {
                    if (book[page][row][col + i] == '_')
                    {
                        book[page][row][col + i] = str[(unsigned int)i];
                    }
                    else
                    {
                        throw runtime_error("Can't write on written place");
                    }
                }
                // cout << page << row << i << ":" << book[page][row][i] << endl;
            }
            /*
            --------Vertical----------
            */
            else
            {
                if (book[page][row + i][col] == '~')
                {
                    throw runtime_error("Can't write on written place");
                }
                if (book[page][row + i][col] == 0)
                {
                    book[page][row + i][col] = str[(unsigned int)i];
                }
                else
                {
                    if (book[page][row + i][col] == '_')
                    {
                        book[page][row + i][col] = str[(unsigned int)i];
                    }
                    else
                    {
                        throw runtime_error("Can't write on written place");
                    }
                }
            }
        }
    }

    string Notebook::read(int page, int row, int col, Direction direction, int length)
    {
        if (page < 0 || row < 0 || col < 0 || length < 0)
        {
            throw runtime_error("Cannot accept negetive parameters!");
        }
        if (col >= COL_MAX)
        {
            throw runtime_error("column is more then required");
        }
        if ((col + length > COL_MAX) && (direction == Direction::Horizontal))
        {
            throw runtime_error("col + the size of the text is out of bound!");
        }

        string result;

        for (int i = 0; i < length; i++)
        {

            if (direction == Direction::Horizontal)
            {

                if (book[page][row][col + i] == 0)
                {
                    result += '_';
                }
                else
                {
                    result += book[page][row][col + i];
                }
            }
            else
            {
                if (book[page][row + i][col] == 0)
                {
                    result += '_';
                }
                else
                {
                    result += book[page][row + i][col];
                }
            }
        }
        return result;
    }

    void Notebook::erase(int page, int row, int col, Direction direction, int length)
    {
        if (page < 0 || row < 0 || col < 0 || length < 0)
        {
            throw runtime_error("Cannot accept negetive parameters!");
        }
        if (col >= COL_MAX)
        {
            throw runtime_error("column is more then required");
        }
        if ((col + length > COL_MAX) && (direction == Direction::Horizontal))
        {
            throw runtime_error("col + the size of the text is out of bound!");
        }

        for (int i = 0; i < length; i++)
        {
            if (direction == Direction::Horizontal)
            {
                book[page][row][col+i] = '~';
            }
            else
            {
                book[page][row+i][col] = '~';
            }
        }
    }

    void Notebook::show(int page)
    {
        if (page < 0){
            throw runtime_error("Invalid page under 0");
        }
        // show 10 rows
        const int printed_row = 10;
        for(int i = 0; i<printed_row; i++){
            for(int j = 0; j<COL_MAX; j++){
                char ch = book[page][i][j+i] == 0 ? '_':book[page][i][j+i];
                cout<<ch;
            }
            cout << endl;
        }
    }
}