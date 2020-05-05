// To multiply big integers : leetcode : string multiplication
// dicuss solution : one digit at a time: by stefan
// Uses vedic multiplication technique
#include <bits/stdc++.h>
using namespace std;

string multiply(string a, string b) {
    if (a=="0" || b=="0")   return "0";
    int m = a.size() - 1, n = b.size() - 1, carry = 0;

    string product;
    for (int i=0; i<=m+n || carry; ++i) {
        for (int j=max(0, i-n); j<=min(i, m); ++j)
            carry += (a[m-j] - '0') * (b[n-i+j] - '0');
        product += carry % 10 + '0';
        carry /= 10;
    }

    reverse(begin(product), end(product));
    return product;
}

// Driver function
int main(){
    string num1 = "12345345457623535645345";
    string num2 = "4564645634536453524";

    cout << multiply(num1, num2) << endl;
    return 0;
}
