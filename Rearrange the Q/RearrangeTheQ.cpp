////////////////////////////////////////////////////////////////////////
// MELCHOR FILIPPE S. BULANON
////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <utility>
#include <vector>
#include <queue>

using namespace std;


int findFirstInLine(vector<pair<int,int>> arr);
pair<int,int> findPair(int searchFor, vector<pair<int,int>> arr);
queue<int> rearrange(vector<pair<int,int>> arr);


int main() {
    // int n; cin >> n;
    // int x, y;
    // pair<int,int> tempPair;
    vector<pair<int,int>> arr = {{92,7}, {0,92}, {31,141}, {7,31}};
    queue<int> results;
    // while(n--) {
    //     cin >> x >> y;
    //     tempPair = {x,y};
    //     arr.push_back(tempPair);
    // }

    results = rearrange(arr);

    while(!results.empty()) {
        cout << results.front() << ' ';
        results.pop();
    }



    return 0;
}




queue<int> rearrange(vector<pair<int,int>> arr) {
    queue<int> result; 
    pair<int,int> currentPair;
    int searchFor = findFirstInLine(arr);
    result.push(searchFor);


    while(currentPair.first != -1 && currentPair.second != -1) {
        result.push(findPair(searchFor, arr).second);
        searchFor = findPair(searchFor, arr).second;
        currentPair = findPair(searchFor, arr);
        cout << currentPair.second << endl;
    }

    return result;
}

int findFirstInLine(vector<pair<int,int>> arr) {
    for(pair<int,int> x : arr) {
        if (x.first == 0) {
            return x.second;
        }
    }
    return -1;
}

pair<int,int> findPair(int searchFor, vector<pair<int,int>> arr) {
    for (pair<int,int> x : arr) {
        if(x.first == searchFor) {
            return x;
        }
    }
    pair<int,int> notFound(-1,-1);
    return notFound;
}


