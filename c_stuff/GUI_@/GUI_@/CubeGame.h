#pragma once

#include <string>
#include <vector>
#include "ThreeCEngine.h"
#include "olcPixelGameEngine.h"

using namespace std;

class CubeGame : public olc::PixelGameEngine
{
private:
	vector<tce::Renderer> renderer_list;	
	vector<olc::vf2d> rect_list;
	vector<olc::vf2d> rect_pos_list;
	vector <olc::Pixel> color_list;
	tce::Vec3D first_cube_vec = tce::Vec3D(-11, 0, 25);
	olc::vf2d vBall = { 200.0f, 200.0f };

	float fBallRadius = 5.0f;
	float z = 0;
	int cam_position_x = 0;
	int cam_position_y = 0;
	int count = 5;
	int speed = 5;
	int collisons = 0;
	int new_cube_count = 0;
	int new_rect_count = 1;
	

public:
	CubeGame()
	{
		sAppName = "JDG Cube Game";
	}

	bool OnUserCreate() override
	{
		olc::vf2d vRect = { 75.0f, 75.0f };
		olc::vf2d vRectPos = { float(rand() % ScreenWidth()), float(rand() % ScreenHeight()) };
		rect_list.push_back(vRect);
		rect_pos_list.push_back(vRectPos);
		color_list.push_back(GetRandomColor());

		for (int i = 0; i < count; ++i)
		{
			renderer_list.push_back(tce::Renderer(this));
		}
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		MoveWithBtn();
		CheckMouseRect();
		SetCamPosition();
		if (MouseRectCollison()) collisons++;
		Clear(olc::BLACK);
		DrawHeaderString();
		DrawFirstCube();
		DrawRects();
		return true;
	}

	void DrawFirstCube() 
	{
		tce::Renderer renderer_vect       = renderer_list.at(0),
			          renderer_two_vect   = renderer_list.at(1),
			          renderer_three_vect = renderer_list.at(2),
			          renderer_four_vect  = renderer_list.at(3),
			          renderer_five_vect  = renderer_list.at(4);

		tce::DrawCube(first_cube_vec, tce::Vec3D(50, 50, 50), &renderer_vect);
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

	void DrawHeaderString()
	{
		string cube_str = "Cubes = " + to_string(new_rect_count);
		string x_str = "Mouse X = " + to_string(GetMouseX());
		string y_str = "Mouse Y = " + to_string(GetMouseY());
		string cols_str = "Mouse Collisons = " + to_string(collisons);

		olc::PixelGameEngine::DrawString(12, 45, "JDG 3D", olc::DARK_CYAN, 2);
		olc::PixelGameEngine::DrawString(12, 69, cube_str, olc::DARK_CYAN, 2);
		olc::PixelGameEngine::DrawString(12, 93, x_str, olc::DARK_CYAN, 2);
		olc::PixelGameEngine::DrawString(12, 117, y_str, olc::DARK_CYAN, 2);
		olc::PixelGameEngine::DrawString(12, 141, cols_str, olc::DARK_CYAN, 2);
	}

	void DrawRandCube() 
	{
		tce::Renderer r = tce::Renderer(this);
		int rand_x = rand() % ScreenWidth();
		int rand_y = rand() % ScreenHeight();
		tce::DrawCube(tce::Vec3D(rand_x, rand_y, 25), tce::Vec3D(50, 50, 50), &r);
		r.render(olc::BLUE);
	}

	void DrawBall()
	{
		olc::PixelGameEngine::FillCircle(vBall, int(fBallRadius), olc::CYAN);

	}

	void DrawRects()
	{
		for (int i = 0; i < new_rect_count; ++i)
		{
			olc::vf2d vRect = rect_list.at(i);
			olc::vf2d vRectPos = rect_pos_list.at(i);
			olc::Pixel pColor = color_list.at(i);
			olc::PixelGameEngine::FillRect(vRectPos, vRect, pColor);
		}
	}

	void SetCamPosition()
	{
		if (CamOutOfRange()) 
		{
			cam_position_x = 0;
			cam_position_y = 0;
			if (speed < 130) speed += 3;
			else speed = 5;
			new_cube_count++;
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
			// have to use a pointer bc vectors store data at non-cts. locations xD
			tce::Renderer* renderer = &renderer_list.at(i);
			renderer->camera.position.x = cam_position_x;
			renderer->camera.position.y = cam_position_y;
		}
	}

	void MoveWithBtn()
	{
		if (olc::PixelGameEngine::GetKey(olc::UP).bHeld) 
		{
			//cout << "\nBUTTON HELD\n" << endl;
			cam_position_y += speed;
		}
		if (olc::PixelGameEngine::GetKey(olc::DOWN).bHeld) 
		{
			//cout << "\nBUTTON HELD\n" << endl;
			cam_position_y -= speed;
		}
		if (olc::PixelGameEngine::GetKey(olc::RIGHT).bHeld) 
		{
			//cout << "\nBUTTON HELD\n" << endl;
			cam_position_x -= speed;
		}
		if (olc::PixelGameEngine::GetKey(olc::LEFT).bHeld) 
		{
			//cout << "\nBUTTON HELD\n" << endl;
			cam_position_x += speed;
		}
	}

	void CheckMouseRect()
	{
		if (GetMouse(0).bPressed) 
		{
			olc::vf2d vRect = { 75.0f, 75.0 };
			olc::vf2d vRectPos = { float(rand() % ScreenWidth()), float(rand() % ScreenHeight()) };
			olc::Pixel pColor = GetRandomColor();
			rect_list.push_back(vRect);
			rect_pos_list.push_back(vRectPos);
			color_list.push_back(GetRandomColor());
			new_rect_count++;	// this is firing off, try and slow it down
		}
	}

	bool MouseRectCollison()
	{
		// right idea, but just remove all instances 
		// from the vector instead of drawing black ones
		for (int i = 0; i < rect_pos_list.size(); ++i)
		{
			olc::vf2d vRectPos = rect_pos_list.at(i);
			if (GetMouseX() == vRectPos.x || GetMouseX() == vRectPos.y) 
			{
				DeleteRect(vRectPos);
				auto itr = color_list.begin() + i;
				color_list.insert(itr, olc::BLACK);
				return true;
			}
			if (GetMouseY() == vRectPos.x || GetMouseY() == vRectPos.y)
			{
				DeleteRect(vRectPos);
				auto itr = color_list.begin() + i;
				color_list.insert(itr, olc::BLACK);
				return true;
			}
		}
		return false;
	}

	void DeleteRect(olc::vf2d vRectPos) 
	{
		olc::vf2d vRect = { 75.0f, 75.0f };
		olc::PixelGameEngine::FillRect(vRectPos, vRect, olc::BLACK);
	}

	void CheckMouseGrab()
	{
		int m = GetMouseWheel();
		int x = 1;
		cout << "\nMouse Wheel = " << m << "\n" << endl;

		if (olc::PixelGameEngine::GetMouse(0).bHeld)
		{
			cout << "\nMOUSE GRAB\n" << endl;
			cam_position_x += speed;
			cam_position_y += speed;
		}
		if (m > 0 ) 
		{
			cout << "\nMOUSE GRAB\n" << endl;
			cam_position_y++;
		}
		if (m < 0)
		{
			cout << "\nMOUSE GRAB\n" << endl;
			cam_position_y--;
		}
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

	void PrintMouse()
	{
		cout << "\nMouse X = " << GetMouseX() << endl;
		cout << "\nMouse Y = " << GetMouseY() << endl;
	}

	void DebugPrint()
	{
		cout << "X = " << cam_position_x << endl;
		cout << "Y = " << cam_position_y << endl;
		cout << "Speed = " << speed << "\n" << endl;
	}

};
