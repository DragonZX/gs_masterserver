#include "asio.hpp"
#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <time.h>
#include <fstream>
using asio::ip::udp;

class server
{
public:
  server(asio::io_service& io_service, short port)
    : socket_(io_service, udp::endpoint(udp::v4(), port))
  {
      printf("Master Server is strarting...\n");
      refreshList();
    do_receive();
  }

  void do_receive()
  {
    socket_.async_receive_from(
        asio::buffer(data_, max_length), sender_endpoint_,
        [this](std::error_code ec, std::size_t bytes_recvd)
        {
          printf("Request: %s\n",data_);
          if (!ec)
          {
              std::time_t newTimer;
              std::time(&newTimer);
              if(newTimer - timer > 86400){
                refreshList();
              }
                do_send();
          }
          else
          {
            do_receive();
          }
        });
  }

  void do_send()
  {
    socket_.async_send_to(
        asio::buffer(buffer_, strlen(buffer_)), sender_endpoint_,
        [this](std::error_code /*ec*/, std::size_t /*bytes_sent*/)
        {
          printf("Response: %s\n",buffer_);
          do_receive();
        });
  }

  void refreshList(){
    std::ifstream servers ("servercache.txt",std::ifstream::binary);
              if(servers){
                   // while(!servers.eof()){
                        servers.read(buffer_,42);
                        //printf(buffer_);
                   // }
                    servers.close();
                    std::time(&timer);
                }else{
                printf("file not open");
              }
  }

private:
    udp::socket socket_;
    udp::endpoint sender_endpoint_;
    enum { max_length = 1024 };
    char data_[max_length];
    char * buffer_;
    std::time_t timer;
};

int main(void)
{
    asio::io_service io_service;
    server s(io_service, 20810);
    io_service.run();

    return 0;
}
