// 165. Compare Version Numbers
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int compareVersion(string v1, string v2) {
        int ans = 0;
        int n1 = v1.size(), n2 = v2.size();

        for(int i=0,j=0; i < n1 || j < n2; ++i,++j){
            string str1="", str2="";

            while(i < n1 && v1[i] != '.'){
                if(str1.size()==0 && v1[i] == '0'){
                    i++;
                    continue;
                }

                str1 += v1[i++];
            }

            while(j < n2 && v2[j] != '.'){
                if(str2.size()==0 && v2[j] == '0'){
                    j++;
                    continue;
                }

                str2 += v2[j++];
            }

            if(str1.size() < str2.size())   return -1;
            else if(str1.size() > str2.size())  return 1;

            ans = str1.compare(str2);
            if(ans < 0) return -1;
            else if(ans > 0)    return 1;
        }

        return 0;
    }
};

// Driver function
int main(){
    // string version1 = "0.1";
    // string version2 = "1.1";

    // string version1 = "0.1";
    // string version2 = "0.0.1";

    string version1 = "1";
    string version2 = "1.1";

    Solution s;
    cout << s.compareVersion(version1, version2) << endl;

    return 0;
}
