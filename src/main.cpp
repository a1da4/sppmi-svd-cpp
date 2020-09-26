#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
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

    // test id2word, word2id
    cout << "test id2word, word2id" << endl;
    map<string, int>word2id;
    map<int, string>id2word;
    int id = 0;
    string sentence;
    string word;
    while (getline(ifs, sentence)) {
        istringstream iss(sentence);
        while (iss >> word) {
            //cout << word << endl;
            if (word2id.count(word) == 0) {
                word2id.insert(make_pair(word, id));
                id2word.insert(make_pair(id, word));
                id++;
            }
        }
    }
    cout << "print word2id" << endl;
    for (map<string, int>::iterator i=word2id.begin(); i!=word2id.end(); ++i) {
        cout << i->first << " => " << i->second << endl;
    }
    cout << "print id2word" << endl;
    for (map<int, string>::iterator i=id2word.begin(); i!=id2word.end(); ++i) {
        cout << i->first << " => " << i->second << endl;
    }

    return 0;
}

