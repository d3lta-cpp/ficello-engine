#pragma once
#include "logsStream.hpp"
#include "window.hpp"
#include <entt/entt.hpp>
#include <stdexcept>
#include <chrono>

//engine object

namespace ficello
{
	class engine
	{
		ficello::window window_;
		entt::registry globalRegistry_{};
		bool isAppRunning_ = true;
		bool gameLoop(std::chrono::microseconds);
		void proceedEvent();

	public:

		//specify ctors, dtor and assignement :
		//disable copy of the engine
		engine();
		engine(engine&) = delete;
		engine(engine&&) = default;
		void operator=(engine&) = delete;
		virtual ~engine() = default; //in case of herited classes of engine 

		//methodes
		void run();
	};
}
