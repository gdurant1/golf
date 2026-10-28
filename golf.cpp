#include <iostream>
#include <vector>
#include <array>
#include <cstdlib>
#include <fstream>
#include <algorithm>

using namespace std;


//This function will sort the given vector from vec[start] to vec[end], LEAST TO GREATEST
//You must do it recursively, and can only write code in this section (between the BEGIN and END)
void mergesort(vector<unsigned int> &vec,int start, int end) {
    //All semicolons and curly braces between here and the end count as a stroke against you
    //BEGIN GOLF
    //find mid
    if (end - start > 1) {
        int m = (start + end)/2;
        int i = start, j = m;
        vector<unsigned int> t;
        mergesort(vec, start, m),mergesort(vec, m, end);
        //merg into temp

        while (i < m && j < end) {
            if (vec[i] < vec[j]) {t.push_back(vec[i]); i++;}
            else {t.push_back(vec[j]); j++;}

        }

        while (i < m) {t.push_back(vec[i]); i++;}
        while (j < end) {t.push_back(vec[j]); j++;}

        for (int k = 0; k< t.size(); k++) {vec[start+k]=t[k];}
    }
    //END GOLF
}


int main() {
    vector<unsigned int> vec;
    cout << "Please insert natural numbers to sort (0 to end): ";
    while (cin) {
        unsigned int temp;
        cin >> temp;
        if (!cin) break;
        if (temp == 0) break;
        vec.push_back(temp);
    }
    if (vec.size() > 0)
        mergesort(vec,0,vec.size()-1);
    for (unsigned int i : vec) cout << i << " ";
    cout << endl;
    system("/public/mergesort_golf/score"); //Hope Kerney left this installed...
}