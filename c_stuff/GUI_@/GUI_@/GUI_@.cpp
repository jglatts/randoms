#include <iostream>

#define OLC_PGE_APPLICATION
#include "ThreeCEngine.h"

class TCEExample : public olc::PixelGameEngine
{
	tce::Renderer renderer = tce::Renderer(this);
	float z = 0;

public:
	int cam_position = 0;

	TCEExample()
	{
		sAppName = "ThreeCEngine Example";
		//renderer.options.renderDistance[0] = 1; // Set the near render distance to 5
	}

public:
	bool OnUserCreate() override
	{
		// Called once at the start, so create things here
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		Clear(olc::BLACK);
		if (cam_position > 120) cam_position = 0;
		renderer.camera.position.y = cam_position;
		cam_position+=3;
		tce::DrawCube(tce::Vec3D(-25, 0, 25), tce::Vec3D(50, 50, 50), &renderer);
		renderer.render();
		return true;
	}
};

int main()
{
	TCEExample app;
	if (app.Construct(1024, 750, 1, 1, false, true))
		app.Start();
	return 0;
}