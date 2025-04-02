#include "Engine.hpp"
#include <chrono>

// complete header file for start initializing, something like..
/*
GameEngine::GameEngine()
    : isRunning(false)
    , fixedTimeStep(1.0f / 60.0f){
}
*/

void GameEngine::Initialize() {
    // physicsSystem = new PhysicsSystem();
    physicsSystem = std::make_unique<PhysicsSystem>();
    timeSystem = std::make_unique<TimeSystem>();
    // renderSystem
    isRunning = true;
}

void GameEngine::Run() {
    auto lastTime = std::chrono::high_resolution_clock::now();
    float accumulator = 0.0f;

    // loop while running to move player through 3D space + time
}

template<typename T, typename... Args>
T* GameEngine::CreateGameObeject(Args&&... args) {
    auto gameObject = std::make_unique<T>(std::forward<Args>(args)...);
    T* ptr = gameObject.get();
    gameObjects.push_back(std::move(gameObject));
    return ptr;
}