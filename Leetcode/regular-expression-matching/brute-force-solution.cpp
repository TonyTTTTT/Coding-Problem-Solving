#include <iostream>
#include <string>
#include <vector>
using namespace std;

// struct pattern {
//     bool 
// }

class Solution {
public:
    bool isMatch(string s, string p) {
        int idx = 0;
        string substring = "";
        vector<string> splitted;
        bool star_occur, star_first = false;

        if (p[1] == '*') {
            star_first = true;
        }

        while (idx < p.size()) {
            star_occur = false;
            while(true) {
                if (idx == p.size()) {
                    break;
                }
                if (p[idx+1] == '*') {
                    star_occur = true;
                    break;
                }
                substring.push_back(p[idx]);
                idx++;
            }
            if (star_occur) {
                string tmp = "*";
                tmp.push_back(p[idx]);
                splitted.push_back(tmp);
                idx += 2;
            }
            if (substring != "") {
                splitted.push_back(substring);
            }
            substring = "";
        }

        idx = 0;
        int splitted_idx = 0;

        while (idx < s.size()) {
            if (splitted_idx >= splitted.size()) {
                return false;
            }

            if (splitted[splitted_idx][0] == '*') {
                int offset = 1;
                while (splitted[splitted_idx + offset][0] == '*') {
                    offset++;
                }

            } else {
                if (s.substr(idx, splitted[splitted_idx].size()) == splitted[splitted_idx]) {
                    idx += splitted[splitted_idx].size();
                    splitted_idx++;
                } else {
                    // not match the hard limit experssion => false
                    return false;
                }
            }
        }

        // if (not star_first) {
        //     if (s.substr(idx, substrings[substrings_idx].size()) != substrings[substrings_idx]) {
        //         return false;
        //     }
        //     idx += substrings[substrings_idx].size();
        //     substrings_idx++;
        // }

        // while (idx < s.size()) {
        //     if (substrings_idx >= substrings.size() and stars_idx >= stars.size()) {
        //         return false;
        //     }
        //     if (substrings_idx < substrings.size() and s.substr(idx, substrings[substrings_idx].size()) == substrings[substrings_idx]) {
        //         idx += substrings[substrings_idx].size();
        //         substrings_idx++;
        //         stars_idx++;
        //     } else if (stars_idx < stars.size()) {
        //         if (stars[stars_idx] == '.' or s[idx] == stars[stars_idx]) {
        //             idx++;
        //         } else if (s[idx] != stars[stars_idx]) {
        //             return false;
        //         }
        //     } else {
        //         // stars_idx >= stars.size() and substrings_idx < substrings.size() and s.substr(idx, substrings[substrings_idx].size()) != substrings[substrings_idx]
        //         // i.e. only substring left but didn't match
        //         return false;
        //     }
        // }

        // // for (stars_idx; stars_idx<stars.size(); stars_idx++) {
        // //     while (s.substr(idx, substrings[substrings_idx].size()) != substrings[substrings_idx]) {
        // //         if (s[idx] != stars[stars_idx]) {
        // //             return false;
        // //         }
        // //         idx++;
        // //     }
        // //     idx += substrings[substrings_idx].size();
        // //     substrings_idx++;
        // //     if (substrings_idx >= substrings.size() or idx >= s.size()) {
        // //         break;
        // //     }
        // // }

        // if (idx < s.size()) {
        //     return false;
        // }

        return true;
    }
};

int main() {
    Solution solution;
    string case1 = "c*ab..acd*ezgf*kkl.*oty*xtex.*";
    string case2 = "a*abz*cdz";
    bool ans = solution.isMatch("aab", "c*a*b");
    if (ans) {
        cout<<"match"<<endl;
    } else {
        cout<<"not match"<<endl;
    }

    return 0;
}