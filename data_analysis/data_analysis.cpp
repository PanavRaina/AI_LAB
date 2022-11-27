#include <bits/stdc++.h>
using namespace std;

vector<float> movingAverage(vector<int>v)
{
    vector<float> m_average;
    float beta = 0.9;
    float val = 0;
    m_average.push_back(val);
    for(int i =0; i<v.size(); i++)
    {
        val = (beta * v[i]) + (1-beta)*val;
        m_average.push_back(val);
    }
    return m_average;
}

int main()
{
    vector<int> data = {0 ,2 ,1 ,22 ,2 ,1 ,3 ,5 ,9 ,15,8,10,10 ,11 ,10 ,14 ,20 ,25 ,27 ,58 ,78 ,
                69 ,94 ,74 ,86 ,73,153 ,136 ,120 ,187 ,309 ,424 ,486 ,560 ,579 ,609,484,         
                573,565 ,813 ,871 ,854 ,758 ,1243 ,1031 ,886 ,1061 ,922,1371 ,1580,1239,
                1537 ,1292 ,1667 ,1408 ,1835 ,1607 ,1568 ,1902 ,1705,1801,2391};
    float mean=0;
    for(int i=0;i<data.size();i++)
    {
        mean+=data[i];
    }
    mean=mean/data.size();
    cout<<"MEAN : "<<mean<<endl;
    float variance=0;
    for(int i=0;i<data.size();i++)
    {
        float xi;
        xi = (data[i]-mean)*(data[i]-mean);
        variance += xi;
    }
    variance=variance/(data.size()-1);
    cout<<"VARIANCE : "<<variance<<endl;
    cout<<"STANDARD DEVIATION : "<<sqrt(variance)<<endl;

    vector<int> gradient;
    for(int i=0;i<data.size();i++)
    {
        if(i+1<data.size())
        {
            int g = data[i+1]-data[i];
            gradient.push_back(g);
        }
    }
    cout<<"GRADIENT : ";
    for(int i=0;i<gradient.size();i++)
    {
        cout<<gradient[i]<<' ';
    }
    vector<int> laplacian;
    for(int i=0;i<gradient.size();i++)
    {
        if(i+1<gradient.size())
        {
            int g = gradient[i+1]-gradient[i];
            laplacian.push_back(g);
        }
    }
    cout<<endl;
    cout<<"LAPLACIAN : ";
    for(int i=0;i<laplacian.size();i++)
    {
        cout<<laplacian[i]<<' ';
    }
    cout<<endl;
    vector<int> s_filter = {5,-6,1,6,-5};
    vector<int> smooth_data;
    for(int i=0;i<data.size();i++)
    {
        if(i==0)
        {
            int num=0;
            int index=0;
            for(int j=2;j<s_filter.size();j++)
            {
                num=num+(s_filter[j]*data[index]);
                index++;
            }
            smooth_data.push_back(num);
        }
        else if(i==1)
        {
            int num=0;
            int index=0;
            for(int j=1;j<s_filter.size();j++)
            {
                num=num+(s_filter[j]*data[index]);
                index++;
            }
            smooth_data.push_back(num);
        }
        else if(i==data.size()-2)
        {
            int num=0;
            int index=data.size()-4;
            for(int j=0;j<s_filter.size()-1;j++)
            {
                num=num+(s_filter[j]*data[index]);
                index++;
            }
            smooth_data.push_back(num);
        }
        else if(i==data.size()-1)
        {
            int num=0;
            int index=data.size()-3;
            for(int j=0;j<s_filter.size()-2;j++)
            {
                num=num+(s_filter[j]*data[index]);
                index++;
            }
            smooth_data.push_back(num);
        }
        else 
        {
            int num=0;
            int index=i-2;
            for(int j=0;j<s_filter.size();j++)
            {
                num=num+(s_filter[j]*data[index]);
                index++;
            }
            smooth_data.push_back(num);
        }
    }
    cout<<"DATA AFTER APPLYING SMOOTHING FILTER OF SIZE 5 : ";
    for(int i=0;i<smooth_data.size();i++)
    {
        cout<<smooth_data[i]<<' ';
    }
    cout<<endl;

    cout<<"Moving average for the given data : ";
    vector<float> movavg;
    movavg=movingAverage(data);
    for(int i=0;i<movavg.size();i++)
    {
        cout<<movavg[i]<<' ';
    }
    return 0;
}
