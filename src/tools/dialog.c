/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Display dialogs
*/

#include "header.h"

static int get_npc_num(char *pathname)
{
    char *pathnames[] = {"image/npc/grey.png",
    "image/npc/void.png", "image/npc/zilios.png",
    "image/npc/sharp.png", "image/npc/sarah.png",
    "image/npc/ralem.png", "image/npc/rarrior.png",
    "image/npc/nig.png", "image/npc/liam.png",
    "image/npc/ian.png", "image/npc/guard.png",
    "image/npc/klive.png", "image/npc/blouik.png",
    "image/npc/alexia.png", "image/npc/achille.png"};

    for (size_t i = 0; i < 15; i++)
        if (my_strcmp(pathnames[i], pathname) == 0)
            return i;
    return -1;
}

const char *sharp_dialog[] = {"Shla, shla, shla... this"\
" tower is pretty easy for Sharp, shla, shla, Black Dagger"\
" yeaaah... Oh hey newbie, here to take on The Tower, good "\
"luck you'll need it",
"Still here newbie ? You look weak, go grab some items,"\
" shla, shla, shla...",
"Shla, shla, shla … Go away newbie ! I’m in a fight, shla…",
"Shla, shla, shla …",
"If you think you are gonna beat the Tower like that, you "\
"are stupid, newbie ! Shla, shla, shla …"};

const char *klive_dialog[] = {"This time I am ready, I have "\
"trained for one year, I’m sure I’ll get to the next floor!",
"You can do it Klive, you’re strong Klive, huh… I think",
"Motivation, motivation, motivation ! is there any Soda around?",
"I AM THE STRONGEEEEEST ! At least, I hope...",
"Here Is Klive ! Watch out evil creatures !"};

const char *void_dialog[] = {"...",
"...no return...",
"...no type...",
"...nothing...",
"..void..."};

const char *ian_dialog[] = {"I can feel your energy, ohhh, yes, "\
"i can feel it, come closer...",
"You seem very strong, ummm, yes what an energy, you may get to "\
"the last floor.",
"The Gods of Light hope you will reach the end.",
"Yes energy, surround me...",
"Watch out ! I feel negative energy from the next floor..."};

const char *sarah_dialog[] = {"Hey cutie, what is it? Oh yes, I"\
"don’t care, bye...",
"I’ve fallen in love, i think i hurt myself, can you heal me? Just "\
"kidding… go away",
"Get the f*** out of here, you want a picture or what",
"Are you going to stop looking at me !",
"Can you please stop interrupting me !"};

const char *blouik_dialog[] = {"“Hey, you got any Burglos? I’ve lost "\
"my Kwik",
"Have you seen the size of those Bloubies?",
"My name is Blouik Gazorpinurickos, nice to kwik you",
"This monster looks like a pwik",
"Do you want Skrilwok ?"};

const char *rarrior_dialog[] = {"I am here for revenge !",
"RAAAAAAAAAAAAAAAAAH !",
"A fight only ends when all the enemies are dead.",
"Don’t touch me !",
"F***** Darkelion !"};

const char *nig_dialog[] = {"Hey, wassup my nigg, doin’ okay? "\
"This tower is lit",
"Hey man, don’t use the N word.",
"What did you call me? Say that again b*tch",
"You human, never stop laughing about my kind",
"Go away before I get mad !"};

const char *ralem_dialog[] = {"What? oh my arm… a Tricarn ate it boy",
"This floor is pretty hard, be careful boy...",
"In my hometown they used to call me Ralem the invincible, maybe "\
"someday you’ll be a badass like me boy...",
"Are you lost, boy ?",
"I hope I will get to the top this time, boy."};

const char *achille_dialog[] = {"Mmmmmmm…",
"Go away i’m meditating. Mmmmm…",
"My hair? It’s my 589 days on this floor, so i lost it",
"Let the spirit of my master be with me.",
"You should be meditating, it helps a lot !"};

const char *guard_dialog[] = {"Watch out ! There are strong monster "\
"at this floor",
"Hello ! My name is Guard, and I am a knight",
"What ? Obviously I’m a girl !",
"My helmet helps me to focus my vision.",
"Tell me if you need help !"};

const char *liam_dialog[] = {"Blood, blood, blood, Team STF for life,"\
"blood...",
"What? The red on my shirt? That’s Ketchup dude…",
"You look nice, you will look better when i kill-um call you, hehe…",
"Blooooood...",
"Do you wanna see my knife closer ?"};

const char *zilios_dialog[] = {"What? A zombie? Where?",
"Go away, i’m green not a Zombie",
"Xylios god of the Greens, protect me, i told you to leave me…",
"6 arms give advantages and disadvantages",
"What was that !? Oh it’s only you..."};

const char *grey_dialog[] = {"I am grey.",
"Who are you ?",
"Step away.",
"Leave me alone.",
"My fist will beat them all."};

const char *alexia_dialog[] = {"Yo bro !",
"Oh are you also a soldier ?",
"Hey !",
"You jacket is awesome, just like mine !",
"YO BRO !"};

static const char *choose_dialog(int npc_num)
{
    const char **dialog[] = {grey_dialog, void_dialog, zilios_dialog,
    sharp_dialog, sarah_dialog, ralem_dialog, rarrior_dialog,
    nig_dialog, liam_dialog, ian_dialog, guard_dialog, klive_dialog,
    blouik_dialog, alexia_dialog, achille_dialog};

    return dialog[npc_num][random_int(5)];
}

void display_dialog(game_manager_t *gm, size_t npc_id)
{
    int npc_num =
    get_npc_num(gm->scenes[gm->scene_id]->players[npc_id]->pathname);
    const char *dialog = choose_dialog(npc_num);

    if (my_strcmp(gm->scenes[gm->scene_id]->texts[0]->string, "") == 0) {
        free(gm->scenes[gm->scene_id]->texts[0]->string);
        gm->scenes[gm->scene_id]->texts[0]->string =
        my_strdup(dialog);
        gm->scenes[gm->scene_id]->texts[0]->pos.x = 1000 - my_strlen(dialog)
        * 7;
    }
}

void erase_dialog(game_manager_t *gm)
{
    free(gm->scenes[gm->scene_id]->texts[0]->string);
    gm->scenes[gm->scene_id]->texts[0]->string = my_strdup("");
}