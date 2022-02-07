#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <exception>
#include <utility>
#include <map>
#include <math.h>
using namespace std;

struct point{
    int x;
    int y;
    bool operator<(const point &p) const{
        if (x != p.x) return x < p.x;
        else return y < p.y;
    }
    bool operator==(const point p) const{
        return (x==p.x && y ==p.y);
    }
};
struct Line{
    point start;
    point finish;
    bool operator<(const Line &l) const{
        return(sqrt((finish.y-start.y)^2 + (finish.x-start.x)^2) < sqrt((l.finish.y- l.start.y)^2 + (l.finish.x - l.start.x)^2));
    }
};
int Part1(const vector<Line> input){
    //Creating a map with all the points that were visited and the count of times it was visited
    std::map<point, int> map;
    for(int i = 0 ; i < input.size() ; i++){
        int yStart = input[i].start.y;
        int xStart = input[i].start.x;
        int yfinish = input[i].finish.y;
        int xfinish = input[i].finish.x;
        //Horizental lines
        if(yStart == yfinish){
            if(xStart< xfinish){
                for(int j = xStart; j <= xfinish ; j++){
                    point current;
                    current.x = j;
                    current.y = yStart;
                    if(map.find(current) != map.end()){
                        (map.find(current) -> second)++;
                    }
                    else{
                        map.insert(make_pair(current , 1));
                    }
                }
            }
            else{
                for(int j = xfinish; j <= xStart ; j++){
                    point current;
                    current.x = j;
                    current.y = yStart;
                    if(map.find(current) != map.end()){
                        (map.find(current) -> second)++;
                    }
                    else{
                        map.insert(make_pair(current , 1));
                    }
                }
            }
        }

        //Checking for vertical lines
        else if(xStart== xfinish){
            if(yStart < yfinish){
                for(int j = yStart ; j <= yfinish ; j++){
                    point current;
                    current.x = xStart;
                    current.y = j;
                    if(map.find(current) != map.end()){
                        (map.find(current) -> second)++;
                    }
                    else{
                        map.insert(make_pair(current , 1));
                    }
                }
            }
            else{
                for(int j = yStart ; j >= yfinish ; j--){
                    point current;
                    current.x = xStart;
                    current.y = j;
                    if(map.find(current) != map.end()){
                        (map.find(current) -> second)++;
                    }
                    else{
                        map.insert(make_pair(current , 1));
                    }
                }
            }
        }
    }
    //Checking how many points were visited twice.
    
    int answer = 0;
    for(auto it = map.begin() ; it !=map.end() ; it++){
        if((it -> second) > 1){
            answer++;
        }
    }

    return answer;
}


int Part2(const vector<Line> input){
    //Creating a map with all the points that were visited and the count of times it was visited
    std::map<point, int> map;
    for(int i = 0 ; i < input.size() ; i++){
        int yStart = input[i].start.y;
        int xStart = input[i].start.x;
        int yfinish = input[i].finish.y;
        int xfinish = input[i].finish.x;
        //Horizental lines
        if(yStart == yfinish){
            if(xStart< xfinish){
                for(int j = xStart; j <= xfinish ; j++){
                    point current;
                    current.x = j;
                    current.y = yStart;
                    if(map.find(current) != map.end()){
                        (map.find(current) -> second)++;
                    }
                    else{
                        map.insert(make_pair(current , 1));
                    }
                }
            }
            else{
                for(int j = xfinish; j <= xStart ; j++){
                    point current;
                    current.x = j;
                    current.y = yStart;
                    if(map.find(current) != map.end()){
                        (map.find(current) -> second)++;
                    }
                    else{
                        map.insert(make_pair(current , 1));
                    }
                }
            }
        }

        //Checking for vertical lines
        else if(xStart== xfinish){
            if(yStart < yfinish){
                for(int j = yStart ; j <= yfinish ; j++){
                    point current;
                    current.x = xStart;
                    current.y = j;
                    if(map.find(current) != map.end()){
                        (map.find(current) -> second)++;
                    }
                    else{
                        map.insert(make_pair(current , 1));
                    }
                }
            }
            else{
                for(int j = yStart ; j >= yfinish ; j--){
                    point current;
                    current.x = xStart;
                    current.y = j;
                    if(map.find(current) != map.end()){
                        (map.find(current) -> second)++;
                    }
                    else{
                        map.insert(make_pair(current , 1));
                    }
                }
            }
        }
        //Checking for diagonal lines
        else if(((yfinish - yStart)/(xfinish - xStart))==1 || ((yfinish - yStart)/(xfinish - xStart))==-1){
            if(yStart < yfinish){
                for(int j = 0 ; j<=(yfinish - yStart) ; j++){
                    point current;
                    current.x = xStart + j;
                    current.y = yStart + j;
                    if(map.find(current) != map.end()){
                        (map.find(current) -> second)++;
                    }
                    else{
                        map.insert(make_pair(current , 1));
                    }
                }
            }
            else{
                for(int j = 0 ; j<= (yStart - yfinish) ; j++){
                    point current;
                    current.x = xStart + j;
                    current.y = yStart - j;
                    if(map.find(current) != map.end()){
                        (map.find(current) -> second)++;
                    }
                    else{
                        map.insert(make_pair(current , 1));
                    }
                }
            }
        }
    }
    //Checking how many points were visited twice.
    
    int answer = 0;

    for(auto it = map.begin() ; it !=map.end() ; it++){
        if((it -> second) > 1){
            answer++;
        }
    }

    return answer;
}

int main(){
    //Converting the input to an array of lines
    fstream file("data.txt");
    vector<Line> lines;
    string line;
    while(getline(file, line)){
        int max_x = 0;
        int max_y = 0;
        char delimiter = '\0';
        int x1, y1, x2, y2;
        stringstream ss;
        ss<<line;
        ss>>x1>>delimiter>>y1>>delimiter>>delimiter>>x2>>delimiter>>y2;
        struct point p1, p2;
        p1.x = x1;
        p1.y = y1;
        p2.x = x2;
        p2.y = y2;
        struct Line lineseg;
        lineseg.start = p1;
        lineseg.finish = p2;
        lines.push_back(lineseg);
        max_x = max(max_x, max(p1.x , p2.x));
        max_y = max(max_y, max(p1.y, p2.y));
    }
    file.close();
    cout<<"Part 1: "<<Part1(lines)<<endl;
    cout<<"Part 2: "<<Part2(lines)<<endl;
}
