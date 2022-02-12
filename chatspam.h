void (*SendChatMessage)(void *instance, _monoString *message);
void (*old_LobbyGlobalChatUpdate)(void *instance);
void LobbyGlobalChatUpdate(void *instance)
{
    if(instance != nullptr)
    {
        if(isGlobalChatSpam)
        {
            for(int Message = 1; Message < 8; Message++)
            {
                switch (Message)
                {
                    case 1:
                        SendChatMessage(instance, CreateMonoString(OBFUSCATE("Polarmods is here!")));
                        break;

                    case 2:
                        SendChatMessage(instance, CreateMonoString(OBFUSCATE("Polarmods is on top.")));
                        break;

                    case 3:
                        SendChatMessage(instance, CreateMonoString(OBFUSCATE("Visit Polarmods.com for android modding tutorials, mods, and more!")));
                        break;

                    case 4:
                        SendChatMessage(instance, CreateMonoString(OBFUSCATE("Be a part of the best community today at Polarmods.com :)")));
                        break;

                    case 5:
                        SendChatMessage(instance, CreateMonoString(OBFUSCATE("This game has no anticheat, even Axey can mod it xD")));
                        break;

                    case 6:
                        SendChatMessage(instance, CreateMonoString(OBFUSCATE("Do the thing you wanted to do today, instead of pushing it to the next day. Just do it!")));
                        break;

                    case 7:
                        SendChatMessage(instance, CreateMonoString(OBFUSCATE("Join our discord! discord.gg/QCpzqjtcUB")));
                        break;
                }
            }
        }
    }
    old_LobbyGlobalChatUpdate(instance);
}

void Hooks()
{
    hook((void*)offsets->LobbyGlobalChatUpdate, (void*)LobbyGlobalChatUpdate, (void**)&old_LobbyGlobalChatUpdate); //Update (CombatMaster.View.UI.Lobby.LobbyGlobalChat)
    SendChatMessage = (void(*)(void*, _monoString*))offsets->isGlobalChatMessage; //SendGlobalMessage (CombatMaster.View.UI.Lobby.LobbyGlobalChat)
}
