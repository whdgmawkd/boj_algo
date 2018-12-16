#include <iostream>
#include <string>
#include <bitset>
using namespace std;
int main(void) {
	int cmd;
	cin >> cmd;
	while (cmd--) {
		string opcode;
		short rd, ra, rb;
		cin >> opcode >> rd >> ra >> rb;
		rb = rb << 1;
		short opbin = 0;
		if (opcode.find("ADD") != -1)
			opbin = 0;
		else if (opcode.find("SUB") != -1)
			opbin = 1;
		else if (opcode.find("MOV") != -1)
			opbin = 2;
		else if (opcode.find("AND") != -1)
			opbin = 3;
		else if (opcode.find("OR") != -1)
			opbin = 4;
		else if (opcode.find("NOT") != -1)
			opbin = 5;
		else if (opcode.find("MULT") != -1)
			opbin = 6;
		else if (opcode.find("LSFTL") != -1)
			opbin = 7;
		else if (opcode.find("LSFTR") != -1)
			opbin = 8;
		else if (opcode.find("ASFTR") != -1)
			opbin = 9;
		else if (opcode.find("RL") != -1)
			opbin = 10;
		else if (opcode.find("RR") != -1)
			opbin = 11;
		opbin = opbin << 1;
		if (opcode.find('C') != string::npos) {
			opbin += 1;
			rb = rb >> 1;
		}
		opbin = opbin << 4;
		opbin += rd;
		opbin = opbin << 3;
		opbin += ra;
		opbin = opbin << 4;
		opbin += rb;
		cout << bitset<16>(opbin) << endl;
	}
}