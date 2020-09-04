#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'performOperations' function below.
 *
 * The function is expected to return a LONG_INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER N
 *  2. INTEGER_ARRAY op
 */

void swap(int &a, int &b){
    long temp = b;
    b = a;
    a = temp;
}
template<typename T>
void Print(const vector<T> &a){
    for (auto x: a){
        cout << x << " ";
    }
    cout << endl;
}

vector<long> performOperations(int N, vector<int> op) {
    vector<int> vec;
    vector<long> result;
    vector<int>::iterator it;
    long sum = 0;
    for (int i=1; i<=N; i++){
        vec.push_back(i);
        sum += i;
    }
    int count1 = 0;
    int count2 = 0;
    for (auto x : op){
        it = vec.end()-1;
        if (binary_search(vec.begin()+count1, vec.end()-count2, x)){
            swap(vec[0], *it);
            count1++;
            count2++;
            cout << "Swapping in binary search: "; Print(vec);
        }
        else{
            int flag = 0;
            for (int i = 0; i<count1; i++){
                if (x == vec[i]){
                    swap(vec[0], *it);
                    count1++;
                    count2++;
                    flag = 1;
                    cout << "Swapping in first half else: "; Print(vec);
                }
            }
            for (int i = count2; i<N; i++){
                if (x == vec[i]){
                    swap(vec[0], *it);
                    count1++;
                    count2++;
                    flag = 1;
                    cout << "Swapping in second half else: "; Print(vec);
                }
            }
            if (flag == 0){
                sum -= *it;
                sum += x;
                *it = x;
                count2++;
                cout << "Adding: "; Print(vec);
            }
        }
        if (count1 > count2){
            int flag = 0;
            it = vec.end()-1;
            for(int y: vec){
                if (x == y){
                    swap(vec[0], *it);
                    flag = 1;
                    // cout << "Swapping"; Print(vec);
                }
            }
        if (flag == 0){
            sum -= *it;
            sum += x;
            *it = x;
        }
        }
        result.push_back(sum);

    }





   /* //cout << "Initial: "; Print(vec);
    for (auto x: op){
        int flag = 0;
        it = vec.end()-1;
        for(int y: vec){
            if (x == y){
                swap(vec[0], *it);
                flag = 1;
               // cout << "Swapping"; Print(vec);
            }
        }
        if (flag == 0){
            sum -= *it;
            sum += x;
            *it = x;
        }
        //cout << "Adding: "; Print(vec);
        result.push_back(sum);
    }
    //cout << "Result vector: "; Print(result);
    */
    return result;
}

int main()
{
    int N, M, opp;
    cin >> N >> M;
    vector<int> v;
    for (int i = 0; i<M; i++){
        cin >> opp;
        v.push_back(opp);
    }
    vector<long> result = performOperations(N, v);
    cout << "Result: ";
    for (auto x: result){
        cout << x << endl;
    }
}
