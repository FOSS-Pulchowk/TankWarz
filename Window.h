#include <string>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Window
{
  public:
	Window();
	Window(const std::string &title, const sf::Vector2u &size);
	~Window();

	void BeginDraw(); //Starts to draw i.e. clear all the other items
	void EndDraw(); //End draw for that frame i.e. display the drawing

	void Update(); //Update the window
	bool Active(); //Check if the current window is active

	bool IsDone(); //check if the window is done to close
	bool IsFullscreen(); //check if the window is full screen
	sf::RenderWindow *GetRenderWindow(); //returns the renderwindow to be used by other classes
	sf::Vector2u GetWindowSize(); //returns the size of window

	void ToggleFullscreen(); //toggles beetween normal mode and fullscreen

	void Draw(sf::Drawable &l_drawable); //draw the given drawable to the screen
	void Destroy(); //sets the m_done to true and move out of the loop

  private:
	void Setup(const std::string title, const sf::Vector2u &size);
	void Create();

	sf::RenderWindow m_window;
	sf::Vector2u m_windowSize;
	std::string m_windowTitle;
	bool m_isDone;
	bool m_isFullscreen;
};