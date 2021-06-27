#include <amxmodx>

#define PLUGIN "flashbang"
#define VERSION "1.0"
#define AUTHOR ""

new g_nMsgFade
new g_fbfx

public plugin_init() // installing new plugin
{
	register_plugin(PLUGIN, VERSION, AUTHOR)
	register_event("Fade", "Flashed", "be", "4=255", "5=255", "6=255", "7>199")
	g_nMsgFade = get_user_msgid("Fade")
	// registering server_cvars
	register_cvar("amx_fb_mode", "1")
	register_cvar("amx_fb_r", "2")
	register_cvar("amx_fb_g", "1")
	register_cvar("amx_fb_b", "1")
}

public plugin_precache() // adding some sounds
{
	precache_sound("yoursound .wav format")
	precache_sound("^^")
	precache_sound("^^")
	// add your three sounds
}

public Flashed(id) // installing colors and options for being flashed
{
	new iMode = get_cvar_num("amx_fb_mode")
	if(!iMode) return PLUGIN_CONTINUE
		new iRed, iGreen, iBlue
	switch(iMode)
	{
		case 1:
		{
			iRed = get_cvar_num("amx_fb_r")
			iGreen = get_cvar_num("amx_fb_g")
			iBlue = get_cvar_num("amx_fb_b")
		}
		case 2:
		{
			iRed = random_num(0, 255)
			iGreen = random_num(0 ,255)
			iBlue = random_num(0, 255)
		}
	}
	if(!(iRed) || !(iGreen) || !(iBlue))
	{
		iRed = 100
		iGreen = 100
		iBlue = 100
	}
	message_begin(MSG_ONE, g_nMsgFade, {0, 0, 0}, id)
	write_short(read_data(1)) // duration of being flashed
	write_short(read_data(1)) // hold time of being flashed
	write_short(read_data(3)) // fade type
	write_byte(iRed)
	write_byte(iGreen)
	write_byte(iBlue)
	write_byte(read_data(7))
	message_end()
	client_cmd(id, "yoursoundhere") // you are hearing stunning sound now
	set_task(1.5, "shtflash", id) // stunned
	return PLUGIN_HANDLED
}

public shtflash(id) // wake up bruh
{
	if(g_fbfx == 0)
	{
		client_cmd(id, "yoursoundhere")
		client_cmd(id, "yoursoundhere")
		g_fbfx = 1
		set_task(7.0, "flashstun_unblock", id) // blocking stun event
	}

}

public flashstun_unblock(id) // blocking stunnig event for your eyes : )
gfbfx = 0
