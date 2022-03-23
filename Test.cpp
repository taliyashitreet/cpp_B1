#include "doctest.h"
#include "Notebook.hpp"
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;
using std::string;
using ariel::Direction;

int rand_range(int min, int max)
{
    int range = max - min + 1;
    return rand() % range + min;
}
string longIn(){
    string ans="";
    for (size_t i = 0; i < 150; i++)
    {
       ans+='a';
    }
    return ans;
    
}

TEST_CASE("Good Input"){
    ariel::Notebook notebook;
    notebook.write(0,0,0,Direction::Vertical,"Hello");
    CHECK(notebook.read(0,0,0,Direction::Vertical,5)=="Hello");
    notebook.write(1,1,0,Direction::Vertical,"World");
    CHECK(notebook.read(1,1,0,Direction::Vertical,5)=="World");
     notebook.write(2,0,0,Direction::Horizontal,"supercalifrangeliskiexpialidoshi");
    CHECK(notebook.read(2,0,0,Direction::Horizontal,32)=="supercalifrangeliskiexpialidoshi");
    string put= "abc";
    for(int i=100; i<115; i++){
        put[2]=i;
        notebook.write(i,0,0,Direction::Vertical,put);
        CHECK(notebook.read(i,0,0,Direction::Vertical,3)==put);
    }
}

TEST_CASE("bad input"){
    ariel::Notebook n;
    CHECK_THROWS(n.read(1,-2,3,Direction::Vertical,5));
    CHECK_THROWS(n.read(2,-2,3,Direction::Vertical,5));
    CHECK_THROWS(n.read(-3,-2,3,Direction::Vertical,5));
}

TEST_CASE("Writing at wrong place"){
    ariel::Notebook notebook;
     string put= "abc";
    for(int i=20; i<200; i++){
        put[2]=i;
        notebook.write(i,0,0,Direction::Vertical,put);
    }
    for(int i=20; i<200; i++){
        put[2]=i;
        CHECK_THROWS(notebook.write(i,0,0,Direction::Vertical,put));
        //already put a string in this place
    }

}

TEST_CASE("To long input"){
    ariel::Notebook notebook;
    CHECK_THROWS(notebook.write(0,0,0,Direction::Horizontal,longIn()));
    CHECK_THROWS(notebook.write(1,0,2,Direction::Horizontal,longIn()));
    CHECK_THROWS(notebook.write(7,8,9,Direction::Horizontal,longIn()));
}