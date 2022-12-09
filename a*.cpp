#include <bits/stdc++.h>
using namespace std;
#define v 10
vector<int>opened(v);
priority_queue<pair<int,int>> open;
vector<bool> close(v,false);
char pathchar[10]={'A','B','C','D','E','F','G','H','I','J'};

void trackPath(vector<int>&path,int j){
	if(j==0) return;
	
   trackPath(path,path[j]);
   cout<<pathchar[path[j]]<<"->";
}

vector<int> aStarAlgo(int graph[v][v], int h[], int k, int goal)
{
	vector<int> g(v, INT_MAX);
	vector<int> f(v, INT_MAX);
	vector<int> path(v);
	g[0] = 0;
	f[0] = h[0];
	path[0]=-1;
	open.push(make_pair(-f[0], k));
	opened.push_back(k);
	while (!open.empty())
	{
		int current = open.top().second;
		if (current == goal)
			return path;
		open.pop();
		close[current]=true;
		int pos;
		for(int i=0;i<opened.size();i++){
			if(opened[i]==current){
				pos=i;
				break;
			}
		}
		opened.erase(opened.begin()+pos);
		
		for (int i = 0; i < v; i++)
		{
			if (graph[current][i] != 0) 
			{
				int tentative_g = g[current] + graph[current][i];
				if (tentative_g < g[i])
				{
					path[i] = current;
					g[i] = tentative_g;
					f[i] = tentative_g + h[i];
					int flag=0;
					if(close[i]==false){
                      open.push({-1*f[i],i});
						opened.push_back(i);
					}
					


				}

			}
		}
	}
	return path;

}

int main()
{
	int h[10] = {15, 13, 13, 12, 10, 9, 7, 6, 5, 0};
	int graph[10][10] = {{0, 6, 3, 1, 0, 0, 0, 0, 0, 0},
						 {6, 0, 2, 6, 3, 4, 0, 0, 0, 0},
						 {3, 2, 0, 0, 4, 5, 0, 0, 0, 0},
						 {1, 6, 0, 0, 7, 8, 9, 0, 0, 0},
						 {0, 3, 4, 7, 0, 6, 9, 9, 0, 0},
						 {0, 4, 5, 8, 6, 0, 8, 9, 0, 0},
						 {0, 0, 0, 9, 9, 8, 0, 11, 12, 14},
						 {0, 0, 0, 0, 9, 9, 11, 0, 14, 15},
						 {0, 0, 0, 0, 0, 0, 12, 14, 0, 0},
						 {0, 0, 0, 0, 0, 0, 14, 15, 0, 0}};

	vector<int>path=aStarAlgo(graph,h,0,9);
	cout<<"Path from starting Node A to Goal Node J- ";
    trackPath(path,9);
	cout<<"J";

}
