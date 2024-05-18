/*
** EPITECH PROJECT, 2024
** Jamalakitou
** File description:
** init_menu
*/

#include "../../include/functions.h"
#include "../../include/structs.h"

char *make_str(void)
{
   char *str = "Developers :\n- Ewan.schaffhauser@epitech.eu\n\n";
    str = my_strcat(str, "- Corentin.bergaentzle@epitech.eu\n\n");
    str = my_strcat(str, "- Nathan.callegari@epitech.eu\n\n");
    str = my_strcat(str, "- Matteo.milin@epitech.eu\n\n");
    str = my_strcat(str, "- Thomas.richalet@epitech.eu\n\n");
    str = my_strcat(str, "Developed with :\n - CSFML\n\n");
    return str;
}

option_t *init_option(sfFont *font)
{
    option_t *opt = malloc(sizeof(option_t));

    opt->back = create_rectangle((sfVector2f) {600, 900}, (sfVector2f) {650, 100}, sfBlack, sfColor_fromRGB(80, 80, 80));
    opt->fps = create_text("fps :", font,(sfVector2f) {720, 120}, 50);
    opt->fps30 = create_text("30", font,(sfVector2f) {900, 120}, 50);
    opt->fps60 = create_text("60", font,(sfVector2f) {1000, 120}, 50);
    opt->fps90 = create_text("90", font,(sfVector2f) {1100, 120}, 50);

    return opt;
}

menu_t *init_menu(void)
{
    menu_t *menu = malloc(sizeof(menu_t));
    sfFont *font = sfFont_createFromFile("./assets/Pixellari.ttf");

    menu->opt = init_option(font);
    menu->condic = 0;
    menu->condio = 0;
    menu->condip = 0;
    menu->condiq = 0;
    menu->back = create_rectangle((sfVector2f) {1300, 900}, (sfVector2f) {350, 100}, sfBlack, sfColor_fromRGB(80, 80, 80));
    menu->lucas = create_text("lucas.andres@epitech.eu", font, (sfVector2f) {1520, 980}, 10);
    menu->txtcredit = create_text(make_str(), font, (sfVector2f) {400, 150}, 50);
    menu->play = create_text("PLAY", font, (sfVector2f) {830, 400}, 100);
    menu->option = create_text("OPTION", font, (sfVector2f) {765, 550}, 100);
    menu->credit = create_text("CREDITS", font, (sfVector2f) {745, 700}, 100);
    menu->quit = create_text("QUIT", font, (sfVector2f) {830, 850}, 100);
    return menu;
}
