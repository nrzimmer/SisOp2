#ifndef DATA_TYPES_H
#define DATA_TYPES_H

#include <iostream>
#include <map>
#include <ctime>

// Packet that is sent between server and client
typedef struct __packet
{
    uint16_t type;          // Packet type
    uint16_t sqn;           // Sequence number
    uint16_t length;        // Message lenght
    uint64_t timestamp;     // Message timestamp
    const char _payload[];  // Message payload

} packet;

// Payload for a client login packet
typedef struct __login_payload
{
    char username[21];  // Client username
    char groupname[21]; // Groupname

} login_payload;

// Struct for recording a chat message, for storage in the history file
typedef struct __message_record
{
    char username[23];      // User who sent this message (20 for name, 1 for \0 and 2 for brackets)
    uint16_t length;        // Message length
    uint64_t timestamp;     // Message timestamp for ordering purposes
    const char _message[];  // What the user said

} message_record;

#endif