#ifndef SCENE_H
#define SCENE_H

#include "ac_engine.h"

class Scene
{
public:
   virtual ~Scene() {}

   virtual void Init() = 0;
   virtual void HandleEvents(SDL_Event& event) = 0;
   virtual void Update(float deltaTime) = 0;
   virtual void Render(SDL_Renderer* renderer = ac_engine::GetInstance()->GetRenderer()) = 0;
   virtual void Clean() = 0;
};

#endif SCENE_H