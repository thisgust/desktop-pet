#include <raylib.h>
#include <raymath.h>

#include <iostream>

typedef struct Pet {
	Texture sprite;
	Vector2 velocity;
} pet;

int main() {
	SetConfigFlags(FLAG_WINDOW_UNDECORATED | FLAG_WINDOW_TRANSPARENT);
	InitWindow(64, 64, nullptr);

	pet pet1 = (pet){
		.sprite = LoadTexture("Sprite-0001.png"),
		.velocity = { 0 }
	};

	while(!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(BLANK);
		DrawTexture(pet1.sprite, 0, 0, RAYWHITE);

		Vector2 mousePosInScreen = Vector2Add(GetMousePosition(), GetWindowPosition());
		std::cout << mousePosInScreen.x << " " << mousePosInScreen.y << std::endl;

		if(IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
			SetWindowPosition(mousePosInScreen.x, mousePosInScreen.y);
		}

		if(IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
			SetWindowPosition(GetWindowPosition().x, GetWindowPosition().y);
			pet1.velocity.y = GetWindowPosition().y;
		}

		if(GetWindowPosition().y < GetMonitorHeight(GetCurrentMonitor()) && !IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
			pet1.velocity.y += 1200.0f * GetFrameTime();
			SetWindowPosition(GetWindowPosition().x, pet1.velocity.y);
		} else {
			pet1.velocity.y = 0;
		}
		EndDrawing();
	}

	CloseWindow();
	return 0;
}
