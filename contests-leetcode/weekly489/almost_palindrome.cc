#include<iostream>
#include<string>
#include<vector>

using namespace std;

int longest_lengh(string &s){
    int n = s.size();
    if(n <= 1) return 0;
    int ans = 0;

    auto expand = [&](int l, int r) {
        // Expand while perfectly matching
        while(l >= 0 && r < n && s[l] == s[r]) {
            l--; r++;
        }
        
        // Pure palindrome found: s[l+1...r-1].
        int pureLen = r - l - 1;
        if(pureLen > 0) ans = max(ans, pureLen);
        
        // Mismatch at (l, r).
        // Branch 1: Skip s[l]. Compare s[l-1] vs s[r].
        if (l >= 0) {
            int l1 = l - 1, r1 = r;
            while(l1 >= 0 && r1 < n && s[l1] == s[r1]) {
                l1--; r1++;
            }
            ans = max(ans, r1 - l1 - 1);
        }

        // Branch 2: Skip s[r]. Compare s[l] vs s[r+1].
        if (r < n) {
            int l2 = l, r2 = r + 1; 
            while(l2 >= 0 && r2 < n && s[l2] == s[r2]) {
                l2--; r2++;
            }
            ans = max(ans, r2 - l2 - 1);
        }
    };

    for(int i = 0; i < n; i++) {
        expand(i, i);      // Odd length centers
        expand(i, i + 1);  // Even length centers
    }
    return ans;
}

int main(){
    string s1 = "abca";
    cout << longest_lengh(s1) << endl;

    string s2 = "abba";
    cout << longest_lengh(s2) << endl;

    string s3 = "zzabba";
    cout << longest_lengh(s3) << endl;

    string s4 = "ab";
    cout << "ab -> " << longest_lengh(s4) << endl;

    string s5 = "aaaa";
    cout << "aaaa -> " << longest_lengh(s5) << endl;

    string s6 = "abcdef";
    cout << "abcdef -> " << longest_lengh(s6) << endl;

    string s7 = "xabba";
    cout << "xabba -> " << longest_lengh(s7) << endl;

    string s8 = "xxabcbayx";
    cout << "xxabcbayx -> " << longest_lengh(s8) << endl;

    string s9 = "aa";
    cout << "aa -> " << longest_lengh(s9) << endl;

    string s10 = "racecar";
    cout << "racecar -> " << longest_lengh(s10) << endl;

    return 0;
}