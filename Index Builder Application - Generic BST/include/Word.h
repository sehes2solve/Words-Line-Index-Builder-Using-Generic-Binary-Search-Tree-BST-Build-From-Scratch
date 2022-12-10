#ifndef WORD_H
#define WORD_H
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

class Word
{
    public:
        Word();

        bool operator > (const Word&);
        bool operator < (const  Word&);
        bool operator >= (const Word&);
        bool operator <= (const Word&);
        bool operator == (const Word&);
        bool operator != (const Word&);
        Word operator = (const Word&);
        void set_word(string);
        void add_index(int);
        void clear();
        friend ostream& operator <<(ostream&,const Word&);
        virtual ~Word();

    protected:

    private:
        bool comp(char,char);
        string word;
        vector<int> indices;
};

#endif // WORD_H
