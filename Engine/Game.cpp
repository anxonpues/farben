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
	counter( 0.0f ),
	frames_per_mode(800.0f),
	pi( 3.141596f )
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
			{
				int val = (int)counter;
				int mode = val % 12;
				switch (mode)
				{
				case  0:
				{ {
						// red steady high, green steasy low, blue step down  MAGENTA to RED
						r = 255;
						g = 0;
						b = 256 - (val % 256);
						break;
					}
				case  1:
				{
					// red steady high, green steasy low, blue steady low RED
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

				};
				case  3:
				{
					// red steady high, green steady high, blue steady low YELLOW
					r = 255;
					g = 255;
					b = 0;
					break;
				};
				case  4:
				{
					// red step down, green steady high, blue steady low YELLOW to GREEN
					r = 256 - (val % 256);
					g = 255;
					b = 0;
					break;
				};
				case  5:
				{
					// red steady low, green steady high, blue steady low  GREEN
					r = 0;
					g = 255;
					b = 0;
					break;
				};
				case  6:
				{
					// red steady low, green steady high, blue step up  GREEN to CYAN
					r = 0;
					g = 255;
					b = val % 256;
					break;
				};
				case  7:
				{
					// red steady low, green steady high, blue steady high  CYAN
					r = 0;
					g = 255;
					b = 255;
					break;
				};
				case  8:
				{
					// red steady low, green step down, blue steady low  CYAN to BLUE
					r = 0;
					g = 256 - (val % 256);
					b = 255;
					break;
				};
				case 9:
				{
					// red steady low, green steady low, blue steady high  BLUE
					r = 0;
					g = 0;
					b = 255;
					break;
				};
				case 10:
				{
					// red step up, green steady low, blue steady high BLUE to  MAGENTA
					r = val % 256;
					g = 0;
					b = 255;
					break;
				};
				default:
				}
				{

					break;
				}

				}
			}
			gfx.PutPixel(i,j,r,g,b);
		}
		counter = counter + 0.003f ;
		/*
		  r = (int)((std::sin((counter+0.0f)   / frames_per_mode )+1.3f) * 255.0f);
		  g = (int)((std::sin((counter+pi/2)   / frames_per_mode )+1.3f) * 255.0f);
		  b = (int)((std::sin((counter+3*pi/2) / frames_per_mode )+1.3f) * 255.0f);  
		*/

		// need to make 4 different states cor each primary colour, steady high, step down
		// steady low and step up. As have three primary colors it means 12 main values
		// that looks perfect a mod(val,12) function being val some incrementing integer,
		// related to counter. So for each frame we will start vertical lines with 
		// (x,y,r,g,b) being r,g and b like depending on val % 12, and val = function(counter)
		// that can be as simple as casting val = (int)counter
		// would call val % 12 mode taking values from 0 to 11 un back to 0 cyclicaly.

		
}
