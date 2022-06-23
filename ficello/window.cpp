#include "window.hpp"
#include <utility>

ficello::window::window(std::string title, int x, int y, int w, int h, uint32_t flags)
{
	window_ = SDL_CreateWindow(title.c_str(), x, y, w, h, flags);
	if (window_ == nullptr) throw std::runtime_error({ "failed to create a window: ", SDL_GetError()});
}

ficello::window::window(window&& win) noexcept
{
	*this = std::forward<window>(win);
}

void ficello::window::operator=(window&& win) noexcept
{
	window_ = win.window_;
	win.window_ = nullptr;
}

ficello::window::~window() noexcept
{
	if (window_ != nullptr) SDL_DestroyWindow(window_);
}

const SDL_Window* ficello::window::getSdlHandle()
{
	return window_;
}

void ficello::window::proceedAWindowEvent(SDL_WindowEvent windowEvent)
{
	//assert(event.type == SDL_WINDOWEVENT && "ficello::window can only proceed window Event");
	if (SDL_GetWindowID(window_) != windowEvent.windowID) return; //check if it concerne this window
	if (reponseToEvent_.contains(windowEvent.event)) reponseToEvent_[windowEvent.event](windowEvent);
}

void ficello::window::setReponseToEvent(Uint8 eventName, std::function<void(SDL_WindowEvent)> reponse)
{
	reponseToEvent_[eventName] = reponse;
}
