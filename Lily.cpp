//Include websocket stuff from sleepy-discord
#include "sleepy_discord/websocketpp_websocket.h"

//include nlohmann_json
#include "nlohmann/json.hpp"

//get strings
#include <string>

//set json
using json = nlohmann::json;

//Create the bot client
class Bot : public SleepyDiscord::DiscordClient {
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

    //Create an inputstream for options.json
    std::ifstream options("options.json");

    //Create a json object called optionsjson
    json optionsJSON;

    //save the output of options to the optionsjson
    options >> optionsJSON;

    //Create a client using the token found in optionsJSON
    Bot client(optionsJSON["token"], 2);
    client.run();
}