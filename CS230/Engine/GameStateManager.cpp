/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  GameStateManager.cpp
Project:    CS230 Engine
Author:     Taekyung Ho
Created:    March 11, 2025
*/

#include "GameStateManager.h"
#include "Engine.h"

CS230::GameStateManager::GameStateManager() :
    current_gamestate(nullptr),
    next_gamestate(nullptr),
    status(Status::STARTING)
{
}

void CS230::GameStateManager::AddGameState(GameState& gamestate) {
    //Your Code
    gamestates.push_back(&gamestate);
}

void CS230::GameStateManager::SetNextGameState(int index) {
    //Your Code
    next_gamestate = gamestates[index];
}

void CS230::GameStateManager::ReloadState() {
    //Your Code
    status = Status::UNLOADING;
}

void CS230::GameStateManager::ClearNextGameState() {
    //Your Code
    next_gamestate = nullptr;
}

bool CS230::GameStateManager::HasGameEnded() {
    return status == Status::EXIT;
}

void CS230::GameStateManager::Update() {
    switch (status) {
    case Status::STARTING:
        //Your Code
        if (gamestates.size() != 0) {
            next_gamestate = gamestates[0];
            status = Status::LOADING;
        }
        else {
            status = Status::STOPPING;
        }       
        
        break;
    case Status::LOADING:
        current_gamestate = next_gamestate;
        Engine::GetLogger().LogEvent("Load " + current_gamestate->GetName());
        current_gamestate->Load();
        Engine::GetLogger().LogEvent("Load Complete");
        status = Status::UPDATING;
        break;
    case Status::UPDATING:
        //Your Code
        if (current_gamestate != next_gamestate) {
            //do i have to call SetNextGameState() at here?
            status = Status::UNLOADING;
        }
        else {
            Engine::GetLogger().LogVerbose("Update " + current_gamestate->GetName());
            current_gamestate->Update();
        }
        break;
    case Status::UNLOADING:
        //Your Code
        Engine::GetLogger().LogEvent("Unload " + current_gamestate->GetName());
        current_gamestate->Unload();
        Engine::GetLogger().LogEvent("Unload Complete");
        if (next_gamestate == nullptr) {
            status = Status::STOPPING;
        }
        else {
            status = Status::LOADING;
        }
        break;
    case Status::STOPPING:
        //Your Code
        status = Status::EXIT;
        break;
    case Status::EXIT:
        break;
    }
}


