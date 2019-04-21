#include "Message.h"

Message::Message(int sender_, int receiver_, MessageType msg_, double dispatchTime_)
	: sender(sender_),receiver(receiver_),msg(msg_),dispatchTime(dispatchTime_)
{

}