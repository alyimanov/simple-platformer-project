#ifndef GLOBALS_H
#define GLOBALS_H

#include "raylib.h"

#include <string>
#include <cstddef>
#include <cmath>

/* Game Elements */

const char WALL   = '#';
const char AIR    = ' ';
const char PLAYER = '@';
const char COIN   = '*';
const char EXIT   = 'E';
const char JUMP_BOOST_POTION = 'J';
const char SPIKES = '1';
const char SKELETON = 'S';
const char SWORD = '+';
const char LEVER1 = '4';
const char LEVER2 = '5';
const char LEVER3 = '6';
const char GRAAL = 'G';
const char DOOR = 'D';

/* Levels */

struct level {
    size_t rows = 0, columns = 0;
    char *data = nullptr;
};

char LEVEL_1_DATA[] = {
    '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#',
    '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#',
    '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#',
    '#', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', '#',
    '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#',
    '#', ' ', '@', ' ', ' ', ' ', ' ', ' ', 'E', ' ', '#',
    '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'
};

level LEVEL_1 = {
    7, 11,
    LEVEL_1_DATA
};

char LEVEL_2_DATA[] = {
    '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#',
    '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#',
    '#', ' ', '#', ' ', ' ', '#', '#', '#', '#', ' ', '#',
    '#', ' ', '#', ' ', ' ', '*', '*', '#', ' ', ' ', '#',
    '#', ' ', '#', ' ', ' ', ' ', ' ', '#', ' ', ' ', '#',
    '#', '@', '#', ' ', ' ', ' ', ' ', '#', 'E', ' ', '#',
    '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'
};

level LEVEL_2 = {
    7, 11,
    LEVEL_2_DATA
};

char LEVEL_3_DATA[] = {
    '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#',
    '#', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', 'E', '#',
    '#', '*', ' ', ' ', ' ', ' ', '*', ' ', '#', '#', '#',
    '#', '#', ' ', ' ', ' ', '*', ' ', '#', '#', '#', '#',
    '#', ' ', ' ', ' ', ' ', ' ', '#', '#', '#', '#', '#',
    '#', '@', ' ', ' ', ' ', '#', '#', '#', '#', '#', '#',
    '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'
};

level LEVEL_3 = {
    7, 11,
    LEVEL_3_DATA
};

char LEVEL_4_DATA[] = {
    '#', '#', '#', '#', '#', '#',
    '#', ' ', ' ', ' ', 'E', '#',
    '#', ' ', ' ', ' ', '#', '#',
    '#', ' ', ' ', ' ', ' ', '#',
    '#', ' ', ' ', ' ', ' ', '#',
    '#', ' ', ' ', ' ', ' ', '#',
    '#', '#', ' ', ' ', ' ', '#',
    '#', ' ', ' ', ' ', '#', '#',
    '#', ' ', ' ', ' ', ' ', '#',
    '#', ' ', ' ', ' ', ' ', '#',
    '#', '@', ' ', ' ', '*', '#',
    '#', '#', '#', '#', '#', '#',
};

level LEVEL_4 = {
    12, 6,
    LEVEL_4_DATA
};

char LEVEL_5_DATA[] = {
    '#', '#', '#', '#', '#', '#', '#','#', '#', '#', '#', '#', '#',
    '#', '#', '#', ' ', ' ', ' ', ' ',' ', ' ', ' ', ' ', ' ', '#',
    '#', '#', ' ', ' ', ' ', '#', '#','#', '#', '#', '#', ' ', '#',
    '#', ' ', ' ', ' ', ' ', '#', ' ',' ', ' ', ' ', ' ', ' ', '#',
    '#', ' ', ' ', ' ', ' ', '#', ' ',' ', ' ', ' ', ' ', ' ', '#',
    '#', ' ', ' ', ' ', ' ', '#', ' ','#', '#', '#', '#', '#', '#',
    '#', '@', ' ', ' ', ' ', '#', ' ',' ', ' ', ' ', ' ', ' ', '#',
    '#', '#', '#', '#', ' ', '#', ' ',' ', ' ', ' ', ' ', ' ', '#',
    '#', '#', ' ', ' ', ' ', '#', '#','#', '#', '#', '#', ' ', '#',
    '#', ' ', ' ', ' ', ' ', '#', ' ',' ', ' ', ' ', ' ', ' ', '#',
    '#', 'J', ' ', ' ', '*', '#', 'E',' ', ' ', ' ', ' ', ' ', '#',
    '#', '#', '#', '#', '#', '#', '#','#', '#', '#', '#', '#', '#',
};

level LEVEL_5 = {
    12, 13,
    LEVEL_5_DATA
};

char LEVEL_6_DATA[] = {
    '#', '#', '#', '#', '#', '#','#', '#', '#', '#', '#', '#',
    '#', 'E', ' ', ' ', ' ', ' ',' ', ' ', ' ', ' ', ' ', '#',
    '#', '#', '#', '#', '#', '#','#', '#', '#', '#', ' ', '#',
    '#', '#', '#', ' ', ' ', ' ',' ', ' ', ' ', ' ', ' ', '#',
    '#', '#', ' ', ' ', ' ', ' ',' ', ' ', ' ', '*', ' ', '#',
    '#', ' ', ' ', ' ', ' ', ' ',' ', ' ', ' ', '#', '#', '#',
    '#', ' ', ' ', ' ', ' ', ' ',' ', '#', ' ', '#', '#', '#',
    '#', ' ', ' ', ' ', ' ', '#',' ', ' ', ' ', '#', '#', '#',
    '#', ' ', ' ', '#', ' ', ' ',' ', ' ', ' ', '#', '#', '#',
    '#', ' ', ' ', '#', ' ', ' ',' ', ' ', ' ', '#', '#', '#',
    '#', '@', ' ', '#', '1', '1','1', '1', '1', '#', '#', '#',
    '#', '#', '#', '#', '#', '#','#', '#', '#', '#', '#', '#',
};

level LEVEL_6 = {
    12, 12,
    LEVEL_6_DATA
};

char LEVEL_7_DATA[] = {
    '#', '#', '#', '#', '#', '#','#', '#', '#', '#', '#', '#',
    '#', ' ', ' ', ' ', ' ', ' ',' ', ' ', ' ', ' ', ' ', '#',
    '#', '@', ' ', ' ', ' ', ' ',' ', ' ', ' ', ' ', ' ', '#',
    '#', '#', '#', '#', '#', '#','#', '#', '#', '#', ' ', '#',
    '#', '#', '*', ' ', ' ', ' ',' ', ' ', ' ', ' ', ' ', '#',
    '#', '#', '+', ' ', ' ', ' ',' ', ' ', ' ', ' ', ' ', '#',
    '#', '#', '#', ' ', ' ', '#',' ', ' ', '#', ' ', ' ', '#',
    '#', ' ', '#', ' ', ' ', ' ',' ', ' ', ' ', ' ', ' ', '#',
    '#', ' ', '#', ' ', ' ', ' ',' ', ' ', ' ', ' ', ' ', '#',
    '#', ' ', '#', ' ', ' ', ' ',' ', ' ', ' ', ' ', '#', '#',
    '#', 'E', 'S', ' ', ' ', ' ',' ', ' ', ' ', '#', '#', '#',
    '#', '#', '#', '#', '#', '#','#', '#', '#', '#', '#', '#',
};

level LEVEL_7 = {
    12, 12,
    LEVEL_7_DATA
};

char LEVEL_8_DATA[] = {
    '#', '#', '#', '#', '#', '#','#', '#', '#', '#', '#', '#', '#', '#', '#', '#',
    '#', '#', '#', ' ', ' ', ' ',' ', ' ', ' ', 'D', ' ', ' ', ' ', ' ', ' ', '#',
    '#', '#', ' ', ' ', ' ', ' ',' ', ' ', ' ', '#', '#', '#', ' ', ' ', ' ', '#',
    '#', ' ', ' ', ' ', ' ', ' ',' ', ' ', '#', '#', '#', '#', ' ', ' ', '6', '#',
    '#', ' ', ' ', 'G', ' ', ' ',' ', '#', '#', ' ', ' ', '#', ' ', ' ', '#', '#',
    '#', 'E', ' ', '#', ' ', ' ','#', '#', ' ', ' ', '5', '#', '#', ' ', ' ', '#',
    '#', '#', '#', '#', '#', '#','#', '#', ' ', ' ', '#', '#', ' ', ' ', ' ', '#',
    '#', ' ', ' ', ' ', ' ', ' ',' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#',
    '#', ' ', ' ', ' ', ' ', ' ',' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', '#',
    '#', ' ', ' ', ' ', '#', ' ',' ', ' ', ' ', '#', '#', '#', ' ', ' ', '#', '#',
    '#', '4', '#', '1', '#', '1','#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '@', '#',
    '#', '#', '#', '#', '#', '#','#', '#', '#', '#', '#', '#', '#', '#', '#', '#',
};

level LEVEL_8 = {
    12, 16,
    LEVEL_8_DATA
};

int level_index = 0;
const int LEVEL_COUNT = 8;

level LEVELS[LEVEL_COUNT] = {
    LEVEL_1,
    LEVEL_2,
    LEVEL_3,
    LEVEL_4,
    LEVEL_5,
    LEVEL_6,
    LEVEL_7,
    LEVEL_8
};
/* Loaded Level Data */

level current_level;
char *current_level_data;

/* Player data */

const float GRAVITY_FORCE = 0.01f;
float JUMP_STRENGTH = 0.3f;
const float MOVEMENT_SPEED = 0.1f;

Vector2 player_pos;
float player_y_velocity = 0;

bool is_player_on_ground;
bool is_sword_picked = false;
bool lever_activation1 = false;
bool lever_activation2 = false;
bool lever_activation3 = false;
bool is_door_open = false;

int player_score = 0;

/* Graphic Metrics */

const float CELL_SCALE = 0.8f; // An aesthetic parameter to add some negative space around level
const float SCREEN_SCALE_DIVISOR = 700.0f; // The divisor was found through experimentation
                                           // to scale things accordingly to look pleasant.

Vector2 screen_size;
float screen_scale; // Used to scale str/UI components size and displacements based on the screen_size size
float cell_size;
Vector2 shift_to_center;

/* Fonts */

Font menu_font;

/* Display Text Parameters */

struct Text {
    std::string str;
    Vector2 position = { 0.50f, 0.50f };
    float size = 32.0f;
    Color color = WHITE;
    float spacing = 4.0f;
    Font* font = &menu_font;
};

Text game_title = {
    "Platformer",
    { 0.50f, 0.50f },
    100.0f,
    RED
};

Text game_subtitle = {
    "Press Enter to Start\n\n"
    "Collect every coin\n\nto finish the game",
    { 0.50f, 0.65f }
};

Text game_paused = {
    "Press Escape to Resume. \n\n"
    "Press E to exit game"
};

Text game_paused_for_hint = {
    "Find three hidden levers\n\n"
    "Press F to pull lever.\n\n"
    "Press Escape to Resume"
};


Text defeat_title = {
    "Game Over.\n\n"
    "Press Enter to return to Menu"
};

Text victory_title = {
    "You Won!",
    { 0.50f, 0.50f },
    100.0f,
    RED
};

Text victory_subtitle = {
    "Press Enter to go back to menu",
    { 0.50f, 0.65f }
};

/* Images and Sprites */

Texture2D wall_image;
Texture2D air_image;
Texture2D exit_image;
Texture2D jump_boost_potion_image;
Texture2D spikes_image;
Texture2D skeleton_image;
Texture2D sword_image;
Texture2D lever_unactivated_image;
Texture2D lever_activated_image;
Texture2D graal_image;
Texture2D door_image;

struct sprite {
    size_t frame_count    = 0;
    size_t frames_to_skip = 3;
    size_t frames_skipped = 0;
    size_t frame_index    = 0;
    bool loop = true;
    size_t prev_game_frame = 0;
    Texture2D *frames = nullptr;
};

sprite coin_sprite;
sprite player_sprite;

/* Sounds */

Sound coin_sound;
Sound exit_sound;
Sound potion_sound;
Sound sword_sound;
Sound defeat_sound;
Sound skeleton_death_sound;
Sound lever_sound;
Sound graal_sound;
Sound door_sound;

/* Music*/

Music ost;

/* Victory Menu Background */

struct victory_ball {
    float x, y;
    float dx, dy;
    float radius;
};

const size_t VICTORY_BALL_COUNT     = 2000;
const float VICTORY_BALL_MAX_SPEED  = 2.0f;
const float VICTORY_BALL_MIN_RADIUS = 2.0f;
const float VICTORY_BALL_MAX_RADIUS = 3.0f;
const Color VICTORY_BALL_COLOR      = { 180, 180, 180, 255 };
const unsigned char VICTORY_BALL_TRAIL_TRANSPARENCY = 100;
victory_ball victory_balls[VICTORY_BALL_COUNT];

/* Frame Counter */

size_t game_frame = 0;

/* Game States */

enum game_state {
    MENU_STATE,
    GAME_STATE,
    PAUSE_STATE,
    VICTORY_STATE,
    DEFEAT_STATE,
    HINT_STATE
};
game_state game_state = MENU_STATE;

/* Forward Declarations */

// GRAPHICS_H

void draw_text(Text &text);
void derive_graphics_metrics_from_loaded_level();
void draw_menu();
void draw_game_overlay();
void draw_level();
void draw_player();
void draw_pause_menu();
void create_victory_menu_background();
void animate_victory_menu_background();
void draw_victory_menu_background();
void draw_victory_menu();

// LEVEL_H

bool is_colliding(Vector2 pos, char look_for = '#', level &level = current_level);
char& get_collider(Vector2 pos, char look_for, level &level = current_level);

void load_level(int offset = 0);
void unload_level();

// PLAYER_H

void spawn_player();
void move_player_horizontally(float delta);
void update_player();

// ASSETS_H

void load_fonts();
void unload_fonts();

void load_images();
void unload_images();

void draw_image(Texture2D image, Vector2 pos, float width, float height);
void draw_image(Texture2D image, Vector2 pos, float size);

sprite load_sprite(
    const std::string &file_name_prefix,
    const std::string &file_name_suffix,
    size_t frame_count = 1,
    bool loop = true,
    size_t frames_to_skip = 3
);
void unload_sprite(sprite &sprite);
void draw_sprite(sprite &sprite, Vector2 pos, float width, float height);
void draw_sprite(sprite &sprite, Vector2 pos, float size);

void load_sounds();
void unload_sounds();

void load_music();
void unload_music();

// UTILITIES_H

float rand_from_to(float from, float to);
float rand_up_to(float to);

#endif // GLOBALS_H