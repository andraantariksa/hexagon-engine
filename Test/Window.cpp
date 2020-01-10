#pragma once

#include <Source/Engine/Window/Window.hpp>
#include <gtest/gtest.h>

namespace {

  TEST(Window, WindowSize)
  {
      Hx::Window::Window window = Hx::Window::Window::Builder()
      .SetSize(1280, 720)
      .Build();
      EXPECT_EQ(720, window.GetHeight());
      EXPECT_EQ(1280, window.GetWidth());
  }

}