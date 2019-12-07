#include "Window/lib.cpp"

int main(int argc, char* argv[]) {
	Window::Window main_window = Window::Window::Builder()
		.SetTitle("Test")
		.SetHeight(300)
		.SetWidth(300)
		.Build();
	return 0;
}