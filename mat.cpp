#include <iostream>
using namespace std;
#include <stdexcept>
#include "mat.hpp"
#include <vector>
namespace ariel {
    vector<vector<char>> drowCols(vector<vector<char>> matrix, char c){
        int colMax=matrix[0].size()-1;
        int count=0;

        for(int j =1; j<matrix[0].size();j+=2){
            for(int i=j;i<matrix.size()-1-count*2;i++){
                if(matrix.size()-1-count*2>matrix.size()) break; // for integer overflow
                matrix[i][j]=c;
            }
            count++;
        }

        int counter=0;
        for(int j =matrix[0].size()-2; j>=1;j-=2){
            for(int i=matrix.size()-counter*2-2;i>=1+2*counter;i--){
                matrix[i][j]=c;
                
            }
            counter++;
        }
        return matrix;
    }
    vector<vector<char>> drowRows(vector<vector<char>> matrix, int w, char c){
        int _w=w;
        for(int i=1; i<matrix.size();i+=2){
            if(matrix.size()-i<=3) break;
            for(int j=i;j<=w;j++){
                matrix[i][j] = c;
            }
            w-=2;
        }
        int _w_=1;
        int counter=0;
        for(int i=matrix.size()-2;i>=0;i-=2){
            if(i==matrix.size()/2) break;
            for(int j=_w-2*counter;j>=_w_;j--){
                matrix[i][j] = c;
            }
            counter++;
            _w_+=2;
        }
        return matrix;
    }
    string mat(int a, int b, char c, char d){
        if(a%2==0 || b%2==0){
            throw std::invalid_argument("a and b must be odd!");
        }
        if(a<0 || b<0){
            throw std::invalid_argument("a and b must be greater then 0");
        }
        string result ="";
        vector<vector<char>> matrix(b);
        for(int i=0;i<b;i++){
            matrix[i].resize(a,c);
        }
        if(b==1){
            for(int i=0;i<a;i++){
                result+=matrix[0][i];
            }
            result+='\n';
        return result;
        }
        matrix = drowRows(matrix, a-2, d);
        matrix = drowCols(matrix, d);

        for(int i=0;i<b;i++){
            for(int j=0;j<a;j++){
                result+=matrix[i][j];
            }
            result+='\n';
        }
        
        return result;
    }
}
