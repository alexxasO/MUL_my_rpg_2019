/*
** EPITECH PROJECT, 2020
** omar.c
** File description:
** salut moi c'est omar voilà mes trucs, contactez moi sur teams
*/

sfRenderWindow *window_create(unsigned int width, unsigned int height)
{
    sfRenderWindow *window;
    sfVideoMode mode = {width, height, 32};

    window = sfRenderWindow_create(mode,"circles", sfResize | sfClose, NULL);
    if (!window)
        return NULL;
    sfRenderWindow_setFramerateLimit(window, 60);
    return window;
}

//initialisations des deux structures

perso_t init_perso(int x, int y, char *filename)
{
    perso_t perso;
    sfTexture *texture = sfTexture_createFromFile(filename, NULL);

    perso.sprite_name = filename;
    perso.sprite = sfSprite_create();
    sfSprite_setTexture(perso.sprite, texture, sfTrue);
    perso.pos.x = x;
    perso.pos.y = y;
    return perso;
}

map_t init_map(int x, int y, char *filename)
{
    map_t map;
    sfTexture *texture = sfTexture_createFromFile(filename, NULL);
    sfImage *image = sfImage_createFromFile("sprites/map_black_and_white.png");

    map.sprite = sfSprite_create();
    map.image = image;
    sfSprite_setTexture(map.sprite, texture, sfTrue);
    map.pos.x = x;
    map.pos.y = y;
    return map;
}

// la boucle display, bien mettre move_event() dans la boucle event
// et bien faire un renderwindowclear avant de mettre display()

void start_pattern()
{
    sfRenderWindow *window = window_create(1920, 1080);
    sfEvent event;
    map_t map = init_map(0, 0, "sprites/map.png");
    perso_t perso = init_perso(500, 500, "sprites/bas.png");

    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
            move_event(window, event, &perso, &map);
        }
        sfRenderWindow_clear(window, sfBlack);
        display(&map, &perso, window);
    }
    sfRenderWindow_destroy(window);
}

// display.c
// display les sprites de mouvements avec position et sprite actualisés a chaque boucle

void map_display(map_t *map, sfRenderWindow *window)
{
    sfSprite_setPosition(map->sprite, map->pos);
    sfRenderWindow_drawSprite(window, map->sprite, NULL);
}

//le scale c'est pour la taille du sprite(garde la pour un max de précision)

void display(map_t *map, perso_t *perso, sfRenderWindow *window)
{
    sfTexture *texture = sfTexture_createFromFile(perso->sprite_name, NULL);
    sfVector2f scale = {0.4, 0.4};

    sfSprite_destroy(perso->sprite);
    perso->sprite = sfSprite_create();
    sfRenderWindow_clear(window, sfBlack);
    sfSprite_setTexture(perso->sprite, texture, sfTrue);
    sfSprite_setScale(perso->sprite, scale);
    sfSprite_setPosition(perso->sprite, perso->pos);
    map_display(map, window);
    sfRenderWindow_drawSprite(window, perso->sprite, NULL);
    sfRenderWindow_display(window);
}

//move.c
//chaque key et son mouvement de sprite + un check corners avec le truc des couleurs de pix

static bool check_corners(map_t *map, perso_t *perso, int x, int y)
{
    sfVector2f sprite_pos = sfSprite_getPosition(perso->sprite);
    sfColor color;

    sprite_pos.x += x;
    sprite_pos.y += y;
    color = sfImage_getPixel(map->image, sprite_pos.x + 6, sprite_pos.y + 6);
    if (color.r != sfWhite.r && color.g != sfWhite.g && color.b != sfWhite.b)
        return false;
    return true;
}

void key_down(map_t *map, perso_t *perso, sfRenderWindow *window)
{
    int speed = 2;

    perso->sprite_name = "sprites/bas.png";
    display(map, perso, window);
    if (perso->pos.y < 950 && check_corners(map, perso, 0, 6)) {
        perso->pos.y += speed;
        perso->sprite_name = "sprites/bas1.png";
        display(map, perso, window);
        perso->pos.y += speed;
        perso->sprite_name = "sprites/bas2.png";
        display(map, perso, window);
        perso->pos.y += speed;
        perso->sprite_name = "sprites/bas3.png";
        display(map, perso, window);
        perso->sprite_name = "sprites/bas4.png";
    }
}

void key_up(map_t *map, perso_t *perso, sfRenderWindow *window)
{
    int speed = 2;

    perso->sprite_name = "sprites/haut.png";
    display(map, perso, window);
    if (check_corners(map, perso, 0, -6)) {
        perso->pos.y -= speed;
        perso->sprite_name = "sprites/haut1.png";
        display(map, perso, window);
        perso->pos.y -= speed;
        perso->sprite_name = "sprites/haut2.png";
        display(map, perso, window);
        perso->pos.y -= speed;
        perso->sprite_name = "sprites/haut3.png";
        display(map, perso, window);
        perso->sprite_name = "sprites/haut4.png";
    }
}

void key_left(map_t *map, perso_t *perso, sfRenderWindow *window)
{
    int speed = 2;

    perso->sprite_name = "sprites/left.png";
    display(map, perso, window);
    if (perso->pos.x > 0 && check_corners(map, perso, 0, 6)) {
        perso->pos.x -= speed;
        perso->sprite_name = "sprites/left1.png";
        display(map, perso, window);
        perso->pos.x -= speed;
        perso->sprite_name = "sprites/left2.png";
        display(map, perso, window);
        perso->pos.x -= speed;
        perso->sprite_name = "sprites/left3.png";
        display(map, perso, window);
        perso->sprite_name = "sprites/left4.png";
    }
}

static void key_right(map_t *map, perso_t *perso, sfRenderWindow *window)
{
    int speed = 2;

    perso->sprite_name = "sprites/droite.png";
    display(map, perso, window);
    if (perso->pos.x < 974 && check_corners(map, perso, 6, 0)) {
        perso->pos.x += speed;
        perso->sprite_name = "sprites/droite1.png";
        display(map, perso, window);
        perso->pos.x += speed;
        perso->sprite_name = "sprites/droite2.png";
        display(map, perso, window);
        perso->pos.x += speed;
        perso->sprite_name = "sprites/droite3.png";
        display(map, perso, window);
        perso->sprite_name = "sprites/droite4.png";
    }
}

//move_event.c
//l'event qui lance les mouvements selon la touche

void move_event(sfRenderWindow *window, sfEvent event, perso_t *perso, map_t *map)
{
    if (event.type == sfEvtKeyPressed) {
        if (event.key.code == sfKeyLeft)
            key_left(map, perso, window);
        if (event.key.code == sfKeyRight)
            key_right(map, perso, window);
        if (event.key.code == sfKeyDown)
            key_down(map, perso, window);
        if (event.key.code == sfKeyUp)
            key_up(map, perso, window);
    }
}
