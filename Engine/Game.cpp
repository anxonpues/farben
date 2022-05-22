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
#include <cmath>

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	r( 0 ),
	g( 0 ),
	b( 0 ),
	x( 0 ),
	y( 0 ),
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
	if (counter >= (255.0f * 255.0f * 255.0f))
		counter = 0;

	int val = (int)counter;
	int mode = val % 11;
	switch (mode)
	{
		case  0:
		{
			// red steady high, green steasy low, blue step down  MAGENTA to RED
			r = 255;
			g = 0;
			b = 255 - (val % 256);
			break;
		}
		case  1:
		{
			// red steady high, green steasy low, blue steady low RED
			break;
			r = 255;
			g = 0;
			b = 0;
			break;
		}
		case  2:
		{
			// red steady high, green step up, blue steady low RED to YELLOW
			r = 255;
			g = val % 256;
			b = 0;
			break;
		}
		case  3:
		{
			// red steady high, green steady high, blue steady low YELLOW
			break;
			r = 255;
			g = 255;
			b = 0;
			break;
		}
		case  4:
		{
			// red step down, green steady high, blue steady low YELLOW to GREEN
			r = 255 - (val % 256);
			g = 255;
			b = 0;
			break;
		}
		case  5:
		{
			// red steady low, green steady high, blue steady low  GREEN
			break;
			r = 0;
			g = 255;
			b = 0;
			break;
		}
		case  6:
		{
			// red steady low, green steady high, blue step up  GREEN to CYAN
			r = 0;
			g = 255;
			b = val % 256;
			break;
		}
		case  7:
		{
			// red steady low, green steady high, blue steady high  CYAN
			break;
			r = 0;
			g = 255;
			b = 255;
			break;
		}
		case  8:
		{
			// red steady low, green step down, blue steady low  CYAN to BLUE
			r = 0;
			g = 255 - (val % 256);
			b = 255;
			break;
		}
		case 9:
		{
			// red steady low, green steady low, blue steady high  BLUE
			break;
			r = 0;
			g = 0;
			b = 255;
			break;
		}
		case 10:
		{
			// red step up, green steady low, blue steady high BLUE to  MAGENTA
			r = val % 256;
			g = 0;
			b = 255;
			break;
		}
		default:
		{}
	}
	long long retard = 0;
	long long kr = 0;
	while (retard < 10000000000000L)
	{
		kr = kr + (retard % 256);
		retard++;
		kr = kr % 1000000000;
	}
	kr = 0;
	long long moreRetard = 0;
	while (moreRetard < 100000000055000L)
	{
		moreRetard++;
		kr += (moreRetard % 256);
		if (kr > 1000000000L)
			kr = kr % 256;
	}
	counter = counter + 0.0001f;
	for (int i = 0; x < sw; i++)
		x = i;
}



void Game::ComposeFrame()
{
	long long moreRetard = 0;
	long long retard = 0;
	for (y = 0; y < sh; y++)
	{
		gfx.PutPixel( x,y, r, g, b);
		int kr = 0;
		while (retard < 10000000000000L)
		{		
			kr = kr + (retard % 256);
			retard++;
			kr = kr % 1000000000;
		}
			
	}
	int kr = 0;
	while (moreRetard < 100000000055000L)
	{
		moreRetard++;
		kr += (moreRetard % 256);
		if (kr > 1000000000L)
			kr = kr % 256;
	}
	counter = counter + 0.0001f;
}

