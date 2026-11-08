#include <stdio.h>

int move_left_racket(int position, char step);
int move_right_racket(int position, char step);
void draw_field(int pos_lracket, int pos_rracket, int x_ball, int y_ball, int score_left, int score_right);
void win(int score_left, int score_right);
int valid_step(char step);

int main() {
    int pos_lracket = 13, pos_rracket = 13, x_ball = 40, y_ball = 13, move_ballx = 1, move_bally = 1;
    int score_left = 0, score_right = 0;
    char step;
    draw_field(pos_lracket, pos_rracket, x_ball, y_ball, score_left, score_right);
    while (score_left < 21 && score_right < 21 && scanf("%c", &step) == 1) {
        if (valid_step(step)) {
            pos_lracket = move_left_racket(pos_lracket, step);
            pos_rracket = move_right_racket(pos_rracket, step);
            if (y_ball == 2) {
                move_bally = -move_bally;
            } else if (y_ball == 24) {
                move_bally = -move_bally;
            }
            if (x_ball == 2 && y_ball >= pos_lracket - 1 && y_ball <= pos_lracket + 1) {
                move_ballx = -move_ballx;
            } else if (x_ball == 77 && y_ball >= pos_rracket - 1 && y_ball <= pos_rracket + 1) {
                move_ballx = -move_ballx;
            }
            x_ball += move_ballx;
            y_ball += move_bally;
            if (x_ball < 1) {
                score_right++;
                x_ball = 40;
                y_ball = 13;
                move_ballx = 1;
            } else if (x_ball > 78) {
                score_left++;
                x_ball = 40;
                y_ball = 13;
                move_ballx = -1;
            }
            draw_field(pos_lracket, pos_rracket, x_ball, y_ball, score_left, score_right);
        } else {
            draw_field(pos_lracket, pos_rracket, x_ball, y_ball, score_left, score_right);
        }
    }
    win(score_left, score_right);
    return 0;
}

int valid_step(char step) { return step == 'A' || step == 'Z' || step == 'K' || step == 'M' || step == ' '; }

int move_left_racket(int position, char step) {
    if (step == 'A' && position > 3) {
        position--;
    } else if (step == 'Z' && position < 23) {
        position++;
    }
    return position;
}

int move_right_racket(int position, char step) {
    if (step == 'K' && position > 3) {
        position--;
    } else if (step == 'M' && position < 23) {
        position++;
    }
    return position;
}

void draw_field(int pos_lracket, int pos_rracket, int x_ball, int y_ball, int score_left, int score_right) {
    int width = 80;
    int height = 25;
    for (int i = 0; i < 27; i++) {
        printf(" ");
    }
    printf("PLAYER 1: %d : %d :PLAYER 2\n", score_left, score_right);
    for (int y = 1; y <= height; y++) {
        printf("|");
        for (int x = 1; x <= width - 2; x++) {
            if (y == 1 || y == height) {
                printf("#");

            } else if ((x == 1) && (y == pos_lracket - 1 || y == pos_lracket || y == pos_lracket + 1)) {
                printf("#");

            } else if ((x == width - 2) &&
                       (y == pos_rracket - 1 || y == pos_rracket || y == pos_rracket + 1)) {
                printf("#");

            } else if (x == x_ball && y == y_ball) {
                printf("o");
            } else {
                printf(" ");
            }
        }
        printf("|\n");
    }
}

void win(int score_left, int score_right) {
    printf("                        ");
    if (score_left == 21) {
        printf("PLAYER 1 WIN. ПОЗДРАВЛЯЕМ!!! \n");
    } else if (score_right == 21) {
        printf("PLAYER 2 WIN ПОЗДРАВЛЯЕМ!!! \n");
    }
}
