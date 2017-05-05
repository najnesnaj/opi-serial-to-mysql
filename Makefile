CC=gcc
CFLAGS= -I inc -I /usr/include/mysql
LIBS=/usr/lib/arm-linux-gnueabihf/libmysqlclient.so
testserial : opi-serial.o opi-uart.o opi-mysql.o 
	$(CC) -o testserial opi-serial.o opi-uart.o opi-mysql.o  $(CFLAGS) $(LIBS)

