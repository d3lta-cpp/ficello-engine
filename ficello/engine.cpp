#include "engine.hpp"

ficello::engine::engine() : window_{}
{
	window_.setReponseToEvent(SDL_WINDOWEVENT_CLOSE, { [this](SDL_WindowEvent) {
		isAppRunning_ = false;
		} });
}

bool ficello::engine::gameLoop(std::chrono::microseconds)
{
	proceedEvent();
	return isAppRunning_;
}

void ficello::engine::proceedEvent()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_WINDOWEVENT:
			window_.proceedAWindowEvent(event.window);
		default:
			break;
		}
	}
}




void ficello::engine::run()
{
	auto start = std::chrono::high_resolution_clock::now();
	auto end = std::chrono::high_resolution_clock::now();
	do {
		end = start;
		start = std::chrono::high_resolution_clock::now();
	} while (gameLoop(std::chrono::duration_cast<std::chrono::microseconds>(end - start)));
}
