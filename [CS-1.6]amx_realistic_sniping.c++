// the code has been cleaned of redundant lines clogging the plugin, unfinished

#include <amxmodx>
#include <engine>
#include <fakemeta>
#include <hamsandwich>

#define PLUGIN "Sniper_Realism"
#define VERSION "1.6.0"
#define AUTHOR ""

#pragma semicolon 1

new const ZOOM_SOUND[] = "twojdzwiek w formacie weapons/plik.wav"
const Float:ZOOM_VOL = 0.2;
const Float:ZOOM_ATTN = 2.4;

// screenfade/zanikanie ekranu
enum (<<= 1) {
	FFADE_IN, // zadnej edycji
	FFADE_OUT = 1, // fadeout i fadein znaczy to samo
	FFADE_MODULATE, // modulator, nie kombinuj
	FFADE_STAYOUT // ignoruje czas dzialania, ale dziala dopoki nie pojawi sie informacja zwrotna
};

enum {
	_Red,
	_Green,
	_Blue
};
