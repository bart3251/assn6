#ifndef MMPP_H
#define MMPP_H
#include <vector>
#include <time.h>
#include <iostream>
#include "dotp.h"
using namespace std;

vector<vector<double> > tp(vector<vector<double> > m){
        vector<vector<double> > trans;
        trans.resize(m[0].size());
        #pragma omp parallel
	{
	#pragma omp for
	for(int i = 0; i<m.size(); i++){
                trans[i].resize(m.size());
                for(int j = 0; j<m[i].size(); j++){
                        trans[i][j] = m[j][i];
                }
        }
	}
        return trans;
}

vector<vector<double> > mmpp(vector<vector<double> > m1,vector<vector<double> > m2){
        vector<vector<double> > p;
        if(m1.size() != m2[0].size()){cout<<m1.size()<<" "<<m2[0].size()<<endl; p.clear(); return p;}
        vector<vector<double> > m = tp(m2);
	struct timespec start, finish;
	double elapsed;
	p.resize(m1.size());
	clock_gettime(CLOCK_MONOTONIC, &start);
	#pragma omp parallel for
	for(int i = 0; i<m1.size(); i++){
		vector<double> temp;
		for(int j = 0; j<m1[i].size(); j++){
			temp.push_back(dotp(m1[i],m[i]));
		}
		p[i] = temp;
        }
	clock_gettime(CLOCK_MONOTONIC, &finish);
	elapsed = (finish.tv_sec - start.tv_sec);
	elapsed += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;
	cout<<elapsed<<endl;
        return p;
}
#endif
