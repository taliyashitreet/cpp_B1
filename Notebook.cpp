#include "Notebook.hpp"
using ariel::Direction;
using std::string;
using namespace std;

namespace ariel
{

    void Notebook::write(int page, int row, int col, Direction d, string text)
    {
        // if (page < 0 || row < 0 || col < 0)
        // {
        //     throw invalid_argument("invalid input");
        // }
        // if (d == Direction::Horizontal && (unsigned int)col + text.length() > 100)
        // {
        //     throw invalid_argument("to long text");
        // }
        // if (!this->n.contains(page))
        // {
        //     map<int, char *> put;
        //     this->n.insert({page, put});
        // }
        // int tmpRow = row;
        // int tmpCol = col;
        // for (int i = 0; i < text.length(); i++)
        // {
        //     if (this->n.at(page).contains(tmpRow) &&
        //         this->n.at(page).at(tmpRow)[(unsigned int)tmpCol] != '_')
        //     {
        //         throw invalid_argument("already written here");
        //     }
        //     if (d == Direction::Horizontal)
        //     {
        //         tmpCol++;
        //     }
        //     else
        //     {
        //         tmpRow++;
        //     }
        // }

        // for (size_t c = 0; c < text.length(); c++)
        // {
        //     if (!this->n.at(page).contains(row))
        //     {
        //         char* put = new char[101];
        //         for (int i = 0; i < 101; i++)
        //         {
        //             put[i] = '_';
        //         }
        //         put[100] = '\0';
        //         this->n.at(page).insert({row, put});
        //     }

        //     this->n.at(page).at(row)[(unsigned int)col] = text.at(c);
        //     if (d == Direction::Horizontal)
        //     {
        //         col++;
        //     }
        //     else
        //     {
        //         row++;
        //     }
        // }
        return;
    }
    string Notebook::read(int page, int row, int col, Direction d, int len)
    {
        if (page < 0 || row < 0 || col < 0)
        {
            throw invalid_argument("invalid input");
        }
        if (d == Direction::Horizontal && col + len > 100)
        {
            throw invalid_argument("to long text");
        }
        if (!this->n.contains(page))
        {
            return "";
        }

        string ans = "";
        for (int i = 0; i < len; i++)
        {
            if (!this->n.at(page).contains(row))
            {
                ans += '_';
            }
            else
            {
                ans += this->n.at(page).at(row)[(unsigned int)col];
            }
            if (d == Direction::Horizontal)
            {
                col++;
            }
            else
            {
                row++;
            }
        }
        return ans;
    }
    

    void Notebook::erase(int page, int row, int col, Direction d, int len)
    {
        if (page < 0 || row < 0 || col < 0)
        {
            throw invalid_argument("invalid input");
        }
        if (d == Direction::Horizontal && col + len > 100)
        {
            throw invalid_argument("to long text");
        }
        if (!this->n.contains(page))
        {
            map<int, char *> put;
            this->n.insert({page, put});
        }
        for (int i = 0; i < len; i++)
        {
            if (!this->n.at(page).contains(row))
            {
               char* put = new char[101];
                for (int i = 0; i < 101; i++)
                {
                    put[i] = '_';
                }
                put[100] = '\0';
                this->n.at(page).insert({row, put});
            }
            this->n.at(page).at(row)[(unsigned int)col] = '~';
            if (d == Direction::Horizontal)
            {
                col++;
            }
            else
            {
                row++;
            }
        }
    }
    string Notebook::show(int page)
    {
        return "";
    }
            Notebook::~Notebook(){
            for(map<int,map<int,char*>>::iterator it = this->n.begin(); it!=this->n.end(); ++it){
                map<int,char*> tmpMap = this->n.at(it->first);
                for(map<int,char*>::iterator it2= tmpMap.begin(); it2!= tmpMap.end(); ++it2){
                    delete this->n.at(it->first).at(it2->first);
        
                }
            }
        }
}