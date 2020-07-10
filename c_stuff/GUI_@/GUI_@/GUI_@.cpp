#define OLC_PGE_APPLICATION

#include "olcPixelGameEngine.h"

using namespace olc;

// Override base class with your custom functionality
class Example : public olc::PixelGameEngine
{
public:
	Example()
	{
		// Name you application
		sAppName = "JDG";
	}

public:
	bool OnUserCreate() override
	{
		// called once at start
		Clear(DARK_CYAN);
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		StartPixels(fElapsedTime);
		return true;
	}

	void StartPixels(float fElapsedTime)
	{
		printf("Mouse X = %d\nMouse Y = %d\n\n", GetMouseX(), GetMouseY());
		if (GetMouseY() < 60) {
			Clear(DARK_RED);
			DrawString(50, 40, "JDG", Pixel(rand() % 256, rand() % 256, rand() % 256), 4);
			DrawString(40, 120, "2020 Baby", Pixel(rand() % 256, rand() % 256, rand() % 256), 2);
		}
		else {
			Clear(DARK_CYAN);
			DrawString(50, 40, "JDG", Pixel(0, 0, 0), 4);
			DrawString(40, 120, "2020 Baby", Pixel(0, 0, 0), 2);
			DrawCircle(120, 170, 10);
			FillCircle(120, 170, 20, DARK_RED);
		}
		if (CheckKeys()) {
			Clear(DARK_YELLOW);
			DrawString(20, 40, "BUTTON PRESSED", Pixel(0, 0, 0), 2);
		}
	}

	bool CheckKeys() 
	{
		return GetKey(UP).bHeld || GetKey(DOWN).bHeld || GetKey(LEFT).bHeld || GetKey(RIGHT).bHeld;
	}

};

int main()
{
	Example demo;
	if (demo.Construct(256, 240, 4, 4))
		demo.Start();
	return 0;
}