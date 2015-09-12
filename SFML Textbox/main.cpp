
//
// Disclamer:
// ----------
//
// This code will work only if you selected window, graphics and audio.
//
// Note that the "Run Script" build phase will copy the required frameworks
// or dylibs to your application bundle so you can execute it on any OS X
// computer.
//
// Your resource files (images, sounds, fonts, ...) are also copied to your
// application bundle. To get the path to these resource, use the helper
// method resourcePath() from ResourcePath.hpp
//

// Here is a small helper for you ! Have a look.
#include "ResourcePath.hpp"

#include "Textbox.hpp"

int main(int, char const**) {
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");

    // Set the Icon
    sf::Image icon;
    if (!icon.loadFromFile(resourcePath() + "icon.png")) {
        return EXIT_FAILURE;
    }
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    // Create a graphical text to display
    sf::Font font;
    if (!font.loadFromFile(resourcePath() + "sansation.ttf")) {
        return EXIT_FAILURE;
    }
	
	Textbox textbox(window, font);
	textbox.setDimensons(100, 100, 400, 50);
	textbox.setFocus(true);

    // Start the game loop
    while (window.isOpen()) {
        // Process events
        sf::Event event;
        while (window.pollEvent(event)) {
            // Close window: exit
            if(event.type == sf::Event::Closed) {
                window.close();
            }
			bool didHitReturn = textbox.pollEvent(event);
			if(didHitReturn) {
				// do stuff here using textbox.getString()
			}
        }

        // Clear screen
        window.clear();
		
		textbox.draw();

        // Update the window
        window.display();
    }

    return EXIT_SUCCESS;
}
