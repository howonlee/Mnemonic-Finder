#include "MnemonicsLister.h"
#include <stdlib.h>

int main( int argc, const char* argv[] )
{
	if (argc != 2){
		cout << "Usage: program numbertolist" << endl;
		exit(1);
	}
	MnemonicsLister lister;
	string numberToList(argv[1]);
	lister.listMnemonics(numberToList);//Insert whatever you want here!
	return 0;
}
