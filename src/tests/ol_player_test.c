#include "ol_debug.h"
#include "ol_player.h"
#include <gtk/gtk.h>
#include <stdlib.h>
#include <string.h>

static OlPlayer *player = NULL;

/* void get_music_info () */
/* { */
/*   if (controller == NULL) */
/*   { */
/*     controller = ol_player_get_active_player (); */
/*   } */
/*   if (controller == NULL) */
/*     return; */
/*   OlMusicInfo music = {0}; */
/*   if (!ol_player_get_music_info (controller, &music)) */
/*   { */
/*     printf ("get music info failed\n"); */
/*     controller = NULL; */
/*     return; */
/*   } */
/*   guint time = 0; */
/*   if (!controller->get_played_time (&time)) */
/*   { */
/*     printf ("get ellasped time failed\n"); */
/*     controller = NULL; */
/*     return; */
/*   } */
/*   guint duration = 0; */
/*   if (!controller->get_music_length (&duration)) */
/*   { */
/*     printf ("get duration failed\n"); */
/*     controller = NULL; */
/*     return; */
/*   } */
/*   printf ("title: %s\n" */
/*           "artist: %s\n" */
/*           "album: %s\n" */
/*           "uri: %s\n" */
/*           "time: %d\n" */
/*           "duration :%d\n", */
/*           music.title, */
/*           music.artist, */
/*           music.album, */
/*           music.uri, */
/*           time, */
/*           duration); */
/*   return; */
/* } */

/* void play () */
/* { */
/*   if (controller == NULL) */
/*     return; */
/*   if (!(ol_player_get_capacity (controller) & OL_PLAYER_PLAY)) */
/*   { */
/*     fprintf (stderr, "The player doesn't suppor this action\n"); */
/*     return; */
/*   } */
/*   if (!ol_player_play (controller)) */
/*   { */
/*     fprintf (stderr, "Play failed\n"); */
/*   } */
/* } */

/* void _pause () */
/* { */
/*   if (controller == NULL) */
/*     return; */
/*   if (!(ol_player_get_capacity (controller) & OL_PLAYER_PAUSE)) */
/*   { */
/*     fprintf (stderr, "The player doesn't suppor this action\n"); */
/*     return; */
/*   } */
/*   if (!ol_player_pause (controller)) */
/*   { */
/*     fprintf (stderr, "Play failed\n"); */
/*   } */
/* } */

/* void prev () */
/* { */
/*   if (controller == NULL) */
/*     return; */
/*   if (!(ol_player_get_capacity (controller) & OL_PLAYER_PREV)) */
/*   { */
/*     fprintf (stderr, "The player doesn't suppor this action\n"); */
/*     return; */
/*   } */
/*   if (!ol_player_prev (controller)) */
/*   { */
/*     fprintf (stderr, "Prev failed\n"); */
/*   } */
/* } */

/* void next () */
/* { */
/*   if (controller == NULL) */
/*     return; */
/*   if (!(ol_player_get_capacity (controller) & OL_PLAYER_NEXT)) */
/*   { */
/*     fprintf (stderr, "The player doesn't suppor this action\n"); */
/*     return; */
/*   } */
/*   if (!ol_player_next (controller)) */
/*   { */
/*     fprintf (stderr, "Next failed\n"); */
/*   } */
/* } */

/* void stop () */
/* { */
/*   if (controller == NULL) */
/*     return; */
/*   if (!(ol_player_get_capacity (controller) & OL_PLAYER_STOP)) */
/*   { */
/*     fprintf (stderr, "The player doesn't suppor this action\n"); */
/*     return; */
/*   } */
/*   if (!ol_player_stop (controller)) */
/*   { */
/*     fprintf (stderr, "Stop failed\n"); */
/*   } */
/* } */

/* void status () */
/* { */
/*   if (controller == NULL) */
/*     return; */
/*   if (!(ol_player_get_capacity (controller) & OL_PLAYER_STATUS)) */
/*   { */
/*     fprintf (stderr, "The player doesn't suppor this action\n"); */
/*     return; */
/*   } */
/*   enum OlPlayerStatus status = ol_player_get_status (controller); */
/*   switch (status) */
/*   { */
/*   case OL_PLAYER_PLAYING: */
/*     printf ("Playing\n"); */
/*     break; */
/*   case OL_PLAYER_STOPPED: */
/*     printf ("Stopped\n"); */
/*     break; */
/*   case OL_PLAYER_PAUSED: */
/*     printf ("Paused\n"); */
/*     break; */
/*   case OL_PLAYER_UNKNOWN: */
/*     printf ("Unknown\n"); */
/*     break; */
/*   case OL_PLAYER_ERROR: */
/*     printf ("Error\n"); */
/*     break; */
/*   } */
/* } */

/* void capacity () */
/* { */
/*   if (controller == NULL) */
/*     return; */
/*   int cap = ol_player_get_capacity (controller); */
/*   if (cap < 0) */
/*   { */
/*     fprintf (stderr, "Get capacity failed\n"); */
/*     return; */
/*   } */
/*   printf ("Capacity:"); */
/*   if (cap & OL_PLAYER_PLAY) */
/*     printf (" play"); */
/*   if (cap & OL_PLAYER_PAUSE) */
/*     printf (" pause"); */
/*   if (cap & OL_PLAYER_STOP) */
/*     printf (" stop"); */
/*   if (cap & OL_PLAYER_PREV) */
/*     printf (" prev"); */
/*   if (cap & OL_PLAYER_NEXT) */
/*     printf (" next"); */
/*   if (cap & OL_PLAYER_SEEK) */
/*     printf (" seek"); */
/*   if (cap & OL_PLAYER_STATUS) */
/*     printf (" status"); */
/*   printf ("\n"); */
/* } */

/* void seek (int pos) */
/* { */
/*   if (controller == NULL) */
/*     return; */
/*   if (!(ol_player_get_capacity (controller) & OL_PLAYER_SEEK)) */
/*   { */
/*     fprintf (stderr, "The player doesn't suppor this action\n"); */
/*     return; */
/*   } */
/*   if (!ol_player_seek (controller, pos)) */
/*   { */
/*     fprintf (stderr, "Seek failed\n"); */
/*   } */
/* } */

void player_connected_cb(OlPlayer *player, gpointer user_data) {
    printf("Player connected\n");
}

void player_disconnected_cb(OlPlayer *player, gpointer user_data) {
    printf("Player disconnected\n");
}

void status_changed_cb(OlPlayer *player, gpointer user_data) {
    printf("Status changed\n");
}

void track_changed_cb(OlPlayer *player, gpointer user_data) {
    printf("Track changed\n");
}

void caps_changed_cb(OlPlayer *player, gpointer user_data) {
    printf("Caps changed\n");
}

void connect_signals(void) {
    g_signal_connect(player,
                     "player-connected",
                     G_CALLBACK(player_connected_cb),
                     NULL);
    g_signal_connect(player,
                     "player-lost",
                     G_CALLBACK(player_disconnected_cb),
                     NULL);
    g_signal_connect(player,
                     "track-changed",
                     G_CALLBACK(track_changed_cb),
                     NULL);
    g_signal_connect(player,
                     "status-changed",
                     G_CALLBACK(status_changed_cb),
                     NULL);
    g_signal_connect(player,
                     "caps-changed",
                     G_CALLBACK(caps_changed_cb),
                     NULL);
}

int main(int argc, char **argv) {
    ol_log_set_level(OL_INFO);
    /* char usage[] = "Usage: ol_player_test <play|pause|info|next|prev|status|capacity>"; */
    gtk_init(&argc, &argv);
    /* if (argc < 2 || argc > 3) */
    /* { */
    /*   fprintf (stderr, "%s\n", usage); */
    /*   return 1; */
    /* } */
    player = ol_player_new();
    connect_signals();
    /* if (strcmp (argv[1], "info") == 0) */
    /*   get_music_info (); */
    /* else if (strcmp (argv[1], "play") == 0) */
    /*   play (); */
    /* else if (strcmp (argv[1], "pause") == 0) */
    /*   _pause (); */
    /* else if (strcmp (argv[1], "prev") == 0) */
    /*   prev (); */
    /* else if (strcmp (argv[1], "next") == 0) */
    /*   next (); */
    /* else if (strcmp (argv[1], "stop") == 0) */
    /*   stop (); */
    /* else if (strcmp (argv[1], "status") == 0) */
    /*   status (); */
    /* else if (strcmp (argv[1], "capacity") == 0) */
    /*   capacity (); */
    /* else if (argc == 3 && strcmp (argv[1], "seek") == 0) */
    /* { */
    /*   int pos = 0; */
    /*   sscanf (argv[2], "%d", &pos); */
    /*   seek (pos); */
    /* } */
    /* else */
    /*   fprintf (stderr, "%s\n", usage); */
    gtk_main();
    g_object_unref(player);
    return 0;
}
