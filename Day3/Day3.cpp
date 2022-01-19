#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;


int Part1(vector<string> input){
    string epsilon_rate="", gamma_rate="";
    for(int i=0 ; i<input[0].size() ; i++){
        int count_of_ones=0, count_of_zeros=0;
        for(int j=0; j<input.size(); j++){
            if(input[j][i] == '0'){count_of_zeros++;}
            else if(input[j][i]== '1'){count_of_ones++;}
        }
        if(count_of_ones>count_of_zeros){
            gamma_rate+= '1';
            epsilon_rate+='0';
        }
        else{
            gamma_rate+='0';
            epsilon_rate+='1';
        }
    }
    return (stoi(gamma_rate, 0 , 2)*stoi(epsilon_rate,0,2));
}


int main(){
    //Processing input
    fstream file("data1.txt");
    vector<string> input;
    while(file.eof()==false){
        string binary;
        file>>binary;
        input.push_back(binary);
    }
    file.close();
    cout<<Part1(input)<<endl;
}