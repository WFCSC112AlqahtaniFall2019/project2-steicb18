#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;

// function declarations
void mergeSort(vector<int>& a, vector<int>& tmp, int left, int right);
void mergeSortedLists(vector<int>& a, vector<int>& tmp, int left, int middle, int right);

int main() {
    vector<int> test = {3,1,6,4,2,5,7};
    vector<int> testT(7);
    vector<int> expect = {1,2,3,4,5,6,7};

    /*test.at(0) = 3;
    test.at(1) = 1;
    test.at(2) = 6;
    test.at(3) = 4;
    test.at(4) = 2;
    test.at(5) = 5;
    test.at(6) = 7;

    expect.at(0) = 1;
    expect.at(1) = 2;
    expect.at(2) = 3;
    expect.at(3) = 4;
    expect.at(4) = 5;
    expect.at(5) = 6;
    expect.at(6) = 7;*/

    cout<< "Testing started" <<endl;

    cout<< "Expecting : 1   2   3   4   5   6   7, got:   ";
    mergeSort(test, testT, 0, test.size()-1);
    for (int i = 0; i < test.size(); i++)
    {
        cout << test.at(i) <<"   ";
    }
    cout << endl<<"Testing Complete."<<endl;


    // get input: first is random seed, second is vector length
   int seed, length;
    cout<<"Please input seed and length: "<<endl;
    cin >> seed >> length;
    srand(seed);

    vector<int> v(length);  // vector to be sorted
    vector<int> t(length);  // temporary workspace
    vector<int> x(length);


    // initialize and print input
    for (int i = 0; i < v.size(); i++) {
        v.at(i) = rand() % 100;
        cout << v.at(i) << '\t';
    }
    cout << endl;

    // sort v
    mergeSort(v, t, 0, v.size()-1);

    // print output
    for (int i = 0; i < v.size(); i++) {
        cout << v.at(i) << '\t';
    }
    cout << endl;

    // check output, make sure it's sorted
    for (int i = 1; i < v.size(); i++) {
        assert(v.at(i - 1) <= v.at(i));
    }

    return 0;
}
void mergeSort(vector<int>& a, vector<int>& tmp, int left, int right){

    if (right - left + 1 == 1){
        return;
    }
    else{
        int middle = (left + right)/2;
        mergeSort(a, tmp, left, middle);
        mergeSort(a, tmp, middle+1, right);
        mergeSortedLists(a, tmp, left, middle, right);
    }

}
void mergeSortedLists(vector<int>& a, vector<int>& tmp, int left, int middle, int right){
    int j = middle+1;
    int i = left;
    int k = left;
    while (i <= middle && j <= right){
        if(a.at(i) <= a.at(j)){
            tmp.at(k) = a.at(i);
            k++;
            i++;
        }
        else{
            tmp.at(k) = a.at(j);
            k++;
            j++;

        }

    }
    while(i <= middle){
        tmp.at(k) = a.at(i);
        i++;
        k++;

    }
    while(j <= right){
        tmp.at(k) = a.at(j);
        j++;
        k++;
    }

    for (int h = left; h <= right; h++){
        a.at(h) = tmp.at(h);
    }
}
