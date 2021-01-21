#include <iostream>
#include <time.h>
#include <fstream>
#include <vector>

using namespace std;

vector<int> merge(vector<int> v1, vector<int> v2){
		vector<int> vec;
		int iter1=0;
		int iter2=0;

	
		while(iter1<v1.size()&&iter2<v2.size()){
			if(v1[iter1]>=v2[iter2]){
				vec.push_back(v2[iter2]);
				iter2++;
			}
			else{	
				vec.push_back(v1[iter1]);
				iter1++;	
			}
		}
		while(iter1<v1.size()){
				vec.push_back(v1[iter1]);
				iter1++;	
		}
		while(iter2<v2.size()){
				vec.push_back(v2[iter2]);
				iter2++;
		}
	
		return vec;
}
vector<int> mergeSort(vector<int> vec){
		if(vec.size()>1){


		vector<int> v1;
		vector<int> v2;
		vector<int> r;
		
		for(int i=0;i<vec.size()/2;i++){
			v1.push_back(vec[i]);

		}
		for(int i=vec.size()/2;i<vec.size();i++){
			v2.push_back(vec[i]);
		}

		v1=mergeSort(v1);
		v2=mergeSort(v2);
		

		r=merge(v1,v2);
		return r;
					
	}
	else{
		return vec;
	}		
}

int main(){
	srand(time(NULL));
	vector<int> merge;
	int n=0;
	clock_t t2,t1;	
	
	for(int i=0;i<10;i++){
		n+=5000;
		for(int x=0;x<n;x++){
			merge.push_back(rand()%10000);
		}

		t2=clock();
		merge=mergeSort(merge);
		t1=clock();

		merge.clear();
		float elapse=(float)t1 - (float)t2;
		cout<<"Size: "<<n<<" Time: "<<elapse<<" "<<elapse/CLOCKS_PER_SEC<<"s"<<endl;
	}

	return 0;
}

