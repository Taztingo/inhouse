/*
 * CS585
 *
 * Team Bammm
 *  Alvaro Home
 *  Matt Konstantinou
 *  Michael Abramo
 *  Matt Witkowski  
 *  Bradley Crusco
 * Description:
 * Color cpp file.
 *
 */

#include "Color.h"
#include "../String/String.h"

namespace inhouse
{
	namespace Color
	{
		String colorText(String text, String color)
		{
			String selectedColor;

			if (color == "black")
			{
				selectedColor = _blackText;
			}
			else if (color == "red")
			{
				selectedColor = _redText;
			}
			else if (color == "green")
			{
				selectedColor = _greenText;
			}
			else if (color == "yellow")
			{
				selectedColor = _yellowText;
			}
			else if (color == "blue")
			{
				selectedColor = _blueText;
			}
			else if (color == "purple")
			{
				selectedColor = _purpleText;
			}
			else if (color == "cyan")
			{
				selectedColor = _cyanText;
			}
			else if (color == "white")
			{
				selectedColor = _whiteText;
			}
			else
			{
				selectedColor = _defaultText;
			}

			String colorString = _startColor;
			colorString += selectedColor;
			colorString += text;
			colorString += _startColor;
			colorString += _defaultText;

			return colorString;
		}
	}
}
