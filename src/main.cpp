#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <Eigen/Dense>
using namespace std;
using Eigen::MatrixXd;

int main(){
    // test Eigen
    cout << "test Eigen" << endl;
    MatrixXd m(2,2);
    m(0,0) = 3;
    m(1,0) = 2.5;
    m(0,1) = -1;
    m(1,1) = m(1,0) + m(0,1);
    cout << m << endl;

    // test readfile
    cout << "test readfile" << endl;
    ifstream ifs("./../test/input.txt");
    string sentence;
    string word;
    while (getline(ifs, sentence)) {
        istringstream iss(sentence);
        while (iss >> word) {
            cout << word << endl;
        }
    }
}


