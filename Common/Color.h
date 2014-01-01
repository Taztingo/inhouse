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
 * Color header file.
 *
 */

#ifndef COLOR_H_
#define COLOR_H_

#include "../String/String.h"

namespace inhouse
{
	namespace Color
	{
		static const String _blackText = "30m";
		static const String _redText = "31m";
		static const String _greenText = "32m";
		static const String _yellowText = "33m";
		static const String _blueText = "34m";
		static const String _purpleText = "35m";
		static const String _cyanText = "36m";
		static const String _whiteText = "37m";
		static const String _startColor = "\033[";
		static const String _defaultText = "0m";
		static const String HIGHLIGHT = "7;";

		String colorText(String text, String color);
	}
}

#endif
