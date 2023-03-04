#pragma once
#ifndef __FT_SOCKET_H__
#define __FT_SOCKET_H__

#include <string>
#include <set>
//#include <map>
#include <sys/event.h> // kqueue

namespace ft{

// 1. map<int, ClientInfo>
//    client[fd] = info
// 2-1. map<Channel, ClientInfo>
//    channel[name] = info			// info has fd
// 2-2. map<Channel, pair<fd, ClientInfo> >
//    channel[name] = info

struct ClientInfo{
	//int fd;
	std::string nick;
	std::string host;
	std::string channel; // channel no? (like fd)
	bool is_oper;		 // single channel or multi channel
	// ban_channel;
	//std::string level;
	//std::string text;
};

class Socket{
public:
	Socket(int port);
	~Socket();

	void run();

private:
	Socket();
	Socket(const Socket& other);

	Socket& operator=(const Socket&);

	typedef std::set<int>::iterator iterator;

	int __port_;
	//int __password_;
	int __server_fd_;
	int __kq_fd_;
	std::set<int> __client_fd_;
	void (Socket::*__eventPtr_[5])(const std::string &);

	void __srv_create();
	void __setNonBlock(int fd);
	void __updateEvent(int fd);

	void __handleAccept(int client_fd);
	void __handleRead(int client_fd);

	void __insert_client(int fd);
	void __erase_client(int fd);

	void __send(const std::string &buf);
	//void __join(const std::string);
};

}

#endif /* __FT_SOCKET_H__ */
