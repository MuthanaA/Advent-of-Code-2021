//  Day1.cpp
//  Advent of Code 2021
//  Created by Muthana Alhadrab on 1/15/22.

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int number_of_higher_measurements(vector<int> depths){
    int answer = 0;
    int previous = depths[0];
    for(int i =1 ; i <depths.size() ; i++ ){
        if(depths[i]> previous){
            answer++;
        }
        previous= depths[i];
    }
    return answer;
}
int number_of_three_higher_measurements(vector<int> depths){
  int answer=0;
  for (vector<int>::iterator iter = depths.begin()+3 ;iter!=depths.end() ; ++iter ){
    const int previous = *(iter -3) + *(iter -2) + *(iter -1);
    const int current = *(iter -2) + *(iter -1) + *(iter);
    if(current> previous){
      answer++;
    }
  }
  return answer;
}

int main(){
  //Part 1
    fstream file("data2.txt");
    vector<int> measurements;
    while(file.eof()==false){
        int depth;
        file>>depth;
        measurements.push_back(depth);
    }
    file.close();
    cout<< number_of_higher_measurements(measurements);
   
  // Part2
  

    cout<< number_of_three_higher_measurements(measurements);
}

