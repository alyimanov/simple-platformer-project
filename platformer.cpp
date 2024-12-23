#include "raylib.h"

#include "globals.h"
#include "level.h"
#include "player.h"
#include "graphics.h"
#include "assets.h"
#include "utilities.h"

void update_game() {
    game_frame++;

    switch (game_state) {
        case MENU_STATE:
            if (IsKeyPressed(KEY_ENTER)) {
                level_index = 0;
                player_score = 0;
                game_state = GAME_STATE;
                spawn_player();
            }

            break;
        case GAME_STATE:
            if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) {
                move_player_horizontally(MOVEMENT_SPEED);
            }

            if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) {
                move_player_horizontally(-MOVEMENT_SPEED);
            }

            // Calculating collisions to decide whether the player is allowed to jump: don't want them to suction cup to the ceiling or jump midair
            is_player_on_ground = is_colliding({player_pos.x, player_pos.y + 0.1f}, WALL);
            if ((IsKeyDown(KEY_UP) || IsKeyDown(KEY_W) || IsKeyDown(KEY_SPACE)) && is_player_on_ground) {
                player_y_velocity = -JUMP_STRENGTH;
            }

            update_player();

            if (IsKeyPressed(KEY_ESCAPE) && level_index == 7) {
                game_state = HINT_STATE;
            }
            else if (IsKeyPressed(KEY_ESCAPE)) {
                game_state = PAUSE_STATE;
            }
            if (IsKeyPressed(KEY_NINE)) {
                game_state = VICTORY_STATE;
                create_victory_menu_background();
            }
            break;
        case PAUSE_STATE:
            if (IsKeyPressed(KEY_ESCAPE)) {
                game_state = GAME_STATE;
            }
            break;
        case HINT_STATE:
            if (IsKeyPressed(KEY_ESCAPE)) {
                game_state = GAME_STATE;
            }
        case VICTORY_STATE:
            if (IsKeyPressed(KEY_ENTER)) {
                game_state = MENU_STATE;
            }
            break;
        case DEFEAT_STATE:
            if (IsKeyPressed(KEY_ENTER)) {
                level_index = 0;
                load_level();
                game_state = MENU_STATE;
            }
        break;
    }
}

void draw_game() {
    switch (game_state) {
        case MENU_STATE:
            ClearBackground(BLACK);
            draw_menu();
            break;
        case GAME_STATE:
            ClearBackground(BLACK);
            draw_level();
            draw_game_overlay();
            break;
        case PAUSE_STATE:
            ClearBackground(BLACK);
            draw_pause_menu();
            break;
        case VICTORY_STATE:
            ClearBackground(BLACK);
            draw_victory_menu();
            break;
        case DEFEAT_STATE:
            ClearBackground(BLACK);
            draw_defeat_screen();
            break;
        case HINT_STATE:
            ClearBackground(BLACK);
            draw_pause_hint_menu();
            break;
    }
}

int main() {
    InitWindow(1024, 480, "Platformer");
    InitAudioDevice();
    SetTargetFPS(60);
    SetMasterVolume(0.1);
    SetMusicVolume(ost, 0.4f);

    load_fonts();
    load_images();
    load_sounds();
    load_level();
    load_music();

    SetExitKey(KEY_E);

    while (!WindowShouldClose()) {
        UpdateMusicStream(ost);
        PlayMusicStream(ost);

        BeginDrawing();

        update_game();
        draw_game();

        EndDrawing();
    }

    unload_level();
    unload_sounds();
    unload_images();
    unload_fonts();
    unload_music();

    CloseAudioDevice();
    CloseWindow();

    return 0;
}
