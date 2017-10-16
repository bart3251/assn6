#ifndef DOT_H
#define DOT_H
#include <cmath>
#include <vector>
using namespace std;

double dot(vector <double> a, vector<double> b){
        double dot=0;
        if(a.size() != b.size()){return -1;}
        for(int i = 0; i<a.size(); i++){
                dot+=a[i]*b[i];
        }
        return dot;
}
#endif
