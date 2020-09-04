#include<bits/stdc++.h>

using namespace std;

//Define the structs Workshops and Available_Workshops.
//Implement the functions initialize and CalculateMaxWorkshops
struct Workshop{
    int start_time, duration, end_time;
};
struct Available_Workshops{
    int n;
    Workshop *shops;
    Available_Workshops(int num){
        n = num;
        Workshop* workshopArray = new Workshop[num];
        shops = workshopArray;

    }
};

bool comp(const Workshop &a, const Workshop &b){
    return a.end_time < b.end_time;
}
Available_Workshops* initialize(int start_time[], int duration[], int n){
        Available_Workshops* wrks = new Available_Workshops(n);
        for (int i=0; i<n;i++){
            wrks->shops[i].start_time = start_time[i];
            wrks->shops[i].duration = duration[i];
            wrks->shops[i].end_time = start_time[i] + duration[i];
        }
        return wrks;
    }

int CalculateMaxWorkshops(Available_Workshops* ptr){
    sort(ptr->shops, ptr->shops+ptr->n, comp);
    int m = 1,t;
    //int end_time = ptr.a[0].end_time;
    for (int i=0; i<ptr->n; i++){
        if (i==0){
            t = ptr->shops[i].end_time;
            continue;
        }
        if (ptr->shops[i].start_time >=t){
            m++;
            t= (ptr->shops[i].end_time);
        }
    }
    return m;
}

int main(int argc, char *argv[]) {
    int n; // number of workshops
    cin >> n;
    // create arrays of unknown size n
    int* start_time = new int[n];
    int* duration = new int[n];

    for(int i=0; i < n; i++){
        cin >> start_time[i];
    }
    for(int i = 0; i < n; i++){
        cin >> duration[i];
    }

    Available_Workshops * ptr;
    ptr = initialize(start_time,duration, n);
    cout << CalculateMaxWorkshops(ptr) << endl;
    return 0;
}
