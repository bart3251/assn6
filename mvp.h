#ifndef MVP_H
#define MVP_H
#include <iostream>
#include <time.h>
#include <vector>
#include "dot.h"
using namespace std;
vector<double> mvp(vector<vector<double> > m,vector <double> v){
	vector<double> p;
        if(m[0].size() != v.size()){p.clear(); return p;}
        clock_t start = clock();
	for(int i = 0; i<m.size(); i++){
        	p.push_back(dot(m[i],v));
        }
	cout<<(double)(clock()-start)/CLOCKS_PER_SEC<<endl;
        return p;
}
#endif
