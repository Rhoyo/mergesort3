#include <iostream>
#include <time.h>
#include <fstream>
#include <vector>

using namespace std;

vector<int> merge(vector<int> v1, vector<int> v2, vector<int> v3){
		vector<int> vec;
		int iter1=0;
		int iter2=0;
		int iter3=0;

//Phase 1 sort
		while(iter1<v1.size()&&iter2<v2.size()&&iter3<v3.size()){
			if(v1[iter1]<=v2[iter2]&&v1[iter1]<=v3[iter3]){ //pathway to push v1		
				vec.push_back(v1[iter1]);
				iter1++;
			}
			else if(v2[iter2]<=v3[iter3]&&v2[iter2]<=v1[iter1]){ //pathway to push v2
				vec.push_back(v2[iter2]);
				iter2++;	
			}
			else{ //pathway to push v3
				vec.push_back(v3[iter3]);
				iter3++;
			}
		}

//Phase 2 sort
		while(iter1<v1.size()&&iter2<v2.size()){ //v3 done
			if(v1[iter1]<=v2[iter2]){
				vec.push_back(v1[iter1]);
				iter1++;
			}
			else{	
				vec.push_back(v2[iter2]);
				iter2++;	
			}
		}
		while(iter1<v1.size()&&iter3<v3.size()){ //v2 done
			if(v1[iter1]>=v3[iter3]){
				vec.push_back(v3[iter3]);
				iter3++;
			}
			else{	
				vec.push_back(v1[iter1]);
				iter1++;	
			}
		}
		while(iter3<v3.size()&&iter2<v2.size()){ //v1 done
			if(v3[iter3]>=v2[iter2]){
				vec.push_back(v2[iter2]);
				iter2++;
			}
			else{	
				vec.push_back(v3[iter3]);
				iter3++;	
			}
		}

//Phase 3 sort
		while(iter1<v1.size()){
				vec.push_back(v1[iter1]);
				iter1++;	
		}
		while(iter2<v2.size()){
				vec.push_back(v2[iter2]);
				iter2++;
		}
		while(iter3<v3.size()){
				vec.push_back(v3[iter3]);
				iter3++;
		}
		//complete	
		return vec;
}

vector<int> mergeSort(vector<int> vec){
	if(vec.size()>2){	

		vector<int> v1;
		vector<int> v2;
		vector<int> v3;
		vector<int> r;
		
//filling in 3 arrays from original
		for(int i=0;i<vec.size()/3;i++)
			v1.push_back(vec[i]);
		

		for(int i=vec.size()/3;i<2*vec.size()/3;i++)
			v2.push_back(vec[i]);


		for(int i=2*vec.size()/3;i<vec.size();i++)
			v3.push_back(vec[i]);
		
		

		v1=mergeSort(v1);
		v2=mergeSort(v2);
		v3=mergeSort(v3);
		
		r=merge(v1,v2,v3);
		return r;
					
	}
	else{
		if(vec.size()==2){ //case with unsorted array of size 2
			if(vec[0]>vec[1]){	
				vec.push_back(vec[0]);
				vec.erase(vec.begin());
			}
		}
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

