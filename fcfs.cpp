#include<bits/stdc++.h>
using namespace std;
int bt[1000],wt[1000],tt[1000],n,t_tt,t_wt;
double avg_wt,avg_tt;
int main() {
    cout<<endl<<"Enter the number of Process = ";
    cin>>n;
    cout<<"Enter the Burst Time : ";
    for(int i = 0; i < n; i++)
    cin>>bt[i];
    wt[0] = 0;
    //Waiting time 
    for(int i = 1; i < n; i++) {
        wt[i] = wt[i-1] + bt[i-1];
    }
    //turnAround Time
    for(int i = 0; i < n; i++) {
        tt[i] = wt[i] + bt[i];
    }
    //calculating averages
    t_wt = accumulate(wt,wt+n,0);
    t_tt = accumulate(tt,tt+n,0);
    avg_wt = (double) t_wt/n;
    avg_tt = (double) t_tt/n;

    cout<<endl<<"Process  "<<"Burst Time  "<<"Waiting Time  "<<"TurnAround Time"<<endl;
    for(int i = 0; i < n; i++) {
        cout<<"  P"<<i+1<<"          "<<bt[i]<<"          "<<wt[i]<<"              "<<tt[i]<<endl;
    }
    cout<<endl<<"Average Waiting Time = "<<avg_wt<<endl;
    cout<<"Average TrunAround Time = "<<avg_tt<<endl<<endl; 
    //Grant Chart
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < bt[i]*5; j++) {
            if(j == bt[i] * 5 - 1) 
            cout<<"|";
            else 
            cout<<"-";
        }
    }
    cout<<endl;
    for(int i = 0; i < n; i++) {
        for(int j = 1; j < (bt[i]*5)/2-2; j++)
        cout<<" ";
        cout<<"P"<<i+1<<":";
        if(bt[i] <= 9) cout<<0<<bt[i];
        else cout<<bt[i];
        for(int j = 1; j < (bt[i]*5)/2-1; j++)
        cout<<" ";
    }
    cout<<endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < bt[i]*5; j++) {
            if(j == bt[i] * 5 - 1) 
            cout<<"|";
            else 
            cout<<"-";
        }
    }
}