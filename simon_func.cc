//note: since putting template in .cc file will cause further trouble for users to initialize it, 
//I simply put all templates in .h file
#include "simon_func.h"
using namespace std;

//splitToVec(string str, char c) split str separated by c, 
//                               then put the result in an vector, 
//                               and returns that vector.
vector<string> splitToVec(string str, const char c){
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

//splitToDeq(string str, char c, deque<string> & vec) split str separated by c, 
//                               then put the non-empty substrings in vec.
void splitToDeq(string str, char c, deque<string> & vec){
	istringstream ss(str);
	string tmp;
	while(getline(ss, tmp, c)) 
		if(tmp != "") vec.push_back(tmp);
	return;
}

//strContain(string s1, string s2) returns true if s1 contains s2, otherwise false.
//  i.e "ac~d" contains "~", thus strContain("ac~d","~") returns true.
bool strContain(string s1, string s2){
	return s1.find(s2) != string::npos;
}





