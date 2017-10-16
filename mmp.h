#ifndef MMP_H
#define MMP_H
#include <vector>
#include <time.h>
#include <iostream>
#include "dot.h"
using namespace std;

vector<vector<double> > t(vector<vector<double> > m){
        vector<vector<double> > trans;
        trans.resize(m[0].size());
        for(int i = 0; i<m.size(); i++){
                trans[i].resize(m.size());
                for(int j = 0; j<m[i].size(); j++){
                        trans[i][j] = m[j][i];
                }
        }
        return trans;
}

vector<vector<double> > mmp(vector<vector<double> > m1,vector<vector<double> > m2){
        vector<vector<double> > p;
	vector<double> c;
	vector<double> temp;
        if(m1.size() != m2[0].size()){cout<<m1.size()<<" "<<m2[0].size()<<endl; p.clear(); return p;}
        vector<vector<double> > m = t(m2);
	clock_t start = clock();
	for(int i = 0; i<m1.size(); i++){
		for(int j = 0; j<m1[i].size(); j++){
			temp.push_back(dot(m1[i],m[i]));
		}
		p.push_back(temp);
		temp.clear();
        }
	cout<<(double)(clock()-start)/CLOCKS_PER_SEC<<endl;
        return p;
}
#endif
