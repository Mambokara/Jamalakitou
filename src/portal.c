/*
** EPITECH PROJECT, 2024
** The-olympics-flame-journey
** File description:
** portal
*/
#include "../include/structs.h"
#include <SFML/Graphics.h>
#include "../include/functions.h"

static int coord_portal(player_t *player, portal_t *portal)
{
    for (int i = 0; i < portal->nbr_portal; i++) {
        if ((player->pos.x < portal->portal_pos[i]->pos.x + 10 || player->pos.x <
            portal->portal_pos[i]->pos.x - 10) && (player->pos.y <
            portal->portal_pos[i]->pos.y + 10 || player->pos.y <
            portal->portal_pos[i]->pos.y - 10)) {
            return 1;
    } else {
            return 0;
        }
    }
}

static void teleport(player_t *player, portal_t *portal, int i)
{
    if (coord_portal(player, portal) == 1) {
        player->pos.x = portal->portal_pos[i]->pos_tp.x;
        player->pos.y = portal->portal_pos[i]->pos_tp.y;
        sfSprite_setPosition(player->runner, player->pos);
    }
}

static void create_portal(portal_t *portal)
{
    sfVector2f test = {4120,800};
    sfVector2f scale = {1,1};

    create_sprite_portal(portal, test, PORTAL, scale);
    create_sprite_portal(portal, test, PORTAL, scale);
}

void link_portal(portal_t *portal, int src, int dest)
{
    portal->portal_pos[src]->pos_tp = portal->portal_pos[dest]->pos;
}

void get_portal_in_struct(portal_t *portal)
{
    create_portal(portal);
}

void display_portal(flame_t *flame)
{
    sfRenderWindow_drawSprite(WINDOW, flame->player->runner, NULL);
}