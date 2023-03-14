#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    double avg_wt,avg_tt;
    cout<<endl<<"Enter the number of Process = ";
    cin>>n;
    cout<<endl<<"Enter the Burst Time : ";
    vector<pair<int, int> > bt(n);
    vector<int>wt(n),tt(n);
    for(int i = 0; i < n; i++) {
        cin>>bt[i].first;
        bt[i].second = i+1;
    }
    sort(bt.begin(),bt.end());
    wt[0] = 0;
    tt[0] = bt[0].first;
    //Waiting Time & TurnAround Time
    for(int i = 1; i < n; i++) {
        wt[i] = wt[i-1] + bt[i-1].first;
        tt[i] = wt[i] + bt[i].first;
    }
    //calculating averages
    avg_wt = (double) accumulate(wt.begin(),wt.end(),0)/n;
    avg_tt = (double) accumulate(tt.begin(),tt.end(),0)/n;
    cout<<endl<<"Process  "<<"Burst Time  "<<"Waiting Time  "<<"TurnAround Time"<<endl;
    for(int i = 0; i < n; i++) {
        cout<<"  P"<<bt[i].second<<"          "<<bt[i].first<<"          "<<wt[i]<<"              "<<tt[i]<<endl;
    }
    cout<<endl<<"Average Waiting Time = "<<avg_wt<<endl;
    cout<<"Average TrunAround Time = "<<avg_tt<<endl<<endl; 
    //Grant Chart
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < bt[i].first*5; j++) {
            if(j == bt[i].first * 5 - 1) 
            cout<<"|";
            else 
            cout<<"-";
        }
    }
    cout<<endl;
    for(int i = 0; i < n; i++) {
        for(int j = 1; j < (bt[i].first * 5)/2-2; j++)
        cout<<" ";
        cout<<"P"<<bt[i].second<<":";
        if(bt[i].first <= 9) cout<<0<<bt[i].first;
        else cout<<bt[i].first;
        for(int j = 1; j < (bt[i].first * 5)/2-1; j++)
        cout<<" ";
    }
    cout<<endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < bt[i].first * 5; j++) {
            if(j == bt[i].first * 5 - 1) 
            cout<<"|";
            else 
            cout<<"-";
        }
    }
}