//
//  Textbox.hpp
//  SFML Textbox
//
//  Created by Thomas Redding on 9/12/15.
//  Copyright © 2015 Thomas Redding. All rights reserved.
//

#ifndef Textbox_cpp
#define Textbox_cpp

#include <stdio.h>
#include <iostream>
#include <SFML/Graphics.hpp>

class Textbox {
public:
	Textbox(sf::RenderWindow &windowToUse, sf::Font &fontToUse);
	void setDimensons(double newX, double newY, double newWidth, double newHeight);
	void draw();
	void setString(std::string newString);
	std::string getString();
	bool pollEvent(sf::Event event);
	void setFocus(bool newFocus);
	void setReturnEvent(void (*newFunctionToCall)());
private:
	bool isFocused;
	double x;
	double y;
	double width;
	double height;
	std::string string = "";
	sf::Font &font;
	sf::RenderWindow &window;
	sf::RectangleShape background;
	sf::Text text;
	
	bool enterText(sf::Uint32 unicode);
};

#endif /* Textbox_cpp */
