/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  Engine.cpp
Project:    CS230 Engine
Author:     Taekyung Ho
Created:    March 11, 2025
*/

#include "Engine.h"

Engine::Engine() :
#ifdef _DEBUG
    logger(CS230::Logger::Severity::Debug, true)
#else
    logger(CS230::Logger::Severity::Event, false)
#endif
{}

void Engine::Start(std::string window_title) {
    logger.LogEvent("Engine Started"); //why use logevent? --> we can use this either severity is debug or severity is event, and it is just important event..
    window.Start(window_title);
    //Start other services
}

void Engine::Stop() {
    //Stop all services
    logger.LogEvent("Engine Stopped");
}

void Engine::Update() {
    logger.LogVerbose("Engine Update");
    gamestatemanager.Update();
    window.Update();
    //Update other services
}

bool Engine::HasGameEnded()
{
    if (gamestatemanager.HasGameEnded() == true || window.IsClosed() == true) {
        return true;
    }
    else {
        return false;
    }
    
}
