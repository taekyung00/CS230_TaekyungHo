/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  Engine.h
Project:    CS230 Engine
Author:     Taekyung Ho
Created:    March 11, 2025
*/
#pragma once
#include "Logger.h"
#include "Window.h"
#include "GameStateManager.h"

//don't use CS230 namespace to get access to engine globally..????even if use namespace, ....
class Engine {
public:
    static Engine& Instance() {
        static Engine instance;
        return instance; //why we have to keep track of "instance" ???
    }

    static CS230::Logger& GetLogger() {
        return Instance().logger; //why Instance.logger, not just logger?
    }

    static CS230::Window& GetWindow() {
        return Instance().window;
    }

    static CS230::GameStateManager& GetGameStateManager() {
        return Instance().gamestatemanager;
    }

    void Start(std::string window_title);
    void Stop();
    void Update();

    bool HasGameEnded();

private:
    Engine();

    CS230::Logger logger;
    CS230::Window window;
    CS230::GameStateManager gamestatemanager;
};
