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
		Fill(0, 0, ScreenWidth(), ScreenHeight(), L' ', 0);   //Cleans the screen before drawing! 
		for (int y = 0; y < ScreenHeight(); y++) {
			for (int x = 0; x < ScreenWidth(); x++) {
				//let's create a normalized space: Meaning 0 represents the left hand side, and 1 is on the right hand side 
				float fMiddlePoint = 0.5f;    // 0.5 represents the middle point
				float fRoadWidth = 0.6f;	  // road width will be 60% of the screen
				float fClipWidth = fRoadWidth * 0.15f;	// the borders in the track will be 15% of the road width

				fRoadWidth *= 0.5f;	// assumes the road is symmetrical at the middle point

				//left and right grass variables. Study the Calculations as such.
				int nLeftGrass = (fMiddlePoint - fRoadWidth - fClipWidth) * ScreenWidth(); 
				int nLeftClip = (fMiddlePoint - fRoadWidth) * ScreenWidth();
				int nRightGrass = (fMiddlePoint + fRoadWidth - fClipWidth) * ScreenWidth(); 
				int nRightClip = (fMiddlePoint + fRoadWidth) * ScreenWidth();

				//Draws the grass. Study the Calculations as such.
				int nRow = ScreenHeight() / 2 + y;
				if (x >= 0 && nLeftGrass) 
					Draw(x, nRow, PIXEL_SOLID, FG_GREEN);
				if (x >= nLeftGrass && x < nLeftClip) 
					Draw(x, nRow, PIXEL_SOLID, FG_RED);
				if (x >= nLeftClip && x < nRightClip)
					Draw(x, nRow, PIXEL_SOLID, FG_GREY);
				if (x >= nRightClip && x < nRightGrass)
					Draw(x, nRow, PIXEL_SOLID, FG_RED);
				if (x >= nRightGrass && x < ScreenWidth())
					Draw(x, nRow, PIXEL_SOLID, FG_GREY);
			}
		}

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