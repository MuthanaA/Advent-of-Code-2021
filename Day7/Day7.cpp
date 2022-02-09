#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <numeric>
using namespace std;

long long int Part1(const vector<int> input){
    int median = 0;
    auto sorted = input;
    sort(sorted.begin() , sorted.end());
    int idx=0;
    if (sorted.size() % 2 == 1){
        idx = sorted[(sorted.size() + 1) / 2];
    }
    else
    {
        int left = sorted[(sorted.size() / 2) - 1];
        int right = sorted[sorted.size() / 2];
        idx = (left + right) / 2;
    }
    int fuel=0;
    for (int i = 0; i < sorted.size() ; i++){ 
        fuel += abs(sorted[i] - idx);
    }
    return fuel;
}

int Part2(const vector<int> input){
    int median = 0;
    auto sorted = input;
    sort(sorted.begin() , sorted.end());
    int idx=round(std::accumulate(sorted.begin(), sorted.end(), 0)/ input.size());
    
    //The sum of first n numbers = n(n+1)/2
    int fuel=0;
    for (int i = 0; i < sorted.size() ; i++){ 
        int diff = abs(sorted[i] - idx);
        fuel+=(diff*(diff+1))/2;
    }
    return fuel;
}

int main(){
    fstream file("data.txt");
    vector<int> input;
    string chr="";
    while(getline(file, chr,','))
    {
        int num = stoi(chr);
        input.push_back(num);
    }
    file.close();
    cout<<Part1(input)<<endl;
    cout<<Part2(input)<<endl;

}
