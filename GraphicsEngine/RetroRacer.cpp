#include <iostream>
using namespace std;
#include "olcConsoleGameEngine.h"

class OneLoneCoder_FormulaOLC : public olcConsoleGameEngine {
public:
	OneLoneCoder_FormulaOLC() {
		m_sAppName = L"Formula OLC";
	}

private:

protected:
	virtual bool OnUserCreate() {
		return true;
	}
	virtual bool OnUserUpdate(float fElapsedTime) {
		return true;
	}
};

int main() {
	//Create the instance of the class above
	OneLoneCoder_FormulaOLC game;
	game.ConstructConsole(160, 100, 8, 8);
	game.Start();

	return 0;
}