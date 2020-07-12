#pragma once

#include "ThreeCEngine.h"
#include "olcPixelGameEngine.h"

class TCEExample : public olc::PixelGameEngine
{
	tce::Renderer renderer = tce::Renderer(this);
	tce::Renderer renderer_two = tce::Renderer(this);
	float z = 0;

private:
	int cam_position_x = 0;
	int cam_position_y = 0;

public:

	TCEExample()
	{
		sAppName = "JDG 3D";
		renderer.options.renderDistance[0] = 1; // Set the near render distance to 5
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
		olc::PixelGameEngine::DrawString(20, 45, "JDG 3D", olc::DARK_CYAN, 3);
		if (cam_position_y > 120) cam_position_y = 0;
		renderer.camera.position.y = cam_position_y;
		renderer_two.camera.position.y = cam_position_y;
		cam_position_y += 3;
		tce::DrawCube(tce::Vec3D(-11, 0, 25), tce::Vec3D(50, 50, 50), &renderer);
		tce::DrawCube(tce::Vec3D(-11, 60, 25), tce::Vec3D(10, 10, 10), &renderer_two);
		renderer.render();
		renderer_two.render(olc::DARK_CYAN);
		return true;
	}
};