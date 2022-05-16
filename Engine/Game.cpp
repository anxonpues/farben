/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	r( 0 ),
	g( 0 ),
	b( 0 ),
	counter( 0 )
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	
	const int frames_per_mode = 512;

	/*r = 255 * ((counter / frames_per_mode)%4 == 0) +
		(255 - (counter % frames_per_mode) * ((counter / frames_per_mode)%4 == 1)) +
		0 * ((counter / frames_per_mode)%4 == 2) +
		(counter % frames_per_mode) * ((counter / frames_per_mode)%4 == 3);
	g = 255 * ((counter / frames_per_mode) % 4 == 1) +
		(255 - (counter % frames_per_mode) * ((counter / frames_per_mode) % 4 == 2)) +
		0 * ((counter / frames_per_mode) % 4 == 3) +
		(counter % frames_per_mode) * ((counter / frames_per_mode) % 4 == 0);
	b = 255 * ((counter / frames_per_mode) % 4 == 3) +
		(255 - (counter % frames_per_mode) * ((counter / frames_per_mode) % 4 == 0)) +
		0 * ((counter / frames_per_mode) % 4 == 1) +
		(counter % frames_per_mode) * ((counter / frames_per_mode) % 4 == 2);*/
	r = 255 * ((counter / frames_per_mode) % 6 == 0) +
		255 * ((counter / frames_per_mode) % 6 == 1) +
		(255 - (counter % frames_per_mode) * ((counter / frames_per_mode) % 6 == 2)) +
		0 * ((counter / frames_per_mode) % 6 == 3) +
		0 * ((counter / frames_per_mode) % 6 == 4) +
		(counter % frames_per_mode) * ((counter / frames_per_mode) % 6 == 5);
	
	g = 0 * ((counter / frames_per_mode) % 6 == 0) +
		(counter % frames_per_mode) * ((counter / frames_per_mode) % 6 == 1)+
		255 * ((counter / frames_per_mode) % 6 == 2) +
		255 * ((counter / frames_per_mode) % 6 == 3) +
		(255 - (counter % frames_per_mode) * ((counter / frames_per_mode) % 6 == 4)) +
		0 * ((counter / frames_per_mode) % 6 == 5);

	b = 0 * ((counter / frames_per_mode) % 6 == 0) +
		0 * ((counter / frames_per_mode) % 6 == 1) +
		(counter % frames_per_mode) * ((counter / frames_per_mode) % 6 == 2)+
		255 * ((counter / frames_per_mode) % 6 == 3) +
		255 * ((counter / frames_per_mode) % 6 == 4) +
		(255 - (counter % frames_per_mode) * ((counter / frames_per_mode) % 6 == 5));

	{
		float tot = (float)r + (float)g + (float)b;
		float fct = 256.0f / tot;
		float ro = (float)r * fct;
		float gr = (float)g * fct;
		float bl = (float)b * fct;
		r = (int)ro;
		g = (int)gr;
		b = (int)bl;
	}
	counter %= 16000000;
	

}

void Game::ComposeFrame()
{
	int flop = 0;
	for (int i = 0; i < sw; i++)
	{
		for(int j = 0; j < sh; j++)
		{ 
			gfx.PutPixel(i,j,r,g,b);
			for (int k = 0; k < 1000000; k++)		// retardo
				if (k % 7 >= 3 && k % 11 <= 5)
					flop += 3;
		}
		counter++;
		flop %= 255;
	}
	
}
