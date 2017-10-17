#ifndef MVPP_H
#define MVPP_H
#include <vector>
#include <iostream>
#include <time.h>
#include "dotp.h"
#include <omp.h>
using namespace std;
vector<double> mvpp(vector<vector<double> > m,vector <double> v){
        vector<double> p;
        struct timespec start, finish;
	double elapsed;
	if(m[0].size() != v.size()){p.clear(); return p;}
        #pragma omp parallel sections
	{
	 #pragma omp section
	 {
	  clock_gettime(CLOCK_MONOTONIC, &start);
	  for(int i = 0; i<m.size(); i++){
        	p.push_back(dotp(m[i],v));
          }
	  clock_gettime(CLOCK_MONOTONIC, &finish);
	  elapsed = (finish.tv_sec - start.tv_sec);
	  elapsed += (finish.tv_nsec = start.tv_nsec) / 1000000000.0;
          cout<<elapsed<<endl; 
	 }
	}
        return p;
}
#endif
