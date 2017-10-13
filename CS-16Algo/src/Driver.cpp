#include <iostream>
#include <string>
#include "../inc/dp/AssemblyLine.h"
#include "../inc/dp/FastBoundedFib.h"
#include "../inc/dp/LCS.h"
#include "../inc/dp/KnapSack.h"
#include "../inc/dp/EditDistance.h"
#define FUNCTION(defintio,type){int defintio(int x, int y){return x type y ? x : y;}}
#define foreach(start,end) {for(auto start : end){}}
#define MAX_STR_SIZE 200
using namespace std;

int main() {
	
	/**************************Edit Distance problem***************************************/
	char* x1 = "sunday";
	char* x2 = "monday9o";
	EditDistance* edObj = new EditDistance();
	cout << edObj->GetEditDistance(x1, x2, strlen(x1),strlen(x2),MAX_STR_SIZE) << endl;
	/**************************Assembly Line problem***************************************/
	AssemblyLine* assemble = new AssemblyLine();
	vector<vector<int> > stationTime(2, vector<int>(4));
	
	stationTime[0] = vector<int>({ 4,5,3,2 });
	stationTime[1] = (vector<int>({ 2,10,1,4 }));

	vector<vector<int> > timeFromLineToLine(2, vector<int>(4));
	timeFromLineToLine[0] = (vector<int>({ 0,7,4,5 }));
	timeFromLineToLine[1] = (vector<int>({ 0,9,2,8 }));
	int entryTime[] = { 10, 12 }, exitTime[] = { 18, 7 };

	cout << assemble->CalculateMinTime(stationTime, timeFromLineToLine, entryTime, exitTime) << endl;
	/************************Fibo************************/
	FastBoundedFibonacci fb;
	cout << fb.CalculateBoundedFibonacci(10) << endl;
	/*****************************LCS***********************/
	auto lc = new LCS();
	char* s1;
	char* s2;
	s1 = "AGGTAB";
	s2 = "GXTXAYB";
	cout << lc->GetLCS(s1, s2) << endl;
	/***Knap Sack***/
	KnapSack ks;
	vector<int> v({60,100,120});
	vector<int> w({ 10,20,30 });
	auto tW = 50;
	cout << ks.SolveKnapSack(tW, w,v) << endl;
	/*END*/
	system("pause");
	delete lc;
	delete assemble;
	delete edObj;
	return 0;
}