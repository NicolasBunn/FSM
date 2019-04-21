#pragma once

class Message
{
	public:

		enum class MessageType {drinkInPreparation = 0,drinkIsReady};

		int sender;
		int receiver;
		MessageType msg;
		double dispatchTime;

		Message(int sender_, int receiver_, MessageType msg_, double dispatchTime_ = 0.0);
};
