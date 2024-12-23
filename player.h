#ifndef PLAYER_H
#define PLAYER_H

#include "globals.h"

void spawn_player() {
    for (size_t row = 0; row < current_level.rows; ++row) {
        for (size_t column = 0; column < current_level.columns; ++column) {
            char cell = current_level.data[row * current_level.columns + column];
            if (cell == PLAYER) {
                player_pos.x = static_cast<float>(column);
                player_pos.y = static_cast<float>(row);
                return;
            }
        }
    }
}

void move_player_horizontally(float delta) {
    float next_x = player_pos.x + delta;
    if (!is_colliding({next_x, player_pos.y}, WALL)) {
        player_pos.x = next_x;
    }
    else {
        player_pos.x = roundf(player_pos.x);
    }
}

void update_player() {
    player_pos.y += player_y_velocity;
    player_y_velocity += GRAVITY_FORCE;

    is_player_on_ground = is_colliding({ player_pos.x, player_pos.y + 0.1f }, WALL);
    if (is_player_on_ground) {
        player_y_velocity = 0;
        player_pos.y = roundf(player_pos.y);
    }

    if (is_colliding(player_pos, COIN)) {
        get_collider(player_pos, COIN) = ' ';
        player_score+=10;
        PlaySound(coin_sound);
    }

    if (is_colliding(player_pos, JUMP_BOOST_POTION)) {
        get_collider(player_pos, JUMP_BOOST_POTION) = ' ';
        JUMP_STRENGTH = 0.34f;
        PlaySound(potion_sound);
    }

    if (is_colliding(player_pos, EXIT)) {
        get_collider(player_pos, EXIT) = ' ';
        JUMP_STRENGTH = 0.3f;
        load_level(1);
        PlaySound(exit_sound);
    }

    if (is_colliding(player_pos, SKELETON)) {
        get_collider(player_pos, SKELETON) = ' ';
        if (is_sword_picked == true) {
            UnloadTexture(skeleton_image);
            player_score += 100;
            PlaySound(skeleton_death_sound);
        }
        else {
            game_state = DEFEAT_STATE;
            PlaySound(defeat_sound);
        }
    }

    if (is_colliding(player_pos, SWORD)) {
        get_collider(player_pos, SWORD) = ' ';
        is_sword_picked = true;
        PlaySound(sword_sound);
    }

    if (is_colliding(player_pos, SPIKES)) {
        game_state = DEFEAT_STATE;
        PlaySound(defeat_sound);
    }

    if (is_colliding(player_pos, LEVER1) && IsKeyPressed(KEY_F)) {
        if (player_score >= 70) {
            player_score -= 70;
            lever_activation1 = true;
            PlaySound(lever_sound);
        }
    }

    if (is_colliding(player_pos, LEVER2) && IsKeyPressed(KEY_F)) {
        if (player_score >= 70) {
            player_score -= 70;
            lever_activation2 = true;
            PlaySound(lever_sound);
        }
    }

    if (is_colliding(player_pos, LEVER3) && IsKeyPressed(KEY_F)) {
        if (player_score >= 70) {
            player_score -= 70;
            lever_activation3 = true;
            PlaySound(lever_sound);
        }
    }

    if (is_colliding(player_pos, GRAAL)) {
        get_collider(player_pos, GRAAL) = ' ';
        player_score+=10000;
        PlaySound(graal_sound);
    }

    if (lever_activation1 == true && lever_activation2 == true && lever_activation3 == true) {
        is_door_open = true;
        PlaySound(door_sound);
    }

    if (is_colliding(player_pos, DOOR) && !is_door_open) {
        player_pos.x = roundf(player_pos.x);
    }
}

#endif // PLAYER_H
