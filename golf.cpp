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
        int mid = start + (end - start)/2;
        int i = start, j = mid;
        vector<unsigned int> temp;
        mergesort(vec, start, mid);
        mergesort(vec, mid, end);
        //merg into temp

        while (i < mid && j < end) {
            if (vec[i] < vec[j]) {temp.push_back(vec[i]); i++;}
            else {temp.push_back(vec[j]); j++;}

        }

        while (i < mid) {temp.push_back(vec[i]); i++;}
        while (j < end) {temp.push_back(vec[j]); j++;}

        for (int k = 0; k< temp.size(); k++) {vec[start+k]=temp[k];}
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