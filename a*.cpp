#include<bits/stdc++.h>
using namespace std;


//code will not work as its incomplete


int main(){
    vector<vector<int>> graph = {{0,6,3,1,0,0,0,0,0,0},
                                 {6,0,2,6,3,4,0,0,0,0},
                                 {3,2,0,0,4,5,0,0,0,0},
                                 {1,6,0,0,7,8,9,0,0,0},
                                 {0,3,4,7,0,6,9,9,0,0},
                                 {0,4,5,8,6,0,8,9,0,0},
                                 {0,0,0,9,9,8,0,11,12,14},
                                 {0,0,0,0,9,9,11,0,14,15},
                                 {0,0,0,0,0,0,12,14,0,0},
                                 {0,0,0,0,0,0,14,15,0,0}
                                };
    vector<int> heuristic = {15, 13 , 13, 12, 10, 9, 7, 6, 5, 0};
    vector<pair<int,int>> openList;
    vector<int> closedList;

    openList.push_back(make_pair(0,15));
    int check[] = {1,0,0,0,0,0,0,0,0,0};

    while(true){
        if(openList.size() == 0){
            break;
        }
        int min = INT_MAX;
        int cans = -1;
        for(int i=0;i<openList.size();i++){
            if(openList[i].second < min){
                min = openList[i].second;
                cans = openList[i].first;
            }
        }
        closedList.push_back(cans); // path is updated
        if(heuristic[cans] == 0){
            break; // goal node is found.
        }
        for(int j=0;j<10;j++){
            if(graph[cans][j] != 0){
               if(check[j] == 0){
                    openList.push_back(make_pair(j,graph[cans][j]+heuristic[j]));
                    check[j] = 1;// means edge is present and node is not in either closed or open list.
               }
                else{
                    // still working on it
                }
            }
        }
    }
    for(int i=0;i<closedList.size();i++){
        char temp = 97 + closedList[i];
        cout<<temp<<"--->";
    }
    return 0;
}
