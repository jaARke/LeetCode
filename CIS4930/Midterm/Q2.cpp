#include <bits/stdc++.h>

using namespace std;

/*
- R red arms B blue arms
- can only change to a form with more blue arms than current
- if we have R red arms, it can change to a form [r - b, r + b]

D has one form for every number of red arms b/w 1 and N

- these forms have an associated blue arms with it

- how many times can D change forms before running out of possibliltes


- n is max red arms
- w is the max difference

- n lines each contain blue arms of each form
    - b(i) indicates that form with i red arms has b(i) blue arms


 - print the max possible form changes

 ex: 5 max red arms 5 max difference ()

 blue arms: 5 3 2 1 4   

 so form 1 is 5 blue arms ...


 sort by blue arms 

 (4 1) (3 2) (2 3) (5 4) (1 5)

 start with first, I can change to something with ([r - w, r + w])

*/
int main() {

    int n, w; cin >> n >> w;

    vector<pair<int, int>> f(n);

    for (int i = 0; i < n; i++) {
        
        cin >> f[i].first;
        f[i].second = i + 1;
    }


    sort(begin(f), end(f));

    vector<int> dp(n);
    int m = 0;
    for (int i = 0; i < n; i++) {
        dp[i] = 0;
        int left = f[i].second - w;
        int right = f[i].second + w;
        for (int j = 0; j < i; j++) {
            if (f[j].first < f[i].first && f[j].second <= f[i].second + w && f[j].second >= f[i].second - w) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }

        m = max(m , dp[i]);
    }

    cout << m;
    return 0;
}