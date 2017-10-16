#include <iostream>
#include <vector>
#include <iomanip>
#include "dot.h"
#include "mvp.h"
#include "mvpp.h"
#include "mmp.h"
#include "mmpp.h"
using namespace std;

int main(){
	vector<vector<double> > A;
	vector<double> v;
	int m = 14000;
	int n = 14000;
	cout<<"Building Matrix..."<<endl;
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			v.push_back(i+j);
		}
		A.push_back(v);
		v.clear();
	}
	for(int i = 0; i<n; i++){
		v.push_back(i);
	}
	cout<<"Matrix Vector Multiplication:"<<endl;
	mvp(A,v);
	cout<<"Parallel Matrix Vector Multiplication:"<<endl;
	mvpp(A,v);
	for(int i=0; i<m; i++){
		A[i].clear();
	}
	A.clear();
	v.clear();
	m = 900;
	n = 900;
	vector<vector<double> > B;
	A.resize(m);
	B.resize(n);
	for(int i=0; i<m; i++){
                for(int j=0; j<n; j++){
			B[i].push_back(i);
			v.push_back(i+j);
                }
                A[i] = v;
                v.clear();
        }
	cout<<"Matrix Matrix Multiplication:"<<endl;
	mmp(A,B);
	cout<<"Parallel Matrix Matrix Multiplication:"<<endl;
	mmpp(A,B);
	return 0;
}
