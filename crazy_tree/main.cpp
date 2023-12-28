#include "raylib.h"
#include <iostream>
#include <box2d\box2d.h>

using namespace std;

Texture2D tree;

//Texture2D
class Imag
{
public:
	int posX = 0;
	int posY = 75;

	void Draw()
	{
		DrawTexture(tree, posX, posY, WHITE);
	}
};

//Ball
class Ball
{
public:

	float centerX = 390;
	float centerY = 315;
	float radius = 10;
	int speedX = 1;
	int speedY = 1;

	void Draw()
	{
		DrawCircle(centerX, centerY, radius, BLUE);
	}

	void Update()
	{
		centerX = centerX + speedX;
		centerY = centerY - speedY;
	}
};

Imag imag;
Ball ball;
int main()
{
	//Screen Size
	const int Screen_width = 800;
	const int Screen_Higth = 450;
	InitWindow(Screen_width, Screen_Higth, "Crazy Tree");

	tree = LoadTexture("Graphics/tree.png");


	 //FPS
	 SetTargetFPS(144);

	//Screen Loop
	while (WindowShouldClose() == false)
	{
		BeginDrawing();
			ClearBackground(BLACK);

			//Update
			ball.Update();
			//Draw
			imag.Draw();
			ball.Draw();

		EndDrawing();
	}

	CloseWindow();

	return (0);
}