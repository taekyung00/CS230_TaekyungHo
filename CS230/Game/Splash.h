/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  Splash.h
Project:    CS230 Engine
Author:     Taekyung Ho
Created:    March 12, 2025
*/

#pragma once
#include "../Engine/GameState.h"

class Splash : public CS230::GameState {
public:
    Splash();
    void Load() override;
    void Update() override;
    void Unload() override;

    std::string GetName() override {
        return "Splash";
    }

public:
    int counter = 0;
};
