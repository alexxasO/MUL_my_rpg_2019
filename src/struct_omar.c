/*
** EPITECH PROJECT, 2020
** struct_omar.c
** File description:
** comme son nom l indique ce fichier permet de connaitre les structures utilisées par Omar
*/

typedef struct {
    sfVector2f pos;
    sfSprite *sprite;
    char *sprite_name;
} perso_t;

typedef struct {
    sfVector2f pos;
    sfImage *image;
    sfSprite *sprite;
    unsigned int width;
    unsigned int height;
} map_t;


void display(map_t *map, perso_t *perso, sfRenderWindow *window);
perso_t init_perso(int x, int y, char *filename);
map_t init_map(int x, int y, char *filename);
void move_perso(sfRenderWindow *window, sfEvent event, perso_t *perso, map_t *map);
