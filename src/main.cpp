#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <Eigen/Dense>
using namespace std;
using Eigen::MatrixXd;

// camelCase: functions and variables
// PascalCase: class

class ShiftedPositivePMIEmbedding{
    public:
        void createDic(string filepath){
            ifstream ifs(filepath);
            int wordId = 0;
            string sentence;
            string word;
            while (getline(ifs, sentence)) {
                istringstream iss(sentence);
                while (iss >> word) {
                    if (word2id.count(word) == 0) {
                        word2id.insert(make_pair(word, wordId));
                        id2word.insert(make_pair(wordId, word));
                        wordId++;
                    }
                }
            }
        }
        void printDic(){
            cout << "- print word2id" << endl;
            for (map<string, int>::iterator i=word2id.begin(); i!=word2id.end(); ++i) {
                cout << i->first << " => " << i->second << endl;
            }
            cout << "- print id2word" << endl;
            for (map<int, string>::iterator i=id2word.begin(); i!=id2word.end(); ++i) {
                cout << i->first << " => " << i->second << endl;
            }
        }
    private:
        map<string, int>word2id;
        map<int, string>id2word;
};

int main(){
    // test Eigen
    cout << "1. test Eigen" << endl;
    MatrixXd m(2,2);
    m(0,0) = 3;
    m(1,0) = 2.5;
    m(0,1) = -1;
    m(1,1) = m(1,0) + m(0,1);
    cout << m << endl;

    // test readfile
    cout << "2. test readfile" << endl;
    // test id2word, word2id
    cout << "3. test id2word, word2id" << endl;
    string filePath = "./../test/input.txt";
    ShiftedPositivePMIEmbedding sppmiEmb;
    sppmiEmb.createDic(filePath);
    sppmiEmb.printDic();

    return 0;
}

