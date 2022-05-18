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
#include <math.h>

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	r( 0 ),
	g( 0 ),
	b( 0 ),
	counter( 0.0f )
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
	const float frames_per_mode = 160.0f;
	// PROBAR CON FUNCIONES SINUSOIDALES Y FRECUENCIAS Y DESFASES VARIABLES POR TECLAS 
	// tipo red = sin(counter / lambda + phase )
	r = (int)(sin(counter / frames_per_mode + 0.0f) *255.0f);
	g = (int)(sin(counter / frames_per_mode + 600.f) * 255.0f);
	b = (int)(sin(counter / frames_per_mode + 1200.0f) * 255.0f);
	 
	//r = 255 * (((int)counter / frames_per_mode) % 6 == 0) +
	//	255 * (((int)counter / frames_per_mode) % 6 == 1) +
	//	(255 - ((int)counter % frames_per_mode) * (((int)counter / frames_per_mode) % 6 == 2)) +
	//	0 * (((int)counter / frames_per_mode) % 6 == 3) +
	//	0 * (((int)counter / frames_per_mode) % 6 == 4) +
	//	((int)counter % frames_per_mode) * (((int)counter / frames_per_mode) % 6 == 5);
	//
	//g = 0 * (((int)counter / frames_per_mode) % 6 == 0) +
	//	((int)counter % frames_per_mode) * (((int)counter / frames_per_mode) % 6 == 1)+
	//	255 * (((int)counter / frames_per_mode) % 6 == 2) +
	//	255 * (((int)counter / frames_per_mode) % 6 == 3) +
	//	(255 - ((int)counter % frames_per_mode) * (((int)counter / frames_per_mode) % 6 == 4)) +
	//	0 * (((int)counter / frames_per_mode) % 6 == 5);

	//b = 0 * (((int)counter / frames_per_mode) % 6 == 0) +
	//	0 * (((int)counter / frames_per_mode) % 6 == 1) +
	//	((int)counter % frames_per_mode) * (((int)counter / frames_per_mode) % 6 == 2)+
	//	255 * (((int)counter / frames_per_mode) % 6 == 3) +
	//	255 * (((int)counter / frames_per_mode) % 6 == 4) +
	//	(255 - ((int)counter % frames_per_mode) * (((int)counter / frames_per_mode) % 6 == 5));

	//{
	//	float tot = (float)r + (float)g + (float)b;
	//	float fct = 256.0f / tot;
	//	float ro = (float)r * fct;
	//	float gr = (float)g * fct;
	//	float bl = (float)b * fct;
	//	r = (int)ro;
	//	g = (int)gr;
	//	b = (int)bl;
}


void Game::ComposeFrame()
{
	for (int i = 0; i < sw; i++)
	{
		for(int j = 0; j < sh; j++)
		{ 
			gfx.PutPixel(i,j,r,g,b);
		}
		counter = counter + 0.0099f ;
	}
}
