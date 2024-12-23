#ifndef IMAGES_H
#define IMAGES_H

#include "raylib.h"
#include "globals.h"

#include <string>
#include <cassert>

void load_fonts() {
    menu_font = LoadFontEx("data/fonts/ARCADE_N.ttf", 256, nullptr, 128);
}

void unload_fonts() {
    UnloadFont(menu_font);
}

void load_images() {
    wall_image    = LoadTexture("data/images/wall.png");
    air_image     = LoadTexture("data/images/air.png");
    exit_image    = LoadTexture("data/images/exit.png");
    coin_sprite   = load_sprite("data/images/coin/coin",     ".png", 3, true, 18);
    player_sprite = load_sprite("data/images/player/player", ".png", 3, true, 10);
    jump_boost_potion_image = LoadTexture("data/images/jump_boost_potion.png");
    spikes_image  = LoadTexture("data/images/spikes.png");
    skeleton_image = LoadTexture("data/images/skeleton0.png");
    sword_image   = LoadTexture("data/images/sword.png");
    lever_unactivated_image = LoadTexture("data/images/lever_unactivated.png");
    lever_activated_image = LoadTexture("data/images/lever_activated.png");
    graal_image = LoadTexture("data/images/graal.png");
    door_image = LoadTexture("data/images/door.png");
}

void unload_images() {
    UnloadTexture(wall_image);
    UnloadTexture(air_image);
    UnloadTexture(exit_image);
    UnloadTexture(jump_boost_potion_image);
    UnloadTexture(spikes_image);
    UnloadTexture(skeleton_image);
    UnloadTexture(sword_image);
    UnloadTexture(lever_unactivated_image);
    UnloadTexture(lever_activated_image);
    UnloadTexture(graal_image);
    UnloadTexture(door_image);
    unload_sprite(player_sprite);
    unload_sprite(coin_sprite);
}

void draw_image(Texture2D image, Vector2 pos, float size) {
    draw_image(image, pos, size, size);
}

void draw_image(Texture2D image, Vector2 pos, float width, float height) {
    Rectangle source = { 0.0f, 0.0f, static_cast<float>(image.width), static_cast<float>(image.height) };
    Rectangle destination = { pos.x, pos.y, width, height };
    DrawTexturePro(image, source, destination, { 0.0f, 0.0f }, 0.0f, WHITE);
}

sprite load_sprite(
    const std::string &file_name_prefix,
    const std::string &file_name_suffix,
    size_t frame_count,
    bool loop,
    size_t frames_to_skip
) {
    assert(frame_count < 100);

    sprite result = {
        frame_count, frames_to_skip, 0, 0, loop, 0, new Texture2D[frame_count]
    };

    for (size_t i = 0; i < frame_count; ++i) {
        std::string file_name;
        if (frame_count < 10) {
            file_name = file_name_prefix;
            file_name += std::to_string(i);
            file_name += file_name_suffix;
        } else {
            file_name = file_name_prefix;
            file_name += i < 10 ? ("0" + std::to_string(i)) : std::to_string(i);
            file_name += file_name_suffix;
        }
        result.frames[i] = LoadTexture(file_name.c_str());
    }

    return result;
}

void unload_sprite(sprite &sprite) {
    assert(sprite.frames != nullptr);

    for (size_t i = 0; i < sprite.frame_count; ++i) {
        UnloadTexture(sprite.frames[i]);
    }
    delete[] sprite.frames;
    sprite.frames = nullptr;
}

void draw_sprite(sprite &sprite, Vector2 pos, float size) {
    draw_sprite(sprite, pos, size, size);
}

void draw_sprite(sprite &sprite, Vector2 pos, float width, float height) {
    draw_image(sprite.frames[sprite.frame_index], pos, width, height);

    if (sprite.prev_game_frame == game_frame) {
        return;
    }
    if (sprite.frames_skipped < sprite.frames_to_skip) {
        ++sprite.frames_skipped;
    } else {
        sprite.frames_skipped = 0;

        ++sprite.frame_index;
        if (sprite.frame_index >= sprite.frame_count) {
            sprite.frame_index = sprite.loop ? 0 : sprite.frame_count - 1;
        }
    }
    sprite.prev_game_frame = game_frame;
}

void load_sounds() {
    coin_sound = LoadSound("data/sounds/coin.wav");
    exit_sound = LoadSound("data/sounds/exit.wav");
    potion_sound = LoadSound("data/sounds/potion_sound.mp3");
    sword_sound = LoadSound("data/sounds/sword.mp3");
    defeat_sound = LoadSound("data/sounds/defeat.mp3");
    skeleton_death_sound = LoadSound("data/sounds/skeleton_death.mp3");
    lever_sound = LoadSound("data/sounds/lever.mp3");
    graal_sound = LoadSound("data/sounds/graal_acquired.mp3");
    door_sound = LoadSound("data/sounds/door_opening.mp3");
}

void load_music() {
    ost = LoadMusicStream("data/sounds/ost.mp3");
}

void unload_sounds() {
    UnloadSound(coin_sound);
    UnloadSound(exit_sound);
}

void unload_music() {
    UnloadMusicStream(ost);
}

#endif // IMAGES_H
