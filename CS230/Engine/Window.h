/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  Window.h
Project:    CS230 Engine
Author:     Taekyung Ho
Created:    March 11, 2025
*/

#pragma once
#include <string>
#include <raylib.h>
#include <rlgl.h>

namespace CS230 {
    class Window {
    public:
        void Start(std::string title);
        void Update();
        bool IsClosed() const;

    private:
        static constexpr int default_width = 800;
        static constexpr int default_height = 600;
    };
}
