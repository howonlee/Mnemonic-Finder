
#include "MnemonicsLister.h"

MnemonicsLister::MnemonicsLister() {}
MnemonicsLister::~MnemonicsLister() {}

string MnemonicsLister::getPossLetter(int number){
	switch (number){
		case 2:
			return "ABC";
		case 3:
			return "DEF";
		case 4:
			return "GHI";
		case 5:
			return "JKL";
		case 6:
			return "MNO";
		case 7:
			return "PQRS";
		case 8:
			return "TUV";
		case 9:
			return "WXYZ";
		default:
			return "";
	}
}

void MnemonicsLister::listMnemonics(string mnemonic){
	if (!checkValidString(mnemonic)){
		cout << "Sorry! Wrong format!" << endl;
		return;
	}
	digits = mnemonic;
	digitQueue = parseString(mnemonic);
	parseInts(digitQueue, mnemonics, "", digits.length());
	for (unsigned int i = 0; i < mnemonics.size(); i++)
	{
		cout << mnemonics[i] << endl;
	}
}

bool MnemonicsLister::checkValidString(string toCheck){
	for (unsigned int i = 0; i < toCheck.length(); i++){
		if (!isdigit(toCheck[i]) || toCheck[i] == 0
			|| toCheck[i] == 1){ return false; }
	}
	return true;
}

queue<int> MnemonicsLister::parseString(string toParse){
	queue<int> digitsParsed;
	for (unsigned int i = 0; i < toParse.length(); i++){
		digitsParsed.push(toParse[i] - '0');
	}
	return digitsParsed;
}

void MnemonicsLister::parseInts(queue<int> toParse, vector<string>& mnemonics, string curr, int length){
	if (curr.length() == length){
		mnemonics.push_back(curr);
	}
	if (toParse.empty()) {
		return;
	}

	string mnemonicDigits = getPossLetter(toParse.front());
	toParse.pop();
	for (unsigned int i = 0; i < mnemonicDigits.length(); i++){
		string temp = curr;
		parseInts(toParse, mnemonics, temp.append(1, mnemonicDigits[i]) , length);
	}
}


