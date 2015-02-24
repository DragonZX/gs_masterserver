Windows and MinGW compile:
have g++ folow c++11

#defines:

ASIO_STANDALONE
ASIO_DISABLE_IOCP
_WIN32_WINNT=0x0501
__NO_INLINE__

libraris:

wsock32
ws2_32

#############################
Linux gcc compile:

run compile.sh <patch to this project>

Example:
./compile.sh /media/share