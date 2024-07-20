#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include <memory>
#include <stack>
#include "Scene.h"

class SceneManager {
public:
    void pushScene(std::unique_ptr<Scene> scene) {
        scenes.push(std::move(scene));
    }

    void popScene() {
        if (!scenes.empty()) {
            scenes.pop();
        }
    }

    void handleEvents(SDL_Event& event) {
        if (!scenes.empty()) {
            scenes.top()->HandleEvents(event);
        }
    }

    void update(float deltaTime) {
        if (!scenes.empty()) {
            scenes.top()->Update(deltaTime);
        }
    }

    void render() {
        if (!scenes.empty()) {
            scenes.top()->Render();
        }
    }

private:
    std::stack<std::unique_ptr<Scene>> scenes;
};

#endif // SCENEMANAGER_H
