#include "Word.h"

Word::Word()
{
    //ctor
}
bool comp_char (char c1, char c2)
{
    return tolower(c1) < tolower(c2);
}
bool Word::operator > (const Word& w)
{
    //return (word > w.word);
    return lexicographical_compare(w.word.begin(),w.word.end(),word.begin(),word.end(),comp_char);
}
bool Word::operator < (const Word& w)
{
    return lexicographical_compare(word.begin(),word.end(),w.word.begin(),w.word.end(),comp_char);
}
bool Word::operator >= (const Word& w)
{
    return lexicographical_compare(w.word.begin(),w.word.end(),word.begin(),word.end(),comp_char)||(word == w.word);
}
bool Word::operator <= (const Word& w)
{
    return lexicographical_compare(word.begin(),word.end(),w.word.begin(),w.word.end(),comp_char)||(word == w.word);
}
bool Word::operator == (const Word& w)
{
    return (word == w.word);
}
bool Word::operator != (const Word& w)
{
    return (word != w.word);
}

void Word::set_word(string word)
{
    this->word = word;
}
void Word::add_index(int index)
{
    indices.push_back(index);
    sort( indices.begin(), indices.end() );
    indices.erase( unique( indices.begin(), indices.end() ), indices.end() );
}
void Word::clear()
{
    word = "";
    indices.clear();
}
Word Word::operator = (const Word& w)
{
    if(*this == w)
    {
        for(unsigned int i = 0;i < w.indices.size();i++)
            add_index(w.indices[i]);
    }
    else
    {
        word = w.word;
        indices = w.indices;
    }
    return *this;
}
Word::~Word()
{
    //dtor
}

ostream& operator <<(ostream& out,const Word& w)
{
    out << w.word << ' ';
    for(unsigned int i = 0; i < w.indices.size()-1;i++)
        out << w.indices[i] << ',';
    out << w.indices[w.indices.size()-1] << endl;
    return out;
}
