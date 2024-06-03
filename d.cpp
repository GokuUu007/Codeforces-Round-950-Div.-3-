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
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &x : a)
        cin >> x;


    vector<int> gv;
    for (int i = 0; i + 1 < n; ++i)
        gv.push_back(__gcd(a[i], a[i + 1]));

    const int m = int(gv.size());

    vector<int> suff(m);

    for (int i = m - 1; i >= 0; --i) {
        if (i + 1 < m && gv[i] <= gv[i + 1])
            suff[i] = suff[i + 1];
        else
            suff[i] = i;
    }


    vector<int> pref(m);
    for (int i = 0; i < m; ++i) {
        if (i > 0 && gv[i] >= gv[i - 1]) {
            pref[i] = pref[i - 1];
        } else {
            pref[i] = i;
        }
    }

    if (is_sorted(begin(gv) + 1, gv.end()) || is_sorted(begin(gv), gv.end() - 1)) {
        cout << "YES\n";
        return;
    }

    for (int i = 1; i + 1 < n; ++i) {   
        int new_val = __gcd(a[i - 1], a[i + 1]);
        if (i > 1 && i + 1 < m) {
            if (pref[i - 2] == 0 && suff[i + 1] == m - 1) {
                if (new_val >= gv[i - 2] && new_val <= gv[i + 1]) {
                    cout <<"YES\n";
                    return;
                }
            } 
        } else if (i > 1) {
            if (pref[i - 2] == 0) {
                if (new_val >= gv[i - 2]) {
                    cout << "YES\n";
                    return;
                }
            }
        } else if (i + 1 < m) {
            if (suff[i + 1] == m - 1) {
                if (new_val <= gv[i + 1]) {
                    cout << "YES\n";
                    return;
                }
            }
        }
    }


    cout << "NO\n";
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
