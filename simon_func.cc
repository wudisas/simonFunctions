#include <string>
#include <sstream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <set>
#include <deque>
#include <map>
using namespace std;

#define forEach(i,k,n) for(int i = k; i < n; ++i)
#define forVec(val, vec) for(auto val : vec)
#define toStr(k) std::to_string(k)

//GCD() returns the gcd value of a and b
template <class type>
type GCD(type a, type b){
	if(a < b) swap(a,b);
	while(b != 0) {
		type r = a % b;
		a = b;
		b = r;
	}
	return a;
}

//LCM() returns the lcm value of a and b
template <class type>
type LCM(type a, type b){
	type tmp = GCD(a,b);
	b = a / tmp * b;
	return b;
}

//factor() put all factors from a to vector v in increasing order
template <class type>
void factor(type a, vector<type> & v){
	if(a == 0) return;
	v.clear();
	v.push_back(1);
	type z = 2;
	while(a % z == 0 && a != 1) {v.push_back(z); a /= z;}
	z = 3;
	while(z * z <= a){
		if(a % z == 0) {
			v.push_back(z);
			a /= z;
		} else z += 2;
	} 
	if(a != 1) v.push_back(a);
}

//modpow() is function for exponential. 
template <class type>
type modpow(type base, type exp, type modulus) {
  base %= modulus;
  type result = 1;
  while (exp > 0) {
    if (exp & 1) result = (result * base) % modulus;
    base = (base * base) % modulus;
    exp >>= 1;
  }
  return result;
}

//splitToVec(string str, char c) split str separated by c, 
//                               then put the result in an vector, 
//                               and returns that vector.
vector<string> splitToVec(string str, char c){
	istringstream ss(str);
	string tmp;
	vector<string> vec;
	while(getline(ss, tmp, c)) 
		if(tmp != "") vec.emplace_back(tmp);
	return vec;
}

//splitToVec(string str, char c, vector<string> & vec) split str separated by c, 
//                               then put the non-empty substrings in vec.
void splitToVec(string str, char c , vector<string> & vec){
	istringstream ss(str);
	string tmp;
	while(getline(ss, tmp, c)) 
		if(tmp != "") vec.emplace_back(tmp);
	return;
}

//printVec(vector<type> & vec) receive a reference to a type vector, 
//                             and prints all values in that vector.
template <class type>
void printVec(vector<type> & vec){
	for(auto val : vec) cout<<val<<endl;
	return;
}

//vecFind(vector<type> v, type val) Tries to find the val's index in vector v. If val exists in v, 
//                                  it returns the smallest index of all vals in v.
//                                  Otherwise, it returns -1 and this means that val doesn't exist in v.
//Note: v has to be increasing order!
//i.e. if vector<int> v = {1, 4, 4, 5, 6}, then vecFind(v,4) == 1, vecFind(v,19) == -1
template <class type>
long long vecFind(vector<type> v, type val){
	long long start = 0, end = v.size();
	long long result = -1;
	while(start != end){
		cout<<"val = "<<val<<", start == "<<start<<", end = "<<end<<endl;
		long long mid = start + ((end - start) / 2);
		if(v[mid] == val) {result = mid; end = mid;}
		else if(v[mid] > val) end = mid;
		else start = mid + 1;
	} return result;
}


//strContain(string s1, string s2) returns true if s1 contains s2, otherwise false.
//  i.e "ac~d" contains "~", thus strContain("ac~d","~") returns true.
bool strContain(string s1, string s2){
	return s1.find(s2) != string::npos;
}

//checkVec() returns true if v contains val
template <class type>
bool checkVec(vector<type> v, type val){
	return std::find(v.begin(), v.end(),val) != v.end();
}

//mergeSort template, sort the vector in increasing order
template <class type>
void mergeSortHelper(vector<type> & vec, long long first, long long last) {
    //cout<<"first = "<<first<<", and last = "<<last<<", and vec is : "<<endl;
    //for(int i = first; i < last; ++i) cout<<vec[i]<<" ";
    //cout<<endl;
	if(first == last || first == last - 1) return;
	if(first == last - 2) {
		if(vec[first] > vec[last-1]) {
			type tmp = vec[first];
			vec[first] = vec[last-1];
			vec[last-1] = tmp;
		} return;
	}
	long long second = first + (last - first) / 2;
	//cout<<"second is "<<second<<endl;
	//long long third = second;
	mergeSortHelper(vec, first, second);
	mergeSortHelper(vec, second, last);
	long long start1 = first, start2 = second;
	vector<type> new_vec;
	new_vec.clear();
	//cout<<"first = "<<first<<", and second = "<<second<<", and last = "<<last<<endl;
	//cout<<"start1 = "<<start1<<", start2 = "<<start2<<", and vec is : ";
    //for(int i = first; i < last; ++i) cout<<vec[i]<<" "; cout<<endl;
	while(start1 != second || start2 != last){
		if(start1 == second) new_vec.emplace_back(vec[start2++]);
		else if(start2 == last) new_vec.emplace_back(vec[start1++]);
		else if(vec[start1] > vec[start2]) new_vec.emplace_back(vec[start2++]);
		else new_vec.emplace_back(vec[start1++]);
	} 
	for(int i = 0; first < last; ++i) vec[first++] = new_vec[i];
	
	//cout<<"first = "<<first<<", and second = "<<second<<", and last = "<<last<<", and vec is : "<<endl;
    //for(int i = first; i < last; ++i) cout<<vec[i]<<" "; cout<<endl;
    //cout<<"new_vec is : "; for(unsigned i = 0; i < new_vec.size(); ++i) cout<<new_vec[i]<<" "; cout<<endl<<endl;
	return;
}

template <class type>
void mergeSort(vector<type> & vec){ //in increasing order
	mergeSortHelper(vec,0,vec.size());
	//cout<<"haha"<<endl;
	return;
}

//deleRe(vector<type> & vec) delete the repetead element in vec
//note: vec has to be increasing order, otherwise use mergesort first
template <class type>
void deleRe(vector<type> & vec){
	vector<type> tmp;
	if(vec.size() == 0 || vec.size() == 1) return;
	forEach(i,0,vec.size()-1) {
		if(vec[i] != vec[i+1]) tmp.emplace_back(vec[i]);
		if(i == vec.size() - 2) tmp.emplace_back(vec[i+1]);
	}
	vec.clear();
	vec = tmp;
	return;
}
