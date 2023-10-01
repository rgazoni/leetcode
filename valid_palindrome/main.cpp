#include <cctype>
#include <string>
#include <iostream>
using namespace std;

//Both implementations ae fine
//Both ooperate in O(n) time
//The first implementation uses O(n) space
//The second implementation uses O(1) space
//The second implementation is faster than the first implementation
//Challenge uses the principle of two pointers

/*
class Solution {
public:
    bool isPalindrome(string s) {
        string str;
        if (s.empty()) return true;
        for (int i = 0; i < s.length(); i++) {
            if (isalnum(s[i])) {
                str += s[i];
            }
        }
        int len = str.length();
        for (int i = 0; i < len / 2; i++) {
            if (tolower(str[i]) != tolower(str[len - i - 1])) {
                return false;
            }
        }
        return true;
    }
};
*/

class Solution {
public:
    bool isPalindrome(string s) {

        int right = s.length();
        int left = 0;

        if (s.empty()) return true;

        while (left < right) {
            
            if (!isalnum(s[left])){
                left++;
                continue;
            }
            if (!isalnum(s[right])){
                right--;
                continue;
            }
            if ( tolower(s[left]) != tolower(s[right]) ) {
                return false;
            } else {
                left++;
                right--;
            }
        }
        return true;
    }
};
 
int main() {

    Solution s = Solution();

    cout << s.isPalindrome("A man, a plan, a canal: Panama") << endl;

    return 0;
}
