#pragma once

#include "ThreeCEngine.h"
#include "olcPixelGameEngine.h"

class TCEExample : public olc::PixelGameEngine
{

public:
	float z = 0;
	tce::Renderer renderer       = tce::Renderer(this),
				  renderer_two   = tce::Renderer(this),
				  renderer_three = tce::Renderer(this),
				  renderer_four  = tce::Renderer(this),
				  renderer_five  = tce::Renderer(this);

	TCEExample()
	{
		sAppName = "JDG 3D";
		renderer.options.renderDistance[0] = 1; // Set the near render distance to 5
	}

	bool OnUserCreate() override
	{
		// Called once at the start, so create things here
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		Clear(olc::BLACK);
		DrawHeaderString();
		SetCamPosition();
		DrawFaces();
		MoveWithBtn(speed);
		return true;
	}

private:
	int cam_position_x = 0;
	int cam_position_y = 0;
	int speed = 5;

	void DrawHeaderString()
	{
		olc::PixelGameEngine::DrawString(20, 45, "JDG 3D", olc::DARK_CYAN, 3);
		olc::PixelGameEngine::DrawString(47, 85, "2020", olc::DARK_CYAN, 3);
	}

	void SetCamPosition() 
	{
		if (CamOutOfRange()) {
			cam_position_x = 0;
			cam_position_y = 0;
			speed++;
		}
		renderer.camera.position.y = cam_position_y;
		renderer_two.camera.position.y = cam_position_y;
		renderer_three.camera.position.y = cam_position_y;
		renderer_four.camera.position.y = cam_position_y;
		renderer_five.camera.position.y = cam_position_y;

		renderer.camera.position.x = cam_position_x;
		renderer_two.camera.position.x = cam_position_x;
		renderer_three.camera.position.x = cam_position_x;
		renderer_four.camera.position.x = cam_position_x;
		renderer_five.camera.position.x = cam_position_x;
	}

	bool CamOutOfRange()
	{
		return cam_position_x > 220 || cam_position_x < -195 || cam_position_y > 120 || cam_position_y < -132;
	}

	void DrawFaces()
	{
		tce::DrawCube(tce::Vec3D(-11, 0, 25), tce::Vec3D(50, 50, 50), &renderer);
		tce::DrawCube(tce::Vec3D(-11, 60, 30), tce::Vec3D(10, 10, 10), &renderer_two);
		tce::DrawCube(tce::Vec3D(4, 60, 30), tce::Vec3D(10, 10, 10), &renderer_three);
		tce::DrawCube(tce::Vec3D(19, 60, 30), tce::Vec3D(10, 10, 10), &renderer_four);
		tce::DrawCube(tce::Vec3D(34, 60, 30), tce::Vec3D(10, 10, 10), &renderer_five);

		renderer.render(GetRandomColor());
		renderer_two.render(GetRandomColor());
		renderer_three.render(GetRandomColor());
		renderer_four.render(GetRandomColor());
		renderer_five.render(GetRandomColor());
	}

	olc::Pixel GetRandomColor() 
	{
		return olc::Pixel(rand() % 256, rand() % 256, rand() % 256);
	}
	
	void MoveWithBtn(int speed) 
	{
		// add something for accel...
		if (olc::PixelGameEngine::GetKey(olc::UP).bHeld) {
			cam_position_y += speed;
		}
		if (olc::PixelGameEngine::GetKey(olc::DOWN).bHeld) {
			cam_position_y -= speed;
		}
		if (olc::PixelGameEngine::GetKey(olc::RIGHT).bHeld) {
			cam_position_x -= speed;
		}
		if (olc::PixelGameEngine::GetKey(olc::LEFT).bHeld) {
			cam_position_x += speed;
		}
		printf("X = %d\nY = %d\n\n", cam_position_x, cam_position_y);
	}

};
