#include "Window.h"

namespace Eucolus {
    Window::Window(std::string windowName, Vector2f windowPosition, Vector2f windowSize) {
		m_sdlWindow = SDL_CreateWindow(
			windowName.c_str(), 
			(int)windowPosition.m_x,
			(int)windowPosition.m_y,
			(int)windowSize.m_x,
			(int)windowSize.m_y,
			SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
    }

    Window::~Window() {
		SDL_DestroyWindow(m_sdlWindow);
    }

	SDL_Window* Window::GetSDLWindow() {
		return m_sdlWindow;
	}
}