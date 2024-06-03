/* 

    ॐ हौं जूं सः ॐ भूर्भुवः स्वः 
    ॐ त्र्यम्बकं यजामहे सुगन्धिं पुष्टिवर्धनम् उर्वारुकमिव बन्धनान्मृत्योर्मुक्षीय मामृतात् 
    ॐ स्वः भुवः भूः ॐ सः जूं हौं ॐ

   @Author  : Akshat Madhavan
   @Country : INDIA 
   
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()

#ifdef AKSHAT
#include "debug.h"
#define deb(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define deb(x...)
#endif


template<class T>void output (vector<T> &a) {for (auto &x : a) {cout << x << ' ';}cout << '\n';}
template<typename T> void chmin (T &a, T b) {if (a > b) swap(a, b);}
template<typename T> void chmax (T &a, T b) {if (a < b) swap(a, b);}



void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m));
    for (auto &row : a)
        for (auto &ele : row)
            cin >> ele, --ele;

    vector<vector<int>> b(n, vector<int>(m));
    for (auto &row : b)
        for (auto &ele : row)
            cin >> ele, --ele;


    /*
        let's find the og col and og row
    */

    vector<int> a_row_min(n, n * m), a_col_min(m, n * m);
    vector<int> b_row_min(n, n * m), b_col_min(m, n * m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            a_row_min[i] = min(a_row_min[i], a[i][j]);
            a_col_min[j] = min(a_col_min[j], a[i][j]);
            b_row_min[i] = min(b_row_min[i], b[i][j]);
            b_col_min[j] = min(b_col_min[j], b[i][j]);      
        }
    }

    vector<int> row_index(n * m);
    for (int i = 0; i < n; ++i) {
        row_index[a_row_min[i]] = i;
    }

    vector<int> col_index(n * m);
    for (int i = 0; i < m; ++i) {
        col_index[a_col_min[i]] = i;
    }

    vector<vector<int>> new_a(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        // deb(b_row_min[i]);
        vector<int> cur = a[row_index[b_row_min[i]]];
        for (int j = 0; j < m; ++j) {
            new_a[i][j] = cur[col_index[b_col_min[j]]];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            // cout<<new_a[i][j]+1<<" \n"[j==m-1];
            if (new_a[i][j] != b[i][j]) {
                cout << "NO\n";
                return;
            }
        }
    }

    cout << "YES\n";
} 


int32_t main() {
    
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    #ifdef AKSHAT   
        freopen("error.txt", "w", stderr);  
    #endif  

    int tc = 1;
    cin >> tc;
    for (int cases = 1; cases <= tc; ++cases) {
        solve();
        // cout << (solve() ? "YES\n" : "NO\n");
        // cout << "Case # " << cases;
    } 

    #ifdef AKSHAT
        double timeTaken = 1000.0 * clock() / CLOCKS_PER_SEC;
        cout << "\n[Finished in " << timeTaken << "ms]";
        cerr << "\n[Finished in " << timeTaken << "ms]";
    #endif

    return 0;
}

//JAI SHREE RAM !!!!
