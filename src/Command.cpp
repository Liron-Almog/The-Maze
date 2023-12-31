#include "Command.h"         
#include "GameFont.h"        
#include <chrono>            

// Set the text content and position
//======setText==========
void Command::setText(const string& name, const sf::Vector2i& pos) {
    m_text.setString(name);                
    m_text.setPosition(pos.x, pos.y);
}

//========Constructor========
Command::Command() {

    // Default values
    sf::Color color(197, 179, 88);                
    m_text.setColor(color);                       
    m_text.setFont(GameFont::instance().getFont(TITLE_FONT));  
    m_text.setCharacterSize(55);                  
    m_text.setOutlineThickness(1.5);                
    m_text.setOutlineColor(sf::Color::Black);       
}

// Draw the transition screen
//========drawTransitionScreen========
void Command::drawTransitionScreen(sf::RenderWindow& window) {
    window.clear();                            
    window.draw(m_transitionScreen);            
}

// Sleep for a specified time
//========sleep========
void Command::sleep(const int& time) const {
    std::this_thread::sleep_for(std::chrono::seconds(time));   
}

//========getText========
const sf::Text& Command::getText() const {
    return m_text;                        
}
