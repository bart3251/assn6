#ifndef DOTP_H
#define DOTP_H
#include <cmath>
#include <vector>
using namespace std;

double dotp(vector <double> a, vector<double> b){
        double dot=0;
        if(a.size() != b.size()){return -1;}
        #pragma omp parallel
	{
	#pragma omp for
	for(int i = 0; i<a.size(); i++){
                dot+=a[i]*b[i];
        }
	}
        return dot;
}
#endif
