#include <iostream>
#include <vector>

using namespace std;
string bin(int z,int n) {
    string x = "";
    while (z) {
        x += (z % 2) + '0';
        z /= 2;
    }
    while (x.size()<n)x += '0';
    return x;
}
vector<int> gray_code(int n) {
    vector<int> gray_codes;
    gray_codes.push_back(0);
    for (int i = 0; i < n; i++) {
        int size = gray_codes.size();
        for (int j = size - 1; j >= 0; j--) {
            gray_codes.push_back(gray_codes[j] | (1 << i));
        }
    }
    return gray_codes;
}

int main() {
    int n = 4;
    cin>>n;
    vector<int> codes = gray_code(n);
    for (int code : codes) {
        cout << bin(code,n) << " ";
    }
    cout << endl;
    return 0;
}