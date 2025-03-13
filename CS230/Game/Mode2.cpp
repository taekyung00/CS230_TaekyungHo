/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  Mode1.cpp
Project:    CS230 Engine
Author:     Taekyung Ho
Created:    March 12, 2025
*/
#include "../Engine/Engine.h"
#include "States.h"
#include "Mode2.h"

Mode2::Mode2() {

}

void Mode2::Load() {
}

void Mode2::Update() {
    if (IsKeyPressed(KEY_TWO)) {
        Engine::GetGameStateManager().ClearNextGameState();
        //Engine::GetGameStateManager().SetNextGameState(static_cast<int>(States::Mode2));
    }
}

void Mode2::Unload() {

}