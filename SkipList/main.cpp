#include <bits/stdc++.h>
#include "SkipList.h"
using namespace std;
#define ll long long

vector<int> RandomizeNumbers(int len, int low, int high) {
    vector<int> ans;
    for (int i = 0; i < len; i++) {
        ans.push_back(low + (std::rand() % (high - low + 1)));
    }
    return ans;
}
//////////////////////////// Testing |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
template <typename T>
void TestInsert(SkipList<T>& s,vector<T>& nums) {
    cout << "Elements to be inserted: ";
    for (auto num : nums) {
        cout << num << " ";
    }
    cout << endl;
    for (auto num : nums) {
        s.insert(num);
    }
    cout << "Skip List Elements: \n";
    s.print();
}
template <typename T>
void TestDelete(SkipList<T>& s , vector<T>& nums) {
    cout << "Elements to be Deleted: ";
    for (auto num : nums) {
        cout << num << " ";
    }
    cout << endl;
    for (auto num : nums) {
        s.remove(num);
        s.print();
        cout << "===================================================================\n";
    }
}

pair<int, int> RandomRange() {
    int a = std::rand() % 2000;
    int b = a + std::rand() % 3000;
    return { min(a, b), max(a, b) };

}
int RandomLength() {
    return std::rand() % 20;
}

int main() {

    int tests = 3, len ;
    pair<int, int> range;
    while (tests--) {
        cout << "---------------------------------------------------\n";
        len = RandomLength();
        range = RandomRange();

        cout << "Length: " << len << endl;
        cout << "Range of elements: " << range.first << " " << range.second << endl;
        SkipList<int> s;
        vector<int> num = RandomizeNumbers(len, range.first, range.second);
        TestInsert(s , num);
        cout << "---------------------------------------------------\n";
        TestDelete(s , num);

    }

    return 0;
}
