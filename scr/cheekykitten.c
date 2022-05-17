#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "algo.h"

#define BUFSZ 8

void version () {
    char version[] = "Lib-CheekyKitten 0.3 Beta by Josjuar Lister 2021-2022";
    char algo[] = " -- Logical Algorithm\n";
        fprintf(stderr, version, algo);
}

int cheeky (char *in, char *out, int *flip) {

    int opt, binary = 0, n = 0;
    
    if (flip == NULL) 
        flip = 0;
    unsigned char buf[BUFSZ] = {0};
    size_t bytes = 0, i, readsz = sizeof buf;

    if (in != NULL && out != NULL) {
        if (!strcmp(in, out)) {
            printf("Warning! setting the same input and output will destroy the data\n");
            exit(5318008);
        }
    }
    FILE *fo = out != NULL ? fopen (out, "wb") : stdout;
    if (fo == NULL) {
        printf("error opening output file: %s\n", fo);
        exit(1);
    }
    FILE *fi = in != NULL ? fopen (in, "rb") : stdin;
    if (fi == NULL) {
        printf("error opening input file: %s\n", fi);
        exit(1);
    }

        /* read/output BUFSZ bytes at a time */
        while ((bytes = fread (buf, sizeof *buf, readsz, fi)) == readsz) {
            for (i = 0; i < readsz; i++)
                if (i%2 == 0) {
                    int x = buf[i];
                    int y = buf[i+1];
                        //insert algorithm here!
                    if (! flip) {
                        int tx = x; //weird bug fix
                        int ty = y; //weird bug fix
                        x = x_ixi(tx, ty);
                        y = y_ixi(tx, ty);
                    }
                    else {
                        int tx = x; //weird bug fix
                        int ty = y; //weird bug fix
                        x = x_xx(tx, ty);
                        y = y_xx(tx, ty);
                    }
                    size_t ewx = fwrite(&x, 1, 1, fo);
                    size_t ewy = fwrite(&y, 1, 1, fo);
                    if (ewx == 0 || ewy == 0) {
                        return 2;
                    }
                }
            if (fo == stdout) {
                putchar ('\n');
            }
        }
        /* output final partial buf */
        for (i = 0; i < bytes; i++)
            if (i%2 == 0) {
                int x = buf[i];
                int y = buf[i+1];
                    //and here!
                if (! flip) {
                    int tx = x; //weird bug fix
                    int ty = y; //weird bug fix
                    x = x_ixi(tx, ty);
                    y = y_ixi(tx, ty);
                }
                else {
                    int tx = x; //weird bug fix
                    int ty = y; //weird bug fix
                    x = x_xx(tx, ty);
                    y = y_xx(tx, ty);
                }
                size_t ewx = fwrite(&x, 1, 1, fo);
                size_t ewy = fwrite(&y, 1, 1, fo);
                if (ewx == 0 || ewy == 0) {
                    return 2;
                }
            }

    if (fi != stdin)
        fclose (fi);
    if (fo != stdout)
        fclose (fo);
    else 
        putchar('\n');
    return 0;
}
