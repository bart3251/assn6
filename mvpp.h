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
        if(m[0].size() != v.size()){p.clear(); return p;}
        #pragma omp parallel sections
	{
	clock_t start = clock();
	 #pragma omp section
	 {
	  clock_t start = clock();
	  for(int i = 0; i<m.size(); i++){
        	p.push_back(dotp(m[i],v));
          }
	  clock_t end = clock();
          cout<<(double)(end-start)/CLOCKS_PER_SEC<<endl; 
	 }
	}
        return p;
}
#endif
