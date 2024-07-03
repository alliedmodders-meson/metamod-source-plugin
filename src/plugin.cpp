#include "plugin.h"
#include <cstring>

Plugin g_plugin;

PLUGIN_EXPOSE(Plugin, g_plugin)

bool Plugin::Load(PluginId id, ISmmAPI *ismm, char *error, size_t maxlength, bool late)
{
    PLUGIN_SAVEVARS()
    return true;
}