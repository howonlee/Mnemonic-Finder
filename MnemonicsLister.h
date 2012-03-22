#ifndef _mnemonic_h
#define _mnemonic_h

#include <queue>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class MnemonicsLister{
	
public:
	MnemonicsLister();
	~MnemonicsLister();
	void listMnemonics(string mnemonic);

private:
	string digits;
	queue<int> digitQueue;
	vector<string> mnemonics;

	void simplePrint(string toPrint);
	string getPossLetter(int number);
	bool checkValidString(string toCheck);
	queue<int> parseString(string toParse);
	void parseInts(queue<int> toParse, vector<string>& mnemonics, string curr, int length);

};

#endif