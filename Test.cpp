#include "doctest.h"
#include "mat.hpp"
using namespace ariel;
#include <stdexcept>
#include <string>
#include<iostream>
#include <algorithm>
#include <limits.h>
#include <string.h>
using namespace std;
//By Omer Rabin
string appendS(char c, int i){
    string s="";
    for(int j =0 ; j< i; j++){
        s+=c;
    }
    return s;
}
string nospaces(string input) {
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}


TEST_CASE("Good mat code"){
    CHECK(nospaces(mat(9, 7, '@', '-'))==nospaces("@@@@@@@@@\n@-------@\n@-@@@@@-@\n@-@---@-@\n@-@@@@@-@\n@-------@\n@@@@@@@@@"));
    CHECK(nospaces(mat(13, 5, '@', '-'))==nospaces("@@@@@@@@@@@@@\n@-----------@\n@-@@@@@@@@@-@\n@-----------@\n@@@@@@@@@@@@@"));
    CHECK(nospaces(mat(3, 5, '$', '+'))==nospaces("$$$\n$+$\n$+$\n$+$\n$$$"));
    CHECK(nospaces(mat(11, 7, '$', '%'))==nospaces("$$$$$$$$$$$\n$%%%%%%%%%$\n$%$$$$$$$%$\n$%$%%%%%$%$\n$%$$$$$$$%$\n$%%%%%%%%%$\n$$$$$$$$$$$"));
    CHECK(nospaces(mat(31, 7, '@', '-'))==nospaces("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n@-----------------------------@\n@-@@@@@@@@@@@@@@@@@@@@@@@@@@@-@\n@-@-------------------------@-@\n@-@@@@@@@@@@@@@@@@@@@@@@@@@@@-@\n@-----------------------------@\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"));
}

TEST_CASE("special cases"){

    for(int i=1; i<5;i+=2){
        for(int k=33;k<=47;k++)
        {
            for(int m=33;m<=47;m++)
            {
                std::string s(1, m); // convert to string

                CHECK(nospaces(mat(1,1,(char)m,(char)k))== nospaces(s)); // for a single char
                CHECK(nospaces(mat(i, 1,(char)m, (char)k))==nospaces(appendS((char)m, i))); // for 1 as second param
            }
        }
    }
}


TEST_CASE("Negative integer as input"){
    for(int i=-1; i > -5; i--){
        for(int j=0; j < 5; j++){
            CHECK_THROWS(mat(i,j,'#','$'));
            CHECK_THROWS(mat(-i,-j,'#','$'));
            CHECK_THROWS(mat(i,-j,'#','$'));
        }
    }
}

TEST_CASE("Bad mat code-The output size is not correct or mat structure is not good"){
    for(int i=1;i<5;i+=2){
        for(int j=1;j<5;j+=2){
            int size = nospaces(mat(i,j,char(i),char(j))).length();
            CHECK(size==(i*j)); // check the dimension
        }
    }
}

TEST_CASE("Bad mat code-parameters must be odd"){ // set to 10 because it's takes a lot of time
    for(int i=1;i<5;i++)
    {
        for(int j=2;j<5;j+=2)
        {
            for(int k=33;k<=47;k++)
            {
                for(int m=33;m<=47;m++)
                {
                    CHECK_THROWS(mat(i,j,(char)k,(char)m)); // check if throw error when the second index is even
                }
            }

        }
    }
    for(int i=2;i<5;i+=2)
    {
        for(int j=1;j<5;j++)
        {
            for(int k=33;k<=47;k++)
            {
                for(int m=33;m<=47;m++)
                {
                    CHECK_THROWS(mat(i,j,(char)k,(char)m)); //check if throw error when the first index is even
                }
            }

        }
    } 
}
