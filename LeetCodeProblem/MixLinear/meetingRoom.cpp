#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Interval { 
    int start, end; 
}; 
  
bool compareInterval(Interval i1, Interval i2) 
{ 
    return (i1.start < i2.start); 
} 

class myComparator 
{ 
public: 
    int operator() (const Interval& i1, const Interval& i2) 
    { 
        return i1.end > i2.end; 
    } 
}; 
  

int minMeetingRoom(vector<Interval> v1){
    if(v1.size() == 0){
        return 0;
    }
    sort(v1.begin(),v1.end(),compareInterval);
    
    priority_queue <Interval, vector<Interval>,myComparator> pq;
    pq.push(v1[0]);
    for(int i = 1; i<v1.size(); i++)
    {
        Interval curr = v1[i];
        Interval earl = pq.top();
        pq.pop();
        if(curr.start >= earl.end){
            earl.end = curr.end;
        }else{
            pq.push(curr);
        }
        pq.push(earl);
    }
    return pq.size();
}


int main(){

    vector<Interval> v1 = {{0,4},{5,10},{15,20}};
    cout << minMeetingRoom(v1) << endl;
}

