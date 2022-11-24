#include<bits/stdc++.h>
using namespace std;

float mean(vector<float> arr){
    float sum = 0;
    int n = arr.size();
    float mean_of_array = -1;
    for(int i=0;i<n;i++){
        sum += arr[i];
    }
    mean_of_array = sum/n;
    return mean_of_array;
}

int main(){
    int s1,s2,s3,s4;
    cout<<"Enter the seed values : ";
    cin>>s1>>s2>>s3>>s4;
    int start,end;
    cout<<"Enter the range of numbers in which random numbers are to be generated : ";
    cin>>start>>end;
    vector<float> arr;
    cout<<"Random numbers generated : ";
    for(int i=0;i<100;i++){
        int x = (rand() % (end-start+1))+start;
        cout<<x<<' ';
        arr.push_back(x);
    }
    cout<<endl;
    vector<float> v1,v2,v3,v4;

    v1.push_back(s1);
    v2.push_back(s2);
    v3.push_back(s3);
    v4.push_back(s4);

    for(int i=0;i<50;i++){
        vector<float> a1,a2,a3,a4;
        a1.clear();
        a2.clear();
        a3.clear();
        a4.clear();

        a1.push_back(v1[i]);
        a2.push_back(v2[i]);
        a3.push_back(v3[i]);
        a4.push_back(v4[i]);

        int minimum = INT_MAX;
        int index = -1;

        for(int j=0;j<100;j++){
            if(abs(arr[j] - a1[0]) < minimum){
                index = 1;
                minimum = abs(arr[j] - a1[0]);
            }
            if(abs(arr[j] - a2[0]) < minimum){
                index = 2;
                minimum = abs(arr[j] - a2[0]);
            }
            if(abs(arr[j] - a3[0]) < minimum){
                index = 3;
                minimum = abs(arr[j] - a3[0]);
            }
            if(abs(arr[j] - a4[0]) < minimum){
                index = 4;
                minimum = abs(arr[j] - a4[0]);
            }
            if(index == 1){
                a1.push_back(arr[j]);
                a1[0] = mean(a1);
            }
            if(index == 2){
                a2.push_back(arr[j]);
                a2[0] = mean(a2);
            }
            if(index == 3){
                a3.push_back(arr[j]);
                a3[0] = mean(a3);
            }
            if(index == 4){
                a4.push_back(arr[j]);
                a4[0] = mean(a4);
            }
        }
        v1.push_back(a1[0]);
        v2.push_back(a2[0]);
        v3.push_back(a3[0]);
        v4.push_back(a4[0]);
    }
    int count=0;
    cout<<"V1 : ";
    for(int i=0;i<v1.size();i++){
        count++;
        cout<<v1[i]<<" ";
        if(count==20){
            cout<<endl;
            count=0;
        }
    }
    cout<<endl;
    count=0;
    cout<<"V2 : ";
    for(int i=0;i<v2.size();i++){
        cout<<v2[i]<<" ";
        if(count==20){
            cout<<endl;
            count=0;
        }
    }
    cout<<endl;
    count=0;
    cout<<"V3 : ";
    for(int i=0;i<v3.size();i++){
        cout<<v3[i]<<" ";
        if(count==20){
            cout<<endl;
            count=0;
        }
    }
    cout<<endl;
    count=0;
    cout<<"V4 : ";
    for(int i=0;i<v4.size();i++){
        cout<<v4[i]<<" ";
        if(count==20){
            cout<<endl;
            count=0;
        }
    }
    cout<<endl;
    return 0;
}
