#ifndef HEADER_H
#define HEADER_H
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>


typedef struct song
{
	char* artist;
	char* album_title;
	char* song_title;
	char* genre;

	struct song_length
	{
		int min;
		int sec;

	} length;

	int counter;
	int rate;

}song;

typedef struct Node
{
	song *record;

	struct Node *next;
	struct Node *prev;
}Node;



char* str_cpy(char* str);

int cnt_num(Node* list);

void show_records(Node* list);
void display_info(song* record);
void store(Node* list);
void delete_list(Node* list);
void delete_record(song* record);
void remove_record(Node** pList);
void sorted(Node** pList, Node* node, int option);
void sort_records(Node** pList, int option);
void rate(song* record);
void edit(song* record);

Node* scan_field(Node *list);
Node* search_songTitle(Node *list);
Node* read();
Node* load();

#endif
