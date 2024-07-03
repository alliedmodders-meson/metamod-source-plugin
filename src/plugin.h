#ifndef METAMOD_SOURCE_PLUGIN_PLUGIN_H
#define METAMOD_SOURCE_PLUGIN_PLUGIN_H

#include <ISmmPlugin.h>

class Plugin : public ISmmPlugin
{
public: // plugin_info.cpp
    const char *GetName() override;
    const char *GetAuthor() override;
    const char *GetVersion() override;
    const char *GetDescription() override;
    const char *GetURL() override;
    const char *GetLicense() override;
    const char *GetLogTag() override;
    const char *GetDate() override;

public:
    bool Load(PluginId id, ISmmAPI *ismm, char *error, size_t maxlength, bool late) override;
};

extern Plugin g_plugin;

PLUGIN_GLOBALVARS()

#endif // METAMOD_SOURCE_PLUGIN_PLUGIN_H
