#ifndef TCPSTACK_H
#define TCPSTACK_H

#include <vector>

#define MAX_PACKETSIZE	unsigned int

#include "../../Interface/Pipe.h"

class CWData;

const int c_default_timeout = 10000;

class CTCPStack
{
public:
	CTCPStack(bool add_checksum=false);
	void AddData(char* buf, size_t datasize);
	void AddData(std::string data);

	char* getPacket(size_t* packsize);
	bool getPacket(std::string& msg);

	size_t Send(IPipe* p, char* buf, size_t msglen, int timeoutms = c_default_timeout, bool flush=true);
	size_t Send(IPipe* p, CWData data, int timeoutms = c_default_timeout, bool flush=true);
	size_t Send(IPipe* p, const std::string &msg, int timeoutms = c_default_timeout, bool flush=true);

    void reset(void);

	char *getBuffer();
	size_t getBuffersize();

	void setAddChecksum(bool b);

private:
	
	std::vector<char> buffer;

	bool add_checksum;
};

#endif //TCPSTACK_H