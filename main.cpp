// library
#include <SFML/Graphics.hpp>

// main program
int main()
{
    // create window
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Title");

    // load font
    sf::Font font("C:/Windows/Fonts/arial.ttf");

    // create text
    sf::Text text(font, "Hello There", 100);
    sf::FloatRect bounds = text.getLocalBounds();
    text.setOrigin({bounds.position.x + bounds.size.x/2, text.getCharacterSize()*0.75f});
    text.setPosition({400.f, 300.f});
    text.setOutlineThickness(10.f);
    text.setOutlineColor(sf::Color(0, 170, 255));
    text.setStyle(sf::Text::Italic | sf::Text::Underlined | sf::Text::Bold);

    // while window is still open
    while (window.isOpen())
    {
        // handle events
        while (std::optional event = window.pollEvent())
        {
            // when close button is clicked
            if (event->is<sf::Event::Closed>())
            {
                // close window
                window.close();
            }
            
            // when window is resized
            else if (event->is<sf::Event::Resized>())
            {
                // update view
                window.setView(sf::View(sf::FloatRect({0.f, 0.f}, sf::Vector2f(window.getSize()))));
            }
        }

        // fill window with color
        window.clear(sf::Color(64, 64, 64));

        // draw text
        window.draw(text);

        // display
        window.display();
    }
    
    // program end successfully
    return 0;
}