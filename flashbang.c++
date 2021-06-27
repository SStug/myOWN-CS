#include <amxmodx>

#define PLUGIN "flashbang"
#define VERSION "1.0"
#define AUTHOR "SStug"

new g_fx
new g_Fade


public plugin_init() // installing new plugin
{
	register_plugin(PLUGIN, VERSION, AUTHOR)
	register_event("Fade", "beingFlashed", "be" "4=0", "5=0", "6=0", "7=0")
	g_fade = get_user_msgid("Fade")
	// registering server cvars
	register_cvar("amx_fb_fl", "1")
	register_cvar("amx_fb_r", "2")
	register_cvar("amx_fb_g", "1")
	register_cvar("amx_fb_b", "1")
}

public plugin_precache() // adding some sounds
{
	precache_sound("addhereyour.wavsound")
	precache_sound("addhereyour.wavsound")
	precache_sound("addhereyour.wavsound")
}

public beingFlashed(id) // here we are adding some colors to our plugin, and options for be flashed
{

}

// unfinished
