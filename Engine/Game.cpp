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
	counter( 0.0f ),
	frames_per_mode(16.0f)
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
	if (counter >= (255.0f * 255.0f * 255.0f))
		counter = 0;
}


void Game::ComposeFrame()
{
	for (int i = 0; i < sw; i++)
	{
		for(int j = 0; j < sh; j++)
		{ 
			gfx.PutPixel(i,j,r,g,b);
		}
		counter = counter + 0.00003f ;
		r = (int)((sin((counter+0.0f) / frames_per_mode )+1.3f) * 255.0f);
		g = (int)((sin((counter+256.0f) / frames_per_mode )+1.3f) * 255.0f);
		b = (int)((sin((counter+512.0f) / frames_per_mode )+1.3f) * 255.0f);
	}
}
