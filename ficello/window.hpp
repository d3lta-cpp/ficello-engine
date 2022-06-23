#pragma once
#include <SDL2/SDL.h>
#include <assert.h>
#include <string>
#include <stdexcept>
#include <unordered_map>
#include <functional>

namespace ficello
{
	//a basic C++ warpper around SDL_window
	class window
	{
		SDL_Window* window_;
		std::unordered_map<Uint8, std::function<void(SDL_WindowEvent)>> reponseToEvent_;

	public:
		//ctors and dtors
		window(std::string title = "Default ficello Window", int x = SDL_WINDOWPOS_CENTERED, int y = SDL_WINDOWPOS_CENTERED, int w = 800, int h = 600, uint32_t flags = 0);
		window(window&) = delete;
		window(window&& win) noexcept;
		void operator=(window&) = delete;
		void operator=(window&& win) noexcept;
		virtual ~window() noexcept;
		
		//getters
		const SDL_Window* getSdlHandle();
		void proceedAWindowEvent(SDL_WindowEvent windowEvent);
		void setReponseToEvent(Uint8 eventName, std::function<void(SDL_WindowEvent)> reponse);
	};
}