#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <utility>

using namespace std;

vector<pair<string, int> > process_data(vector<string> input){
    vector<pair<string, int> > processed_data;
    for (string line : input){
        int space_position = line.find_first_of(' ');
        processed_data.push_back(make_pair(line.substr(0, space_position), stoi(line.substr(space_position))));
    }
    return processed_data;
}

int Part1(vector <pair<string, int> > input){
    int depth = 0;
    int distance = 0;
    for(const pair<string, int> line : input){
        if(line.first == "forward"){
            distance+= line.second;
        }
        else if (line.first == "down")
        {
            depth+=line.second;
        }
        else if (line.first == "up")
        {
            depth-=line.second;
        }
    }
    return (depth*distance);
}

int Part2(vector <pair<string, int> > input){
    int depth = 0;
    int distance = 0;
    int aim = 0;
    for(const pair<string, int> line : input){
        if(line.first == "forward"){
            distance+= line.second;
            depth += (aim*line.second);
        }
        else if (line.first == "down")
        {
            aim += line.second;
        }
        else if (line.first == "up")
        {
            aim -=line.second;
        }
    }
    return (depth*distance);
}
int main(){
    fstream file("Data1.txt");
    vector<string> lines;
    while(file.eof()==false){
        string output;
        getline(file, output);
        lines.push_back(output);
    }
    file.close();
    //Part 1
    cout<<"Answer to Part 1: "<<Part1(process_data(lines))<<endl;
    //Part2
    cout<<"Answer to Part 2: "<<Part2(process_data(lines))<<endl;
}