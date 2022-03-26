//
// Created by Bartu Kaynar on 9.03.2022.
//

/*
    What to Eat Program
    This program helps to a group of people for decising what they eat.
    Copyright (c) 2022 Hasan Bartu Kaynar

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by the Free Software
    foundation; either version 2.1 of the License or any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
    General Public License for more details.

    You should have received a copy of the GNU General Public License along with this program; if not,
    write to the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

    You can contact me as well by: bartu.kaynar@ozu.edu.tr or mail me to Ozyegin University Dorm Cekmekoy/Istanbul 34794 / Turkiye
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NUMBER_OF_STRING 5
#define MAX_STRING_SIZE 40
#define THRESHOLD 10

int main() {
    int people = 0;
    printf("How many people are you?\n>>");
    scanf("%d", &people);
    int i = 0;
    int selected = -1;
    char arr[NUMBER_OF_STRING][MAX_STRING_SIZE] =
            {"Kebab",
             "Burger",
             "Pasta",
             "Lahmacun",
             "Salad"
            };
    int meals[NUMBER_OF_STRING]; // 0:Kebab,1:Burger,2:Pasta,3:Lahmacun,4:Salad
    for (int j = 0; j < NUMBER_OF_STRING; j++) {
        meals[j] = 0;
    }
    while (i < people) {
        printf("Person Number:%d", i + 1);
        printf(" What do you want to eat today?(Enter Number like 12345): \n1-Kebab\n2-Burger\n3-Pasta\n4-Lahmacun\n5-Salad\n>>");
        char select[NUMBER_OF_STRING];
        scanf("%s", &select);
        int order = 0;
        while (order < NUMBER_OF_STRING) {
            switch (select[order]) {
                default:
                    printf("All numbers must be between 1 and 5 rerun the program!!");
                    exit(0);
                case '1':
                    meals[0] += NUMBER_OF_STRING - order;
                    order++;
                    break;
                case '2':
                    meals[1] += NUMBER_OF_STRING - order;
                    order++;
                    break;
                case '3':
                    meals[2] += NUMBER_OF_STRING - order;
                    order++;
                    break;
                case '4':
                    meals[3] += NUMBER_OF_STRING - order;
                    order++;
                    break;
                case '5':
                    meals[4] += NUMBER_OF_STRING - order;
                    order++;
                    break;
            }
        }
        i++;
    }
    int biggerThanThreshold = 0;
    int shortList[biggerThanThreshold];
    for (int j = 0; j < NUMBER_OF_STRING; j++) {

        if (meals[j] > THRESHOLD) {
            printf("%s : %d\n", arr[j], meals[j]);
            shortList[biggerThanThreshold] = j;
            biggerThanThreshold++;
        }
    }
    if (biggerThanThreshold == 0) {
        printf("You are eating at home today!\n");
        exit(0);
    } else if (biggerThanThreshold > 1) {
        bool tie = true;
        while (tie) {
            printf("Second Round is starting...\n");
            for (int j = 0; j < NUMBER_OF_STRING; j++) {
                meals[j] = 0;
            }
            i = 0;
            while (i < people) {
                printf("Person Number:%d", i + 1);
                printf(" What do you want to eat today?(Enter Number like 12345):\n");
                /*for(int j = 0; j < NUMBER_OF_STRING; j++){
                    printf("shortlist %d %s\n",j,arr[shortList[j]]);
                }*/
                for (int i = 0; i < biggerThanThreshold; i++) {
                    printf("%d-%s\n", (i + 1), arr[shortList[i]]);
                }
                char select[biggerThanThreshold];
                scanf("%s", &select);
                int order = 0;
                while (order < biggerThanThreshold) {
                    switch (shortList[(select[order] - '0') - 1]) {
                        default:
                            printf("All numbers must be between 1 and 5 rerun the program!!", biggerThanThreshold);
                            exit(0);
                        case 0:
                            meals[0] += NUMBER_OF_STRING - order;
                            //printf("%d\n",meals[0]);
                            order++;
                            break;
                        case 1:
                            meals[1] += NUMBER_OF_STRING - order;
                            //printf("%d\n",meals[1]);
                            order++;
                            break;
                        case 2:
                            meals[2] += NUMBER_OF_STRING - order;
                            //printf("%d\n",meals[2]);
                            order++;
                            break;
                        case 3:
                            meals[3] += NUMBER_OF_STRING - order;
                            //printf("%d\n",meals[3]);
                            order++;
                            break;
                        case 4:
                            meals[4] += NUMBER_OF_STRING - order;
                            //printf("%d\n",meals[4]);
                            order++;
                            break;
                    }
                }
                i++;
            }
            biggerThanThreshold = 0;
            shortList[biggerThanThreshold];
            for (int j = 0; j < NUMBER_OF_STRING; j++) {
                printf("%s => %d\n", arr[j], meals[j]);
                if (meals[j] > THRESHOLD) {
                    shortList[biggerThanThreshold] = j;
                    biggerThanThreshold++;
                }
            }
            selected = -1;
            for (int i = 0; i < NUMBER_OF_STRING; i++) {
                if (meals[i] == meals[selected] && meals[i] > 0)
                {
                    tie = true;
                    printf("Please select again because there is a tie between foods!!\n");
                    break;
                }
                else tie = false;
                if (selected == -1 || meals[i] > meals[selected]) { selected = i; }
            }
        }
    }
    printf("You are eating %s", arr[selected]);
    return 0;
}


