//http://codepad.org/EtjWLys5
#include <iostream>
using namespace std;
/* 'X'=88 , 'O'=79 , '.'=46 */
class Noughts_and_Crosses
{
private:
    int *_iter_begin;
    int _count_X, _count_O;
    int _line_X, _line_O;

public:
    Noughts_and_Crosses(int &arg_beg) : _iter_begin(&arg_beg),_count_X(0),_count_O(0),_line_X(0),_line_O(0){};
    void reset_data();
    void input(const string &arg_s1,const string &arg_s2,const string &arg_s3);
    void check();
    void column_check(int &arg_column);
    void row_check(int &arg_row);
    void cross_check(int &arg_i);
    bool is_cheating();
    ~Noughts_and_Crosses(){};
};

int main()
{
    string s1="", s2="", s3="";
    int board[9]={46};
    Noughts_and_Crosses nc(board[0]);
    while (cin >> s1)
    {
        cin >> s2 >> s3;
        nc.input(s1,s2,s3);
        nc.check();
    }
    return 0;
}

void Noughts_and_Crosses::reset_data()
{
    _count_X = 0;
    _count_O = 0;
    _line_X = 0;
    _line_O = 0;
    return;
}
void Noughts_and_Crosses::input(const string &arg_s1,const string &arg_s2,const string &arg_s3)
{
    reset_data();
    for (int i = 0; i < 3; ++i)
    {
        *(_iter_begin+i)=(int)arg_s1[i];
    }
    for (int i = 0; i < 3; ++i)
    {
        *(_iter_begin+3+i)=(int)arg_s2[i];
    }
    for (int i = 0; i < 3; ++i)
    {
        *(_iter_begin+6+i)=(int)arg_s3[i];
    }
    return;
}
void Noughts_and_Crosses::check()
{
    for(int i=0; i<9;++i)
    {
        if (*(_iter_begin+i) == 88)
        {
            ++_count_X;
        }
        if (*(_iter_begin+i) == 79)
        {
            ++_count_O;
        }
    }
    for (int i = 0; i < 3; ++i)
    {
        column_check(i);
        row_check(i);
        cross_check(i);
    }
    if (is_cheating())
    {
        cout << "Cheating!" << endl;
        return;
    }
    else if (_line_O)
    {
        cout << "O win" << endl;
        return;
    }
    else if (_line_X)
    {
        cout << "X win" << endl;
        return;
    }
    else if ((_count_O + _count_X) == 9)
    {
        cout << "Tie" << endl;
        return;
    }
    else
    {
        cout << "Not yet" << endl;
        return;
    }
}
void Noughts_and_Crosses::column_check(int &arg_column)
{
    if (*(_iter_begin + arg_column) == 46)
    {
        return;
    }
    bool same_element = *(_iter_begin + arg_column) == *(_iter_begin + arg_column + 3) \
                        && *(_iter_begin + arg_column) == *(_iter_begin + arg_column + 6);
    if (same_element)
    {
        if (*(_iter_begin + arg_column) == 79)
        {
            ++_line_O;
        }
        else if (*(_iter_begin + arg_column) == 88)
        {
            ++_line_X;
        }
    }
    return;
}
void Noughts_and_Crosses::row_check(int &arg_row)
{
    if (*(_iter_begin + (arg_row * 3)) == 46)
    {
        return;
    }
    bool same_element = *(_iter_begin + (arg_row * 3)) == *(_iter_begin + 1 + (arg_row * 3)) \
                        && *(_iter_begin + (arg_row * 3)) == *(_iter_begin + 2 + (arg_row * 3));
    if (same_element)
    {
        if (*(_iter_begin + (arg_row * 3)) == 79)
        {
            ++_line_O;
        }
        else if (*(_iter_begin + (arg_row * 3)) == 88)
        {
            ++_line_X;
        }
    }
    return;
}
void Noughts_and_Crosses::cross_check(int &arg_i)
{
    if (arg_i == 2)
    {
        return;
    }
    if (*(_iter_begin + 4) == 46)
    {
        return;
    }
    bool same_element = *(_iter_begin + 4) == *(_iter_begin + arg_i * 2)  \
                        && *(_iter_begin + 4) == *(_iter_begin + (8 - arg_i * 2));
    if (same_element)
    {
        if (*(_iter_begin + 4) == 79)
        {
            ++_line_O;
        }
        else if (*(_iter_begin + 4) == 88)
        {
            ++_line_X;
        }
    }
    return;
}
bool Noughts_and_Crosses::is_cheating()
{
    bool cheating = (((_count_X - _count_O) != 1) && ((_count_X - _count_O) != 0)) \
                    || (_line_O == 1 && _line_X == 1) \
                    || (_line_X == 1 && (_count_X - _count_O) == 0);
    return cheating;
}