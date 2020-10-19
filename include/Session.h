#ifndef SESSION_H
#define SESSION_H

#include "User.h"
#include "Group.h"
#include "CommunicationUtils.h"

class Session : protected CommunicationUtils
{
private:
    User *user;   // User connected to the session
    Group *group; // Group the user is connected to
    int socket;   // Scoket through which communication happens

public:
    /**
     * @brief Class constructor
     * @param username Name of the user creating the session
     * @param groupname Name of the group the user is joining
     * @param socket Socket descriptor used for communication
     */
    Session(std::string username, std::string groupname, int socket);

    /**
     * @brief Class destructor 
     */
    ~Session();

    /**
     * @brief Checks if session was created ok
     * @returns True if session opened ok, false otherwise 
     */
    bool isOpen();

    // SESSION LOGIC METHODS

    /**
     * @brief Sends the last N messages saved to the client
     * @param N how many messages to send 
     * @returns Number of messages read and sent
     */
    int sendHistory(int N);

    /**
     * @brief Sends a message from the client as the user to the group
     * @param message The message being sent
     */
    void messageGroup(message_record *message);

    /**
     * @brief Sends a message form the group to the client 
     * @param message The message being sent
     */
    void messageClient(message_record *message);
};

#endif
