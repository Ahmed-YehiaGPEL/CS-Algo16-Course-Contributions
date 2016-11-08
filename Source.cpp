#include <iostream>
#include <string>
#include "EditDistance.h"
#include "AssemblyLine.h"

#define MAX_STR_SIZE 200
using namespace std;

const int NUM_LINES = 4;



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
	
	system("pause");
	
	delete assemble;
	delete edObj;
	return 0;
}