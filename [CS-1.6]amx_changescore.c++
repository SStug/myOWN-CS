#include <amxmodx>
#include <amxmisc>
#include <cstrike>
#include <fun>

#define NAME = "change_player_score"
#define VERSION = "1.0.0"
#define AUTHOR = ""

new gMsgScoreInfo

public plugin_init()
{
	register_plugin("change_player_score", "1.0.0", "")
	register_clcmd("amx_changescore", "changescore", ADMIN_CVAR, " - amx_changescore <nick> <kills#> <deaths#>")
	gMsgScoreInfo = get_user_msgid("ScoreInfo")
}

public change_score(id, level, cid)
{
	if(!cmd_access(id, level, cid, 2))
	{
		return PLUGIN_HANDLED
	}
	new victim[32], deathsl[32], killsl[32]
	read_argv(1, victim, 31)
	read_argv(2, killsl, 31)
	new kills = str_to_num(killsl)
	read_argv(3, deathsl, 31)
	new deaths = str_to_num(deathsl)
	if (victim[0] == "@")
	{
		new team[32], inum
		get_players(team, inum, "e", victim[1])
		if (inum == 0)
		{
			console_print(id, "[AMX]Nie znaleziono podanego gracza.")
			return PLUGIN_HANDLED
		}
		for (new i = 0; i < inum; i++)
		{
			new teams = get_user_team(team[i])
			set_user_kills(team[i], kills)
			cs_set_user_deaths(team[i], deaths)
			message_begin(MSG_ALL, gMsgScoreInfo)
			write_byte(team[i])
			write_short(kills)
			write_short(deaths)
			write_short(0)
			write_short(teams)
			message_end()
		}
	}
	else
	{
		new user = cmd_target(id, victim, 0)
		new authid[32]
		get_user_authid(user, authid, 31)
		if (!user)
		{
			console_print(id, "[AMX]Nie znaleziono podanego gracza.")
			return PLUGIN_HANDLED
		}
		new teams = get_user_team(user)
		set_user_kills(user, kills)
		cs_set_user_deaths(user, deaths)
		message_begin(MSG_ALL, gMsgScoreInfo)
		write_byte(user)
		write_short(kills)
		write_short(deaths)
		write_short(0)
		write_short(teams)
		message_end()
	}
	return PLUGIN_HANDLED
}
