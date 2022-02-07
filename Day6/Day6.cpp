#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int Part1(const vector<int> nums , const int &simDuration){
    vector<int> input = nums;
    for(int i = 0 ; i < simDuration ; i++){
        int newOnes=0;
        for(int i = 0 ; i < input.size() ; i++){
            if(input[i] == 0){
                input[i]=6;
                newOnes++;
            }
            else{
                input[i]--;
            }
        }
        for(int i = 0 ; i<newOnes ; i++){
            input.push_back(8);
        }
    }
    return input.size();
}

long long int Part2(const vector<int> nums , int days){
    map<int, long long int> map;
    for(int i = 0 ; i <=8 ; i++){
        map.insert(make_pair(i,0));
    }
    for (int i = 0; i < nums.size() ; i++){ 
        (map.find(nums[i]) -> second)++;
    }
    for (int i = 0; i < days ; i++){ 
        auto newOnes = map.find(0) ->second;
        for (int j = 0; j <= 7 ; j++){ 
            (map.find(j) -> second) = (map.find(j+1) -> second);
        }
        (map.find(6) -> second) += newOnes;
        (map.find(8) -> second) = newOnes;
    }
    //counting
    long long int count = 0 ;
    for(int i =0 ; i<9 ; i++){
        count += map.find(i) ->second;
    }
    return count;
}
int main(){
    ifstream file("data.txt");
    string chr = "";
    vector<int> input;
    while(getline(file, chr,','))
    {
        int num = stoi(chr);
        input.push_back(num);
    }
    file.close();

    cout<<Part1(input, 80)<<endl;
    cout<<Part2(input, 256)<<endl;
}
