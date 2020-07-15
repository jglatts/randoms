#pragma once

#include <string>
#include <vector>
#include "ThreeCEngine.h"
#include "olcPixelGameEngine.h"

using namespace std;

class CubeGame : public olc::PixelGameEngine
{
private:
	vector<tce::Renderer> renderer_list;	// vector for renderers, try and use references
	float z = 0;
	int cam_position_x = 0;
	int cam_position_y = 0;
	int count = 5;
	int speed = 5;

public:
	CubeGame()
	{
		sAppName = "JDG Cube Game";
	}

	bool OnUserCreate() override
	{
		Clear(olc::BLACK);
		for (int i = 0; i < count; ++i)
		{
			renderer_list.push_back(tce::Renderer(this));
		}
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		// main loop here
		// have to do rand()'ing to get it to display
		Clear(olc::BLACK);
		SetCamPosition();
		MoveWithBtn(speed); 
		DrawFirstCube();
		return true;
	}

	void DrawFirstCube() 
	{
		tce::Renderer renderer_vect       = renderer_list.at(0),
			          renderer_two_vect   = renderer_list.at(1),
			          renderer_three_vect = renderer_list.at(2),
			          renderer_four_vect  = renderer_list.at(3),
			          renderer_five_vect  = renderer_list.at(4);

		tce::DrawCube(tce::Vec3D(-11, 0, 25), tce::Vec3D(50, 50, 50), &renderer_vect);
		tce::DrawCube(tce::Vec3D(-11, 60, 30), tce::Vec3D(10, 10, 10), &renderer_two_vect);
		tce::DrawCube(tce::Vec3D(4, 60, 30), tce::Vec3D(10, 10, 10), &renderer_three_vect);
		tce::DrawCube(tce::Vec3D(19, 60, 30), tce::Vec3D(10, 10, 10), &renderer_four_vect);
		tce::DrawCube(tce::Vec3D(34, 60, 30), tce::Vec3D(10, 10, 10), &renderer_five_vect);

		renderer_vect.render(GetRandomColor());
		renderer_two_vect.render(GetRandomColor());
		renderer_three_vect.render(GetRandomColor());
		renderer_four_vect.render(GetRandomColor());
		renderer_five_vect.render(GetRandomColor());
	}

	void SetCamPosition()
	{
		if (CamOutOfRange()) {
			cam_position_x = 0;
			cam_position_y = 0;
			if (speed < 130) speed += 3;
			else speed = 5;
			//count++;
		}
		UpdateRenderers();
	}

	bool CamOutOfRange()
	{
		return cam_position_x > 220 || cam_position_x < -195 || cam_position_y > 120 || cam_position_y < -132;
	}

	void UpdateRenderers()
	{
		for (int i = 0; i < count; ++i)
		{
			tce::Renderer* renderer = &renderer_list.at(i);
			renderer->camera.position.x = cam_position_x;
			renderer->camera.position.y = cam_position_y;
		}
	}

	void MoveWithBtn(int speed)
	{
		if (olc::PixelGameEngine::GetKey(olc::UP).bHeld) {
			printf("\nBUTTON HELD\n");
			cam_position_y += speed;
		}
		if (olc::PixelGameEngine::GetKey(olc::DOWN).bHeld) {
			printf("\nBUTTON HELD\n");
			cam_position_y -= speed;
		}
		if (olc::PixelGameEngine::GetKey(olc::RIGHT).bHeld) {
			printf("\nBUTTON HELD\n");
			cam_position_x -= speed;
		}
		if (olc::PixelGameEngine::GetKey(olc::LEFT).bHeld) {
			printf("\nBUTTON HELD\n");
			cam_position_x += speed;
		}
		printf("X = %d\nY = %d\nSpeed = %d\n\n", cam_position_x, cam_position_y, speed);
	}

	olc::Pixel GetRandomColor()
	{
		return olc::Pixel(rand() % 256, rand() % 256, rand() % 256);
	}

	void OriginalExample(float fElapsedTime, tce::Renderer renderer) 
	{
		Clear(olc::BLACK);
		z += fElapsedTime * 10;
		renderer.camera.position.y = z;
		tce::DrawCube(tce::Vec3D(-25, -25, 25), tce::Vec3D(50, 50, 50), &renderer);
		renderer.render();
	}

};
