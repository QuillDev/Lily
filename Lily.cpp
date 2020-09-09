//Include websocket stuff from sleepy-discord
#include "sleepy_discord/websocketpp_websocket.h"


//get strings
#include <string>

class Bot : SleepyDiscord::DiscordClient {
public:
    using SleepyDiscord::DiscordClient::DiscordClient;

    void onMessage(SleepyDiscord::Message message){

        //checks on message to see if it's worth looking at
        if(message.author.bot) return;
        if(!message.startsWith(">")) return; //TODO Load prefix from file

        //get the id of the channel, type is SleepyDiscord::Snowflake<Channel>
        auto channelID = message.channelID;

        //save the message content to a string
        std::string content = message.content;

        //send the message to the channel
        sendMessage(channelID, content);
    }
};

int main(){

}